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

#ifndef GRPC_ACTION_H_
#define GRPC_ACTION_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct GRPCAction
{
    Checked<int32_t> Port{ "port", true, "description" };
    Checked<std::string> Service{ "service", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static GRPCAction ParseFromJson(const std::string& jsonData);
};

struct GRPCActionBuilder
{
    GRPCActionBuilder& Port(int32_t port);

    GRPCActionBuilder& Service(const std::string& service);

    GRPCAction Build();

private:
    GRPCAction grpcAction_;
};

} // namespace kubecpp::model::internal::pod::container

#endif // GRPC_ACTION_H_