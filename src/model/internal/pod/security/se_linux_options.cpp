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

#include "kubecpp/model/internal/pod/security/se_linux_options.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::security
{

std::string SELinuxOptions::ParseToJson() const
{
    return ParseFieldsToJson(Level, Role, Type, User);
}

SELinuxOptions SELinuxOptions::ParseFromJson(const std::string& jsonData)
{
    SELinuxOptions result;
    ParseFieldsFromJson(jsonData, result.Level, result.Role, result.Type, result.User);
    return result;
}

SELinuxOptionsBuilder& SELinuxOptionsBuilder::Level(const std::string& level)
{
    seLinuxOptions_.Level = level;
    return *this;
}

SELinuxOptionsBuilder& SELinuxOptionsBuilder::Role(const std::string& role)
{
    seLinuxOptions_.Role = role;
    return *this;
}

SELinuxOptionsBuilder& SELinuxOptionsBuilder::Type(const std::string& type)
{
    seLinuxOptions_.Type = type;
    return *this;
}

SELinuxOptionsBuilder& SELinuxOptionsBuilder::User(const std::string& user)
{
    seLinuxOptions_.User = user;
    return *this;
}

SELinuxOptions SELinuxOptionsBuilder::Build()
{
    return std::move(seLinuxOptions_);
}

} // namespace kubecpp::model::internal::pod::security