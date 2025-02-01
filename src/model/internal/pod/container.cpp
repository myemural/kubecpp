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

namespace kubecpp::model::internal::pod
{

std::string ContainerPortType::ParseToJson() const
{
    return ParseFieldsToJson(ContainerPort, HostIP, HostPort, Name, Protocol);
}

std::string SecretKeySelector::ParseToJson() const
{
    return ParseFieldsToJson(Key, Name, Optional);
}

std::string ConfigMapKeySelector::ParseToJson() const
{
    return ParseFieldsToJson(Key, Name, Optional);
}

std::string EnvVarSource::ParseToJson() const
{
    return ParseFieldsToJson(ConfigMapKeyRef, FieldRef, ResourceFieldRef, SecretKeyRef);
}

std::string EnvVar::ParseToJson() const
{
    return ParseFieldsToJson(Name, Value, ValueFrom);
}

std::string SecretEnvSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional);
}

std::string ConfigMapEnvSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional);
}

std::string EnvFromSource::ParseToJson() const
{
    return ParseFieldsToJson(ConfigMapRef, Prefix, SecretRef);
}

std::string VolumeMount::ParseToJson() const
{
    return ParseFieldsToJson(MountPath, Name, MountPropagation, ReadOnly, RecursiveReadOnly, SubPath, SubPathExpr);
}

std::string VolumeDevice::ParseToJson() const
{
    return ParseFieldsToJson(DevicePath, Name);
}

std::string ContainerResizePolicy::ParseToJson() const
{
    return ParseFieldsToJson(ResourceName, RestartPolicy);
}

std::string LifecycleType::ParseToJson() const
{
    return ParseFieldsToJson(PostStart, PreStop);
}

std::string Container::ParseToJson() const
{
    return ParseFieldsToJson(Name, Image, ImagePullPolicy, Command, Args, WorkingDir, Ports, Env, EnvFrom, VolumeMounts,
    VolumeDevices, Resources, ResizePolicy, Lifecycle, TerminationMessagePath, TerminationMessagePolicy, LivenessProbe,
    ReadinessProbe, StartupProbe, RestartPolicy, SecurityContext, Stdin, StdinOnce, Tty);
}

Container Container::ParseFromJson(const std::string& jsonData)
{
    /// TODO: Will be implemented later.
    Container result;
    ParseFieldsFromJson(jsonData, result.Name);
    return result;
}

std::string EphemeralContainer::ParseToJson() const
{
    return ParseFieldsToJson(Name, TargetContainerName, Image, ImagePullPolicy, Command, Args, WorkingDir, Env, EnvFrom,
    VolumeMounts, VolumeDevices, ResizePolicy, TerminationMessagePath, TerminationMessagePolicy, RestartPolicy,
    SecurityContext, Stdin, StdinOnce, Tty);
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

ContainerBuilder& ContainerBuilder::Ports(const std::vector<ContainerPortType>& ports)
{
    container_.Ports = ports;
    return *this;
}

ContainerBuilder& ContainerBuilder::Env(const std::vector<EnvVar>& env)
{
    container_.Env = env;
    return *this;
}

ContainerBuilder& ContainerBuilder::EnvFrom(const std::vector<EnvFromSource>& envFrom)
{
    container_.EnvFrom = envFrom;
    return *this;
}

ContainerBuilder& ContainerBuilder::VolumeMounts(const std::vector<VolumeMount>& volumeMounts)
{
    container_.VolumeMounts = volumeMounts;
    return *this;
}

ContainerBuilder& ContainerBuilder::VolumeDevices(const std::vector<VolumeDevice>& volumeDevices)
{
    container_.VolumeDevices = volumeDevices;
    return *this;
}

ContainerBuilder& ContainerBuilder::Resources(const common::ResourceRequirements& resources)
{
    container_.Resources = resources;
    return *this;
}

ContainerBuilder& ContainerBuilder::ResizePolicy(const std::vector<ContainerResizePolicy>& resizePolicy)
{
    container_.ResizePolicy = resizePolicy;
    return *this;
}

ContainerBuilder& ContainerBuilder::Lifecycle(const LifecycleType& lifecycle)
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

EphemeralContainerBuilder& EphemeralContainerBuilder::Env(const std::vector<EnvVar>& env)
{
    ephemeralContainer_.Env = env;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::EnvFrom(const std::vector<EnvFromSource>& envFrom)
{
    ephemeralContainer_.EnvFrom = envFrom;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::VolumeMounts(const std::vector<VolumeMount>& volumeMounts)
{
    ephemeralContainer_.VolumeMounts = volumeMounts;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::VolumeDevices(const std::vector<VolumeDevice>& volumeDevices)
{
    ephemeralContainer_.VolumeDevices = volumeDevices;
    return *this;
}

EphemeralContainerBuilder& EphemeralContainerBuilder::ResizePolicy(const std::vector<ContainerResizePolicy>& resizePolicy)
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
