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

#ifndef SECURITY_CONTEXT_H_
#define SECURITY_CONTEXT_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/pod/security/app_armor_profile.h"
#include "kubecpp/model/internal/pod/security/se_linux_options.h"
#include "kubecpp/model/internal/pod/security/seccomp_profile.h"
#include "kubecpp/model/internal/pod/security/windows_security_context_options.h"

namespace kubecpp::model::internal::pod::container
{

struct Capabilities
{
    Checked<std::vector<std::string>> Add{ "add", false, "description" };
    Checked<std::vector<std::string>> Drop{ "drop", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct SecurityContext
{
    Checked<bool> AllowPrivilegeEscalation{ "allowPrivilegeEscalation", false, "description" };
    Checked<security::AppArmorProfile> AppArmorProfile{ "appArmorProfile", false, "description" };
    Checked<Capabilities> Capabilities{ "capabilities", false, "description" };
    Checked<std::string> ProcMount{ "procMount", false, "description" };
    Checked<bool> Privileged{ "privileged", false, "description" };
    Checked<bool> ReadOnlyRootFilesystem{ "readOnlyRootFilesystem", false, "description" };
    Checked<int64_t> RunAsUser{ "runAsUser", false, "description" };
    Checked<bool> RunAsNonRoot{ "runAsNonRoot", false, "description" };
    Checked<int64_t> RunAsGroup{ "runAsGroup", false, "description" };
    Checked<security::SELinuxOptions> SeLinuxOptions{ "seLinuxOptions", false, "description" };
    Checked<security::SeccompProfile> SeccompProfile{ "seccompProfile", false, "description" };
    Checked<security::WindowsSecurityContextOptions> WindowsOptions{ "windowsOptions", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod::container

#endif // SECURITY_CONTEXT_H_