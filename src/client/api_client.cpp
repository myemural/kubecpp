/*
 * Copyright 2025 Mustafa Yemural(myemural)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "kubecpp/client/api_client.h"

#include <algorithm>
#include <iostream>

#include "cpr/cpr.h"
#include "cpr/ssl_ctx.h"
#include "cpr/ssl_options.h"

#include "kubecpp/client/api_client.h"
#include "kubecpp/common/constants.h"
#include "kubecpp/common/file_utils.h"
#include "kubecpp/common/string_utils.h"

namespace kubecpp::client
{

namespace
{

/// TODO: Currently only accepts json.
inline const auto kDefaultHeader = cpr::Header{ { "Content-Type", "application/json" }, { "Accept", "application/json" } };

} // namespace

using namespace kubecpp::common;
using namespace kubecpp::common::constants;

ApiClient::ApiClient(const ApiConfig& config)
    : basePath_{ kK8sDefaultBasePath }
{
    // Get current context
    const auto currentContext = config.CurrentContext;

    // Get current user and cluster
    std::string currentUser;
    std::string currentCluster;
    if(auto contextIt = std::find_if(config.Contexts.begin(), config.Contexts.end(),
       [&currentContext](const ApiConfig::NamedContext& item) { return item.Name == currentContext; });
    contextIt != config.Contexts.end()) {
        currentUser    = contextIt->Context.User;
        currentCluster = contextIt->Context.Cluster;
    }

    // Get client certificate and client key
    if(auto userIt = std::find_if(config.Users.begin(), config.Users.end(),
       [&currentUser](const ApiConfig::NamedAuthInfo& item) { return item.Name == currentUser; });
    userIt != config.Users.end()) {
        const std::string clientCertificate = userIt->User.ClientCertificateData;
        sslConfig_.ClientCertFile           = CreateTempFile("kubeconfig", clientCertificate);
        const std::string clientKey         = userIt->User.ClientKeyData;
        sslConfig_.ClientKeyFile            = CreateTempFile("kubeconfig", clientKey);

        // Get Bearer Token, if available
        if(!userIt->User.Token.empty()) {
            bearerToken_ = userIt->User.Token;
        }
    }

    // Get server address and CA
    if(auto clusterIt = std::find_if(config.Clusters.begin(), config.Clusters.end(),
       [&currentCluster](const ApiConfig::NamedCluster& item) { return item.Name == currentCluster; });
    clusterIt != config.Clusters.end()) {
        basePath_                   = clusterIt->Cluster.Server;
        const std::string currentCA = clusterIt->Cluster.CertificateAuthorityData;
        sslConfig_.CaCertFile       = CreateTempFile("kubeconfig", currentCA);
    }
}

ApiClient::~ApiClient()
{
    RemoveFile(sslConfig_.CaCertFile);
    RemoveFile(sslConfig_.ClientCertFile);
    RemoveFile(sslConfig_.ClientKeyFile);
}

ApiClient::ApiResponse ApiClient::Execute(const HttpMethod& method, const std::string& path, const std::string& body) const
{
    const cpr::SslOptions sslOpts = cpr::Ssl(cpr::ssl::VerifyPeer{ !sslConfig_.InsecureSkipTlsVerify },
    cpr::ssl::CertFile{ sslConfig_.ClientCertFile }, cpr::ssl::KeyFile{ sslConfig_.ClientKeyFile });

    cpr::Response response;
    std::string fullUrl = BuildPath({ basePath_, path });

    /// TODO: This logic can be changed.
    if(method == HttpMethod::kPost) {
        response = cpr::Post(cpr::Url{ fullUrl }, kDefaultHeader, cpr::Body(body), sslOpts, cpr::Bearer{ bearerToken_ });
    } else if(method == HttpMethod::kGet) {
        response = cpr::Get(cpr::Url{ fullUrl }, kDefaultHeader, sslOpts, cpr::Bearer{ bearerToken_ });
    } else if(method == HttpMethod::kDelete) {
        response = cpr::Delete(cpr::Url{ fullUrl }, kDefaultHeader, cpr::Body(body), sslOpts, cpr::Bearer{ bearerToken_ });
    } else if(method == HttpMethod::kPut) {
        response = cpr::Put(cpr::Url{ fullUrl }, kDefaultHeader, cpr::Body(body), sslOpts, cpr::Bearer{ bearerToken_ });
    } else if(method == HttpMethod::kPatch) {
        response = cpr::Patch(cpr::Url{ fullUrl }, kDefaultHeader, cpr::Body(body), sslOpts, cpr::Bearer{ bearerToken_ });
    }

    // For debugging
    std::cout << "Request: " << '\n';
    std::cout << "Path: " << fullUrl << '\n';
    std::cout << "Body: " << body << '\n';

    std::cout << "Response: " << '\n';
    std::cout << "Status code: " << response.status_code << '\n';
    std::cout << "Body: " << response.text << '\n';
    std::cout << "Error code: " << static_cast<int>(response.error.code) << '\n';
    std::cout << "Error message: " << response.error.message << '\n';

    return ApiResponse{ response.status_code, response.text, response.reason };
}

} // namespace kubecpp::client