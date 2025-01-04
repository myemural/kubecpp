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

#ifndef AFFINITY_H_
#define AFFINITY_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/label_selector.h"
#include "kubecpp/model/internal/common/node_selector_requirement.h"

namespace kubecpp::model::internal::pod
{

struct NodeSelectorTerm
{
    Checked<common::NodeSelectorRequirement> MatchExpressions{ "matchExpressions", false, "description" };
    Checked<common::NodeSelectorRequirement> MatchFields{ "matchFields", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PreferredSchedulingTerm
{
    Checked<NodeSelectorTerm> Preference{ "preference", true, "description" };
    Checked<int32_t> Weight{ "weight", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct NodeSelector
{
    Checked<std::vector<NodeSelectorTerm>> NodeSelectorTerms{ "nodeSelectorTerms", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PodAffinityTermType
{
    Checked<std::string> TopologyKey{ "topologyKey", true, "description" };
    Checked<common::LabelSelector> LabelSelector{ "labelSelector", false, "description" };
    Checked<std::vector<std::string>> MatchLabelKeys{ "matchLabelKeys", false, "description" };
    Checked<std::vector<std::string>> MismatchLabelKeys{ "mismatchLabelKeys", false, "description" };
    Checked<common::LabelSelector> NamespaceSelector{ "namespaceSelector", false, "description" };
    Checked<std::vector<std::string>> Namespaces{ "namespaces", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct WeightedPodAffinityTerm
{
    Checked<PodAffinityTermType> PodAffinityTerm{ "podAffinityTerm", true, "description" };
    Checked<int32_t> Weight{ "weight", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct NodeAffinityType
{
    Checked<std::vector<PreferredSchedulingTerm>> PreferredDuringSchedulingIgnoredDuringExecution{
        "preferredDuringSchedulingIgnoredDuringExecution", false, "description"
    };
    Checked<NodeSelector> RequiredDuringSchedulingIgnoredDuringExecution{
        "requiredDuringSchedulingIgnoredDuringExecution", false, "description"
    };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PodAffinityType
{
    Checked<std::vector<WeightedPodAffinityTerm>> PreferredDuringSchedulingIgnoredDuringExecution{
        "preferredDuringSchedulingIgnoredDuringExecution", false, "description"
    };
    Checked<std::vector<PodAffinityTermType>> RequiredDuringSchedulingIgnoredDuringExecution{
        "requiredDuringSchedulingIgnoredDuringExecution", false, "description"
    };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PodAntiAffinityType
{
    Checked<std::vector<WeightedPodAffinityTerm>> PreferredDuringSchedulingIgnoredDuringExecution{
        "preferredDuringSchedulingIgnoredDuringExecution", false, "description"
    };
    Checked<std::vector<PodAffinityTermType>> RequiredDuringSchedulingIgnoredDuringExecution{
        "requiredDuringSchedulingIgnoredDuringExecution", false, "description"
    };

    [[nodiscard]] std::string ParseToJson() const;
};

struct AffinityType
{
    Checked<NodeAffinityType> NodeAffinity{ "nodeAffinity", false, "description" };
    Checked<PodAffinityType> PodAffinity{ "podAffinity", false, "description" };
    Checked<PodAntiAffinityType> PodAntiAffinity{ "podAntiAffinity", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod

#endif // AFFINITY_H_