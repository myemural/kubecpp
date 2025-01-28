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

#include "kubecpp/model/internal/pod/pod_spec.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string PodOs::ParseToJson() const
{
    return ParseFieldsToJson(Name);
}

PodOs PodOs::ParseFromJson(const std::string& jsonData)
{
    PodOs result;
    ParseFieldsFromJson(jsonData, result.Name);
    return result;
}

std::string PodSpec::ParseToJson() const
{
    return ParseFieldsToJson(Containers, InitContainers, EphemeralContainers, ImagePullSecrets, EnableServiceLinks, Os,
    Volumes, NodeSelector, NodeName, Affinity, Tolerations, SchedulerName, RuntimeClassName, PriorityClassName,
    Priority, PreemptionPolicy, TopologySpreadConstraints, Overhead, RestartPolicy, TerminationGracePeriodSeconds,
    ActiveDeadlineSeconds, ReadinessGates, Hostname, SetHostnameAsFQDN, Subdomain, HostAliases, DnsConfig, DnsPolicy,
    HostNetwork, HostPID, HostIPC, ShareProcessNamespace, ServiceAccountName, AutomountServiceAccountToken,
    SecurityContext, HostUsers, ResourceClaims, SchedulingGates, ServiceAccount);
}

PodSpec PodSpec::ParseFromJson(const std::string& jsonData)
{
    PodSpec result;
    ParseFieldsFromJson(jsonData, result.Containers, result.InitContainers, result.EphemeralContainers,
    result.ImagePullSecrets, result.EnableServiceLinks, result.Os, result.Volumes, result.NodeSelector, result.NodeName,
    result.Affinity, result.Tolerations, result.SchedulerName, result.RuntimeClassName, result.PriorityClassName,
    result.Priority, result.PreemptionPolicy, result.TopologySpreadConstraints, result.Overhead, result.RestartPolicy,
    result.TerminationGracePeriodSeconds, result.ActiveDeadlineSeconds, result.ReadinessGates, result.Hostname,
    result.SetHostnameAsFQDN, result.Subdomain, result.HostAliases, result.DnsConfig, result.DnsPolicy, result.HostNetwork,
    result.HostPID, result.HostIPC, result.ShareProcessNamespace, result.ServiceAccountName, result.AutomountServiceAccountToken,
    result.SecurityContext, result.HostUsers, result.ResourceClaims, result.SchedulingGates, result.ServiceAccount);
    return result;
}

PodOsBuilder& PodOsBuilder::Name(const std::string& name)
{
    podOs_.Name = name;
    return *this;
}

PodOs PodOsBuilder::Build()
{
    return std::move(podOs_);
}

