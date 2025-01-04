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

#include "kubecpp/model/pod.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::core::v1
{

[[nodiscard]] std::string Pod::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, ApiVersion);
    CHECK_AND_SET_FIELD(result, Kind);
    CHECK_AND_SET_OBJECT_FIELD(result, Metadata);
    CHECK_AND_SET_OBJECT_FIELD(result, Spec);
    return nlohmann::to_string(result);
}

Pod Pod::ParseFromJson(const std::string& jsonData)
{
    Pod result;
    nlohmann::json data = nlohmann::json::parse(jsonData);
    result.ApiVersion   = data[result.ApiVersion.GetKeyName()].template get<std::string>();
    result.Kind         = data[result.Kind.GetKeyName()].template get<std::string>();
    // internal::ObjectMeta metadata;
    // result.Metadata = metadata.ParseFromJson(nlohmann::to_string(data[result.Metadata.GetKeyName()]));
    // PodSpec spec;
    // result.Spec = spec.ParseFromJson(nlohmann::to_string(data[result.Spec.GetKeyName()]));

    return result;
}

std::string PodList::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, Items);
    CHECK_AND_SET_FIELD(result, ApiVersion);
    CHECK_AND_SET_FIELD(result, Kind);
    CHECK_AND_SET_OBJECT_FIELD(result, Metadata);
    return nlohmann::to_string(result);
}

PodList PodList::ParseFromJson(const std::string& jsonData)
{
    PodList result;
    nlohmann::json data = nlohmann::json::parse(jsonData);

    return result;
}

PodBuilder& PodBuilder::ApiVersion(const std::string& apiVersion)
{
    pod_.ApiVersion = apiVersion;
    return *this;
}

PodBuilder& PodBuilder::Kind(const std::string& kind)
{
    pod_.Kind = kind;
    return *this;
}

PodBuilder& PodBuilder::Metadata(const internal::common::ObjectMeta& objectMeta)
{
    pod_.Metadata = objectMeta;
    return *this;
}

PodBuilder& PodBuilder::Spec(const internal::pod::PodSpec& podSpec)
{
    pod_.Spec = podSpec;
    return *this;
}

Pod PodBuilder::Build()
{
    return std::move(pod_);
}

} // namespace kubecpp::model::core::v1