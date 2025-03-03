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
    KeyToPath result;
    ParseFieldsFromJson(jsonData, result.Key, result.Path, result.Mode);
    return result;
}

std::string DownwardAPIVolumeFile::ParseToJson() const
{
    return ParseFieldsToJson(Path, FieldRef, Mode, ResourceFieldRef);
}

DownwardAPIVolumeFile DownwardAPIVolumeFile::ParseFromJson(const std::string& jsonData)
{
    DownwardAPIVolumeFile result;
    ParseFieldsFromJson(jsonData, result.Path, result.FieldRef, result.Mode, result.ResourceFieldRef);
    return result;
}

std::string PersistentVolumeClaimTemplate::ParseToJson() const
{
    return ParseFieldsToJson(Spec, Metadata);
}

PersistentVolumeClaimTemplate PersistentVolumeClaimTemplate::ParseFromJson(const std::string& jsonData)
{
    PersistentVolumeClaimTemplate result;
    ParseFieldsFromJson(jsonData, result.Spec, result.Metadata);
    return result;
}

std::string PersistentVolumeClaimVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(ClaimName, ReadOnly);
}

PersistentVolumeClaimVolumeSource PersistentVolumeClaimVolumeSource::ParseFromJson(const std::string& jsonData)
{
    PersistentVolumeClaimVolumeSource result;
    ParseFieldsFromJson(jsonData, result.ClaimName, result.ReadOnly);
    return result;
}

std::string ConfigMapVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, DefaultMode, Items);
}

ConfigMapVolumeSource ConfigMapVolumeSource::ParseFromJson(const std::string& jsonData)
{
    ConfigMapVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Name, result.Optional, result.DefaultMode, result.Items);
    return result;
}

std::string SecretVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(SecretName, Optional, DefaultMode, Items);
}

SecretVolumeSource SecretVolumeSource::ParseFromJson(const std::string& jsonData)
{
    SecretVolumeSource result;
    ParseFieldsFromJson(jsonData, result.SecretName, result.Optional, result.DefaultMode, result.Items);
    return result;
}

std::string DownwardAPIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DefaultMode, Items);
}

DownwardAPIVolumeSource DownwardAPIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    DownwardAPIVolumeSource result;
    ParseFieldsFromJson(jsonData, result.DefaultMode, result.Items);
    return result;
}

std::string ClusterTrustBundleProjection::ParseToJson() const
{
    return ParseFieldsToJson(Path, LabelSelector, Name, Optional, SignerName);
}

ClusterTrustBundleProjection ClusterTrustBundleProjection::ParseFromJson(const std::string& jsonData)
{
    ClusterTrustBundleProjection result;
    ParseFieldsFromJson(jsonData, result.Path, result.LabelSelector, result.Name, result.Optional, result.SignerName);
    return result;
}

std::string ConfigMapProjection::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, Items);
}

ConfigMapProjection ConfigMapProjection::ParseFromJson(const std::string& jsonData)
{
    ConfigMapProjection result;
    ParseFieldsFromJson(jsonData, result.Name, result.Optional, result.Items);
    return result;
}

std::string DownwardAPIProjection::ParseToJson() const
{
    return ParseFieldsToJson(Items);
}

DownwardAPIProjection DownwardAPIProjection::ParseFromJson(const std::string& jsonData)
{
    DownwardAPIProjection result;
    ParseFieldsFromJson(jsonData, result.Items);
    return result;
}

std::string SecretProjection::ParseToJson() const
{
    return ParseFieldsToJson(Name, Optional, Items);
}

SecretProjection SecretProjection::ParseFromJson(const std::string& jsonData)
{
    SecretProjection result;
    ParseFieldsFromJson(jsonData, result.Name, result.Optional, result.Items);
    return result;
}

std::string ServiceAccountTokenProjection::ParseToJson() const
{
    return ParseFieldsToJson(Path, Audience, ExpirationSeconds);
}

ServiceAccountTokenProjection ServiceAccountTokenProjection::ParseFromJson(const std::string& jsonData)
{
    ServiceAccountTokenProjection result;
    ParseFieldsFromJson(jsonData, result.Path, result.Audience, result.ExpirationSeconds);
    return result;
}

std::string VolumeProjection::ParseToJson() const
{
    return ParseFieldsToJson(ClusterTrustBundle, ConfigMap, DownwardAPI, Secret, ServiceAccountToken);
}

