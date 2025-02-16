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

#ifndef POD_AFFINITY_H_
#define POD_AFFINITY_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/label_selector.h"

namespace kubecpp::model::internal::pod
{

struct PodAffinityTermType
{
    Checked<std::string> TopologyKey{ "topologyKey", true, "description" };
    Checked<common::LabelSelector> LabelSelector{ "labelSelector", false, "description" };
    Checked<std::vector<std::string>> MatchLabelKeys{ "matchLabelKeys", false, "description" };
    Checked<std::vector<std::string>> MismatchLabelKeys{ "mismatchLabelKeys", false, "description" };
    Checked<common::LabelSelector> NamespaceSelector{ "namespaceSelector", false, "description" };
    Checked<std::vector<std::string>> Namespaces{ "namespaces", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PodAffinityTermType ParseFromJson(const std::string& jsonData);
};

struct WeightedPodAffinityTerm
{
    Checked<PodAffinityTermType> PodAffinityTerm{ "podAffinityTerm", true, "description" };
    Checked<int32_t> Weight{ "weight", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static WeightedPodAffinityTerm ParseFromJson(const std::string& jsonData);
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
    static PodAffinityType ParseFromJson(const std::string& jsonData);
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
    static PodAntiAffinityType ParseFromJson(const std::string& jsonData);
};

struct PodAffinityTermBuilder
{
    PodAffinityTermBuilder& TopologyKey(const std::string& topologyKey);

    PodAffinityTermBuilder& LabelSelector(const common::LabelSelector& labelSelector);

    PodAffinityTermBuilder& MatchLabelKeys(const std::vector<std::string>& matchLabelKeys);

    PodAffinityTermBuilder& MismatchLabelKeys(const std::vector<std::string>& mismatchLabelKeys);

    PodAffinityTermBuilder& NamespaceSelector(const common::LabelSelector& namespaceSelector);

    PodAffinityTermBuilder& Namespaces(const std::vector<std::string>& namespaces);

    PodAffinityTermType Build();

private:
    PodAffinityTermType podAffinityTerm_;
};

struct WeightedPodAffinityTermBuilder
{
    WeightedPodAffinityTermBuilder& PodAffinityTerm(const PodAffinityTermType& podAffinityTerm);

    WeightedPodAffinityTermBuilder& Weight(int32_t weight);

    WeightedPodAffinityTerm Build();

private:
    WeightedPodAffinityTerm weightedPodAffinityTerm_;
};

struct PodAffinityBuilder
{
    PodAffinityBuilder& PreferredDuringSchedulingIgnoredDuringExecution(
    const std::vector<WeightedPodAffinityTerm>& preferredDuringSchedulingIgnoredDuringExecution);

    PodAffinityBuilder& RequiredDuringSchedulingIgnoredDuringExecution(
    const std::vector<PodAffinityTermType>& requiredDuringSchedulingIgnoredDuringExecution);

    PodAffinityType Build();

private:
    PodAffinityType podAffinity_;
};

struct PodAntiAffinityBuilder
{
    PodAntiAffinityBuilder& PreferredDuringSchedulingIgnoredDuringExecution(
    const std::vector<WeightedPodAffinityTerm>& preferredDuringSchedulingIgnoredDuringExecution);

    PodAntiAffinityBuilder& RequiredDuringSchedulingIgnoredDuringExecution(
    const std::vector<PodAffinityTermType>& requiredDuringSchedulingIgnoredDuringExecution);

    PodAntiAffinityType Build();

private:
    PodAntiAffinityType podAntiAffinity_;
};

} // namespace kubecpp::model::internal::pod

#endif // POD_AFFINITY_H_