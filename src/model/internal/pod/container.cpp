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

#include "kubecpp/model/internal/pod/container.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod
{

std::string Container::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Image);
    CHECK_AND_SET_FIELD(result, ImagePullPolicy);
    CHECK_AND_SET_FIELD(result, Command);
    CHECK_AND_SET_FIELD(result, Args);
    CHECK_AND_SET_FIELD(result, WorkingDir);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, Ports);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, Env);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, EnvFrom);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, VolumeMounts);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, VolumeDevices);
    CHECK_AND_SET_OBJECT_FIELD(result, Resources);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, ResizePolicy);
    CHECK_AND_SET_OBJECT_FIELD(result, Lifecycle);
    CHECK_AND_SET_FIELD(result, TerminationMessagePath);
    CHECK_AND_SET_FIELD(result, TerminationMessagePolicy);
    CHECK_AND_SET_OBJECT_FIELD(result, LivenessProbe);
    CHECK_AND_SET_OBJECT_FIELD(result, ReadinessProbe);
    CHECK_AND_SET_OBJECT_FIELD(result, StartupProbe);
    CHECK_AND_SET_FIELD(result, RestartPolicy);
    CHECK_AND_SET_OBJECT_FIELD(result, SecurityContext);
    CHECK_AND_SET_FIELD(result, Stdin);
    CHECK_AND_SET_FIELD(result, StdinOnce);
    CHECK_AND_SET_FIELD(result, Tty);
    return nlohmann::to_string(result);
}

ContainerBuilder& ContainerBuilder::Name(const std::string& name)
{
    container_.Name = name;
    return *this;
}

ContainerBuilder& ContainerBuilder::Image(const std::string& image)
{
    container_.Image = image;
    return *this;
}

ContainerBuilder& ContainerBuilder::ImagePullPolicy(const std::string& imagePullPolicy)
{
    container_.ImagePullPolicy = imagePullPolicy;
    return *this;
}

ContainerBuilder& ContainerBuilder::Command(const std::vector<std::string>& command)
{
    container_.Command = command;
    return *this;
}

ContainerBuilder& ContainerBuilder::Args(const std::vector<std::string>& args)
{
    container_.Args = args;
    return *this;
}

ContainerBuilder& ContainerBuilder::WorkingDir(const std::string& workingDir)
{
    container_.WorkingDir = workingDir;
    return *this;
}

ContainerBuilder& ContainerBuilder::Ports(const std::vector<container::ContainerPortType>& ports)
{
    container_.Ports = ports;
    return *this;
}

ContainerBuilder& ContainerBuilder::Env(const std::vector<container::EnvVar>& env)
{
    container_.Env = env;
    return *this;
}

ContainerBuilder& ContainerBuilder::EnvFrom(const std::vector<container::EnvFromSource>& envFrom)
{
    container_.EnvFrom = envFrom;
    return *this;
}

ContainerBuilder& ContainerBuilder::VolumeMounts(const std::vector<container::VolumeMount>& volumeMounts)
{
    container_.VolumeMounts = volumeMounts;
    return *this;
}

ContainerBuilder& ContainerBuilder::VolumeDevices(const std::vector<container::VolumeDevice>& volumeDevices)
{
    container_.VolumeDevices = volumeDevices;
    return *this;
}

ContainerBuilder& ContainerBuilder::Resources(const common::ResourceRequirements& resources)
{
    container_.Resources = resources;
    return *this;
}

ContainerBuilder& ContainerBuilder::ResizePolicy(const std::vector<container::ContainerResizePolicy>& resizePolicy)
{
    container_.ResizePolicy = resizePolicy;
    return *this;
}

ContainerBuilder& ContainerBuilder::Lifecycle(const container::Lifecycle& lifecycle)
{
    container_.Lifecycle = lifecycle;
    return *this;
}

ContainerBuilder& ContainerBuilder::TerminationMessagePath(const std::string& terminationMessagePath)
{
    container_.TerminationMessagePath = terminationMessagePath;
    return *this;
}

ContainerBuilder& ContainerBuilder::TerminationMessagePolicy(const std::string& terminationMessagePolicy)
{
    container_.TerminationMessagePolicy = terminationMessagePolicy;
    return *this;
}

ContainerBuilder& ContainerBuilder::LivenessProbe(const container::Probe& livenessProbe)
{
    container_.LivenessProbe = livenessProbe;
    return *this;
}

ContainerBuilder& ContainerBuilder::ReadinessProbe(const container::Probe& readinessProbe)
{
    container_.ReadinessProbe = readinessProbe;
    return *this;
}

ContainerBuilder& ContainerBuilder::StartupProbe(const container::Probe& startupProbe)
{
    container_.StartupProbe = startupProbe;
    return *this;
}

ContainerBuilder& ContainerBuilder::RestartPolicy(const std::string& restartPolicy)
{
    container_.RestartPolicy = restartPolicy;
    return *this;
}

ContainerBuilder& ContainerBuilder::SecurityContext(const container::SecurityContext& securityContext)
{
    container_.SecurityContext = securityContext;
    return *this;
}

ContainerBuilder& ContainerBuilder::Stdin(bool stdIn)
{
    container_.Stdin = stdIn;
    return *this;
}

ContainerBuilder& ContainerBuilder::StdinOnce(bool stdinOnce)
{
    container_.StdinOnce = stdinOnce;
    return *this;
}

ContainerBuilder& ContainerBuilder::Tty(bool tty)
{
    container_.Tty = tty;
    return *this;
}

Container ContainerBuilder::Build()
{
    return std::move(container_);
}

} // namespace kubecpp::model::internal::pod
