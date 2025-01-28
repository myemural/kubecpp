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

#include "kubecpp/model/internal/pod/host_alias.h"

#include "kubecpp/common/json_utils.h",

namespace kubecpp::model::internal::pod
{

std::string HostAlias::ParseToJson() const
{
    return ParseFieldsToJson(Ip, HostNames);
}

HostAlias HostAlias::ParseFromJson(const std::string& jsonData)
{
    HostAlias result;
    ParseFieldsFromJson(jsonData, result.Ip, result.HostNames);
    return result;
}

HostAliasBuilder& HostAliasBuilder::Ip(const std::string& ip)
{
    hostAlias_.Ip = ip;
    return *this;
}

HostAliasBuilder& HostAliasBuilder::HostNames(const std::vector<std::string>& hostNames)
{
    hostAlias_.HostNames = hostNames;
    return *this;
}

HostAlias HostAliasBuilder::Build()
{
    return std::move(hostAlias_);
}


} // namespace kubecpp::model::internal::pod