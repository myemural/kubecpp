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

#include "kubecpp/model/internal/pod/security/seccomp_profile.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::security
{

std::string SeccompProfile::ParseToJson() const
{
    return ParseFieldsToJson(Type, LocalhostProfile);
}

SeccompProfile SeccompProfile::ParseFromJson(const std::string& jsonData)
{
    SeccompProfile result;
    ParseFieldsFromJson(jsonData, result.Type, result.LocalhostProfile);
    return result;
}

SeccompProfileBuilder& SeccompProfileBuilder::Type(const std::string& type)
{
    seccompProfile_.Type = type;
    return *this;
}

SeccompProfileBuilder& SeccompProfileBuilder::LocalhostProfile(const std::string& localhostProfile)
{
    seccompProfile_.LocalhostProfile = localhostProfile;
    return *this;
}

SeccompProfile SeccompProfileBuilder::Build()
{
    return std::move(seccompProfile_);
}

} // namespace kubecpp::model::internal::pod::security