VolumeProjection VolumeProjection::ParseFromJson(const std::string& jsonData)
{
    VolumeProjection result;
    ParseFieldsFromJson(jsonData, result.ClusterTrustBundle, result.ConfigMap, result.DownwardAPI, result.Secret,
    result.ServiceAccountToken);
    return result;
}

std::string ProjectedVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DefaultMode, Sources);
}

ProjectedVolumeSource ProjectedVolumeSource::ParseFromJson(const std::string& jsonData)
{
    ProjectedVolumeSource result;
    ParseFieldsFromJson(jsonData, result.DefaultMode, result.Sources);
    return result;
}

std::string EmptyDirVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Medium, SizeLimit);
}

EmptyDirVolumeSource EmptyDirVolumeSource::ParseFromJson(const std::string& jsonData)
{
    EmptyDirVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Medium, result.SizeLimit);
    return result;
}

std::string HostPathVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Path, Type);
}

HostPathVolumeSource HostPathVolumeSource::ParseFromJson(const std::string& jsonData)
{
    HostPathVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Path, result.Type);
    return result;
}

std::string AWSElasticBlockStoreVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, Partition, ReadOnly);
}

AWSElasticBlockStoreVolumeSource AWSElasticBlockStoreVolumeSource::ParseFromJson(const std::string& jsonData)
{
    AWSElasticBlockStoreVolumeSource result;
    ParseFieldsFromJson(jsonData, result.VolumeID, result.FsType, result.Partition, result.ReadOnly);
    return result;
}

std::string AzureDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DiskName, DiskURI, CachingMode, FsType, Kind, ReadOnly);
}

AzureDiskVolumeSource AzureDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    AzureDiskVolumeSource result;
    ParseFieldsFromJson(
    jsonData, result.DiskName, result.DiskURI, result.CachingMode, result.FsType, result.Kind, result.ReadOnly);
    return result;
}

std::string AzureFileVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(SecretName, ShareName, ReadOnly);
}

AzureFileVolumeSource AzureFileVolumeSource::ParseFromJson(const std::string& jsonData)
{
    AzureFileVolumeSource result;
    ParseFieldsFromJson(jsonData, result.SecretName, result.ShareName, result.ReadOnly);
    return result;
}

std::string CephFSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Monitors, Path, ReadOnly, SecretFile, SecretRef, User);
}

CephFSVolumeSource CephFSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    CephFSVolumeSource result;
    ParseFieldsFromJson(
    jsonData, result.Monitors, result.Path, result.ReadOnly, result.SecretFile, result.SecretRef, result.User);
    return result;
}

std::string CinderVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, ReadOnly, SecretRef);
}

CinderVolumeSource CinderVolumeSource::ParseFromJson(const std::string& jsonData)
{
    CinderVolumeSource result;
    ParseFieldsFromJson(jsonData, result.VolumeID, result.FsType, result.ReadOnly, result.SecretRef);
    return result;
}

std::string CSIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Driver, FsType, NodePublishSecretRef, ReadOnly, VolumeAttributes);
}

CSIVolumeSource CSIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    CSIVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Driver, result.FsType, result.NodePublishSecretRef, result.ReadOnly, result.VolumeAttributes);
    return result;
}

std::string EphemeralVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeClaimTemplate);
}

EphemeralVolumeSource EphemeralVolumeSource::ParseFromJson(const std::string& jsonData)
{
    EphemeralVolumeSource result;
    ParseFieldsFromJson(jsonData, result.VolumeClaimTemplate);
    return result;
}

std::string FCVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(FsType, Lun, ReadOnly, TargetWWNs, Wwids);
}

FCVolumeSource FCVolumeSource::ParseFromJson(const std::string& jsonData)
{
    FCVolumeSource result;
    ParseFieldsFromJson(jsonData, result.FsType, result.Lun, result.ReadOnly, result.TargetWWNs, result.Wwids);
    return result;
}

std::string FlexVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Driver, FsType, Options, ReadOnly, SecretRef);
}

FlexVolumeSource FlexVolumeSource::ParseFromJson(const std::string& jsonData)
{
    FlexVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Driver, result.FsType, result.Options, result.ReadOnly, result.SecretRef);
    return result;
}

std::string FlockerVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(DatasetName, DatasetUUID);
}

FlockerVolumeSource FlockerVolumeSource::ParseFromJson(const std::string& jsonData)
{
    FlockerVolumeSource result;
    ParseFieldsFromJson(jsonData, result.DatasetName, result.DatasetUUID);
    return result;
}

