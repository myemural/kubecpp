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

#include "kubecpp/model/internal/common/node_selector_requirement.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string NodeSelectorRequirement::ParseToJson() const
{
    return ParseFieldsToJson(Key, Operator, Values);
}

NodeSelectorRequirement NodeSelectorRequirement::ParseFromJson(const std::string& jsonData)
{
    NodeSelectorRequirement result;
    ParseFieldsFromJson(jsonData, result.Key, result.Operator, result.Values);
    return result;
}

NodeSelectorRequirementBuilder& NodeSelectorRequirementBuilder::Key(const std::string& key)
{
    nodeSelectorRequirement_.Key = key;
    return *this;
}

NodeSelectorRequirementBuilder& NodeSelectorRequirementBuilder::Operator(const std::string& oprtr)
{
    nodeSelectorRequirement_.Operator = oprtr;
    return *this;
}

NodeSelectorRequirementBuilder& NodeSelectorRequirementBuilder::Values(const std::vector<std::string>& values)
{
    nodeSelectorRequirement_.Values = values;
    return *this;
}

NodeSelectorRequirement NodeSelectorRequirementBuilder::Build()
{
    return std::move(nodeSelectorRequirement_);
}

} // namespace kubecpp::model::internal::common