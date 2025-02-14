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

#include "kubecpp/model/internal/pod/container/grpc_action.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string GRPCAction::ParseToJson() const
{
    return ParseFieldsToJson(Port, Service);
}

GRPCAction GRPCAction::ParseFromJson(const std::string& jsonData)
{
    GRPCAction result;
    ParseFieldsFromJson(jsonData, result.Port, result.Service);
    return result;
}

GRPCActionBuilder& GRPCActionBuilder::Port(int32_t port)
{
    grpcAction_.Port = port;
    return *this;
}

GRPCActionBuilder& GRPCActionBuilder::Service(const std::string& service)
{
    grpcAction_.Service = service;
    return *this;
}

GRPCAction GRPCActionBuilder::Build()
{
    return std::move(grpcAction_);
}

} // namespace kubecpp::model::internal::pod::container