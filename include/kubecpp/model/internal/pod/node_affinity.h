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

#ifndef NODE_AFFINITY_H_
#define NODE_AFFINITY_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/node_selector_requirement.h"

namespace kubecpp::model::internal::pod
{

struct NodeSelectorTerm
{
    Checked<common::NodeSelectorRequirement> MatchExpressions{ "matchExpressions", false, "description" };
    Checked<common::NodeSelectorRequirement> MatchFields{ "matchFields", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static NodeSelectorTerm ParseFromJson(const std::string& jsonData);
};

struct PreferredSchedulingTerm
{
    Checked<NodeSelectorTerm> Preference{ "preference", true, "description" };
    Checked<int32_t> Weight{ "weight", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PreferredSchedulingTerm ParseFromJson(const std::string& jsonData);
};

struct NodeSelector
{
    Checked<std::vector<NodeSelectorTerm>> NodeSelectorTerms{ "nodeSelectorTerms", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static NodeSelector ParseFromJson(const std::string& jsonData);
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
    static NodeAffinityType ParseFromJson(const std::string& jsonData);
};

struct NodeSelectorTermBuilder
{
    NodeSelectorTermBuilder& MatchExpressions(const common::NodeSelectorRequirement& matchExpressions);

    NodeSelectorTermBuilder& MatchFields(const common::NodeSelectorRequirement& matchFields);

    NodeSelectorTerm Build();

private:
    NodeSelectorTerm nodeSelectorTerm_;
};

struct PreferredSchedulingTermBuilder
{
    PreferredSchedulingTermBuilder& Preference(const NodeSelectorTerm& preference);

    PreferredSchedulingTermBuilder& Weight(int32_t weight);

    PreferredSchedulingTerm Build();

private:
    PreferredSchedulingTerm preferredSchedulingTerm_;
};

struct NodeSelectorBuilder
{
    NodeSelectorBuilder& NodeSelectorTerms(const std::vector<NodeSelectorTerm>& nodeSelectorTerms);

    NodeSelector Build();

private:
    NodeSelector nodeSelector_;
};

struct NodeAffinityBuilder
{
    NodeAffinityBuilder& PreferredDuringSchedulingIgnoredDuringExecution(
    const std::vector<PreferredSchedulingTerm>& preferredDuringSchedulingIgnoredDuringExecution);

    NodeAffinityBuilder& RequiredDuringSchedulingIgnoredDuringExecution(
    const NodeSelector& requiredDuringSchedulingIgnoredDuringExecution);

    NodeAffinityType Build();

private:
    NodeAffinityType nodeAffinity_;
};

} // namespace kubecpp::model::internal::pod

#endif // NODE_AFFINITY_H_