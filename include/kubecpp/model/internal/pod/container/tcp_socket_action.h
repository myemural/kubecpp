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

#ifndef TCP_SOCKET_ACTION_H_
#define TCP_SOCKET_ACTION_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct TCPSocketAction
{
    Checked<std::string> Port{ "port", true, "description" }; // IntOrString
    Checked<std::string> Host{ "host", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static TCPSocketAction ParseFromJson(const std::string& jsonData);
};

struct TCPSocketActionBuilder
{
    TCPSocketActionBuilder& Port(const std::string& port);

    TCPSocketActionBuilder& Host(const std::string& host);

    TCPSocketAction Build();

private:
    TCPSocketAction tcpSocketAction_;
};

} // namespace kubecpp::model::internal::pod::container

#endif // TCP_SOCKET_ACTION_H_