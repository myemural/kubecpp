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

#ifndef POD_STATUS_H_
#define POD_STATUS_H_

#include <unordered_map>
#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/resource_requirements.h"
#include "kubecpp/model/internal/pod/status/host_ip.h"
#include "kubecpp/model/internal/pod/status/pod_ip.h"
#include "kubecpp/model/internal/pod/status/pod_condition.h"
#include "kubecpp/model/internal/pod/status/pod_resource_claim_status.h"

namespace kubecpp::model::internal::pod
{

struct ResourceHealth
{
    Checked<std::string> ResourceID{ "resourceID", true, "description" };
    Checked<std::string> Health{ "health", true, "description" };
};

struct ResourceStatus
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::vector<ResourceHealth>> Resources{ "resources", true, "description" };
};

struct ContainerStateRunning
{
    Checked<std::string> StartedAt{ "startedAt", true, "description" }; // Time
};

struct ContainerStateTerminated
{
    Checked<std::string> ContainerID{ "containerID", true, "description" };
    Checked<std::string> ExitCode{ "exitCode", true, "description" };
    Checked<std::string> StartedAt{ "startedAt", true, "description" };   // Time
    Checked<std::string> FinishedAt{ "finishedAt", true, "description" }; // Time
    Checked<std::string> Message{ "message", true, "description" };
    Checked<std::string> Reason{ "reason", true, "description" };
    Checked<int32_t> Signal{ "signal", true, "description" };
};

struct ContainerStateWaiting
{
    Checked<std::string> Message{ "message", true, "description" };
    Checked<std::string> Reason{ "reason", true, "description" };
};

struct ContainerState
{
    Checked<ContainerStateRunning> Running{ "running", true, "description" };
    Checked<ContainerStateTerminated> Terminated{ "terminated", true, "description" };
    Checked<ContainerStateWaiting> Waiting{ "Waiting", true, "description" };
};

struct LinuxContainerUser
{
    Checked<int64_t> Gid{ "gid", true, "description" };
    Checked<int64_t> Uid{ "uid", true, "description" };
    Checked<std::vector<int64_t>> SupplementalGroups{ "supplementalGroups", true, "description" };
};

struct ContainerUser
{
    Checked<LinuxContainerUser> Linux{ "linux", true, "description" };
};

struct VolumeMountStatus
{
    Checked<std::string> MountPath{ "mountPath", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", true, "description" };
    Checked<std::string> RecursiveReadOnly{ "recursiveReadOnly", true, "description" };
};

struct ContainerStatus
{
    Checked<std::unordered_map<std::string, std::string>> AllocatedResources{ "allocatedResources", true, "description" }; // Quantity
    Checked<std::vector<ResourceStatus>> AllocatedResourcesStatus{ "allocatedResourcesStatus", true, "description" };
    Checked<std::string> ContainerID{ "containerID", true, "description" };
    Checked<std::string> Image{ "image", true, "description" };
    Checked<std::string> ImageID{ "imageID", true, "description" };
    Checked<ContainerState> LastState{ "lastState", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };
    Checked<bool> Ready{ "ready", true, "description" };
    Checked<common::ResourceRequirements> Resources{ "resources", true, "description" };
    Checked<int32_t> RestartCount{ "restartCount", true, "description" };
    Checked<bool> Started{ "started", true, "description" };
    Checked<ContainerState> State{ "state", true, "description" };
    Checked<ContainerUser> User{ "user", true, "description" };
    Checked<std::vector<VolumeMountStatus>> VolumeMounts{ "volumeMounts", true, "description" };
};

struct PodStatus
{
    Checked<std::string> NominatedNodeName{ "nominatedNodeName", true, "description" };
    Checked<std::string> HostIp{ "hostIP", true, "description" };
    Checked<std::vector<status::HostIP>> HostIPs{ "hostIPs", true, "description" };
    Checked<std::string> StartTime{ "startTime", true, "description" }; // Time
    Checked<std::string> Phase{ "phase", true, "description" };
    Checked<std::string> Message{ "message", true, "description" };
    Checked<std::string> Reason{ "reason", true, "description" };
    Checked<std::string> PodIp{ "podIP", true, "description" };
    Checked<std::vector<status::PodIP>> PodIPs{ "podIPs", true, "description" };
    Checked<std::vector<status::PodCondition>> Conditions{ "conditions", true, "description" };
    Checked<std::string> QosClass{ "qosClass", true, "description" };
    Checked<std::vector<ContainerStatus>> InitContainerStatuses{ "InitContainerStatuses", true, "description" };
    Checked<std::vector<ContainerStatus>> ContainerStatuses{ "containerStatuses", true, "description" };
    Checked<std::vector<ContainerStatus>> EphemeralContainerStatuses{ "ephemeralContainerStatuses", true, "description" };
    Checked<std::vector<status::PodResourceClaimStatus>> ResourceClaimStatuses{ "resourceClaimStatuses", true, "description" };
    Checked<std::string> Resize{ "resize", true, "description" };

    static PodStatus ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::pod

#endif // POD_STATUS_H_