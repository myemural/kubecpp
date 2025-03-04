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

#ifndef NODE_SELECTOR_REQUIREMENT_H_
#define NODE_SELECTOR_REQUIREMENT_H_

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct NodeSelectorRequirement
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Operator{ "operator", true, "description" };
    Checked<std::vector<std::string>> Values{ "values", false, "description" }; // std::string -> Quantity

    [[nodiscard]] std::string ParseToJson() const;
    static NodeSelectorRequirement ParseFromJson(const std::string& jsonData);
};

struct NodeSelectorRequirementBuilder
{
    NodeSelectorRequirementBuilder& Key(const std::string& key);

    NodeSelectorRequirementBuilder& Operator(const std::string& oprtr);

    NodeSelectorRequirementBuilder& Values(const std::vector<std::string>& values);

    NodeSelectorRequirement Build();

private:
    NodeSelectorRequirement nodeSelectorRequirement_;
};

} // namespace kubecpp::model::internal::common

#endif // NODE_SELECTOR_REQUIREMENT_H_