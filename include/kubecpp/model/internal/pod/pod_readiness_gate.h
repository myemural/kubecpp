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

#ifndef POD_READINESS_GATE_H_
#define POD_READINESS_GATE_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod
{

struct PodReadinessGate
{
    Checked<std::string> ConditionType{ "conditionType", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PodReadinessGate ParseFromJson(const std::string& jsonData);
};

struct PodReadinessGateBuilder
{
    PodReadinessGateBuilder& ConditionType(const std::string& conditionType);

    PodReadinessGate Build();

private:
    PodReadinessGate podReadinessGate_;
};

} // namespace kubecpp::model::internal::pod

#endif // POD_READINESS_GATE_H_