std::string GCEPersistentDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PdName, FsType, Partition, ReadOnly);
}

GCEPersistentDiskVolumeSource GCEPersistentDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    GCEPersistentDiskVolumeSource result;
    ParseFieldsFromJson(jsonData, result.PdName, result.FsType, result.Partition, result.ReadOnly);
    return result;
}

std::string GlusterfsVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Endpoints, Path, ReadOnly);
}

GlusterfsVolumeSource GlusterfsVolumeSource::ParseFromJson(const std::string& jsonData)
{
    GlusterfsVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Endpoints, result.Path, result.ReadOnly);
    return result;
}

std::string ISCSIVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Iqn, Lun, TargetPortal, ChapAuthDiscovery, ChapAuthSession, FsType, InitiatorName,
    IscsiInterface, Portals, ReadOnly, SecretRef);
}

ISCSIVolumeSource ISCSIVolumeSource::ParseFromJson(const std::string& jsonData)
{
    ISCSIVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Iqn, result.Lun, result.TargetPortal, result.ChapAuthDiscovery, result.ChapAuthSession,
    result.FsType, result.InitiatorName, result.IscsiInterface, result.Portals, result.ReadOnly, result.SecretRef);
    return result;
}

std::string ImageVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PullPolicy, Reference);
}

ImageVolumeSource ImageVolumeSource::ParseFromJson(const std::string& jsonData)
{
    ImageVolumeSource result;
    ParseFieldsFromJson(jsonData, result.PullPolicy, result.Reference);
    return result;
}

std::string NFSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Path, Server, ReadOnly);
}

NFSVolumeSource NFSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    NFSVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Path, result.Server, result.ReadOnly);
    return result;
}

std::string PhotonPersistentDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(PdID, FsType);
}

PhotonPersistentDiskVolumeSource PhotonPersistentDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    PhotonPersistentDiskVolumeSource result;
    ParseFieldsFromJson(jsonData, result.PdID, result.FsType);
    return result;
}

std::string PortworxVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumeID, FsType, ReadOnly);
}

PortworxVolumeSource PortworxVolumeSource::ParseFromJson(const std::string& jsonData)
{
    PortworxVolumeSource result;
    ParseFieldsFromJson(jsonData, result.VolumeID, result.FsType, result.ReadOnly);
    return result;
}

std::string QuobyteVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Registry, Volume, Group, ReadOnly, Tenant, User);
}

QuobyteVolumeSource QuobyteVolumeSource::ParseFromJson(const std::string& jsonData)
{
    QuobyteVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Registry, result.Volume, result.Group, result.ReadOnly, result.Tenant, result.User);
    return result;
}

std::string RBDVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(Image, Monitors, FsType, Keyring, Pool, ReadOnly, SecretRef, User);
}

RBDVolumeSource RBDVolumeSource::ParseFromJson(const std::string& jsonData)
{
    RBDVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Image, result.Monitors, result.FsType, result.Keyring, result.Pool,
    result.ReadOnly, result.SecretRef, result.User);
    return result;
}

std::string ScaleIOVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(
    Gateway, SecretRef, System, FsType, ProtectionDomain, ReadOnly, SslEnabled, StorageMode, StoragePool, VolumeName);
}

ScaleIOVolumeSource ScaleIOVolumeSource::ParseFromJson(const std::string& jsonData)
{
    ScaleIOVolumeSource result;
    ParseFieldsFromJson(jsonData, result.Gateway, result.SecretRef, result.System, result.FsType, result.ProtectionDomain,
    result.ReadOnly, result.SslEnabled, result.StorageMode, result.StoragePool, result.VolumeName);
    return result;
}

std::string StorageOSVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(FsType, ReadOnly, SecretRef, VolumeName, VolumeNamespace);
}

StorageOSVolumeSource StorageOSVolumeSource::ParseFromJson(const std::string& jsonData)
{
    StorageOSVolumeSource result;
    ParseFieldsFromJson(jsonData, result.FsType, result.ReadOnly, result.SecretRef, result.VolumeName, result.VolumeNamespace);
    return result;
}

std::string VsphereVirtualDiskVolumeSource::ParseToJson() const
{
    return ParseFieldsToJson(VolumePath, FsType, StoragePolicyID, StoragePolicyName);
}

