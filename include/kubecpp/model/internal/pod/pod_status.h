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

namespace kubecpp::model::internal::pod
{

struct HostIP
{
    Checked<std::string> Ip{ "ip", true, "description" };

    static HostIP ParseFromJson(const std::string& jsonData);
};

struct PodIP
{
    Checked<std::string> Ip{ "ip", true, "description" };

    static PodIP ParseFromJson(const std::string& jsonData);
};

struct PodCondition
{
    Checked<std::string> Status{ "status", true, "description" };
    Checked<std::string> Type{ "type", true, "description" };
    Checked<std::string> LastProbeTime{ "lastProbeTime", false, "description" };           // Time
    Checked<std::string> LastTransitionTime{ "lastTransitionTime", false, "description" }; // Time
    Checked<std::string> Message{ "message", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };

    static PodCondition ParseFromJson(const std::string& jsonData);
};

struct ResourceHealth
{
    Checked<std::string> ResourceID{ "resourceID", true, "description" };
    Checked<std::string> Health{ "health", false, "description" };

    static ResourceHealth ParseFromJson(const std::string& jsonData);
};

struct ResourceStatus
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::vector<ResourceHealth>> Resources{ "resources", false, "description" };

    static ResourceStatus ParseFromJson(const std::string& jsonData);
};

struct ContainerStateRunning
{
    Checked<std::string> StartedAt{ "startedAt", false, "description" }; // Time

    static ContainerStateRunning ParseFromJson(const std::string& jsonData);
};

struct ContainerStateTerminated
{
    Checked<std::string> ContainerID{ "containerID", false, "description" };
    Checked<std::string> ExitCode{ "exitCode", false, "description" };
    Checked<std::string> StartedAt{ "startedAt", false, "description" };   // Time
    Checked<std::string> FinishedAt{ "finishedAt", false, "description" }; // Time
    Checked<std::string> Message{ "message", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };
    Checked<int32_t> Signal{ "signal", false, "description" };

    static ContainerStateTerminated ParseFromJson(const std::string& jsonData);
};

struct ContainerStateWaiting
{
    Checked<std::string> Message{ "message", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };

    static ContainerStateWaiting ParseFromJson(const std::string& jsonData);
};

struct ContainerState
{
    Checked<ContainerStateRunning> Running{ "running", false, "description" };
    Checked<ContainerStateTerminated> Terminated{ "terminated", false, "description" };
    Checked<ContainerStateWaiting> Waiting{ "Waiting", false, "description" };

    static ContainerState ParseFromJson(const std::string& jsonData);
};

struct LinuxContainerUser
{
    Checked<int64_t> Gid{ "gid", true, "description" };
    Checked<int64_t> Uid{ "uid", true, "description" };
    Checked<std::vector<int64_t>> SupplementalGroups{ "supplementalGroups", false, "description" };

    static LinuxContainerUser ParseFromJson(const std::string& jsonData);
};

struct ContainerUser
{
    Checked<LinuxContainerUser> Linux{ "linux", false, "description" };

    static ContainerUser ParseFromJson(const std::string& jsonData);
};

struct VolumeMountStatus
{
    Checked<std::string> MountPath{ "mountPath", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<std::string> RecursiveReadOnly{ "recursiveReadOnly", false, "description" };

    static VolumeMountStatus ParseFromJson(const std::string& jsonData);
};

struct ContainerStatus
{
    Checked<std::unordered_map<std::string, std::string>> AllocatedResources{ "allocatedResources", false, "description" }; // Quantity
    Checked<std::vector<ResourceStatus>> AllocatedResourcesStatus{ "allocatedResourcesStatus", false, "description" };
    Checked<std::string> ContainerID{ "containerID", false, "description" };
    Checked<std::string> Image{ "image", false, "description" };
    Checked<std::string> ImageID{ "imageID", false, "description" };
    Checked<ContainerState> LastState{ "lastState", false, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Ready{ "ready", false, "description" };
    Checked<common::ResourceRequirements> Resources{ "resources", false, "description" };
    Checked<int32_t> RestartCount{ "restartCount", false, "description" };
    Checked<bool> Started{ "started", false, "description" };
    Checked<ContainerState> State{ "state", false, "description" };
    Checked<ContainerUser> User{ "user", false, "description" };
    Checked<std::vector<VolumeMountStatus>> VolumeMounts{ "volumeMounts", false, "description" };

    static ContainerStatus ParseFromJson(const std::string& jsonData);
};

struct PodResourceClaimStatus
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> ResourceClaimName{ "resourceClaimName", false, "description" };

    static PodResourceClaimStatus ParseFromJson(const std::string& jsonData);
};

struct PodStatus
{
    Checked<std::string> NominatedNodeName{ "nominatedNodeName", false, "description" };
    Checked<std::string> HostIp{ "hostIP", false, "description" };
    Checked<std::vector<HostIP>> HostIPs{ "hostIPs", false, "description" };
    Checked<std::string> StartTime{ "startTime", false, "description" }; // Time
    Checked<std::string> Phase{ "phase", false, "description" };
    Checked<std::string> Message{ "message", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };
    Checked<std::string> PodIp{ "podIP", false, "description" };
    Checked<std::vector<PodIP>> PodIPs{ "podIPs", false, "description" };
    Checked<std::vector<PodCondition>> Conditions{ "conditions", false, "description" };
    Checked<std::string> QosClass{ "qosClass", false, "description" };
    Checked<std::vector<ContainerStatus>> InitContainerStatuses{ "InitContainerStatuses", false, "description" };
    Checked<std::vector<ContainerStatus>> ContainerStatuses{ "containerStatuses", false, "description" };
    Checked<std::vector<ContainerStatus>> EphemeralContainerStatuses{ "ephemeralContainerStatuses", false, "description" };
    Checked<std::vector<PodResourceClaimStatus>> ResourceClaimStatuses{ "resourceClaimStatuses", false, "description" };
    Checked<std::string> Resize{ "resize", false, "description" };

    static PodStatus ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::pod

#endif // POD_STATUS_H_