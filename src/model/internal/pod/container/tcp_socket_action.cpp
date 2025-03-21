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

#include "kubecpp/model/internal/pod/container/tcp_socket_action.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string TCPSocketAction::ParseToJson() const
{
    return ParseFieldsToJson(Port, Host);
}

TCPSocketAction TCPSocketAction::ParseFromJson(const std::string& jsonData)
{
    TCPSocketAction result;
    ParseFieldsFromJson(jsonData, result.Port, result.Host);
    return result;
}

TCPSocketActionBuilder& TCPSocketActionBuilder::Port(const std::string& port)
{
    tcpSocketAction_.Port = port;
    return *this;
}

TCPSocketActionBuilder& TCPSocketActionBuilder::Host(const std::string& host)
{
    tcpSocketAction_.Host = host;
    return *this;
}

TCPSocketAction TCPSocketActionBuilder::Build()
{
    return std::move(tcpSocketAction_);
}

} // namespace kubecpp::model::internal::pod::container