PodSpecBuilder& PodSpecBuilder::Containers(const std::vector<Container>& containers)
{
    podSpec_.Containers = containers;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::InitContainers(const std::vector<Container>& initContainers)
{
    podSpec_.InitContainers = initContainers;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::EphemeralContainers(const std::vector<EphemeralContainer>& ephemeralContainers)
{
    podSpec_.EphemeralContainers = ephemeralContainers;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ImagePullSecrets(const std::vector<common::LocalObjectReference>& imagePullSecrets)
{
    podSpec_.ImagePullSecrets = imagePullSecrets;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::EnableServiceLinks(bool enableServiceLinks)
{
    podSpec_.EnableServiceLinks = enableServiceLinks;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Os(const PodOs& podOs)
{
    podSpec_.Os = podOs;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Volumes(const std::vector<common::Volume>& volumes)
{
    podSpec_.Volumes = volumes;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::NodeSelector(const std::unordered_map<std::string, std::string>& nodeSelector)
{
    podSpec_.NodeSelector = nodeSelector;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::NodeName(const std::string& nodeName)
{
    podSpec_.NodeName = nodeName;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Affinity(const AffinityType& affinity)
{
    podSpec_.Affinity = affinity;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Tolerations(const std::vector<Toleration>& tolerations)
{
    podSpec_.Tolerations = tolerations;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::SchedulerName(const std::string& schedulerName)
{
    podSpec_.SchedulerName = schedulerName;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::RuntimeClassName(const std::string& runtimeClassName)
{
    podSpec_.RuntimeClassName = runtimeClassName;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::PriorityClassName(const std::string& priorityClassName)
{
    podSpec_.PriorityClassName = priorityClassName;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Priority(int32_t priority)
{
    podSpec_.Priority = priority;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::PreemptionPolicy(const std::string& preemptionPolicy)
{
    podSpec_.PreemptionPolicy = preemptionPolicy;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::TopologySpreadConstraints(const std::vector<TopologySpreadConstraint>& topologySpreadConstraints)
{
    podSpec_.TopologySpreadConstraints = topologySpreadConstraints;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Overhead(const std::unordered_map<std::string, std::string>& overhead)
{
    podSpec_.Overhead = overhead;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::RestartPolicy(const std::string& restartPolicy)
{
    podSpec_.RestartPolicy = restartPolicy;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::TerminationGracePeriodSeconds(int64_t terminationGracePeriodSeconds)
{
    podSpec_.TerminationGracePeriodSeconds = terminationGracePeriodSeconds;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ActiveDeadlineSeconds(int64_t activeDeadlineSeconds)
{
    podSpec_.ActiveDeadlineSeconds = activeDeadlineSeconds;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ReadinessGates(const std::vector<PodReadinessGate>& readinessGates)
{
    podSpec_.ReadinessGates = readinessGates;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Hostname(const std::string& hostname)
{
    podSpec_.Hostname = hostname;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::SetHostnameAsFQDN(bool setHostnameAsFQDN)
{
    podSpec_.SetHostnameAsFQDN = setHostnameAsFQDN;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::Subdomain(const std::string& subdomain)
{
    podSpec_.Subdomain = subdomain;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::HostAliases(const std::vector<HostAlias>& hostAliases)
{
    podSpec_.HostAliases = hostAliases;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::DnsConfig(const PodDNSConfig& dnsConfig)
{
    podSpec_.DnsConfig = dnsConfig;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::DnsPolicy(const std::string& dnsPolicy)
{
    podSpec_.DnsPolicy = dnsPolicy;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::HostNetwork(bool hostNetwork)
{
    podSpec_.HostNetwork = hostNetwork;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::HostPID(bool hostPID)
{
    podSpec_.HostPID = hostPID;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::HostIPC(bool hostIPC)
{
    podSpec_.HostIPC = hostIPC;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ShareProcessNamespace(bool shareProcessNamespace)
{
    podSpec_.ShareProcessNamespace = shareProcessNamespace;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ServiceAccountName(const std::string& serviceAccountName)
{
    podSpec_.ServiceAccountName = serviceAccountName;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::AutomountServiceAccountToken(bool automountServiceAccountToken)
{
    podSpec_.AutomountServiceAccountToken = automountServiceAccountToken;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::SecurityContext(const PodSecurityContext& securityContext)
{
    podSpec_.SecurityContext = securityContext;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::HostUsers(bool hostUsers)
{
    podSpec_.HostUsers = hostUsers;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ResourceClaims(const std::vector<PodResourceClaim>& resourceClaims)
{
    podSpec_.ResourceClaims = resourceClaims;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::SchedulingGates(const std::vector<PodSchedulingGate>& schedulingGates)
{
    podSpec_.SchedulingGates = schedulingGates;
    return *this;
}

PodSpecBuilder& PodSpecBuilder::ServiceAccount(const std::string& serviceAccount)
{
    podSpec_.ServiceAccount = serviceAccount;
    return *this;
}

PodSpec PodSpecBuilder::Build()
{
    return std::move(podSpec_);
}

} // namespace kubecpp::model::internal::pod
