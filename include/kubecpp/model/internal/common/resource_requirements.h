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

#ifndef RESOURCE_REQUIREMENTS_H_
#define RESOURCE_REQUIREMENTS_H_

#include <unordered_map>
#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct ResourceClaim
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Request{ "request", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ResourceClaim ParseFromJson(const std::string& jsonData);
};

struct ResourceRequirements
{
    Checked<std::vector<ResourceClaim>> Claims{ "claims", false, "description" };
    Checked<std::unordered_map<std::string, std::string>> Limits{ "limits", false, "description" };     // Quantity
    Checked<std::unordered_map<std::string, std::string>> Requests{ "requests", false, "description" }; // Quantity

    [[nodiscard]] std::string ParseToJson() const;
    static ResourceRequirements ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::common

#endif // RESOURCE_REQUIREMENTS_H_