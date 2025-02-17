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

ContainerPortType ContainerPortType::ParseFromJson(const std::string& jsonData)
{
    ContainerPortType result;
    ParseFieldsFromJson(jsonData, result.ContainerPort, result.HostIP, result.HostPort, result.Name, result.Protocol);
    return result;
}

std::string SecretKeySelector::ParseToJson() const
{
    return ParseFieldsToJson(Key, Name, Optional);
}

SecretKeySelector SecretKeySelector::ParseFromJson(const std::string& jsonData)
{
    SecretKeySelector result;
    ParseFieldsFromJson(jsonData, result.Key, result.Name, result.Optional);
    return result;
}

std::string ConfigMapKeySelector::ParseToJson() const
{
    return ParseFieldsToJson(Key, Name, Optional);
}

ConfigMapKeySelector ConfigMapKeySelector::ParseFromJson(const std::string& jsonData)
{
    ConfigMapKeySelector result;
    ParseFieldsFromJson(jsonData, result.Key, result.Name, result.Optional);
    return result;
}

std::string EnvVarSource::ParseToJson() const
{
    return ParseFieldsToJson(ConfigMapKeyRef, FieldRef, ResourceFieldRef, SecretKeyRef);
}

EnvVarSource EnvVarSource::ParseFromJson(const std::string& jsonData)
{
    EnvVarSource result;
    ParseFieldsFromJson(jsonData, result.ConfigMapKeyRef, result.FieldRef, result.ResourceFieldRef, result.SecretKeyRef);
    return result;
}

std::string EnvVar::ParseToJson() const
{
    return ParseFieldsToJson(Name, Value, ValueFrom);
}

EnvVar EnvVar::ParseFromJson(const std::string& jsonData)
{
    EnvVar result;
    ParseFieldsFromJson(jsonData, result.Name, result.Value, result.ValueFrom);
    return result;
}

std::string SecretEnvSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional);
}

SecretEnvSource SecretEnvSource::ParseFromJson(const std::string& jsonData)
{
    SecretEnvSource result;
    ParseFieldsFromJson(jsonData, result.Name, result.Optional);
    return result;
}

std::string ConfigMapEnvSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional);
}

ConfigMapEnvSource ConfigMapEnvSource::ParseFromJson(const std::string& jsonData)
{
    ConfigMapEnvSource result;
    ParseFieldsFromJson(jsonData, result.Name, result.Optional);
    return result;
}

std::string EnvFromSource::ParseToJson() const
{
    return ParseFieldsToJson(ConfigMapRef, Prefix, SecretRef);
}

EnvFromSource EnvFromSource::ParseFromJson(const std::string& jsonData)
{
    EnvFromSource result;
    ParseFieldsFromJson(jsonData, result.ConfigMapRef, result.Prefix, result.SecretRef);
    return result;
}

std::string VolumeMount::ParseToJson() const
{
    return ParseFieldsToJson(MountPath, Name, MountPropagation, ReadOnly, RecursiveReadOnly, SubPath, SubPathExpr);
}

VolumeMount VolumeMount::ParseFromJson(const std::string& jsonData)
{
    VolumeMount result;
    ParseFieldsFromJson(jsonData, result.MountPath, result.Name, result.MountPropagation, result.ReadOnly,
    result.RecursiveReadOnly, result.SubPath, result.SubPathExpr);
    return result;
}

std::string VolumeDevice::ParseToJson() const
{
    return ParseFieldsToJson(DevicePath, Name);
}

VolumeDevice VolumeDevice::ParseFromJson(const std::string& jsonData)
{
    VolumeDevice result;
    ParseFieldsFromJson(jsonData, result.DevicePath, result.Name);
    return result;
}

std::string ContainerResizePolicy::ParseToJson() const
{
    return ParseFieldsToJson(ResourceName, RestartPolicy);
}

ContainerResizePolicy ContainerResizePolicy::ParseFromJson(const std::string& jsonData)
{
    ContainerResizePolicy result;
    ParseFieldsFromJson(jsonData, result.ResourceName, result.RestartPolicy);
    return result;
}

std::string LifecycleType::ParseToJson() const
{
    return ParseFieldsToJson(PostStart, PreStop);
}

LifecycleType LifecycleType::ParseFromJson(const std::string& jsonData)
{
    LifecycleType result;
    ParseFieldsFromJson(jsonData, result.PostStart, result.PostStart);
    return result;
}

std::string Container::ParseToJson() const
{
    return ParseFieldsToJson(Name, Image, ImagePullPolicy, Command, Args, WorkingDir, Ports, Env, EnvFrom, VolumeMounts,
    VolumeDevices, Resources, ResizePolicy, Lifecycle, TerminationMessagePath, TerminationMessagePolicy, LivenessProbe,
    ReadinessProbe, StartupProbe, RestartPolicy, SecurityContext, Stdin, StdinOnce, Tty);
}

