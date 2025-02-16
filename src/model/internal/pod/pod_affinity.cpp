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

PodAffinityTermBuilder& PodAffinityTermBuilder::TopologyKey(const std::string& topologyKey)
{
    podAffinityTerm_.TopologyKey = topologyKey;
    return *this;
}

PodAffinityTermBuilder& PodAffinityTermBuilder::LabelSelector(const common::LabelSelector& labelSelector)
{
    podAffinityTerm_.LabelSelector = labelSelector;
    return *this;
}

PodAffinityTermBuilder& PodAffinityTermBuilder::MatchLabelKeys(const std::vector<std::string>& matchLabelKeys)
{
    podAffinityTerm_.MatchLabelKeys = matchLabelKeys;
    return *this;
}

PodAffinityTermBuilder& PodAffinityTermBuilder::MismatchLabelKeys(const std::vector<std::string>& mismatchLabelKeys)
{
    podAffinityTerm_.MismatchLabelKeys = mismatchLabelKeys;
    return *this;
}

PodAffinityTermBuilder& PodAffinityTermBuilder::NamespaceSelector(const common::LabelSelector& namespaceSelector)
{
    podAffinityTerm_.NamespaceSelector = namespaceSelector;
    return *this;
}

PodAffinityTermBuilder& PodAffinityTermBuilder::Namespaces(const std::vector<std::string>& namespaces)
{
    podAffinityTerm_.Namespaces = namespaces;
    return *this;
}

PodAffinityTermType PodAffinityTermBuilder::Build()
{
    return std::move(podAffinityTerm_);
}

WeightedPodAffinityTermBuilder& WeightedPodAffinityTermBuilder::PodAffinityTerm(const PodAffinityTermType& podAffinityTerm)
{
    weightedPodAffinityTerm_.PodAffinityTerm = podAffinityTerm;
    return *this;
}

WeightedPodAffinityTermBuilder& WeightedPodAffinityTermBuilder::Weight(int32_t weight)
{
    weightedPodAffinityTerm_.Weight = weight;
    return *this;
}

WeightedPodAffinityTerm WeightedPodAffinityTermBuilder::Build()
{
    return std::move(weightedPodAffinityTerm_);
}

PodAffinityBuilder& PodAffinityBuilder::PreferredDuringSchedulingIgnoredDuringExecution(
const std::vector<WeightedPodAffinityTerm>& preferredDuringSchedulingIgnoredDuringExecution)
{
    podAffinity_.PreferredDuringSchedulingIgnoredDuringExecution = preferredDuringSchedulingIgnoredDuringExecution;
    return *this;
}

PodAffinityBuilder& PodAffinityBuilder::RequiredDuringSchedulingIgnoredDuringExecution(
const std::vector<PodAffinityTermType>& requiredDuringSchedulingIgnoredDuringExecution)
{
    podAffinity_.RequiredDuringSchedulingIgnoredDuringExecution = requiredDuringSchedulingIgnoredDuringExecution;
    return *this;
}

PodAffinityType PodAffinityBuilder::Build()
{
    return std::move(podAffinity_);
}

PodAntiAffinityBuilder& PodAntiAffinityBuilder::PreferredDuringSchedulingIgnoredDuringExecution(
const std::vector<WeightedPodAffinityTerm>& preferredDuringSchedulingIgnoredDuringExecution)
{
    podAntiAffinity_.PreferredDuringSchedulingIgnoredDuringExecution = preferredDuringSchedulingIgnoredDuringExecution;
    return *this;
}

PodAntiAffinityBuilder& PodAntiAffinityBuilder::RequiredDuringSchedulingIgnoredDuringExecution(
const std::vector<PodAffinityTermType>& requiredDuringSchedulingIgnoredDuringExecution)
{
    podAntiAffinity_.RequiredDuringSchedulingIgnoredDuringExecution = requiredDuringSchedulingIgnoredDuringExecution;
    return *this;
}

PodAntiAffinityType PodAntiAffinityBuilder::Build()
{
    return std::move(podAntiAffinity_);
}

} // namespace kubecpp::model::internal::pod