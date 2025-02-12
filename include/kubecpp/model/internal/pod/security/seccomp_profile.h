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

#ifndef SECCOMP_PROFILE_H_
#define SECCOMP_PROFILE_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::security
{

struct SeccompProfile
{
    Checked<std::string> Type{ "type", true, "description" };
    Checked<std::string> LocalhostProfile{ "localhostProfile", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static SeccompProfile ParseFromJson(const std::string& jsonData);
};

struct SeccompProfileBuilder
{
    SeccompProfileBuilder& Type(const std::string& type);

    SeccompProfileBuilder& LocalhostProfile(const std::string& localhostProfile);

    SeccompProfile Build();

private:
    SeccompProfile seccompProfile_;
};

} // namespace kubecpp::model::internal::pod::security

#endif // SECCOMP_PROFILE_H_