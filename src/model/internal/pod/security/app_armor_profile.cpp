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

#include "kubecpp/model/internal/pod/security/app_armor_profile.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::security
{

std::string AppArmorProfile::ParseToJson() const
{
    return ParseFieldsToJson(Type, LocalhostProfile);
}

AppArmorProfile AppArmorProfile::ParseFromJson(const std::string& jsonData)
{
    AppArmorProfile result;
    ParseFieldsFromJson(jsonData, result.Type, result.LocalhostProfile);
    return result;
}

} // namespace kubecpp::model::internal::pod::security