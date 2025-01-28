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

#ifndef VOLUME_H_
#define VOLUME_H_

#include <cstdint>
#include <map>
#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/local_object_reference.h"
#include "kubecpp/model/internal/common/object_field_selector.h"
#include "kubecpp/model/internal/common/object_meta.h"
#include "kubecpp/model/internal/common/resource_field_selector.h"

namespace kubecpp::model::internal::common
{

/// TODO: This will be implemented in PersistentVolumeClaim.
struct PersistentVolumeClaimSpec
{
};

struct KeyToPath
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Path{ "path", true, "description" };
    Checked<std::int32_t> Mode{ "mode", false, "description" };
};

struct DownwardAPIVolumeFile
{
    Checked<std::string> Path{ "path", true, "description" };
    Checked<ObjectFieldSelector> FieldRef{ "fieldRef", false, "description" };
    Checked<std::int32_t> Mode{ "mode", false, "description" };
    Checked<ResourceFieldSelector> ResourceFieldRef{ "resourceFieldRef", false, "description" };
};

struct PersistentVolumeClaimTemplate
{
    Checked<PersistentVolumeClaimSpec> Spec{ "spec", true, "description" };
    Checked<ObjectMeta> Metadata{ "metadata", false, "description" };
};

struct PersistentVolumeClaimVolumeSource
{
    Checked<std::string> ClaimName{ "claimName", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct ConfigMapVolumeSource
{
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };
    Checked<std::int32_t> DefaultMode{ "defaultMode", false, "description" };
    Checked<std::vector<KeyToPath>> Items{ "items", false, "description" };
};

struct SecretVolumeSource
{
    Checked<std::string> SecretName{ "secretName", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };
    Checked<std::int32_t> DefaultMode{ "defaultMode", false, "description" };
    Checked<std::vector<KeyToPath>> Items{ "items", false, "description" };
};

struct DownwardAPIVolumeSource
{
    Checked<std::int32_t> DefaultMode{ "defaultMode", false, "description" };
    Checked<std::vector<DownwardAPIVolumeFile>> Items{ "items", false, "description" };
};

struct ClusterTrustBundleProjection
{
};

struct ConfigMapProjection
{
};

struct DownwardAPIProjection
{
    Checked<std::vector<DownwardAPIVolumeFile>> Items{ "items", false, "description" };
};

struct SecretProjection
{
};

struct ServiceAccountTokenProjection
{
};

struct VolumeProjection
{
    Checked<ClusterTrustBundleProjection> ClusterTrustBundle{ "clusterTrustBundle", false, "description" };
    Checked<ConfigMapProjection> ConfigMap{ "configMap", false, "description" };
    Checked<DownwardAPIProjection> DownwardAPI{ "downwardAPI", false, "description" };
    Checked<SecretProjection> Secret{ "secret", false, "description" };
    Checked<ServiceAccountTokenProjection> ServiceAccountToken{ "serviceAccountToken", false, "description" };
};

struct ProjectedVolumeSource

{
    Checked<std::int32_t> DefaultMode{ "defaultMode", false, "description" };
    Checked<std::vector<VolumeProjection>> Sources{ "sources", false, "description" };
};

struct EmptyDirVolumeSource
{
    Checked<std::string> Medium{ "medium", false, "description" };
    Checked<std::string> SizeLimit{ "sizeLimit", false, "description" }; // Quantity
};

struct HostPathVolumeSource
{
    Checked<std::string> Path{ "path", true, "description" };
    Checked<std::string> Type{ "type", false, "description" };
};

struct AWSElasticBlockStoreVolumeSource
{
    Checked<std::string> VolumeID{ "volumeID", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::int32_t> Partition{ "partition", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct AzureDiskVolumeSource
{
    Checked<std::string> DiskName{ "diskName", true, "description" };
    Checked<std::string> DiskURI{ "diskURI", true, "description" };
    Checked<std::string> CachingMode{ "cachingMode", false, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::string> Kind{ "kind", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct AzureFileVolumeSource
{
    Checked<std::string> SecretName{ "secretName", true, "description" };
    Checked<std::string> ShareName{ "shareName", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct CephFSVolumeSource
{
    Checked<std::vector<std::string>> Monitors{ "monitors", true, "description" };
    Checked<std::string> Path{ "path", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<std::string> SecretFile{ "secretFile", false, "description" };
    Checked<LocalObjectReference> SecretRef{ "secretRef", false, "description" };
};

struct CinderVolumeSource
{
    Checked<std::string> VolumeID{ "volumeID", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<LocalObjectReference> SecretRef{ "secretRef", false, "description" };
};

struct CSIVolumeSource
{
    Checked<std::string> Driver{ "driver", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<LocalObjectReference> NodePublishSecretRef{ "nodePublishSecretRef", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<std::map<std::string, std::string>> VolumeAttributes{ "volumeAttributes", false, "description" };
};

struct EphemeralVolumeSource
{
    Checked<PersistentVolumeClaimTemplate> VolumeClaimTemplate{ "volumeClaimTemplate", false, "description" };
};

struct FCVolumeSource
{
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::int32_t> Lun{ "lun", false, "description" };
    Checked<bool> readOnly{ "readOnly", false, "description" };
    Checked<std::vector<std::string>> TargetWWNs{ "targetWWNs", false, "description" };
    Checked<std::vector<std::string>> Wwids{ "wwids", false, "description" };
};

struct FlexVolumeSource
{
    Checked<std::string> Driver{ "driver", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::unordered_map<std::string, std::string>> Options{ "options", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<LocalObjectReference> SecretRef{ "secretRef", false, "description" };
};

struct FlockerVolumeSource
{
    Checked<std::string> DatasetName{ "datasetName", false, "description" };
    Checked<std::string> DatasetUUID{ "datasetUUID", false, "description" };
};

struct GCEPersistentDiskVolumeSource
{
    Checked<std::string> PdName{ "pdName", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::int32_t> Partition{ "partition", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct GlusterfsVolumeSource
{
    Checked<std::string> Endpoints{ "endpoints", true, "description" };
    Checked<std::string> Path{ "path", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct ISCSIVolumeSource
{
    Checked<std::string> Iqn{ "iqn", true, "description" };
    Checked<std::int32_t> Lun{ "lun", true, "description" };
    Checked<std::string> TargetPortal{ "targetPortal", true, "description" };
    Checked<bool> ChapAuthDiscovery{ "chapAuthDiscovery", false, "description" };
    Checked<bool> ChapAuthSession{ "chapAuthSession", false, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::string> InitiatorName{ "initiatorName", false, "description" };
    Checked<std::string> IscsiInterface{ "iscsiInterface", false, "description" };
    Checked<std::vector<std::string>> Portals{ "portals", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<LocalObjectReference> SecretRef{ "secretRef", false, "description" };
};

struct ImageVolumeSource
{
    Checked<std::string> PullPolicy{ "pullPolicy", false, "description" };
    Checked<std::string> Reference{ "reference", false, "description" };
};

struct NFSVolumeSource
{
    Checked<std::string> Path{ "path", true, "description" };
    Checked<std::string> Server{ "server", true, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct PhotonPersistentDiskVolumeSource
{
    Checked<std::string> PdID{ "pdID", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
};

struct PortworxVolumeSource
{
    Checked<std::string> VolumeID{ "volumeID", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
};

struct QuobyteVolumeSource
{
    Checked<std::string> Registry{ "registry", true, "description" };
    Checked<std::string> Volume{ "volume", true, "description" };
    Checked<std::string> Group{ "group", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<std::string> Tenant{ "tenant", false, "description" };
    Checked<std::string> User{ "user", false, "description" };
};

struct RBDVolumeSource
{
    Checked<std::string> Image{ "image", true, "description" };
    Checked<std::vector<std::string>> Monitors{ "monitors", true, "description" };
    Checked<std::string> FsType{ "fsType", false, "description" };
    Checked<std::string> Keyring{ "keyring", false, "description" };
    Checked<std::string> Pool{ "pool", false, "description" };
    Checked<bool> ReadOnly{ "readOnly", false, "description" };
    Checked<LocalObjectReference> SecretRef{ "secretRef", false, "description" };
    Checked<std::string> User{ "user", false, "description" };
};

struct ScaleIOVolumeSource
{
};

struct StorageOSVolumeSource
{
};

struct VsphereVirtualDiskVolumeSource
{
};

struct GitRepoVolumeSource
{
};

struct Volume
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<PersistentVolumeClaimVolumeSource> PersistentVolumeClaim{ "persistentVolumeClaim", false, "description" };
    Checked<ConfigMapVolumeSource> ConfigMap{ "configMap", false, "description" };
    Checked<SecretVolumeSource> Secret{ "secret", false, "description" };
    Checked<DownwardAPIVolumeSource> DownwardAPI{ "downwardAPI", false, "description" };
    Checked<ProjectedVolumeSource> Projected{ "projected", false, "description" };
    Checked<EmptyDirVolumeSource> EmptyDir{ "emptyDir", false, "description" };
    Checked<HostPathVolumeSource> HostPath{ "hostPath", false, "description" };
    Checked<AWSElasticBlockStoreVolumeSource> AwsElasticBlockStore{ "awsElasticBlockStore", false, "description" };
    Checked<AzureDiskVolumeSource> AzureDisk{ "azureDisk", false, "description" };
    Checked<AzureFileVolumeSource> AzureFile{ "azureFile", false, "description" };
    Checked<CephFSVolumeSource> Cephfs{ "cephfs", false, "description" };
    Checked<CinderVolumeSource> Cinder{ "cinder", false, "description" };
    Checked<CSIVolumeSource> Csi{ "csi", false, "description" };
    Checked<EphemeralVolumeSource> Ephemeral{ "ephemeral", false, "description" };
    Checked<FCVolumeSource> Fc{ "fc", false, "description" };
    Checked<FlexVolumeSource> FlexVolume{ "flexVolume", false, "description" };
    Checked<FlockerVolumeSource> Flocker{ "flocker", false, "description" };
    Checked<GCEPersistentDiskVolumeSource> GcePersistentDisk{ "gcePersistentDisk", false, "description" };
    Checked<GlusterfsVolumeSource> Glusterfs{ "glusterfs", false, "description" };
    Checked<ISCSIVolumeSource> Iscsi{ "iscsi", false, "description" };
    Checked<ImageVolumeSource> Image{ "image", false, "description" };
    Checked<NFSVolumeSource> Nfs{ "nfs", false, "description" };
    Checked<PhotonPersistentDiskVolumeSource> PhotonPersistentDisk{ "photonPersistentDisk", false, "description" };
    Checked<PortworxVolumeSource> PortworxVolume{ "portworxVolume", false, "description" };
    Checked<QuobyteVolumeSource> Quobyte{ "quobyte", false, "description" };
    Checked<RBDVolumeSource> Rbd{ "rbd", false, "description" };
    Checked<ScaleIOVolumeSource> ScaleIO{ "scaleIO", false, "description" };
    Checked<StorageOSVolumeSource> Storageos{ "storageos", false, "description" };
    Checked<VsphereVirtualDiskVolumeSource> VsphereVolume{ "vsphereVolume", false, "description" };
    Checked<GitRepoVolumeSource> GitRepo{ "gitRepo", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static Volume ParseFromJson(const std::string& jsonData);
};

struct VolumeBuilder
{
    VolumeBuilder& Name(const std::string& name);

    Volume Build();

private:
    Volume volume_;
};

} // namespace kubecpp::model::internal::common

#endif // VOLUME_H_