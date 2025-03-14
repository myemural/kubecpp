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

#ifndef POD_SECURITY_CONTEXT_H_
#define POD_SECURITY_CONTEXT_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/pod/security/app_armor_profile.h"
#include "kubecpp/model/internal/pod/security/se_linux_options.h"
#include "kubecpp/model/internal/pod/security/seccomp_profile.h"
#include "kubecpp/model/internal/pod/security/windows_security_context_options.h"

namespace kubecpp::model::internal::pod
{

struct Sysctl
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Value{ "value", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static Sysctl ParseFromJson(const std::string& jsonData);
};

struct PodSecurityContext
{
    Checked<security::AppArmorProfile> AppArmorProfile{ "appArmorProfile", false, "description" };
    Checked<int64_t> FsGroup{ "fsGroup", false, "description" };
    Checked<std::string> FsGroupChangePolicy{ "fsGroupChangePolicy", false, "description" };
    Checked<int64_t> RunAsUser{ "runAsUser", false, "description" };
    Checked<bool> RunAsNonRoot{ "runAsNonRoot", false, "description" };
    Checked<int64_t> RunAsGroup{ "runAsGroup", false, "description" };
    Checked<security::SeccompProfile> SeccompProfile{ "seccompProfile", false, "description" };
    Checked<security::SELinuxOptions> SeLinuxOptions{ "seLinuxOptions", false, "description" };
    Checked<std::vector<int64_t>> SupplementalGroups{ "supplementalGroups", false, "description" };
    Checked<std::string> SupplementalGroupsPolicy{ "supplementalGroupsPolicy", false, "description" };
    Checked<std::vector<Sysctl>> Sysctls{ "sysctls", false, "description" };
    Checked<security::WindowsSecurityContextOptions> WindowsOptions{ "windowsOptions", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PodSecurityContext ParseFromJson(const std::string& jsonData);
};

struct SysctlBuilder
{
    SysctlBuilder& Name(const std::string& name);

    SysctlBuilder& Value(const std::string& value);

    Sysctl Build();

private:
    Sysctl sysctl_;
};

struct PodSecurityContextBuilder
{
    PodSecurityContextBuilder& AppArmorProfile(const security::AppArmorProfile& appArmorProfile);

    PodSecurityContextBuilder& FsGroup(int64_t fsGroup);

    PodSecurityContextBuilder& FsGroupChangePolicy(const std::string& fsGroupChangePolicy);

    PodSecurityContextBuilder& RunAsUser(int64_t runAsUser);

    PodSecurityContextBuilder& RunAsNonRoot(bool runAsNonRoot);

    PodSecurityContextBuilder& RunAsGroup(int64_t runAsGroup);

    PodSecurityContextBuilder& SeccompProfile(const security::SeccompProfile& seccompProfile);

    PodSecurityContextBuilder& SeLinuxOptions(const security::SELinuxOptions& seLinuxOptions);

    PodSecurityContextBuilder& SupplementalGroups(const std::vector<int64_t>& supplementalGroups);

    PodSecurityContextBuilder& SupplementalGroupsPolicy(const std::string& supplementalGroupsPolicy);

    PodSecurityContextBuilder& Sysctls(const std::vector<Sysctl>& sysctls);

    PodSecurityContextBuilder& WindowsOptions(const security::WindowsSecurityContextOptions& windowsOptions);

    PodSecurityContext Build();

private:
    PodSecurityContext podSecurityContext_;
};

} // namespace kubecpp::model::internal::pod

#endif // POD_SECURITY_CONTEXT_H_