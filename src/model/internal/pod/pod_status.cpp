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

#include "kubecpp/model/internal/pod/pod_status.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

HostIP HostIP::ParseFromJson(const std::string& jsonData)
{
    HostIP result;
    ParseFieldsFromJson(jsonData, result.Ip);
    return result;
}

PodIP PodIP::ParseFromJson(const std::string& jsonData)
{
    PodIP result;
    ParseFieldsFromJson(jsonData, result.Ip);
    return result;
}

PodCondition PodCondition::ParseFromJson(const std::string& jsonData)
{
    PodCondition result;
    ParseFieldsFromJson(jsonData, result.Status, result.Type, result.LastProbeTime, result.LastTransitionTime,
    result.Message, result.Reason);
    return result;
}

ResourceHealth ResourceHealth::ParseFromJson(const std::string& jsonData)
{
    ResourceHealth result;
    ParseFieldsFromJson(jsonData, result.ResourceID, result.Health);
    return result;
}

ResourceStatus ResourceStatus::ParseFromJson(const std::string& jsonData)
{
    ResourceStatus result;
    ParseFieldsFromJson(jsonData, result.Name, result.Resources);
    return result;
}

ContainerStateRunning ContainerStateRunning::ParseFromJson(const std::string& jsonData)
{
    ContainerStateRunning result;
    ParseFieldsFromJson(jsonData, result.StartedAt);
    return result;
}

ContainerStateTerminated ContainerStateTerminated::ParseFromJson(const std::string& jsonData)
{
    ContainerStateTerminated result;
    ParseFieldsFromJson(jsonData, result.ContainerID, result.ExitCode, result.StartedAt, result.FinishedAt,
    result.Message, result.Reason, result.Signal);
    return result;
}

ContainerStateWaiting ContainerStateWaiting::ParseFromJson(const std::string& jsonData)
{
    ContainerStateWaiting result;
    ParseFieldsFromJson(jsonData, result.Message, result.Reason);
    return result;
}

ContainerState ContainerState::ParseFromJson(const std::string& jsonData)
{
    ContainerState result;
    ParseFieldsFromJson(jsonData, result.Running, result.Terminated, result.Waiting);
    return result;
}

LinuxContainerUser LinuxContainerUser::ParseFromJson(const std::string& jsonData)
{
    LinuxContainerUser result;
    ParseFieldsFromJson(jsonData, result.Gid, result.Uid, result.SupplementalGroups);
    return result;
}

ContainerUser ContainerUser::ParseFromJson(const std::string& jsonData)
{
    ContainerUser result;
    ParseFieldsFromJson(jsonData, result.Linux);
    return result;
}

VolumeMountStatus VolumeMountStatus::ParseFromJson(const std::string& jsonData)
{
    VolumeMountStatus result;
    ParseFieldsFromJson(jsonData, result.MountPath, result.Name, result.ReadOnly, result.RecursiveReadOnly);
    return result;
}

ContainerStatus ContainerStatus::ParseFromJson(const std::string& jsonData)
{
    ContainerStatus result;
    ParseFieldsFromJson(jsonData, result.AllocatedResources, result.AllocatedResourcesStatus, result.ContainerID,
    result.Image, result.ImageID, result.LastState, result.Name, result.Ready, result.Resources, result.RestartCount,
    result.Started, result.State, result.User, result.VolumeMounts);
    return result;
}

PodResourceClaimStatus PodResourceClaimStatus::ParseFromJson(const std::string& jsonData)
{
    PodResourceClaimStatus result;
    ParseFieldsFromJson(jsonData, result.Name, result.ResourceClaimName);
    return result;
}

PodStatus PodStatus::ParseFromJson(const std::string& jsonData)
{
    PodStatus result;
    ParseFieldsFromJson(jsonData, result.NominatedNodeName, result.HostIp, result.HostIPs, result.StartTime, result.Phase,
    result.Message, result.Reason, result.PodIp, result.PodIPs, result.Conditions, result.QosClass, result.InitContainerStatuses,
    result.ContainerStatuses, result.EphemeralContainerStatuses, result.ResourceClaimStatuses, result.Resize);
    return result;
}

} // namespace kubecpp::model::internal::pod