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

#include "kubecpp/model/internal/pod/pod_security_context.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string Sysctl::ParseToJson() const
{
    return ParseFieldsToJson(Name, Value);
}

Sysctl Sysctl::ParseFromJson(const std::string& jsonData)
{
    Sysctl result;
    ParseFieldsFromJson(jsonData, result.Name, result.Value);
    return result;
}

std::string PodSecurityContext::ParseToJson() const
{
    return ParseFieldsToJson(AppArmorProfile, FsGroup, FsGroupChangePolicy, RunAsUser, RunAsNonRoot, RunAsGroup,
    SeccompProfile, SeLinuxOptions, SupplementalGroups, SupplementalGroupsPolicy, Sysctls, WindowsOptions);
}

PodSecurityContext PodSecurityContext::ParseFromJson(const std::string& jsonData)
{
    PodSecurityContext result;
    ParseFieldsFromJson(jsonData, result.AppArmorProfile, result.FsGroup, result.FsGroupChangePolicy, result.RunAsUser,
    result.RunAsNonRoot, result.RunAsGroup, result.SeccompProfile, result.SeLinuxOptions, result.SupplementalGroups,
    result.SupplementalGroupsPolicy, result.Sysctls, result.WindowsOptions);
    return result;
}

SysctlBuilder& SysctlBuilder::Name(const std::string& name)
{
    sysctl_.Name = name;
    return *this;
}

SysctlBuilder& SysctlBuilder::Value(const std::string& value)
{
    sysctl_.Value = value;
    return *this;
}

Sysctl SysctlBuilder::Build()
{
    return std::move(sysctl_);
}


} // namespace kubecpp::model::internal::pod