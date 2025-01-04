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

#include "kubecpp/model/internal/pod/ephemeral_container.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod
{

std::string EphemeralContainer::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, TargetContainerName);
    CHECK_AND_SET_FIELD(result, Image);
    CHECK_AND_SET_FIELD(result, ImagePullPolicy);
    CHECK_AND_SET_FIELD_CONTAINER(result, Command);
    CHECK_AND_SET_FIELD_CONTAINER(result, Args);
    CHECK_AND_SET_FIELD(result, WorkingDir);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, Env);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, EnvFrom);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, VolumeMounts);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, VolumeDevices);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, ResizePolicy);
    CHECK_AND_SET_FIELD(result, TerminationMessagePath);
    CHECK_AND_SET_FIELD(result, TerminationMessagePolicy);
    CHECK_AND_SET_FIELD(result, RestartPolicy);
    CHECK_AND_SET_OBJECT_FIELD(result, SecurityContext);
    CHECK_AND_SET_FIELD(result, Stdin);
    CHECK_AND_SET_FIELD(result, StdinOnce);
    CHECK_AND_SET_FIELD(result, Tty);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod