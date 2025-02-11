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

PodSecurityContextBuilder& PodSecurityContextBuilder::AppArmorProfile(const security::AppArmorProfile& appArmorProfile)
{
    podSecurityContext_.AppArmorProfile = appArmorProfile;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::FsGroup(int64_t fsGroup)
{
    podSecurityContext_.FsGroup = fsGroup;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::FsGroupChangePolicy(const std::string& fsGroupChangePolicy)
{
    podSecurityContext_.FsGroupChangePolicy = fsGroupChangePolicy;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::RunAsUser(int64_t runAsUser)
{
    podSecurityContext_.RunAsUser = runAsUser;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::RunAsNonRoot(bool runAsNonRoot)
{
    podSecurityContext_.RunAsNonRoot = runAsNonRoot;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::RunAsGroup(int64_t runAsGroup)
{
    podSecurityContext_.RunAsGroup = runAsGroup;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::SeccompProfile(const security::SeccompProfile& seccompProfile)
{
    podSecurityContext_.SeccompProfile = seccompProfile;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::SeLinuxOptions(const security::SELinuxOptions& seLinuxOptions)
{
    podSecurityContext_.SeLinuxOptions = seLinuxOptions;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::SupplementalGroups(const std::vector<int64_t>& supplementalGroups)
{
    podSecurityContext_.SupplementalGroups = supplementalGroups;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::SupplementalGroupsPolicy(const std::string& supplementalGroupsPolicy)
{
    podSecurityContext_.SupplementalGroupsPolicy = supplementalGroupsPolicy;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::Sysctls(const std::vector<Sysctl>& sysctls)
{
    podSecurityContext_.Sysctls = sysctls;
    return *this;
}

PodSecurityContextBuilder& PodSecurityContextBuilder::WindowsOptions(const security::WindowsSecurityContextOptions& windowsOptions)
{
    podSecurityContext_.WindowsOptions = windowsOptions;
    return *this;
}

PodSecurityContext PodSecurityContextBuilder::Build()
{
    return std::move(podSecurityContext_);
}

} // namespace kubecpp::model::internal::pod