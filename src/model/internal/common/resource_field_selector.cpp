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

#include "kubecpp/model/internal/common/resource_field_selector.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string ResourceFieldSelector::ParseToJson() const
{
    return ParseFieldsToJson(Resource, ContainerName, Divisor);
}

ResourceFieldSelector ResourceFieldSelector::ParseFromJson(const std::string& jsonData)
{
    ResourceFieldSelector result;
    ParseFieldsFromJson(jsonData, result.Resource, result.ContainerName, result.Divisor);
    return result;
}

ResourceFieldSelectorBuilder& ResourceFieldSelectorBuilder::Resource(const std::string& resource)
{
    resourceFieldSelector_.Resource = resource;
    return *this;
}

ResourceFieldSelectorBuilder& ResourceFieldSelectorBuilder::ContainerName(const std::string& containerName)
{
    resourceFieldSelector_.ContainerName = containerName;
    return *this;
}

ResourceFieldSelectorBuilder& ResourceFieldSelectorBuilder::Divisor(const std::string& divisor)
{
    resourceFieldSelector_.Divisor = divisor;
    return *this;
}

ResourceFieldSelector ResourceFieldSelectorBuilder::Build()
{
    return std::move(resourceFieldSelector_);
}

} // namespace kubecpp::model::internal::common
