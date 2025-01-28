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

#include "kubecpp/model/internal/pod/pod_dns_config.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string PodDNSConfigOption::ParseToJson() const
{
    return ParseFieldsToJson(Name, Value);
}

PodDNSConfigOption PodDNSConfigOption::ParseFromJson(const std::string& jsonData)
{
    PodDNSConfigOption result;
    ParseFieldsFromJson(jsonData, result.Name, result.Value);
    return result;
}

std::string PodDNSConfig::ParseToJson() const
{
    return ParseFieldsToJson(Nameservers, Options, Searches);
}

PodDNSConfig PodDNSConfig::ParseFromJson(const std::string& jsonData)
{
    PodDNSConfig result;
    ParseFieldsFromJson(jsonData, result.Nameservers, result.Options, result.Searches);
    return result;
}

PodDNSConfigOptionBuilder& PodDNSConfigOptionBuilder::Name(const std::string& name)
{
    podDNSConfigOption_.Name = name;
    return *this;
}

PodDNSConfigOptionBuilder& PodDNSConfigOptionBuilder::Value(const std::string& value)
{
    podDNSConfigOption_.Value = value;
    return *this;
}

PodDNSConfigOption PodDNSConfigOptionBuilder::Build()
{
    return std::move(podDNSConfigOption_);
}

PodDNSConfigBuilder& PodDNSConfigBuilder::Nameservers(const std::vector<std::string>& nameservers)
{
    podDNSConfig_.Nameservers = nameservers;
    return *this;
}

PodDNSConfigBuilder& PodDNSConfigBuilder::Options(const std::vector<PodDNSConfigOption>& options)
{
    podDNSConfig_.Options = options;
    return *this;
}

PodDNSConfigBuilder& PodDNSConfigBuilder::Searches(const std::vector<std::string>& searches)
{
    podDNSConfig_.Searches = searches;
    return *this;
}

PodDNSConfig PodDNSConfigBuilder::Build()
{
    return std::move(podDNSConfig_);
}

} // namespace kubecpp::model::internal::pod