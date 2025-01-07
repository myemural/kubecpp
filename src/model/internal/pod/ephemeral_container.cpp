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

EphemeralContainerBuilder& EphemeralContainerBuilder::Name(const std::string& name)
{
    ephemeralContainer_.Name = name;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::TargetContainerName(const std::string& targetContainerName)
{
    ephemeralContainer_.TargetContainerName = targetContainerName;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Image(const std::string& image)
{
    ephemeralContainer_.Image = image;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::ImagePullPolicy(const std::string& imagePullPolicy)
{
    ephemeralContainer_.ImagePullPolicy = imagePullPolicy;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Command(const std::vector<std::string>& command)
{
    ephemeralContainer_.Command = command;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Args(const std::vector<std::string>& args)
{
    ephemeralContainer_.Args = args;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::WorkingDir(const std::string& workingDir)
{
    ephemeralContainer_.WorkingDir = workingDir;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Env(const std::vector<container::EnvVar>& env)
{
    ephemeralContainer_.Env = env;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::EnvFrom(const std::vector<container::EnvFromSource>& envFrom)
{
    ephemeralContainer_.EnvFrom = envFrom;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::VolumeMounts(const std::vector<container::VolumeMount>& volumeMounts)
{
    ephemeralContainer_.VolumeMounts = volumeMounts;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::VolumeDevices(const std::vector<container::VolumeDevice>& volumeDevices)
{
    ephemeralContainer_.VolumeDevices = volumeDevices;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::ResizePolicy(const std::vector<container::ContainerResizePolicy>& resizePolicy)
{
    ephemeralContainer_.ResizePolicy = resizePolicy;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::TerminationMessagePath(const std::string& terminationMessagePath)
{
    ephemeralContainer_.TerminationMessagePath = terminationMessagePath;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::TerminationMessagePolicy(const std::string& terminationMessagePolicy)
{
    ephemeralContainer_.TerminationMessagePolicy = terminationMessagePolicy;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::RestartPolicy(const std::string& restartPolicy)
{
    ephemeralContainer_.RestartPolicy = restartPolicy;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::SecurityContext(const container::SecurityContext& securityContext)
{
    ephemeralContainer_.SecurityContext = securityContext;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Stdin(bool stdIn)
{
    ephemeralContainer_.Stdin = stdIn;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::StdinOnce(bool stdinOnce)
{
    ephemeralContainer_.StdinOnce = stdinOnce;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::Tty(bool tty)
{
    ephemeralContainer_.Tty = tty;
    return *this;
}

EphemeralContainer EphemeralContainerBuilder::Build()
{
    return std::move(ephemeralContainer_);
}

} // namespace kubecpp::model::internal::pod