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

#include "kubecpp/model/internal/pod/pod_affinity.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string PodAffinityTermType::ParseToJson() const
{
    return ParseFieldsToJson(TopologyKey, LabelSelector, MatchLabelKeys, MismatchLabelKeys, NamespaceSelector, Namespaces);
}

PodAffinityTermType PodAffinityTermType::ParseFromJson(const std::string& jsonData)
{
    PodAffinityTermType result;
    ParseFieldsFromJson(jsonData, result.TopologyKey, result.LabelSelector, result.MatchLabelKeys,
    result.MismatchLabelKeys, result.NamespaceSelector, result.Namespaces);
    return result;
}

std::string WeightedPodAffinityTerm::ParseToJson() const
{
    return ParseFieldsToJson(PodAffinityTerm, Weight);
}

WeightedPodAffinityTerm WeightedPodAffinityTerm::ParseFromJson(const std::string& jsonData)
{
    WeightedPodAffinityTerm result;
    ParseFieldsFromJson(jsonData, result.PodAffinityTerm, result.Weight);
    return result;
}

std::string PodAffinityType::ParseToJson() const
{
    return ParseFieldsToJson(PreferredDuringSchedulingIgnoredDuringExecution, RequiredDuringSchedulingIgnoredDuringExecution);
}

PodAffinityType PodAffinityType::ParseFromJson(const std::string& jsonData)
{
    PodAffinityType result;
    ParseFieldsFromJson(jsonData, result.PreferredDuringSchedulingIgnoredDuringExecution,
    result.RequiredDuringSchedulingIgnoredDuringExecution);
    return result;
}

std::string PodAntiAffinityType::ParseToJson() const
{
    return ParseFieldsToJson(PreferredDuringSchedulingIgnoredDuringExecution, RequiredDuringSchedulingIgnoredDuringExecution);
}

PodAntiAffinityType PodAntiAffinityType::ParseFromJson(const std::string& jsonData)
{
    PodAntiAffinityType result;
    ParseFieldsFromJson(jsonData, result.PreferredDuringSchedulingIgnoredDuringExecution,
    result.RequiredDuringSchedulingIgnoredDuringExecution);
    return result;
}

} // namespace kubecpp::model::internal::pod