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

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod::container
{

std::string CapabilitiesType::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Add);
    CHECK_AND_SET_FIELD(result, Drop);
    return nlohmann::to_string(result);
}

std::string SecurityContext::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, AllowPrivilegeEscalation);
    CHECK_AND_SET_OBJECT_FIELD(result, AppArmorProfile);
    CHECK_AND_SET_OBJECT_FIELD(result, Capabilities);
    CHECK_AND_SET_FIELD(result, ProcMount);
    CHECK_AND_SET_FIELD(result, Privileged);
    CHECK_AND_SET_FIELD(result, ReadOnlyRootFilesystem);
    CHECK_AND_SET_FIELD(result, RunAsUser);
    CHECK_AND_SET_FIELD(result, RunAsNonRoot);
    CHECK_AND_SET_FIELD(result, RunAsGroup);
    CHECK_AND_SET_OBJECT_FIELD(result, SeLinuxOptions);
    CHECK_AND_SET_OBJECT_FIELD(result, SeccompProfile);
    CHECK_AND_SET_OBJECT_FIELD(result, WindowsOptions);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod::container