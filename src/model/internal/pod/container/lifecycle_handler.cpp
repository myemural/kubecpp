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

#include "kubecpp/model/internal/pod/container/lifecycle_handler.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string LifecycleHandler::ParseToJson() const
{
    return ParseFieldsToJson(Exec, HttpGet, Sleep, TcpSocket);
}

LifecycleHandler LifecycleHandler::ParseFromJson(const std::string& jsonData)
{
    LifecycleHandler result;
    ParseFieldsFromJson(jsonData, result.Exec, result.HttpGet, result.Sleep, result.TcpSocket);
    return result;
}

LifecycleHandlerBuilder& LifecycleHandlerBuilder::Exec(const ExecAction& exec)
{
    lifecycleHandler_.Exec = exec;
    return *this;
}

LifecycleHandlerBuilder& LifecycleHandlerBuilder::HttpGet(const HTTPGetAction& httpGet)
{
    lifecycleHandler_.HttpGet = httpGet;
    return *this;
}

LifecycleHandlerBuilder& LifecycleHandlerBuilder::Sleep(const SleepAction& sleep)
{
    lifecycleHandler_.Sleep = sleep;
    return *this;
}

LifecycleHandlerBuilder& LifecycleHandlerBuilder::TcpSocket(const TCPSocketAction& tcpSocket)
{
    lifecycleHandler_.TcpSocket = tcpSocket;
    return *this;
}

LifecycleHandler LifecycleHandlerBuilder::Build()
{
    return std::move(lifecycleHandler_);
}

} // namespace kubecpp::model::internal::pod::container