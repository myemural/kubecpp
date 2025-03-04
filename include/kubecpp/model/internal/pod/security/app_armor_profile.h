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

#ifndef APP_ARMOR_PROFILE_H_
#define APP_ARMOR_PROFILE_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::security
{

struct AppArmorProfile
{
    Checked<std::string> Type{ "type", true, "description" };
    Checked<std::string> LocalhostProfile{ "localhostProfile", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static AppArmorProfile ParseFromJson(const std::string& jsonData);
};

struct AppArmorProfileBuilder
{
    AppArmorProfileBuilder& Type(const std::string& type);

    AppArmorProfileBuilder& LocalhostProfile(const std::string& localhostProfile);

    AppArmorProfile Build();

private:
    AppArmorProfile appArmorProfile_;
};

} // namespace kubecpp::model::internal::pod::security

#endif // APP_ARMOR_PROFILE_H_