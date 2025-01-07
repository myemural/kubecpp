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

#ifndef EPHEMERAL_CONTAINER_H_
#define EPHEMERAL_CONTAINER_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/pod/container/container_resize_policy.h"
#include "kubecpp/model/internal/pod/container/env_from_source.h"
#include "kubecpp/model/internal/pod/container/env_var.h"
#include "kubecpp/model/internal/pod/container/security_context.h"
#include "kubecpp/model/internal/pod/container/volume_device.h"
#include "kubecpp/model/internal/pod/container/volume_mount.h"

namespace kubecpp::model::internal::pod
{

struct EphemeralContainer
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> TargetContainerName{ "targetContainerName", true, "description" };
    Checked<std::string> Image{ "image", false, "description" };
    Checked<std::string> ImagePullPolicy{ "imagePullPolicy", false, "description" };
    Checked<std::vector<std::string>> Command{ "command", false, "description" };
    Checked<std::vector<std::string>> Args{ "args", false, "description" };
    Checked<std::string> WorkingDir{ "workingDir", false, "description" };
    Checked<std::vector<container::EnvVar>> Env{ "env", false, "description" };
    Checked<std::vector<container::EnvFromSource>> EnvFrom{ "envFrom", false, "description" };
    Checked<std::vector<container::VolumeMount>> VolumeMounts{ "volumeMounts", false, "description" };
    Checked<std::vector<container::VolumeDevice>> VolumeDevices{ "volumeDevices", false, "description" };
    Checked<std::vector<container::ContainerResizePolicy>> ResizePolicy{ "resizePolicy", false, "description" };
    Checked<std::string> TerminationMessagePath{ "terminationMessagePath", false, "description" };
    Checked<std::string> TerminationMessagePolicy{ "terminationMessagePolicy", false, "description" };
    Checked<std::string> RestartPolicy{ "restartPolicy", false, "description" };
    Checked<bool> Stdin{ "stdin", false, "description" };
    Checked<bool> StdinOnce{ "stdinOnce", false, "description" };
    Checked<bool> Tty{ "tty", false, "description" };
    Checked<container::SecurityContext> SecurityContext{ "securityContext", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct EphemeralContainerBuilder
{
    EphemeralContainerBuilder& Name(const std::string& name);

    EphemeralContainerBuilder& TargetContainerName(const std::string& targetContainerName);

    EphemeralContainerBuilder& Image(const std::string& image);

    EphemeralContainerBuilder& ImagePullPolicy(const std::string& imagePullPolicy);

    EphemeralContainerBuilder& Command(const std::vector<std::string>& command);

    EphemeralContainerBuilder& Args(const std::vector<std::string>& args);

    EphemeralContainerBuilder& WorkingDir(const std::string& workingDir);

    EphemeralContainerBuilder& Env(const std::vector<container::EnvVar>& env);

    EphemeralContainerBuilder& EnvFrom(const std::vector<container::EnvFromSource>& envFrom);

    EphemeralContainerBuilder& VolumeMounts(const std::vector<container::VolumeMount>& volumeMounts);

    EphemeralContainerBuilder& VolumeDevices(const std::vector<container::VolumeDevice>& volumeDevices);

    EphemeralContainerBuilder& ResizePolicy(const std::vector<container::ContainerResizePolicy>& resizePolicy);

    EphemeralContainerBuilder& TerminationMessagePath(const std::string& terminationMessagePath);

    EphemeralContainerBuilder& TerminationMessagePolicy(const std::string& terminationMessagePolicy);

    EphemeralContainerBuilder& RestartPolicy(const std::string& restartPolicy);

    EphemeralContainerBuilder& SecurityContext(const container::SecurityContext& securityContext);

    EphemeralContainerBuilder& Stdin(bool stdIn);

    EphemeralContainerBuilder& StdinOnce(bool stdinOnce);

    EphemeralContainerBuilder& Tty(bool tty);

    EphemeralContainer Build();

private:
    EphemeralContainer ephemeralContainer_;
};

} // namespace kubecpp::model::internal::pod

#endif // EPHEMERAL_CONTAINER_H_