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

#include "kubecpp/model/internal/common/object_meta.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string ManagedFieldsEntry::ParseToJson() const
{
    /// TODO: FieldsV1 will be handled later.
    return ParseFieldsToJson(ApiVersion, FieldsType, Manager, Operation, Subresource, Time);
}

ManagedFieldsEntry ManagedFieldsEntry::ParseFromJson(const std::string& jsonData)
{
    /// TODO: FieldsV1 will be handled later.
    ManagedFieldsEntry result;
    ParseFieldsFromJson(jsonData, result.ApiVersion, result.FieldsType, result.Manager,
    result.Operation, result.Subresource, result.Time);
    return result;
}

std::string OwnerReference::ParseToJson() const
{
    return ParseFieldsToJson(ApiVersion, Kind, Name, Uid, BlockOwnerDeletion, Controller);
}

OwnerReference OwnerReference::ParseFromJson(const std::string& jsonData)
{
    OwnerReference result;
    ParseFieldsFromJson(
    jsonData, result.ApiVersion, result.Kind, result.Name, result.Uid, result.BlockOwnerDeletion, result.Controller);
    return result;
}

std::string ObjectMeta::ParseToJson() const
{
    return ParseFieldsToJson(Name, GenerateName, Namespace, Labels, Annotations, Finalizers, ManagedFields, OwnerReferences);
}

ObjectMeta ObjectMeta::ParseFromJson(const std::string& jsonData)
{
    ObjectMeta result;
    ParseFieldsFromJson(jsonData, result.Name, result.GenerateName, result.Namespace, result.Labels, result.Annotations,
    result.Finalizers, result.ManagedFields, result.OwnerReferences, result.CreationTimestamp, result.DeletionGracePeriodSeconds,
    result.DeletionTimestamp, result.Generation, result.ResourceVersion, result.SelfLink, result.Uid);
    return result;
}

ObjectMetaBuilder& ObjectMetaBuilder::Name(const std::string& name)
{
    metadata_.Name = name;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::GenerateName(const std::string& generateName)
{
    metadata_.GenerateName = generateName;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::Namespace(const std::string& nameSpace)
{
    metadata_.Namespace = nameSpace;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::Labels(const std::unordered_map<std::string, std::string>& labels)
{
    metadata_.Labels = labels;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::Finalizers(const std::vector<std::string>& finalizers)
{
    metadata_.Finalizers = finalizers;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::ManagedFields(const std::vector<ManagedFieldsEntry>& managedFields)
{
    metadata_.ManagedFields = managedFields;
    return *this;
}

ObjectMetaBuilder& ObjectMetaBuilder::OwnerReferences(const std::vector<OwnerReference>& ownerReferences)
{
    metadata_.OwnerReferences = ownerReferences;
    return *this;
}

ObjectMeta ObjectMetaBuilder::Build()
{
    return std::move(metadata_);
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::ApiVersion(const std::string& apiVersion)
{
    manageFieldsEntry_.ApiVersion = apiVersion;
    return *this;
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::FieldsType(const std::string& fieldsType)
{
    manageFieldsEntry_.FieldsType = fieldsType;
    return *this;
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::FieldsV1(const std::string& fieldsV1)
{
    manageFieldsEntry_.FieldsV1 = fieldsV1;
    return *this;
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::Manager(const std::string& manager)
{
    manageFieldsEntry_.Manager = manager;
    return *this;
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::Operation(const std::string& operation)
{
    manageFieldsEntry_.Operation = operation;
    return *this;
}

ManageFieldsEntryBuilder& ManageFieldsEntryBuilder::Subresource(const std::string& subresource)
{
    manageFieldsEntry_.Subresource = subresource;
    return *this;
}

ManagedFieldsEntry ManageFieldsEntryBuilder::Build()
{
    return std::move(manageFieldsEntry_);
}

OwnerReferenceBuilder& OwnerReferenceBuilder::ApiVersion(const std::string& apiVersion)
{
    ownerReference_.ApiVersion = apiVersion;
    return *this;
}

OwnerReferenceBuilder& OwnerReferenceBuilder::Kind(const std::string& kind)
{
    ownerReference_.Kind = kind;
    return *this;
}

OwnerReferenceBuilder& OwnerReferenceBuilder::Name(const std::string& name)
{
    ownerReference_.Name = name;
    return *this;
}

OwnerReferenceBuilder& OwnerReferenceBuilder::Uid(const std::string& uid)
{
    ownerReference_.Uid = uid;
    return *this;
}

OwnerReferenceBuilder& OwnerReferenceBuilder::Controller(bool controller)
{
    ownerReference_.Controller = controller;
    return *this;
}

OwnerReferenceBuilder& OwnerReferenceBuilder::BlockOwnerDeletion(bool blockOwnerDeletion)
{
    ownerReference_.BlockOwnerDeletion = blockOwnerDeletion;
    return *this;
}

OwnerReference OwnerReferenceBuilder::Build()
{
    return std::move(ownerReference_);
}

} // namespace kubecpp::model::internal::common
