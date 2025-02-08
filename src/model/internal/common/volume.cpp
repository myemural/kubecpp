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


#include "kubecpp/model/internal/common/volume.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string PersistentVolumeClaimSpec::ParseToJson() const
{
    return std::string();
}

PersistentVolumeClaimSpec PersistentVolumeClaimSpec::ParseFromJson(const std::string& jsonData)
{
    return PersistentVolumeClaimSpec();
}

std::string KeyToPath::ParseToJson() const
{
    return ParseFieldsToJson(Key, Path, Mode);
}

KeyToPath KeyToPath::ParseFromJson(const std::string& jsonData)
{
    return KeyToPath();
}

std::string DownwardAPIVolumeFile::ParseToJson() const
{
    return ParseFieldsToJson(Path, FieldRef, Mode, ResourceFieldRef);
}

DownwardAPIVolumeFile DownwardAPIVolumeFile::ParseFromJson(const std::string& jsonData)
{
    return DownwardAPIVolumeFile();
}

std::string PersistentVolumeClaimTemplate::ParseToJson() const
{
    return ParseFieldsToJson(Spec, Metadata);
}

PersistentVolumeClaimTemplate PersistentVolumeClaimTemplate::ParseFromJson(const std::string& jsonData)
{
    return PersistentVolumeClaimTemplate();
}

std::string PersistentVolumeClaimVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(ClaimName, ReadOnly);
}

PersistentVolumeClaimVolumeSource PersistentVolumeClaimVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return PersistentVolumeClaimVolumeSource();
}

std::string ConfigMapVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, DefaultMode, Items);
}

ConfigMapVolumeSource ConfigMapVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return ConfigMapVolumeSource();
}

std::string SecretVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(SecretName, Optional, DefaultMode, Items);
}

SecretVolumeSource SecretVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return SecretVolumeSource();
}

std::string DownwardAPIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DefaultMode, Items);
}

DownwardAPIVolumeSource DownwardAPIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return DownwardAPIVolumeSource();
}

std::string ClusterTrustBundleProjection::ParseToJson() const
{
    return ParseFieldsToJson(Path, LabelSelector, Name, Optional, SignerName);
}

ClusterTrustBundleProjection ClusterTrustBundleProjection::ParseFromJson(const std::string& jsonData)
{
    return ClusterTrustBundleProjection();
}

std::string ConfigMapProjection::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, Items);
}

ConfigMapProjection ConfigMapProjection::ParseFromJson(const std::string& jsonData)
{
    return ConfigMapProjection();
}

std::string DownwardAPIProjection::ParseToJson() const
{
    return ParseFieldsToJson(Items);
}

DownwardAPIProjection DownwardAPIProjection::ParseFromJson(const std::string& jsonData)
{
    return DownwardAPIProjection();
}

std::string SecretProjection::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, Items);
}

SecretProjection SecretProjection::ParseFromJson(const std::string& jsonData)
{
    return SecretProjection();
}

std::string ServiceAccountTokenProjection::ParseToJson() const
{
    return ParseFieldsToJson(Path, Audience, ExpirationSeconds);
}

ServiceAccountTokenProjection ServiceAccountTokenProjection::ParseFromJson(const std::string& jsonData)
{
    return ServiceAccountTokenProjection();
}

std::string VolumeProjection::ParseToJson() const
{
    return ParseFieldsToJson(ClusterTrustBundle, ConfigMap, DownwardAPI, Secret, ServiceAccountToken);
}

VolumeProjection VolumeProjection::ParseFromJson(const std::string& jsonData)
{
    return VolumeProjection();
}

std::string ProjectedVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DefaultMode, Sources);
}

ProjectedVolumeSource ProjectedVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return ProjectedVolumeSource();
}

std::string EmptyDirVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Medium, SizeLimit);
}

EmptyDirVolumeSource EmptyDirVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return EmptyDirVolumeSource();
}

std::string HostPathVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Path, Type);
}

HostPathVolumeSource HostPathVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return HostPathVolumeSource();
}

std::string AWSElasticBlockStoreVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, Partition, ReadOnly);
}

AWSElasticBlockStoreVolumeSource AWSElasticBlockStoreVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return AWSElasticBlockStoreVolumeSource();
}

std::string AzureDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DiskName, DiskURI, CachingMode, FsType, Kind, ReadOnly);
}

AzureDiskVolumeSource AzureDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return AzureDiskVolumeSource();
}

std::string AzureFileVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(SecretName, ShareName, ReadOnly);
}

AzureFileVolumeSource AzureFileVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return AzureFileVolumeSource();
}

std::string CephFSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Monitors, Path, ReadOnly, SecretFile, SecretRef, User);
}

CephFSVolumeSource CephFSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return CephFSVolumeSource();
}

std::string CinderVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, ReadOnly, SecretRef);
}

CinderVolumeSource CinderVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return CinderVolumeSource();
}

std::string CSIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Driver, FsType, NodePublishSecretRef, ReadOnly, VolumeAttributes);
}

