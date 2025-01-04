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

#ifndef OBJECT_FIELD_SELECTOR_H_
#define OBJECT_FIELD_SELECTOR_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct ObjectFieldSelector
{
    Checked<std::string> FieldPath{ "fieldPath", true, "description" };
    Checked<std::string> ApiVersion{ "apiVersion", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct ObjectFieldSelectorBuilder
{
    ObjectFieldSelectorBuilder& FieldPath(const std::string& fieldPath);

    ObjectFieldSelectorBuilder& ApiVersion(const std::string& apiVersion);

    ObjectFieldSelector Build();

private:
    ObjectFieldSelector objectFieldSelector_;
};

} // namespace kubecpp::model::internal::common

#endif // OBJECT_FIELD_SELECTOR_H_