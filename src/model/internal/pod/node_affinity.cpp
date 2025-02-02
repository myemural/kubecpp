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

#include "kubecpp/model/internal/pod/node_affinity.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string NodeSelectorTerm::ParseToJson() const
{
    return ParseFieldsToJson(MatchExpressions, MatchFields);
}

NodeSelectorTerm NodeSelectorTerm::ParseFromJson(const std::string& jsonData)
{
    NodeSelectorTerm result;
    ParseFieldsFromJson(jsonData, result.MatchExpressions, result.MatchFields);
    return result;
}

std::string PreferredSchedulingTerm::ParseToJson() const
{
    return ParseFieldsToJson(Preference, Weight);
}

PreferredSchedulingTerm PreferredSchedulingTerm::ParseFromJson(const std::string& jsonData)
{
    PreferredSchedulingTerm result;
    ParseFieldsFromJson(jsonData, result.Preference, result.Weight);
    return result;
}

std::string NodeSelector::ParseToJson() const
{
    return ParseFieldsToJson(NodeSelectorTerms);
}

NodeSelector NodeSelector::ParseFromJson(const std::string& jsonData)
{
    NodeSelector result;
    ParseFieldsFromJson(jsonData, result.NodeSelectorTerms);
    return result;
}

std::string NodeAffinityType::ParseToJson() const
{
    return ParseFieldsToJson(PreferredDuringSchedulingIgnoredDuringExecution, RequiredDuringSchedulingIgnoredDuringExecution);
}

NodeAffinityType NodeAffinityType::ParseFromJson(const std::string& jsonData)
{
    NodeAffinityType result;
    ParseFieldsFromJson(jsonData, result.PreferredDuringSchedulingIgnoredDuringExecution,
    result.RequiredDuringSchedulingIgnoredDuringExecution);
    return result;
}

} // namespace kubecpp::model::internal::pod