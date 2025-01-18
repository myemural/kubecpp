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

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::core::v1
{

[[nodiscard]] std::string Pod::ParseToJson() const
{
    return ParseFieldsToJson(ApiVersion, Kind, Metadata, Spec);
}

Pod Pod::ParseFromJson(const std::string& jsonData)
{
    Pod result;
    ParseFieldsFromJson(jsonData, result.ApiVersion, result.Kind, result.Metadata, result.Spec, result.Status);
    return result;
}

std::string PodList::ParseToJson() const
{
    return ParseFieldsToJson(Items, ApiVersion, Kind, Metadata);
}

PodList PodList::ParseFromJson(const std::string& jsonData)
{
    PodList result;
    ParseFieldsFromJson(jsonData, result.Items, result.ApiVersion, result.Kind, result.Metadata);
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