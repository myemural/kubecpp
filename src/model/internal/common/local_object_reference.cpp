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

#include "kubecpp/model/internal/common/local_object_reference.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string LocalObjectReference::ParseToJson() const
{
    return ParseFieldsToJson(Name);
}

LocalObjectReference LocalObjectReference::ParseFromJson(const std::string& jsonData)
{
    LocalObjectReference result;
    ParseFieldsFromJson(jsonData, result.Name);
    return result;
}

LocalObjectReferenceBuilder& LocalObjectReferenceBuilder::Name(const std::string& name)
{
    localObjectReference_.Name = name;
    return *this;
}

LocalObjectReference LocalObjectReferenceBuilder::Build()
{
    return std::move(localObjectReference_);
}

} // namespace kubecpp::model::internal::common