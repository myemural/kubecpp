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

#include "kubecpp/model/internal/common/object_field_selector.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::common
{

std::string ObjectFieldSelector::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, FieldPath);
    CHECK_AND_SET_FIELD(result, ApiVersion);
    return nlohmann::to_string(result);
}

ObjectFieldSelectorBuilder& ObjectFieldSelectorBuilder::FieldPath(const std::string& fieldPath)
{
    objectFieldSelector_.FieldPath = fieldPath;
    return *this;
}

ObjectFieldSelectorBuilder& ObjectFieldSelectorBuilder::ApiVersion(const std::string& apiVersion)
{
    objectFieldSelector_.ApiVersion = apiVersion;
    return *this;
}

ObjectFieldSelector ObjectFieldSelectorBuilder::Build()
{
    return std::move(objectFieldSelector_);
}

} // namespace kubecpp::model::internal::common