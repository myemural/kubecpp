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

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::common
{

std::string ManagedFieldsEntry::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, ApiVersion);
    CHECK_AND_SET_FIELD(result, FieldsType);
    CHECK_AND_SET_FIELD(result, FieldsV1);
    CHECK_AND_SET_FIELD(result, Manager);
    CHECK_AND_SET_FIELD(result, Operation);
    CHECK_AND_SET_FIELD(result, Subresource);
    return nlohmann::to_string(result);
}

std::string OwnerReference::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, ApiVersion);
    CHECK_AND_SET_FIELD(result, Kind);
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Uid);
    CHECK_AND_SET_FIELD(result, Controller);
    CHECK_AND_SET_FIELD(result, BlockOwnerDeletion);
    return nlohmann::to_string(result);
}

std::string ObjectMeta::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, GenerateName);
    CHECK_AND_SET_FIELD(result, Namespace);
    CHECK_AND_SET_FIELD_CONTAINER(result, Labels);
    CHECK_AND_SET_FIELD_CONTAINER(result, Finalizers);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, ManagedFields);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, OwnerReferences);
    return nlohmann::to_string(result);
}

ObjectMeta ObjectMeta::ParseFromJson(const std::string& jsonData)
{
    ObjectMeta result;
    nlohmann::json data = nlohmann::json::parse(jsonData);
    if(data.contains(result.Name.GetKeyName())) {
        result.Name = data[result.Name.GetKeyName()].template get<decltype(result.Name)::InternalType>();
    }
    if(data.contains(result.GenerateName.GetKeyName())) {
        result.GenerateName = data[result.GenerateName.GetKeyName()].template get<decltype(result.GenerateName)::InternalType>();
    }
    if(data.contains(result.Namespace.GetKeyName())) {
        result.Namespace = data[result.Namespace.GetKeyName()].template get<decltype(result.Namespace)::InternalType>();
    }
    if(data.contains(result.Labels.GetKeyName())) {
        result.Labels = data[result.Labels.GetKeyName()].template get<decltype(result.Labels)::InternalType>();
    }

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
