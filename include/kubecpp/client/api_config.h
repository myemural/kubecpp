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

#ifndef API_CONFIG_H_
#define API_CONFIG_H_

#include <map>
#include <string>
#include <vector>

namespace kubecpp::client
{

struct ApiConfig
{
    struct KubePreferences
    {
        bool Color;
    };

    struct NamedCluster
    {
        struct Cluster
        {
            std::string Server;
            std::string TlsServerName;
            bool InsecureSkipTlsVerify;
            std::string CertificateAuthority;
            std::string CertificateAuthorityData;
            std::string ProxyUrl;
            bool DisableCompression;
        };

        std::string Name;
        Cluster Cluster;
    };

    struct NamedAuthInfo
    {
        struct AuthInfo
        {
            struct AuthProviderConfig
            {
                std::string Name;
                std::map<std::string, std::string> Config;
            };

            struct ExecConfig
            {
                struct ExecEnvVar
                {
                    std::string Name;
                    std::string Value;
                };

                std::string Command;
                std::vector<std::string> Args;
                std::vector<ExecEnvVar> Env;
                std::string ApiVersion;
                std::string InstallHint;
                bool ProvideClusterInfo;
                std::string InteractiveMode;
            };

            std::string ClientCertificate;
            std::string ClientCertificateData;
            std::string ClientKey;
            std::string ClientKeyData;
            std::string Token;
            std::string TokenFile;
            std::string As;
            std::string AsUid;
            std::vector<std::string> AsGroups;
            std::map<std::string, std::string> AsUserExtra;
            std::string Username;
            std::string Password;
            AuthProviderConfig AuthProvider;
            ExecConfig Exec;
        };

        std::string Name;
        AuthInfo User;
    };

    struct NamedContext
    {
        struct Context
        {
            std::string Cluster;
            std::string User;
            std::string Namespace;
        };

        std::string Name;
        Context Context;
    };

    explicit ApiConfig(std::string filePath = "");

    std::string ApiVersion;
    std::string Kind;
    std::string CurrentContext;
    KubePreferences Preferences;
    std::vector<NamedCluster> Clusters;
    std::vector<NamedAuthInfo> Users;
    std::vector<NamedContext> Contexts;
};

} // namespace kubecpp::client

#endif // API_CONFIG_H_