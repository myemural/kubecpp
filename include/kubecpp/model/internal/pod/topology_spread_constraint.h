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

#ifndef TOPOLOGY_SPREAD_CONSTRAINT_H_
#define TOPOLOGY_SPREAD_CONSTRAINT_H_

#include <vector>

#include "kubecpp/common/checked.h"

#include "kubecpp/model/internal/common/label_selector.h"

namespace kubecpp::model::internal::pod
{

struct TopologySpreadConstraint
{
    Checked<int32_t> MaxSkew{ "maxSkew", true, "description" };
    Checked<std::string> TopologyKey{ "topologyKey", true, "description" };
    Checked<std::string> WhenUnsatisfiable{ "whenUnsatisfiable", true, "description" };
    Checked<common::LabelSelector> LabelSelector{ "labelSelector", false, "description" };
    Checked<std::vector<std::string>> MatchLabelKeys{ "matchLabelKeys", false, "description" };
    Checked<int32_t> MinDomains{ "minDomains", false, "description" };
    Checked<std::string> NodeAffinityPolicy{ "nodeAffinityPolicy", false, "description" };
    Checked<std::string> NodeTaintsPolicy{ "nodeTaintsPolicy", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static TopologySpreadConstraint ParseFromJson(const std::string& jsonData);
};

struct TopologySpreadConstraintBuilder
{
    TopologySpreadConstraintBuilder& MaxSkew(int32_t maxSkew);

    TopologySpreadConstraintBuilder& TopologyKey(const std::string& topologyKey);

    TopologySpreadConstraintBuilder& WhenUnsatisfiable(const std::string& whenUnsatisfiable);

    TopologySpreadConstraintBuilder& LabelSelector(const common::LabelSelector& labelSelector);

    TopologySpreadConstraintBuilder& MatchLabelKeys(const std::vector<std::string>& matchLabelKeys);

    TopologySpreadConstraintBuilder& MinDomains(int32_t minDomains);

    TopologySpreadConstraintBuilder& NodeAffinityPolicy(const std::string& nodeAffinityPolicy);

    TopologySpreadConstraintBuilder& NodeTaintsPolicy(const std::string& nodeTaintsPolicy);

    TopologySpreadConstraint Build();

private:
    TopologySpreadConstraint topologySpreadConstraint_;
};

} // namespace kubecpp::model::internal::pod

#endif // TOPOLOGY_SPREAD_CONSTRAINT_H_