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

#include "kubecpp/model/internal/pod/pod_readiness_gate.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod
{

std::string PodReadinessGate::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, ConditionType);
    return nlohmann::to_string(result);
}

PodReadinessGateBuilder& PodReadinessGateBuilder::ConditionType(const std::string& conditionType)
{
    podReadinessGate_.ConditionType = conditionType;
    return *this;
}

PodReadinessGate PodReadinessGateBuilder::Build()
{
    return std::move(podReadinessGate_);
}

} // namespace kubecpp::model::internal::pod