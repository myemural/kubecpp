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

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/resource_requirements.h"
#include "kubecpp/model/internal/pod/container/container_port.h"
#include "kubecpp/model/internal/pod/container/container_resize_policy.h"
#include "kubecpp/model/internal/pod/container/env_from_source.h"
#include "kubecpp/model/internal/pod/container/env_var.h"
#include "kubecpp/model/internal/pod/container/lifecycle.h"
#include "kubecpp/model/internal/pod/container/probe.h"
#include "kubecpp/model/internal/pod/container/security_context.h"
#include "kubecpp/model/internal/pod/container/volume_device.h"
#include "kubecpp/model/internal/pod/container/volume_mount.h"

namespace kubecpp::model::internal::pod
{

struct Container
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Image{ "image", false, "description" };
    Checked<std::string> ImagePullPolicy{ "imagePullPolicy", false, "description" };
    Checked<std::vector<std::string>> Command{ "command", false, "description" };
    Checked<std::vector<std::string>> Args{ "args", false, "description" };
    Checked<std::string> WorkingDir{ "workingDir", false, "description" };
    Checked<std::vector<container::ContainerPortType>> Ports{ "ports", false, "description" };
    Checked<std::vector<container::EnvVar>> Env{ "env", false, "description" };
    Checked<std::vector<container::EnvFromSource>> EnvFrom{ "envFrom", false, "description" };
    Checked<std::vector<container::VolumeMount>> VolumeMounts{ "volumeMounts", false, "description" };
    Checked<std::vector<container::VolumeDevice>> VolumeDevices{ "volumeDevices", false, "description" };
    Checked<common::ResourceRequirements> Resources{ "resources", false, "description" };
    Checked<std::vector<container::ContainerResizePolicy>> ResizePolicy{ "resizePolicy", false, "description" };
    Checked<container::Lifecycle> Lifecycle{ "lifecycle", false, "description" };
    Checked<std::string> TerminationMessagePath{ "terminationMessagePath", false, "description" };
    Checked<std::string> TerminationMessagePolicy{ "terminationMessagePolicy", false, "description" };
    Checked<container::Probe> LivenessProbe{ "livenessProbe", false, "description" };
    Checked<container::Probe> ReadinessProbe{ "readinessProbe", false, "description" };
    Checked<container::Probe> StartupProbe{ "startupProbe", false, "description" };
    Checked<std::string> RestartPolicy{ "restartPolicy", false, "description" };
    Checked<container::SecurityContext> SecurityContext{ "securityContext", false, "description" };
    Checked<bool> Stdin{ "stdin", false, "description" };
    Checked<bool> StdinOnce{ "stdinOnce", false, "description" };
    Checked<bool> Tty{ "tty", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct ContainerBuilder
{
    ContainerBuilder& Name(const std::string& name);

    ContainerBuilder& Image(const std::string& image);

    ContainerBuilder& ImagePullPolicy(const std::string& imagePullPolicy);

    ContainerBuilder& Command(const std::vector<std::string>& command);

    ContainerBuilder& Args(const std::vector<std::string>& args);

    ContainerBuilder& WorkingDir(const std::string& workingDir);

    ContainerBuilder& Ports(const std::vector<container::ContainerPortType>& ports);

    ContainerBuilder& Env(const std::vector<container::EnvVar>& env);

    ContainerBuilder& EnvFrom(const std::vector<container::EnvFromSource>& envFrom);

    ContainerBuilder& VolumeMounts(const std::vector<container::VolumeMount>& volumeMounts);

    ContainerBuilder& VolumeDevices(const std::vector<container::VolumeDevice>& volumeDevices);

    ContainerBuilder& Resources(const common::ResourceRequirements& resources);

    ContainerBuilder& ResizePolicy(const std::vector<container::ContainerResizePolicy>& resizePolicy);

    ContainerBuilder& Lifecycle(const container::Lifecycle& lifecycle);

    ContainerBuilder& TerminationMessagePath(const std::string& terminationMessagePath);

    ContainerBuilder& TerminationMessagePolicy(const std::string& terminationMessagePolicy);

    ContainerBuilder& LivenessProbe(const container::Probe& livenessProbe);

    ContainerBuilder& ReadinessProbe(const container::Probe& readinessProbe);

    ContainerBuilder& StartupProbe(const container::Probe& startupProbe);

    ContainerBuilder& RestartPolicy(const std::string& restartPolicy);

    ContainerBuilder& SecurityContext(const container::SecurityContext& securityContext);

    ContainerBuilder& Stdin(bool stdIn);

    ContainerBuilder& StdinOnce(bool stdinOnce);

    ContainerBuilder& Tty(bool tty);

    Container Build();

private:
    Container container_;
};

} // namespace kubecpp::model::internal::pod

#endif // CONTAINER_H_