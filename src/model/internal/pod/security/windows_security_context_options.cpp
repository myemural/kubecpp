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

#include "kubecpp/model/internal/pod/security/windows_security_context_options.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::security
{

std::string WindowsSecurityContextOptions::ParseToJson() const
{
    return ParseFieldsToJson(GmsaCredentialSpec, GmsaCredentialSpecName, HostProcess, RunAsUserName);
}

WindowsSecurityContextOptions WindowsSecurityContextOptions::ParseFromJson(const std::string& jsonData)
{
    WindowsSecurityContextOptions result;
    ParseFieldsFromJson(jsonData, result.GmsaCredentialSpec, result.GmsaCredentialSpecName, result.HostProcess, result.RunAsUserName);
    return result;
}

WindowsSecurityContextOptionsBuilder& WindowsSecurityContextOptionsBuilder::GmsaCredentialSpec(const std::string& gmsaCredentialSpec)
{
    windowsSecurityContextOptions_.GmsaCredentialSpec = gmsaCredentialSpec;
    return *this;
}

WindowsSecurityContextOptionsBuilder& WindowsSecurityContextOptionsBuilder::GmsaCredentialSpecName(const std::string& gmsaCredentialSpecName)
{
    windowsSecurityContextOptions_.GmsaCredentialSpecName = gmsaCredentialSpecName;
    return *this;
}

WindowsSecurityContextOptionsBuilder& WindowsSecurityContextOptionsBuilder::HostProcess(bool hostProcess)
{
    windowsSecurityContextOptions_.HostProcess = hostProcess;
    return *this;
}

WindowsSecurityContextOptionsBuilder& WindowsSecurityContextOptionsBuilder::RunAsUserName(const std::string& runAsUserName)
{
    windowsSecurityContextOptions_.RunAsUserName = runAsUserName;
    return *this;
}

WindowsSecurityContextOptions WindowsSecurityContextOptionsBuilder::Build()
{
    return std::move(windowsSecurityContextOptions_);
}

} // namespace kubecpp::model::internal::pod::security