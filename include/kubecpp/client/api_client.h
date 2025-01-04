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

#ifndef API_CLIENT_H_
#define API_CLIENT_H_

#include <string>

#include "kubecpp/client/api_config.h"

namespace kubecpp::client
{

enum class HttpMethod : uint8_t { kDelete, kGet, kPatch, kPost, kPut };

class ApiClient
{
public:
    struct ApiResponse
    {
        struct Error
        {
            long ErrorCode{ 0L };
            std::string ErrorMessage;
        };

        long StatusCode{ 0L };
        std::string Body;
        std::string Reason;
        Error ErrorInfo = Error{};
    };

    struct SslConfig
    {
        std::string CaCertFile;
        std::string ClientCertFile;
        std::string ClientKeyFile;
        bool InsecureSkipTlsVerify{ true };
    };

    explicit ApiClient(const ApiConfig& config);
    ~ApiClient();

    [[nodiscard]] ApiResponse Execute(const HttpMethod& method, const std::string& path, const std::string& body = "") const;

private:
    std::string basePath_;
    SslConfig sslConfig_;
};

} // namespace kubecpp::client

#endif // API_CLIENT_H_