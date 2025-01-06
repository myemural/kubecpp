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

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct PersistentVolumeClaimVolumeSource
{
};

struct ConfigMapVolumeSource
{
};

struct SecretVolumeSource
{
};

struct DownwardAPIVolumeSource
{
};

struct ProjectedVolumeSource
{
};

struct EmptyDirVolumeSource
{
};

struct HostPathVolumeSource
{
};

struct AWSElasticBlockStoreVolumeSource
{
};

struct AzureDiskVolumeSource
{
};

struct AzureFileVolumeSource
{
};

struct CephFSVolumeSource
{
};

struct CinderVolumeSource
{
};

struct CSIVolumeSource
{
};

struct EphemeralVolumeSource
{
};

struct FCVolumeSource
{
};

struct FlexVolumeSource
{
};

struct FlockerVolumeSource
{
};

struct GCEPersistentDiskVolumeSource
{
};

struct GlusterfsVolumeSource
{
};

struct ISCSIVolumeSource
{
};

struct ImageVolumeSource
{
};

struct NFSVolumeSource
{
};

struct PhotonPersistentDiskVolumeSource
{
};

struct PortworxVolumeSource
{
};

struct QuobyteVolumeSource
{
};

struct RBDVolumeSource
{
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