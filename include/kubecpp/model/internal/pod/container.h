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
#include "kubecpp/model/internal/common/object_field_selector.h"
#include "kubecpp/model/internal/common/resource_field_selector.h"
#include "kubecpp/model/internal/common/resource_requirements.h"
#include "kubecpp/model/internal/pod/container/lifecycle_handler.h"
#include "kubecpp/model/internal/pod/container/probe.h"
#include "kubecpp/model/internal/pod/container/security_context.h"

namespace kubecpp::model::internal::pod
{

struct ContainerPortType
{
    Checked<int32_t> ContainerPort{ "containerPort", true, "description" };
    Checked<std::string> HostIP{ "hostIP", false, "description" };
    Checked<int32_t> HostPort{ "hostPort", false, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<std::string> Protocol{ "protocol", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ContainerPortType ParseFromJson(const std::string& jsonData);
};

struct SecretKeySelector
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static SecretKeySelector ParseFromJson(const std::string& jsonData);
};

struct ConfigMapKeySelector
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ConfigMapKeySelector ParseFromJson(const std::string& jsonData);
};

struct EnvVarSource
{
    Checked<ConfigMapKeySelector> ConfigMapKeyRef{ "configMapKeyRef", false, "description" };
    Checked<common::ObjectFieldSelector> FieldRef{ "fieldRef", false, "description" };
    Checked<common::ResourceFieldSelector> ResourceFieldRef{ "resourceFieldRef", false, "description" };
    Checked<SecretKeySelector> SecretKeyRef{ "secretKeyRef", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static EnvVarSource ParseFromJson(const std::string& jsonData);
};

struct EnvVar
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Value{ "value", false, "description" };
    Checked<EnvVarSource> ValueFrom{ "valueFrom", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static EnvVar ParseFromJson(const std::string& jsonData);
};

struct SecretEnvSource
{
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static SecretEnvSource ParseFromJson(const std::string& jsonData);
};

struct ConfigMapEnvSource
{
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ConfigMapEnvSource ParseFromJson(const std::string& jsonData);
};

struct EnvFromSource
{
    Checked<ConfigMapEnvSource> ConfigMapRef{ "configMapRef", false, "description" };
    Checked<std::string> Prefix{ "prefix", false, "description" };
    Checked<SecretEnvSource> SecretRef{ "secretRef", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static EnvFromSource ParseFromJson(const std::string& jsonData);
};

struct VolumeMount
{
    Checked<std::string> MountPath{ "mountPath", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> MountPropagation{ "mountPropagation", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<std::string> RecursiveReadOnly{ "recursiveReadOnly", false, "description" };
    Checked<std::string> SubPath{ "subPath", false, "description" };
    Checked<std::string> SubPathExpr{ "subPathExpr", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static VolumeMount ParseFromJson(const std::string& jsonData);
};

struct VolumeDevice
{
    Checked<std::string> DevicePath{ "devicePath", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static VolumeDevice ParseFromJson(const std::string& jsonData);
};

struct ContainerResizePolicy
{
    Checked<std::string> ResourceName{ "resourceName", true, "description" };
    Checked<std::string> RestartPolicy{ "restartPolicy", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ContainerResizePolicy ParseFromJson(const std::string& jsonData);
};

struct LifecycleType
{
    Checked<container::LifecycleHandler> PostStart{ "postStart", false, "description" };
    Checked<container::LifecycleHandler> PreStop{ "preStop", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static LifecycleType ParseFromJson(const std::string& jsonData);
};

struct Container
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Image{ "image", false, "description" };
    Checked<std::string> ImagePullPolicy{ "imagePullPolicy", false, "description" };
    Checked<std::vector<std::string>> Command{ "command", false, "description" };
    Checked<std::vector<std::string>> Args{ "args", false, "description" };
    Checked<std::string> WorkingDir{ "workingDir", false, "description" };
    Checked<std::vector<ContainerPortType>> Ports{ "ports", false, "description" };
    Checked<std::vector<EnvVar>> Env{ "env", false, "description" };
    Checked<std::vector<EnvFromSource>> EnvFrom{ "envFrom", false, "description" };
    Checked<std::vector<VolumeMount>> VolumeMounts{ "volumeMounts", false, "description" };
    Checked<std::vector<VolumeDevice>> VolumeDevices{ "volumeDevices", false, "description" };
    Checked<common::ResourceRequirements> Resources{ "resources", false, "description" };
    Checked<std::vector<ContainerResizePolicy>> ResizePolicy{ "resizePolicy", false, "description" };
    Checked<LifecycleType> Lifecycle{ "lifecycle", false, "description" };
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
    static Container ParseFromJson(const std::string& jsonData);
};

struct EphemeralContainer
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> TargetContainerName{ "targetContainerName", true, "description" };
    Checked<std::string> Image{ "image", false, "description" };
    Checked<std::string> ImagePullPolicy{ "imagePullPolicy", false, "description" };
    Checked<std::vector<std::string>> Command{ "command", false, "description" };
    Checked<std::vector<std::string>> Args{ "args", false, "description" };
    Checked<std::string> WorkingDir{ "workingDir", false, "description" };
    Checked<std::vector<EnvVar>> Env{ "env", false, "description" };
    Checked<std::vector<EnvFromSource>> EnvFrom{ "envFrom", false, "description" };
    Checked<std::vector<VolumeMount>> VolumeMounts{ "volumeMounts", false, "description" };
    Checked<std::vector<VolumeDevice>> VolumeDevices{ "volumeDevices", false, "description" };
    Checked<std::vector<ContainerResizePolicy>> ResizePolicy{ "resizePolicy", false, "description" };
    Checked<std::string> TerminationMessagePath{ "terminationMessagePath", false, "description" };
    Checked<std::string> TerminationMessagePolicy{ "terminationMessagePolicy", false, "description" };
    Checked<std::string> RestartPolicy{ "restartPolicy", false, "description" };
    Checked<bool> Stdin{ "stdin", false, "description" };
    Checked<bool> StdinOnce{ "stdinOnce", false, "description" };
    Checked<bool> Tty{ "tty", false, "description" };
    Checked<container::SecurityContext> SecurityContext{ "securityContext", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static EphemeralContainer ParseFromJson(const std::string& jsonData);
};

struct ContainerBuilder
{
    ContainerBuilder& Name(const std::string& name);

    ContainerBuilder& Image(const std::string& image);

    ContainerBuilder& ImagePullPolicy(const std::string& imagePullPolicy);

    ContainerBuilder& Command(const std::vector<std::string>& command);

    ContainerBuilder& Args(const std::vector<std::string>& args);

    ContainerBuilder& WorkingDir(const std::string& workingDir);

    ContainerBuilder& Ports(const std::vector<ContainerPortType>& ports);

    ContainerBuilder& Env(const std::vector<EnvVar>& env);

    ContainerBuilder& EnvFrom(const std::vector<EnvFromSource>& envFrom);

    ContainerBuilder& VolumeMounts(const std::vector<VolumeMount>& volumeMounts);

    ContainerBuilder& VolumeDevices(const std::vector<VolumeDevice>& volumeDevices);

    ContainerBuilder& Resources(const common::ResourceRequirements& resources);

    ContainerBuilder& ResizePolicy(const std::vector<ContainerResizePolicy>& resizePolicy);

    ContainerBuilder& Lifecycle(const LifecycleType& lifecycle);

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

struct EphemeralContainerBuilder
{
    EphemeralContainerBuilder& Name(const std::string& name);

    EphemeralContainerBuilder& TargetContainerName(const std::string& targetContainerName);

    EphemeralContainerBuilder& Image(const std::string& image);

    EphemeralContainerBuilder& ImagePullPolicy(const std::string& imagePullPolicy);

    EphemeralContainerBuilder& Command(const std::vector<std::string>& command);

    EphemeralContainerBuilder& Args(const std::vector<std::string>& args);

    EphemeralContainerBuilder& WorkingDir(const std::string& workingDir);

    EphemeralContainerBuilder& Env(const std::vector<EnvVar>& env);

    EphemeralContainerBuilder& EnvFrom(const std::vector<EnvFromSource>& envFrom);

    EphemeralContainerBuilder& VolumeMounts(const std::vector<VolumeMount>& volumeMounts);

    EphemeralContainerBuilder& VolumeDevices(const std::vector<VolumeDevice>& volumeDevices);

    EphemeralContainerBuilder& ResizePolicy(const std::vector<ContainerResizePolicy>& resizePolicy);

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

struct ContainerPortBuilder
{
    ContainerPortBuilder& ContainerPort(int32_t containerPort);

    ContainerPortBuilder& HostIP(const std::string& hostIP);

    ContainerPortBuilder& HostPort(int32_t hostPort);

    ContainerPortBuilder& Name(const std::string& name);

    ContainerPortBuilder& Protocol(const std::string& protocol);

    ContainerPortType Build();

private:
    ContainerPortType containerPortType_;
};

struct SecretKeySelectorBuilder
{
    SecretKeySelectorBuilder& Key(const std::string& key);

    SecretKeySelectorBuilder& Name(const std::string& name);

    SecretKeySelectorBuilder& Optional(bool optional);

    SecretKeySelector Build();

private:
    SecretKeySelector secretKeySelector_;
};

struct ConfigMapKeySelectorBuilder
{
    ConfigMapKeySelectorBuilder& Key(const std::string& key);

    ConfigMapKeySelectorBuilder& Name(const std::string& name);

    ConfigMapKeySelectorBuilder& Optional(bool optional);

    ConfigMapKeySelector Build();

private:
    ConfigMapKeySelector configMapKeySelector_;
};

struct EnvVarSourceBuilder
{
    EnvVarSourceBuilder& ConfigMapKeyRef(const ConfigMapKeySelector& configMapKeyRef);

    EnvVarSourceBuilder& FieldRef(const common::ObjectFieldSelector& fieldRef);

    EnvVarSourceBuilder& ResourceFieldRef(const common::ResourceFieldSelector& resourceFieldRef);

    EnvVarSourceBuilder& SecretKeyRef(const SecretKeySelector& secretKeyRef);

    EnvVarSource Build();

private:
    EnvVarSource envVarSource_;
};

struct EnvVarBuilder
{
    EnvVarBuilder& Name(const std::string& name);

    EnvVarBuilder& Value(const std::string& value);

    EnvVarBuilder& ValueFrom(const EnvVarSource& valueFrom);

    EnvVar Build();

private:
    EnvVar envVar_;
};

struct VolumeMountBuilder
{
    VolumeMountBuilder& MountPath(const std::string& mountPath);

    VolumeMountBuilder& Name(const std::string& name);

    VolumeMountBuilder& MountPropagation(const std::string& mountPropagation);

    VolumeMountBuilder& ReadOnly(bool readOnly);

    VolumeMountBuilder& RecursiveReadOnly(const std::string& recursiveReadOnly);

    VolumeMountBuilder& SubPath(const std::string& subPath);

    VolumeMountBuilder& SubPathExpr(const std::string& subPathExpr);

    VolumeMount Build();

private:
    VolumeMount volumeMount_;
};

struct VolumeDeviceBuilder
{
    VolumeDeviceBuilder& DevicePath(const std::string& devicePath);

    VolumeDeviceBuilder& Name(const std::string& name);

    VolumeDevice Build();

private:
    VolumeDevice volumeDevice_;
};

struct ContainerResizePolicyBuilder
{
    ContainerResizePolicyBuilder& ResourceName(const std::string& resourceName);

    ContainerResizePolicyBuilder& RestartPolicy(const std::string& restartPolicy);

    ContainerResizePolicy Build();

private:
    ContainerResizePolicy containerResizePolicy_;
};

struct LifecycleBuilder
{
    LifecycleBuilder& PostStart(const container::LifecycleHandler& postStart);

    LifecycleBuilder& PreStop(const container::LifecycleHandler& preStop);

    LifecycleType Build();

private:
    LifecycleType lifecycle_;
};

} // namespace kubecpp::model::internal::pod

#endif // CONTAINER_H_