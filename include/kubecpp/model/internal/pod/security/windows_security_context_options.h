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

#ifndef WINDOWS_SECURITY_CONTEXT_OPTIONS_H_
#define WINDOWS_SECURITY_CONTEXT_OPTIONS_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::security
{

struct WindowsSecurityContextOptions
{
    Checked<std::string> GmsaCredentialSpec{ "gmsaCredentialSpec", false, "description" };
    Checked<std::string> GmsaCredentialSpecName{ "gmsaCredentialSpecName", false, "description" };
    Checked<bool> HostProcess{ "hostProcess", false, "description" };
    Checked<std::string> RunAsUserName{ "runAsUserName", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static WindowsSecurityContextOptions ParseFromJson(const std::string& jsonData);
};

struct WindowsSecurityContextOptionsBuilder
{
    WindowsSecurityContextOptionsBuilder& GmsaCredentialSpec(const std::string& gmsaCredentialSpec);

    WindowsSecurityContextOptionsBuilder& GmsaCredentialSpecName(const std::string& gmsaCredentialSpecName);

    WindowsSecurityContextOptionsBuilder& HostProcess(bool hostProcess);

    WindowsSecurityContextOptionsBuilder& RunAsUserName(const std::string& runAsUserName);

    WindowsSecurityContextOptions Build();

private:
    WindowsSecurityContextOptions windowsSecurityContextOptions_;
};

} // namespace kubecpp::model::internal::pod::security

#endif // WINDOWS_SECURITY_CONTEXT_OPTIONS_H_