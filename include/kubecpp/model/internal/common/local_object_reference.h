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

#ifndef LOCAL_OBJECT_REFERENCE_H_
#define LOCAL_OBJECT_REFERENCE_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct LocalObjectReference
{
    Checked<std::string> Name{ "name", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static LocalObjectReference ParseFromJson(const std::string& jsonData);
};

struct LocalObjectReferenceBuilder
{
    LocalObjectReferenceBuilder& Name(const std::string& name);

    LocalObjectReference Build();

private:
    LocalObjectReference localObjectReference_;
};

} // namespace kubecpp::model::internal::common

#endif // LOCAL_OBJECT_REFERENCE_H_