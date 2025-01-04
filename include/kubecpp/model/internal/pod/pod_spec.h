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

#ifndef POD_SPEC_H_
#define POD_SPEC_H_

#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/common/json_utils.h"
#include "kubecpp/model/internal/common/local_object_reference.h"
#include "kubecpp/model/internal/common/volume.h"
#include "kubecpp/model/internal/pod/affinity.h"
#include "kubecpp/model/internal/pod/container.h"
#include "kubecpp/model/internal/pod/ephemeral_container.h"
#include "kubecpp/model/internal/pod/host_alias.h"
#include "kubecpp/model/internal/pod/pod_dns_config.h"
#include "kubecpp/model/internal/pod/pod_readiness_gate.h"
#include "kubecpp/model/internal/pod/pod_resource_claim.h"
#include "kubecpp/model/internal/pod/pod_scheduling_gate.h"
#include "kubecpp/model/internal/pod/pod_security_context.h"
#include "kubecpp/model/internal/pod/toleration.h"
#include "kubecpp/model/internal/pod/topology_spread_constraint.h"

namespace kubecpp::model::internal::pod
{

struct PodOs
{
    Checked<std::string> Name{ "name", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PodSpec
{
    Checked<std::vector<Container>> Containers{ "containers", true, "description" };
    Checked<std::vector<Container>> InitContainers{ "initContainers", false, "description" };
    Checked<std::vector<EphemeralContainer>> EphemeralContainers{ "ephemeralContainers", false, "description" };
    Checked<std::vector<common::LocalObjectReference>> ImagePullSecrets{ "imagePullSecrets", false, "description" };
    Checked<bool> EnableServiceLinks{ "enableServiceLinks", false, "description" };
    Checked<PodOs> Os{ "os", false, "description" };
    Checked<std::vector<common::Volume>> Volumes{ "volumes", false, "description" };
    Checked<std::map<std::string, std::string>> NodeSelector{ "nodeSelector", false, "description" };
    Checked<std::string> NodeName{ "nodeName", false, "description" };
    Checked<AffinityType> Affinity{ "affinity", false, "description" };
    Checked<std::vector<Toleration>> Tolerations{ "tolerations", false, "description" };
    Checked<std::string> SchedulerName{ "schedulerName", false, "description" };
    Checked<std::string> RuntimeClassName{ "runtimeClassName", false, "description" };
    Checked<std::string> PriorityClassName{ "priorityClassName", false, "description" };
    Checked<int32_t> Priority{ "priority", false, "description" };
    Checked<std::string> PreemptionPolicy{ "preemptionPolicy", false, "description" };
    Checked<std::vector<TopologySpreadConstraint>> TopologySpreadConstraints{ "topologySpreadConstraints", false, "description" };
    Checked<std::map<std::string, std::string>> Overhead{ "overhead", false, "description" }; // Quantity
    Checked<std::string> RestartPolicy{ "restartPolicy", false, "description" };
    Checked<int64_t> TerminationGracePeriodSeconds{ "terminationGracePeriodSeconds", false, "description" };
    Checked<int64_t> ActiveDeadlineSeconds{ "activeDeadlineSeconds", false, "description" };
    Checked<std::vector<PodReadinessGate>> ReadinessGates{ "readinessGates", false, "description" };
    Checked<std::string> Hostname{ "hostname", false, "description" };
    Checked<bool> SetHostnameAsFQDN{ "setHostnameAsFQDN", false, "description" };
    Checked<std::string> Subdomain{ "subdomain", false, "description" };
    Checked<std::vector<HostAlias>> HostAliases{ "hostAliases", false, "description" };
    Checked<PodDNSConfig> DnsConfig{ "dnsConfig", false, "description" };
    Checked<std::string> DnsPolicy{ "dnsPolicy", false, "description" };
    Checked<bool> HostNetwork{ "hostNetwork", false, "description" };
    Checked<bool> HostPID{ "hostPID", false, "description" };
    Checked<bool> HostIPC{ "hostIPC", false, "description" };
    Checked<bool> ShareProcessNamespace{ "shareProcessNamespace", false, "description" };
    Checked<std::string> ServiceAccountName{ "serviceAccountName", false, "description" };
    Checked<bool> AutomountServiceAccountToken{ "automountServiceAccountToken", false, "description" };
    Checked<PodSecurityContext> SecurityContext{ "securityContext", false, "description" };
    Checked<bool> HostUsers{ "hostUsers", false, "description" };
    Checked<std::vector<PodResourceClaim>> ResourceClaims{ "resourceClaims", false, "description" };
    Checked<std::vector<PodSchedulingGate>> SchedulingGates{ "schedulingGates", false, "description" };
    Checked<std::string> ServiceAccount{ "serviceAccount", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PodOsBuilder
{
    PodOsBuilder& Name(const std::string& name);

    PodOs Build();

private:
    PodOs podOs_;
};

struct PodSpecBuilder
{
    PodSpecBuilder& Containers(const std::vector<Container>& containers);

    PodSpecBuilder& InitContainers(const std::vector<Container>& initContainers);

    PodSpecBuilder& EphemeralContainers(const std::vector<EphemeralContainer>& ephemeralContainers);

    PodSpecBuilder& ImagePullSecrets(const std::vector<common::LocalObjectReference>& imagePullSecrets);

    PodSpecBuilder& EnableServiceLinks(bool enableServiceLinks);

    PodSpecBuilder& Os(const PodOs& podOs);

    PodSpecBuilder& Volumes(const std::vector<common::Volume>& volumes);

    PodSpecBuilder& NodeSelector(const std::map<std::string, std::string>& nodeSelector);

    PodSpecBuilder& NodeName(const std::string& nodeName);

    PodSpecBuilder& Affinity(const AffinityType& affinity);

    PodSpecBuilder& Tolerations(const std::vector<Toleration>& tolerations);

    PodSpecBuilder& SchedulerName(const std::string& schedulerName);

    PodSpecBuilder& RuntimeClassName(const std::string& runtimeClassName);

    PodSpecBuilder& PriorityClassName(const std::string& priorityClassName);

    PodSpecBuilder& Priority(int32_t priority);

    PodSpecBuilder& PreemptionPolicy(const std::string& preemptionPolicy);

    PodSpecBuilder& TopologySpreadConstraints(const std::vector<TopologySpreadConstraint>& topologySpreadConstraints);

    PodSpecBuilder& Overhead(const std::map<std::string, std::string>& overhead);

    PodSpecBuilder& RestartPolicy(const std::string& restartPolicy);

    PodSpecBuilder& TerminationGracePeriodSeconds(int64_t terminationGracePeriodSeconds);

    PodSpecBuilder& ActiveDeadlineSeconds(int64_t activeDeadlineSeconds);

    PodSpecBuilder& ReadinessGates(const std::vector<PodReadinessGate>& readinessGates);

    PodSpecBuilder& Hostname(const std::string& hostname);

    PodSpecBuilder& SetHostnameAsFQDN(bool setHostnameAsFQDN);

    PodSpecBuilder& Subdomain(const std::string& subdomain);

    PodSpecBuilder& HostAliases(const std::vector<HostAlias>& hostAliases);

    PodSpecBuilder& DnsConfig(const PodDNSConfig& dnsConfig);

    PodSpecBuilder& DnsPolicy(const std::string& dnsPolicy);

    PodSpecBuilder& HostNetwork(bool hostNetwork);

    PodSpecBuilder& HostPID(bool hostPID);

    PodSpecBuilder& HostIPC(bool hostIPC);

    PodSpecBuilder& ShareProcessNamespace(bool shareProcessNamespace);

    PodSpecBuilder& ServiceAccountName(const std::string& serviceAccountName);

    PodSpecBuilder& AutomountServiceAccountToken(bool automountServiceAccountToken);

    PodSpecBuilder& SecurityContext(const PodSecurityContext& securityContext);

    PodSpecBuilder& HostUsers(bool hostUsers);

    PodSpecBuilder& ResourceClaims(const std::vector<PodResourceClaim>& resourceClaims);

    PodSpecBuilder& SchedulingGates(const std::vector<PodSchedulingGate>& schedulingGates);

    PodSpecBuilder& ServiceAccount(const std::string& serviceAccount);

    PodSpec Build();

private:
    PodSpec podSpec_;
};

} // namespace kubecpp::model::internal::pod

#endif // POD_SPEC_H_