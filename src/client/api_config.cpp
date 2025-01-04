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

#include "kubecpp/client/api_config.h"

#include "ryml.hpp"
#include "ryml_std.hpp"

#include "kubecpp/common/constants.h"
#include "kubecpp/common/file_utils.h"
#include "kubecpp/common/yaml_utils.h"

namespace kubecpp::client
{

namespace
{

inline void ProcessClusters(std::vector<ApiConfig::NamedCluster>& clusters, const c4::yml::Tree& tree)
{
    for(const auto& cluster : tree["clusters"]) {
        ApiConfig::NamedCluster namedCluster;
        YAML_GET_CHILD(cluster, "name", namedCluster.Name);
        if(cluster.has_child("cluster")) {
            YAML_GET_CHILD(cluster["cluster"], "server", namedCluster.Cluster.Server);
            YAML_GET_CHILD(cluster["cluster"], "tls-server-name", namedCluster.Cluster.TlsServerName);
            YAML_GET_CHILD(cluster["cluster"], "insecure-skip-tls-verify", namedCluster.Cluster.InsecureSkipTlsVerify);
            YAML_GET_CHILD(cluster["cluster"], "certificate-authority", namedCluster.Cluster.CertificateAuthority);
            YAML_GET_CHILD(cluster["cluster"], "certificate-authority-data", namedCluster.Cluster.CertificateAuthorityData);
            YAML_GET_CHILD(cluster["cluster"], "proxy-url", namedCluster.Cluster.ProxyUrl);
            YAML_GET_CHILD(cluster["cluster"], "disable-compression", namedCluster.Cluster.DisableCompression);
        }
        clusters.push_back(std::move(namedCluster));
    }
}

inline void ProcessUsers(std::vector<ApiConfig::NamedAuthInfo>& users, const c4::yml::Tree& tree)
{
    for(const auto& user : tree["users"]) {
        ApiConfig::NamedAuthInfo namedAuthInfo;
        YAML_GET_CHILD(user, "name", namedAuthInfo.Name);
        if(user.has_child("user")) {
            YAML_GET_CHILD(user["user"], "client-certificate", namedAuthInfo.User.ClientCertificate);
            YAML_GET_CHILD(user["user"], "client-certificate-data", namedAuthInfo.User.ClientCertificateData);
            YAML_GET_CHILD(user["user"], "client-key", namedAuthInfo.User.ClientKey);
            YAML_GET_CHILD(user["user"], "client-key-data", namedAuthInfo.User.ClientKeyData);
            YAML_GET_CHILD(user["user"], "token", namedAuthInfo.User.Token);
            YAML_GET_CHILD(user["user"], "tokenFile", namedAuthInfo.User.TokenFile);
            YAML_GET_CHILD(user["user"], "as", namedAuthInfo.User.As);
            YAML_GET_CHILD(user["user"], "as-uid", namedAuthInfo.User.AsUid);
            /// TODO: Add "as-groups"
            /// TODO: Add "as-user-extra"
            YAML_GET_CHILD(user["user"], "username", namedAuthInfo.User.Username);
            YAML_GET_CHILD(user["user"], "password", namedAuthInfo.User.Password);
            /// TODO: Add "auth-provider"
            /// TODO: Add "exec"
        }
        users.push_back(std::move(namedAuthInfo));
    }
}

inline void ProcessContexts(std::vector<ApiConfig::NamedContext>& contexts, const c4::yml::Tree& tree)
{
    for(const auto& context : tree["contexts"]) {
        ApiConfig::NamedContext namedContext;
        YAML_GET_CHILD(context, "name", namedContext.Name);
        if(context.has_child("context")) {
            YAML_GET_CHILD(context["context"], "cluster", namedContext.Context.Cluster);
            YAML_GET_CHILD(context["context"], "user", namedContext.Context.User);
            YAML_GET_CHILD(context["context"], "namespace", namedContext.Context.Namespace);
        }
        contexts.push_back(std::move(namedContext));
    }
}

} // namespace

using namespace kubecpp::common;
using namespace kubecpp::common::constants;

ApiConfig::ApiConfig(std::string filePath)
{
    /// TODO: Currently this part will not work. Will be refactored later.
    if(filePath.empty()) {
#ifndef _WIN32
        filePath = kK8sKubeconfigDefaultPathLinux;
#else
        filePath = kK8sKubeconfigDefaultPathWin;
#endif
    }

    // Read all file
    const std::string fileContent = ReadAllFile(filePath);

    // Process config YAML
    ryml::Tree tree = ryml::parse_in_arena(ryml::to_csubstr(fileContent));
    tree["apiVersion"] >> ApiVersion;
    tree["kind"] >> Kind;
    if(tree.find_child(tree.root_id(), "current-context") != 0ULL) {
        tree["current-context"] >> CurrentContext;
    }
    if(tree.find_child(tree.root_id(), "preferences") != 0ULL) {
        YAML_GET_CHILD(tree["preferences"], "color", Preferences.Color);
    }
    if(tree.find_child(tree.root_id(), "clusters") != 0ULL) {
        ProcessClusters(Clusters, tree);
    }
    if(tree.find_child(tree.root_id(), "users") != 0ULL) {
        ProcessUsers(Users, tree);
    }
    if(tree.find_child(tree.root_id(), "contexts") != 0ULL) {
        ProcessContexts(Contexts, tree);
    }
}

} // namespace kubecpp::client