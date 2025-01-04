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

#include "kubecpp/model/internal/common/label_selector.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::common
{

std::string LabelSelectorRequirement::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Key);
    CHECK_AND_SET_FIELD(result, Operator);
    CHECK_AND_SET_FIELD_CONTAINER(result, Values);
    return nlohmann::to_string(result);
}

std::string LabelSelector::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, MatchExpressions);
    CHECK_AND_SET_FIELD_CONTAINER(result, MatchLabels);
    return nlohmann::to_string(result);
}

LabelSelectorRequirementBuilder& LabelSelectorRequirementBuilder::Key(const std::string& key)
{
    labelSelectorRequirement_.Key = key;
    return *this;
}

LabelSelectorRequirementBuilder& LabelSelectorRequirementBuilder::Operator(const std::string& oprtr)
{
    labelSelectorRequirement_.Operator = oprtr;
    return *this;
}

LabelSelectorRequirementBuilder& LabelSelectorRequirementBuilder::Values(const std::vector<std::string>& values)
{
    labelSelectorRequirement_.Values = values;
    return *this;
}

LabelSelectorRequirement LabelSelectorRequirementBuilder::Build()
{
    return std::move(labelSelectorRequirement_);
}

LabelSelectorBuilder& LabelSelectorBuilder::MatchExpressions(const std::vector<LabelSelectorRequirement>& matchExpressions)
{
    labelSelector_.MatchExpressions = matchExpressions;
    return *this;
}

LabelSelectorBuilder& LabelSelectorBuilder::MatchLabels(const std::map<std::string, std::string>& matchLabels)
{
    labelSelector_.MatchLabels = matchLabels;
    return *this;
}

LabelSelector LabelSelectorBuilder::Build()
{
    return std::move(labelSelector_);
}

} // namespace kubecpp::model::internal::common
