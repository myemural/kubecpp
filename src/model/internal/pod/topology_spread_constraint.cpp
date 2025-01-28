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

#include "kubecpp/model/internal/pod/topology_spread_constraint.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string TopologySpreadConstraint::ParseToJson() const
{
    return ParseFieldsToJson(MaxSkew, TopologyKey, WhenUnsatisfiable, LabelSelector, MatchLabelKeys, MinDomains,
    NodeAffinityPolicy, NodeTaintsPolicy);
}

TopologySpreadConstraint TopologySpreadConstraint::ParseFromJson(const std::string& jsonData)
{
    TopologySpreadConstraint result;
    ParseFieldsFromJson(jsonData, result.MaxSkew, result.TopologyKey, result.WhenUnsatisfiable, result.LabelSelector,
    result.MatchLabelKeys, result.MinDomains, result.NodeAffinityPolicy, result.NodeTaintsPolicy);
    return result;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::MaxSkew(int32_t maxSkew)
{
    topologySpreadConstraint_.MaxSkew = maxSkew;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::TopologyKey(const std::string& topologyKey)
{
    topologySpreadConstraint_.TopologyKey = topologyKey;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::WhenUnsatisfiable(const std::string& whenUnsatisfiable)
{
    topologySpreadConstraint_.WhenUnsatisfiable = whenUnsatisfiable;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::LabelSelector(const common::LabelSelector& labelSelector)
{
    topologySpreadConstraint_.LabelSelector = labelSelector;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::MatchLabelKeys(const std::vector<std::string>& matchLabelKeys)
{
    topologySpreadConstraint_.MatchLabelKeys = matchLabelKeys;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::MinDomains(int32_t minDomains)
{
    topologySpreadConstraint_.MinDomains = minDomains;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::NodeAffinityPolicy(const std::string& nodeAffinityPolicy)
{
    topologySpreadConstraint_.NodeAffinityPolicy = nodeAffinityPolicy;
    return *this;
}

TopologySpreadConstraintBuilder& TopologySpreadConstraintBuilder::NodeTaintsPolicy(const std::string& nodeTaintsPolicy)
{
    topologySpreadConstraint_.NodeTaintsPolicy = nodeTaintsPolicy;
    return *this;
}

TopologySpreadConstraint TopologySpreadConstraintBuilder::Build()
{
    return std::move(topologySpreadConstraint_);
}

} // namespace kubecpp::model::internal::pod