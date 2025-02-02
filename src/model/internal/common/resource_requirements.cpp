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

#include "kubecpp/model/internal/common/resource_requirements.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string ResourceClaim::ParseToJson() const
{
    return ParseFieldsToJson(Name, Request);
}

ResourceClaim ResourceClaim::ParseFromJson(const std::string& jsonData)
{
    ResourceClaim result;
    ParseFieldsFromJson(jsonData, result.Name, result.Request);
    return result;
}

std::string ResourceRequirements::ParseToJson() const
{
    return ParseFieldsToJson(Claims, Limits, Requests);
}

ResourceRequirements ResourceRequirements::ParseFromJson(const std::string& jsonData)
{
    ResourceRequirements result;
    ParseFieldsFromJson(jsonData, result.Claims, result.Limits, result.Requests);
    return result;
}

} // namespace kubecpp::model::internal::common