VsphereVirtualDiskVolumeSource VsphereVirtualDiskVolumeSource::ParseFromJson(const std::string& jsonData)
{
    VsphereVirtualDiskVolumeSource result;
    ParseFieldsFromJson(jsonData, result.VolumePath, result.FsType, result.StoragePolicyID, result.StoragePolicyName);
    return result;
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

VolumeBuilder& VolumeBuilder::PersistentVolumeClaim(const PersistentVolumeClaimVolumeSource& persistentVolumeClaim)
{
    volume_.PersistentVolumeClaim = persistentVolumeClaim;
    return *this;
}

VolumeBuilder& VolumeBuilder::ConfigMap(const ConfigMapVolumeSource& configMap)
{
    volume_.ConfigMap = configMap;
    return *this;
}

VolumeBuilder& VolumeBuilder::Secret(const SecretVolumeSource& secret)
{
    volume_.Secret = secret;
    return *this;
}

VolumeBuilder& VolumeBuilder::DownwardAPI(const DownwardAPIVolumeSource& downwardAPI)
{
    volume_.DownwardAPI = downwardAPI;
    return *this;
}

VolumeBuilder& VolumeBuilder::Projected(const ProjectedVolumeSource& projected)
{
    volume_.Projected = projected;
    return *this;
}

VolumeBuilder& VolumeBuilder::EmptyDir(const EmptyDirVolumeSource& emptyDir)
{
    volume_.EmptyDir = emptyDir;
    return *this;
}

VolumeBuilder& VolumeBuilder::HostPath(const HostPathVolumeSource& hostPath)
{
    volume_.HostPath = hostPath;
    return *this;
}

VolumeBuilder& VolumeBuilder::AwsElasticBlockStore(const AWSElasticBlockStoreVolumeSource& awsElasticBlockStore)
{
    volume_.AwsElasticBlockStore = awsElasticBlockStore;
    return *this;
}

VolumeBuilder& VolumeBuilder::AzureDisk(const AzureDiskVolumeSource& azureDisk)
{
    volume_.AzureDisk = azureDisk;
    return *this;
}

VolumeBuilder& VolumeBuilder::AzureFile(const AzureFileVolumeSource& azureFile)
{
    volume_.AzureFile = azureFile;
    return *this;
}

VolumeBuilder& VolumeBuilder::Cephfs(const CephFSVolumeSource& cephfs)
{
    volume_.Cephfs = cephfs;
    return *this;
}

VolumeBuilder& VolumeBuilder::Cinder(const CinderVolumeSource& cinder)
{
    volume_.Cinder = cinder;
    return *this;
}

VolumeBuilder& VolumeBuilder::Csi(const CSIVolumeSource& csiVolumeSource)
{
    volume_.Csi = csiVolumeSource;
    return *this;
}

VolumeBuilder& VolumeBuilder::Ephemeral(const EphemeralVolumeSource& ephemeral)
{
    volume_.Ephemeral = ephemeral;
    return *this;
}

VolumeBuilder& VolumeBuilder::Fc(const FCVolumeSource& fcVolumeSource)
{
    volume_.Fc = fcVolumeSource;
    return *this;
}

VolumeBuilder& VolumeBuilder::FlexVolume(const FlexVolumeSource& flexVolume)
{
    volume_.FlexVolume = flexVolume;
    return *this;
}

VolumeBuilder& VolumeBuilder::Flocker(const FlockerVolumeSource& flocker)
{
    volume_.Flocker = flocker;
    return *this;
}

VolumeBuilder& VolumeBuilder::GcePersistentDisk(const GCEPersistentDiskVolumeSource& gcePersistentDisk)
{
    volume_.GcePersistentDisk = gcePersistentDisk;
    return *this;
}

VolumeBuilder& VolumeBuilder::Glusterfs(const GlusterfsVolumeSource& glusterfs)
{
    volume_.Glusterfs = glusterfs;
    return *this;
}

VolumeBuilder& VolumeBuilder::Iscsi(const ISCSIVolumeSource& iscsi)
{
    volume_.Iscsi = iscsi;
    return *this;
}

VolumeBuilder& VolumeBuilder::Image(const ImageVolumeSource& image)
{
    volume_.Image = image;
    return *this;
}

VolumeBuilder& VolumeBuilder::Nfs(const NFSVolumeSource& nfsVolumeSource)
{
    volume_.Nfs = nfsVolumeSource;
    return *this;
}

VolumeBuilder& VolumeBuilder::PhotonPersistentDisk(const PhotonPersistentDiskVolumeSource& photonPersistentDisk)
{
    volume_.PhotonPersistentDisk = photonPersistentDisk;
    return *this;
}

VolumeBuilder& VolumeBuilder::PortworxVolume(const PortworxVolumeSource& portworxVolume)
{
    volume_.PortworxVolume = portworxVolume;
    return *this;
}

VolumeBuilder& VolumeBuilder::Quobyte(const QuobyteVolumeSource& quobyte)
{
    volume_.Quobyte = quobyte;
    return *this;
}

VolumeBuilder& VolumeBuilder::Rbd(const RBDVolumeSource& rbdVolumeSource)
{
    volume_.Rbd = rbdVolumeSource;
    return *this;
}

VolumeBuilder& VolumeBuilder::ScaleIO(const ScaleIOVolumeSource& scaleIO)
{
    volume_.ScaleIO = scaleIO;
    return *this;
}

VolumeBuilder& VolumeBuilder::Storageos(const StorageOSVolumeSource& storageos)
{
    volume_.Storageos = storageos;
    return *this;
}

VolumeBuilder& VolumeBuilder::VsphereVolume(const VsphereVirtualDiskVolumeSource& vsphereVolume)
{
    volume_.VsphereVolume = vsphereVolume;
    return *this;
}

VolumeBuilder& VolumeBuilder::GitRepo(const GitRepoVolumeSource& gitRepo)
{
    volume_.GitRepo = gitRepo;
    return *this;
}

Volume VolumeBuilder::Build()
{
    return std::move(volume_);
}

KeyToPathBuilder& KeyToPathBuilder::Key(const std::string& key)
{
    keyToPath_.Key = key;
    return *this;
}

KeyToPathBuilder& KeyToPathBuilder::Path(const std::string& path)
{
    keyToPath_.Path = path;
    return *this;
}

KeyToPathBuilder& KeyToPathBuilder::Mode(std::int32_t mode)
{
    keyToPath_.Mode = mode;
    return *this;
}

KeyToPath KeyToPathBuilder::Build()
{
    return std::move(keyToPath_);
}

DownwardAPIVolumeFileBuilder& DownwardAPIVolumeFileBuilder::Path(const std::string& path)
{
    downwardAPIVolumeFile_.Path = path;
    return *this;
}

DownwardAPIVolumeFileBuilder& DownwardAPIVolumeFileBuilder::FieldRef(const ObjectFieldSelector& fieldRef)
{
    downwardAPIVolumeFile_.FieldRef = fieldRef;
    return *this;
}

DownwardAPIVolumeFileBuilder& DownwardAPIVolumeFileBuilder::Mode(std::int32_t mode)
{
    downwardAPIVolumeFile_.Mode = mode;
    return *this;
}

DownwardAPIVolumeFileBuilder& DownwardAPIVolumeFileBuilder::ResourceFieldRef(const ResourceFieldSelector& resourceFieldRef)
{
    downwardAPIVolumeFile_.ResourceFieldRef = resourceFieldRef;
    return *this;
}

DownwardAPIVolumeFile DownwardAPIVolumeFileBuilder::Build()
{
    return std::move(downwardAPIVolumeFile_);
}

PersistentVolumeClaimTemplateBuilder& PersistentVolumeClaimTemplateBuilder::Spec(const PersistentVolumeClaimSpec& spec)
{
    persistentVolumeClaimTemplate_.Spec = spec;
    return *this;
}

PersistentVolumeClaimTemplateBuilder& PersistentVolumeClaimTemplateBuilder::Metadata(const ObjectMeta& metadata)
{
    persistentVolumeClaimTemplate_.Metadata = metadata;
    return *this;
}

PersistentVolumeClaimTemplate PersistentVolumeClaimTemplateBuilder::Build()
{
    return std::move(persistentVolumeClaimTemplate_);
}

PersistentVolumeClaimVolumeSourceBuilder& PersistentVolumeClaimVolumeSourceBuilder::ClaimName(const std::string& claimName)
{
    persistentVolumeClaimVolumeSource_.ClaimName = claimName;
    return *this;
}

PersistentVolumeClaimVolumeSourceBuilder& PersistentVolumeClaimVolumeSourceBuilder::ReadOnly(bool readOnly)
{
    persistentVolumeClaimVolumeSource_.ReadOnly = readOnly;
    return *this;
}

PersistentVolumeClaimVolumeSource PersistentVolumeClaimVolumeSourceBuilder::Build()
{
    return std::move(persistentVolumeClaimVolumeSource_);
}

ConfigMapVolumeSourceBuilder& ConfigMapVolumeSourceBuilder::Name(const std::string& name)
{
    configMapVolumeSource_.Name = name;
    return *this;
}

ConfigMapVolumeSourceBuilder& ConfigMapVolumeSourceBuilder::Optional(bool optional)
{
    configMapVolumeSource_.Optional = optional;
    return *this;
}

ConfigMapVolumeSourceBuilder& ConfigMapVolumeSourceBuilder::DefaultMode(std::int32_t defaultMode)
{
    configMapVolumeSource_.DefaultMode = defaultMode;
    return *this;
}

ConfigMapVolumeSourceBuilder& ConfigMapVolumeSourceBuilder::Items(const std::vector<KeyToPath>& items)
{
    configMapVolumeSource_.Items = items;
    return *this;
}

ConfigMapVolumeSource ConfigMapVolumeSourceBuilder::Build()
{
    return std::move(configMapVolumeSource_);
}

SecretVolumeSourceBuilder& SecretVolumeSourceBuilder::SecretName(const std::string& secretName)
{
    secretVolumeSource_.SecretName = secretName;
    return *this;
}

SecretVolumeSourceBuilder& SecretVolumeSourceBuilder::Optional(bool optional)
{
    secretVolumeSource_.Optional = optional;
    return *this;
}

SecretVolumeSourceBuilder& SecretVolumeSourceBuilder::DefaultMode(std::int32_t defaultMode)
{
    secretVolumeSource_.DefaultMode = defaultMode;
    return *this;
}

SecretVolumeSourceBuilder& SecretVolumeSourceBuilder::Items(const std::vector<KeyToPath>& items)
{
    secretVolumeSource_.Items = items;
    return *this;
}

SecretVolumeSource SecretVolumeSourceBuilder::Build()
{
    return std::move(secretVolumeSource_);
}

DownwardAPIVolumeSourceBuilder& DownwardAPIVolumeSourceBuilder::DefaultMode(std::int32_t defaultMode)
{
    downwardAPIVolumeSource_.DefaultMode = defaultMode;
    return *this;
}

DownwardAPIVolumeSourceBuilder& DownwardAPIVolumeSourceBuilder::Items(const std::vector<DownwardAPIVolumeFile>& items)
{
    downwardAPIVolumeSource_.Items = items;
    return *this;
}

DownwardAPIVolumeSource DownwardAPIVolumeSourceBuilder::Build()
{
    return std::move(downwardAPIVolumeSource_);
}

ClusterTrustBundleProjectionBuilder& ClusterTrustBundleProjectionBuilder::Path(const std::string& path)
{
    clusterTrustBundleProjection_.Path = path;
    return *this;
}

ClusterTrustBundleProjectionBuilder& ClusterTrustBundleProjectionBuilder::LabelSelector(const common::LabelSelector& labelSelector)
{
    clusterTrustBundleProjection_.LabelSelector = labelSelector;
    return *this;
}

ClusterTrustBundleProjectionBuilder& ClusterTrustBundleProjectionBuilder::Name(const std::string& name)
{
    clusterTrustBundleProjection_.Name = name;
    return *this;
}

ClusterTrustBundleProjectionBuilder& ClusterTrustBundleProjectionBuilder::Optional(bool optional)
{
    clusterTrustBundleProjection_.Optional = optional;
    return *this;
}

ClusterTrustBundleProjectionBuilder& ClusterTrustBundleProjectionBuilder::SignerName(const std::string& signerName)
{
    clusterTrustBundleProjection_.SignerName = signerName;
    return *this;
}

ClusterTrustBundleProjection ClusterTrustBundleProjectionBuilder::Build()
{
    return std::move(clusterTrustBundleProjection_);
}

ConfigMapProjectionBuilder& ConfigMapProjectionBuilder::Name(const std::string& name)
{
    configMapProjection_.Name = name;
    return *this;
}

ConfigMapProjectionBuilder& ConfigMapProjectionBuilder::Optional(bool optional)
{
    configMapProjection_.Optional = optional;
    return *this;
}

ConfigMapProjectionBuilder& ConfigMapProjectionBuilder::Items(const std::vector<KeyToPath>& items)
{
    configMapProjection_.Items = items;
    return *this;
}

ConfigMapProjection ConfigMapProjectionBuilder::Build()
{
    return std::move(configMapProjection_);
}

} // namespace kubecpp::model::internal::common