CSIVolumeSource CSIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return CSIVolumeSource();
}

std::string EphemeralVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeClaimTemplate);
}

EphemeralVolumeSource EphemeralVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return EphemeralVolumeSource();
}

std::string FCVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(FsType, Lun, ReadOnly, TargetWWNs, Wwids);
}

FCVolumeSource FCVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return FCVolumeSource();
}

std::string FlexVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Driver, FsType, Options, ReadOnly, SecretRef);
}

FlexVolumeSource FlexVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return FlexVolumeSource();
}

std::string FlockerVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DatasetName, DatasetUUID);
}

FlockerVolumeSource FlockerVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return FlockerVolumeSource();
}

std::string GCEPersistentDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PdName, FsType, Partition, ReadOnly);
}

GCEPersistentDiskVolumeSource GCEPersistentDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return GCEPersistentDiskVolumeSource();
}

std::string GlusterfsVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Endpoints, Path, ReadOnly);
}

GlusterfsVolumeSource GlusterfsVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return GlusterfsVolumeSource();
}

std::string ISCSIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Iqn, Lun, TargetPortal, ChapAuthDiscovery, ChapAuthSession, FsType, InitiatorName,
    IscsiInterface, Portals, ReadOnly, SecretRef);
}

ISCSIVolumeSource ISCSIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return ISCSIVolumeSource();
}

std::string ImageVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PullPolicy, Reference);
}

ImageVolumeSource ImageVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return ImageVolumeSource();
}

std::string NFSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Path, Server, ReadOnly);
}

NFSVolumeSource NFSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return NFSVolumeSource();
}

std::string PhotonPersistentDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PdID, FsType);
}

PhotonPersistentDiskVolumeSource PhotonPersistentDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return PhotonPersistentDiskVolumeSource();
}

std::string PortworxVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, ReadOnly);
}

PortworxVolumeSource PortworxVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return PortworxVolumeSource();
}

std::string QuobyteVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Registry, Volume, Group, ReadOnly, Tenant, User);
}

QuobyteVolumeSource QuobyteVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return QuobyteVolumeSource();
}

std::string RBDVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Image, Monitors, FsType, Keyring, Pool, ReadOnly, SecretRef, User);
}

RBDVolumeSource RBDVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return RBDVolumeSource();
}

std::string ScaleIOVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(
    Gateway, SecretRef, System, FsType, ProtectionDomain, ReadOnly, SslEnabled, StorageMode, StoragePool, VolumeName);
}

ScaleIOVolumeSource ScaleIOVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return ScaleIOVolumeSource();
}

std::string StorageOSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(FsType, ReadOnly, SecretRef, VolumeName, VolumeNamespace);
}

StorageOSVolumeSource StorageOSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return StorageOSVolumeSource();
}

std::string VsphereVirtualDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumePath, FsType, StoragePolicyID, StoragePolicyName);
}

VsphereVirtualDiskVolumeSource VsphereVirtualDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    return VsphereVirtualDiskVolumeSource();
}

std::string GitRepoVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Repository, Directory, Revision);
}

GitRepoVolumeSource GitRepoVolumeSource::ParseFromJson(const std::string& jsonData)
{
    GitRepoVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Repository, result.Directory, result.Revision);
    return result;
}

std::string Volume::ParseToJson() const
{
    return ParseFieldsToJson(Name, PersistentVolumeClaim, ConfigMap, Secret, DownwardAPI, Projected, EmptyDir, HostPath,
    AwsElasticBlockStore, AzureDisk, AzureFile, Cephfs, Cinder, Csi, Ephemeral, Fc, FlexVolume, Flocker, GcePersistentDisk,
    Glusterfs, Iscsi, Image, Nfs, PhotonPersistentDisk, PortworxVolume, Quobyte, Rbd, ScaleIO, Storageos, VsphereVolume, GitRepo);
}

Volume Volume::ParseFromJson(const std::string& jsonData)
{
    Volume result;
    ParseFieldsFromJson(jsonData, result.Name, result.PersistentVolumeClaim, result.ConfigMap, result.Secret,
    result.DownwardAPI, result.Projected, result.EmptyDir, result.HostPath, result.AwsElasticBlockStore, result.AzureDisk,
    result.AzureFile, result.Cephfs, result.Cinder, result.Csi, result.Ephemeral, result.Fc, result.FlexVolume, result.Flocker,
    result.GcePersistentDisk, result.Glusterfs, result.Iscsi, result.Image, result.Nfs, result.PhotonPersistentDisk,
    result.PortworxVolume, result.Quobyte, result.Rbd, result.ScaleIO, result.Storageos, result.VsphereVolume, result.GitRepo);
    return result;
}

VolumeBuilder& VolumeBuilder::Name(const std::string& name)
{
    volume_.Name = name;
    return *this;
}

Volume VolumeBuilder::Build()
{
    return std::move(volume_);
}

} // namespace kubecpp::model::internal::common