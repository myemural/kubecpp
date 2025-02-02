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

#ifndef RESOURCE_FIELD_SELECTOR_H_
#define RESOURCE_FIELD_SELECTOR_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct ResourceFieldSelector
{
    Checked<std::string> Resource{ "resource", true, "description" };
    Checked<std::string> ContainerName{ "containerName", false, "description" };
    Checked<std::string> Divisor{ "divisor", false, "description" }; // std::string -> Quantity

    [[nodiscard]] std::string ParseToJson() const;
    static ResourceFieldSelector ParseFromJson(const std::string& jsonData);
};

struct ResourceFieldSelectorBuilder
{
    ResourceFieldSelectorBuilder& Resource(const std::string& resource);

    ResourceFieldSelectorBuilder& ContainerName(const std::string& containerName);

    ResourceFieldSelectorBuilder& Divisor(const std::string& divisor);

    ResourceFieldSelector Build();

private:
    ResourceFieldSelector resourceFieldSelector_;
};

} // namespace kubecpp::model::internal::common

#endif // RESOURCE_FIELD_SELECTOR_H_