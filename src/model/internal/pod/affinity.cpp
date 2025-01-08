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

#include "kubecpp/model/internal/pod/affinity.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod
{

std::string NodeSelectorTerm::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, MatchExpressions);
    CHECK_AND_SET_OBJECT_FIELD(result, MatchFields);
    return nlohmann::to_string(result);
}

std::string PreferredSchedulingTerm::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, Preference);
    CHECK_AND_SET_FIELD(result, Weight);
    return nlohmann::to_string(result);
}

std::string NodeSelector::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, NodeSelectorTerms);
    return nlohmann::to_string(result);
}

std::string PodAffinityTermType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, TopologyKey);
    CHECK_AND_SET_OBJECT_FIELD(result, LabelSelector);
    CHECK_AND_SET_FIELD(result, MatchLabelKeys);
    CHECK_AND_SET_FIELD(result, MismatchLabelKeys);
    CHECK_AND_SET_OBJECT_FIELD(result, NamespaceSelector);
    CHECK_AND_SET_FIELD(result, Namespaces);
    return nlohmann::to_string(result);
}

std::string WeightedPodAffinityTerm::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, PodAffinityTerm);
    CHECK_AND_SET_FIELD(result, Weight);
    return nlohmann::to_string(result);
}

std::string NodeAffinityType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, PreferredDuringSchedulingIgnoredDuringExecution);
    CHECK_AND_SET_OBJECT_FIELD(result, RequiredDuringSchedulingIgnoredDuringExecution);
    return nlohmann::to_string(result);
}

std::string PodAffinityType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, PreferredDuringSchedulingIgnoredDuringExecution);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, RequiredDuringSchedulingIgnoredDuringExecution);
    return nlohmann::to_string(result);
}

std::string PodAntiAffinityType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, PreferredDuringSchedulingIgnoredDuringExecution);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, RequiredDuringSchedulingIgnoredDuringExecution);
    return nlohmann::to_string(result);
}

std::string AffinityType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, NodeAffinity);
    CHECK_AND_SET_OBJECT_FIELD(result, PodAffinity);
    CHECK_AND_SET_OBJECT_FIELD(result, PodAntiAffinity);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod