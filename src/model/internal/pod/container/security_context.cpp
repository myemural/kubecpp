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

#include "kubecpp/model/internal/pod/container/security_context.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string CapabilitiesType::ParseToJson() const
{
    return ParseFieldsToJson(Add, Drop);
}

CapabilitiesType CapabilitiesType::ParseFromJson(const std::string& jsonData)
{
    CapabilitiesType result;
    ParseFieldsFromJson(jsonData, result.Add, result.Drop);
    return result;
}

std::string SecurityContext::ParseToJson() const
{
    return ParseFieldsToJson(AllowPrivilegeEscalation, AppArmorProfile, Capabilities, ProcMount, Privileged,
    ReadOnlyRootFilesystem, RunAsUser, RunAsNonRoot, RunAsGroup, SeLinuxOptions, SeccompProfile, WindowsOptions);
}

SecurityContext SecurityContext::ParseFromJson(const std::string& jsonData)
{
    SecurityContext result;
    ParseFieldsFromJson(jsonData, result.AllowPrivilegeEscalation, result.AppArmorProfile, result.Capabilities,
    result.ProcMount, result.Privileged, result.ReadOnlyRootFilesystem, result.RunAsUser, result.RunAsNonRoot,
    result.RunAsGroup, result.SeLinuxOptions, result.SeccompProfile, result.WindowsOptions);
    return result;
}

CapabilitiesBuilder& CapabilitiesBuilder::Add(const std::vector<std::string>& add)
{
    capabilities_.Add = add;
    return *this;
}

CapabilitiesBuilder& CapabilitiesBuilder::Drop(const std::vector<std::string>& drop)
{
    capabilities_.Drop = drop;
    return *this;
}

CapabilitiesType CapabilitiesBuilder::Build()
{
    return std::move(capabilities_);
}

SecurityContextBuilder& SecurityContextBuilder::AllowPrivilegeEscalation(bool allowPrivilegeEscalation)
{
    securityContext_.AllowPrivilegeEscalation = allowPrivilegeEscalation;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::AppArmorProfile(const security::AppArmorProfile& appArmorProfile)
{
    securityContext_.AppArmorProfile = appArmorProfile;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::Capabilities(const CapabilitiesType& capabilities)
{
    securityContext_.Capabilities = capabilities;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::ProcMount(const std::string& procMount)
{
    securityContext_.ProcMount = procMount;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::Privileged(bool privileged)
{
    securityContext_.Privileged = privileged;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::ReadOnlyRootFilesystem(bool readOnlyRootFilesystem)
{
    securityContext_.ReadOnlyRootFilesystem = readOnlyRootFilesystem;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::RunAsUser(int64_t runAsUser)
{
    securityContext_.RunAsUser = runAsUser;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::RunAsNonRoot(bool runAsNonRoot)
{
    securityContext_.RunAsNonRoot = runAsNonRoot;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::RunAsGroup(int64_t runAsGroup)
{
    securityContext_.RunAsGroup = runAsGroup;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::SeLinuxOptions(const security::SELinuxOptions& seLinuxOptions)
{
    securityContext_.SeLinuxOptions = seLinuxOptions;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::SeccompProfile(const security::SeccompProfile& seccompProfile)
{
    securityContext_.SeccompProfile = seccompProfile;
    return *this;
}

SecurityContextBuilder& SecurityContextBuilder::WindowsOptions(const security::WindowsSecurityContextOptions& windowsOptions)
{
    securityContext_.WindowsOptions = windowsOptions;
    return *this;
}

SecurityContext SecurityContextBuilder::Build()
{
    return std::move(securityContext_);
}

} // namespace kubecpp::model::internal::pod::container