Container Container::ParseFromJson(const std::string& jsonData)
{
    Container result;
    ParseFieldsFromJson(jsonData, result.Name, result.Image, result.ImagePullPolicy, result.Command, result.Args,
    result.WorkingDir, result.Ports, result.Env, result.EnvFrom, result.VolumeMounts, result.VolumeDevices,
    result.Resources, result.ResizePolicy, result.Lifecycle, result.TerminationMessagePath,
    result.TerminationMessagePolicy, result.LivenessProbe, result.ReadinessProbe, result.StartupProbe,
    result.RestartPolicy, result.SecurityContext, result.Stdin, result.StdinOnce, result.Tty);
    return result;
}

std::string EphemeralContainer::ParseToJson() const
{
    return ParseFieldsToJson(Name, TargetContainerName, Image, ImagePullPolicy, Command, Args, WorkingDir, Env, EnvFrom,
    VolumeMounts, VolumeDevices, ResizePolicy, TerminationMessagePath, TerminationMessagePolicy, RestartPolicy,
    SecurityContext, Stdin, StdinOnce, Tty);
}

EphemeralContainer EphemeralContainer::ParseFromJson(const std::string& jsonData)
{
    EphemeralContainer result;
    ParseFieldsFromJson(jsonData, result.Name, result.TargetContainerName, result.Image, result.ImagePullPolicy,
    result.Command, result.Args, result.WorkingDir, result.Env, result.EnvFrom, result.VolumeMounts,
    result.VolumeDevices, result.ResizePolicy, result.TerminationMessagePath, result.TerminationMessagePolicy,
    result.RestartPolicy, result.SecurityContext, result.Stdin, result.StdinOnce, result.Tty);
    return result;
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

ContainerPortBuilder& ContainerPortBuilder::ContainerPort(int32_t containerPort)
{
    containerPortType_.ContainerPort = containerPort;
    return *this;
}

ContainerPortBuilder& ContainerPortBuilder::HostIP(const std::string& hostIP)
{
    containerPortType_.HostIP = hostIP;
    return *this;
}

ContainerPortBuilder& ContainerPortBuilder::HostPort(int32_t hostPort)
{
    containerPortType_.HostPort = hostPort;
    return *this;
}

ContainerPortBuilder& ContainerPortBuilder::Name(const std::string& name)
{
    containerPortType_.Name = name;
    return *this;
}

ContainerPortBuilder& ContainerPortBuilder::Protocol(const std::string& protocol)
{
    containerPortType_.Protocol = protocol;
    return *this;
}

ContainerPortType ContainerPortBuilder::Build()
{
    return std::move(containerPortType_);
}

SecretKeySelectorBuilder& SecretKeySelectorBuilder::Key(const std::string& key)
{
    secretKeySelector_.Key = key;
    return *this;
}

SecretKeySelectorBuilder& SecretKeySelectorBuilder::Name(const std::string& name)
{
    secretKeySelector_.Name = name;
    return *this;
}

SecretKeySelectorBuilder& SecretKeySelectorBuilder::Optional(bool optional)
{
    secretKeySelector_.Optional = optional;
    return *this;
}

SecretKeySelector SecretKeySelectorBuilder::Build()
{
    return std::move(secretKeySelector_);
}

ConfigMapKeySelectorBuilder& ConfigMapKeySelectorBuilder::Key(const std::string& key)
{
    configMapKeySelector_.Key = key;
    return *this;
}

ConfigMapKeySelectorBuilder& ConfigMapKeySelectorBuilder::Name(const std::string& name)
{
    configMapKeySelector_.Name = name;
    return *this;
}

ConfigMapKeySelectorBuilder& ConfigMapKeySelectorBuilder::Optional(bool optional)
{
    configMapKeySelector_.Optional = optional;
    return *this;
}

ConfigMapKeySelector ConfigMapKeySelectorBuilder::Build()
{
    return std::move(configMapKeySelector_);
}

EnvVarSourceBuilder& EnvVarSourceBuilder::ConfigMapKeyRef(const ConfigMapKeySelector& configMapKeyRef)
{
    envVarSource_.ConfigMapKeyRef = configMapKeyRef;
    return *this;
}

EnvVarSourceBuilder& EnvVarSourceBuilder::FieldRef(const common::ObjectFieldSelector& fieldRef)
{
    envVarSource_.FieldRef = fieldRef;
    return *this;
}

EnvVarSourceBuilder& EnvVarSourceBuilder::ResourceFieldRef(const common::ResourceFieldSelector& resourceFieldRef)
{
    envVarSource_.ResourceFieldRef = resourceFieldRef;
    return *this;
}

EnvVarSourceBuilder& EnvVarSourceBuilder::SecretKeyRef(const SecretKeySelector& secretKeyRef)
{
    envVarSource_.SecretKeyRef = secretKeyRef;
    return *this;
}

EnvVarSource EnvVarSourceBuilder::Build()
{
    return std::move(envVarSource_);
}

EnvVarBuilder& EnvVarBuilder::Name(const std::string& name)
{
    envVar_.Name = name;
    return *this;
}

EnvVarBuilder& EnvVarBuilder::Value(const std::string& value)
{
    envVar_.Value = value;
    return *this;
}

EnvVarBuilder& EnvVarBuilder::ValueFrom(const EnvVarSource& valueFrom)
{
    envVar_.ValueFrom = valueFrom;
    return *this;
}

EnvVar EnvVarBuilder::Build()
{
    return std::move(envVar_);
}

SecretEnvSourceBuilder& SecretEnvSourceBuilder::Name(const std::string& name)
{
    secretEnvSource_.Name = name;
    return *this;
}

SecretEnvSourceBuilder& SecretEnvSourceBuilder::Optional(bool optional)
{
    secretEnvSource_.Optional = optional;
    return *this;
}

SecretEnvSource SecretEnvSourceBuilder::Build()
{
    return std::move(secretEnvSource_);
}

ConfigMapEnvSourceBuilder& ConfigMapEnvSourceBuilder::Name(const std::string& name)
{
    configMapEnvSource_.Name = name;
    return *this;
}

ConfigMapEnvSourceBuilder& ConfigMapEnvSourceBuilder::Optional(bool optional)
{
    configMapEnvSource_.Optional = optional;
    return *this;
}

ConfigMapEnvSource ConfigMapEnvSourceBuilder::Build()
{
    return std::move(configMapEnvSource_);
}

EnvFromSourceBuilder& EnvFromSourceBuilder::ConfigMapRef(const ConfigMapEnvSource& configMapRef)
{
    envFromSource_.ConfigMapRef = configMapRef;
    return *this;
}

EnvFromSourceBuilder& EnvFromSourceBuilder::Prefix(const std::string& prefix)
{
    envFromSource_.Prefix = prefix;
    return *this;
}

EnvFromSourceBuilder& EnvFromSourceBuilder::SecretRef(const SecretEnvSource& secretRef)
{
    envFromSource_.SecretRef = secretRef;
    return *this;
}

EnvFromSource EnvFromSourceBuilder::Build()
{
    return std::move(envFromSource_);
}

VolumeMountBuilder& VolumeMountBuilder::MountPath(const std::string& mountPath)
{
    volumeMount_.MountPath = mountPath;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::Name(const std::string& name)
{
    volumeMount_.Name = name;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::MountPropagation(const std::string& mountPropagation)
{
    volumeMount_.MountPropagation = mountPropagation;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::ReadOnly(bool readOnly)
{
    volumeMount_.ReadOnly = readOnly;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::RecursiveReadOnly(const std::string& recursiveReadOnly)
{
    volumeMount_.RecursiveReadOnly = recursiveReadOnly;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::SubPath(const std::string& subPath)
{
    volumeMount_.SubPath = subPath;
    return *this;
}

VolumeMountBuilder& VolumeMountBuilder::SubPathExpr(const std::string& subPathExpr)
{
    volumeMount_.SubPathExpr = subPathExpr;
    return *this;
}

VolumeMount VolumeMountBuilder::Build()
{
    return std::move(volumeMount_);
}

VolumeDeviceBuilder& VolumeDeviceBuilder::DevicePath(const std::string& devicePath)
{
    volumeDevice_.DevicePath = devicePath;
    return *this;
}

VolumeDeviceBuilder& VolumeDeviceBuilder::Name(const std::string& name)
{
    volumeDevice_.Name = name;
    return *this;
}

VolumeDevice VolumeDeviceBuilder::Build()
{
    return std::move(volumeDevice_);
}

ContainerResizePolicyBuilder& ContainerResizePolicyBuilder::ResourceName(const std::string& resourceName)
{
    containerResizePolicy_.ResourceName = resourceName;
    return *this;
}

ContainerResizePolicyBuilder& ContainerResizePolicyBuilder::RestartPolicy(const std::string& restartPolicy)
{
    containerResizePolicy_.RestartPolicy = restartPolicy;
    return *this;
}

ContainerResizePolicy ContainerResizePolicyBuilder::Build()
{
    return std::move(containerResizePolicy_);
}

LifecycleBuilder& LifecycleBuilder::PostStart(const container::LifecycleHandler& postStart)
{
    lifecycle_.PostStart = postStart;
    return *this;
}

LifecycleBuilder& LifecycleBuilder::PreStop(const container::LifecycleHandler& preStop)
{
    lifecycle_.PreStop = preStop;
    return *this;
}

LifecycleType LifecycleBuilder::Build()
{
    return std::move(lifecycle_);
}

} // namespace kubecpp::model::internal::pod
