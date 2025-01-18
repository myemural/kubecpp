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

#ifndef OBJECT_META_H_
#define OBJECT_META_H_

#include <unordered_map>
#include <vector>

#include "kubecpp/common/checked.h"
#include "kubecpp/model/validator/dns_label_name_validator.h"
#include "kubecpp/model/validator/label_key_value_validator.h"

namespace kubecpp::model::internal::common
{

struct ManagedFieldsEntry
{
    Checked<std::string> ApiVersion{ "apiVersion", false, "description" };
    Checked<std::string> FieldsType{ "fieldsType", false, "description" };
    Checked<std::string> FieldsV1{ "fieldsV1", false, "description" };
    Checked<std::string> Manager{ "manager", false, "description" };
    Checked<std::string> Operation{ "operation", false, "description" };
    Checked<std::string> Subresource{ "subresource", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ManagedFieldsEntry ParseFromJson(const std::string& jsonData);
};

struct OwnerReference
{
    Checked<std::string> ApiVersion{ "apiVersion", true, "description" };
    Checked<std::string> Kind{ "kind", true, "description" };
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Uid{ "uid", true, "description" };
    Checked<bool> Controller{ "controller", false, "description" };
    Checked<bool> BlockOwnerDeletion{ "blockOwnerDeletion", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static OwnerReference ParseFromJson(const std::string& jsonData);
};

struct ObjectMeta
{
    Checked<std::string, validator::DnsLabelNameValidator> Name{ "name", false, "description" };
    Checked<std::string> GenerateName{ "generateName", false, "description" };
    Checked<std::string, validator::DnsLabelNameValidator> Namespace{ "namespace", false, "description" };
    Checked<std::unordered_map<std::string, std::string>, validator::LabelKeyValueValidator> Labels{ "labels", false, "description" };
    Checked<std::vector<std::string>> Finalizers{ "finalizers", false, "description" };
    Checked<std::vector<ManagedFieldsEntry>> ManagedFields{ "managedFields", false, "description" };
    Checked<std::vector<OwnerReference>> OwnerReferences{ "ownerReferences", false, "description" };
    Checked<std::string> CreationTimestamp{ "creationTimestamp", false, "description" }; // Read-only, Time
    Checked<int64_t> DeletionGracePeriodSeconds{ "deletionGracePeriodSeconds", false, "description" }; // Read-only
    Checked<std::string> DeletionTimestamp{ "deletionTimestamp", false, "description" }; // Read-only, Time
    Checked<int64_t> Generation{ "generation", false, "description" };                   // Read-only
    Checked<std::string> ResourceVersion{ "resourceVersion", false, "description" };     // Read-only
    Checked<std::string> SelfLink{ "selfLink", false, "description" };                   // Read-only
    Checked<std::string> Uid{ "uid", false, "description" };                             // Read-only


    [[nodiscard]] std::string ParseToJson() const;
    static ObjectMeta ParseFromJson(const std::string& jsonData);
};

struct ManageFieldsEntryBuilder
{
    ManageFieldsEntryBuilder& ApiVersion(const std::string& apiVersion);

    ManageFieldsEntryBuilder& FieldsType(const std::string& fieldsType);

    ManageFieldsEntryBuilder& FieldsV1(const std::string& fieldsV1);

    ManageFieldsEntryBuilder& Manager(const std::string& manager);

    ManageFieldsEntryBuilder& Operation(const std::string& operation);

    ManageFieldsEntryBuilder& Subresource(const std::string& subresource);

    ManagedFieldsEntry Build();

private:
    ManagedFieldsEntry manageFieldsEntry_;
};

struct OwnerReferenceBuilder
{
    OwnerReferenceBuilder& ApiVersion(const std::string& apiVersion);

    OwnerReferenceBuilder& Kind(const std::string& kind);

    OwnerReferenceBuilder& Name(const std::string& name);

    OwnerReferenceBuilder& Uid(const std::string& uid);

    OwnerReferenceBuilder& Controller(bool controller);

    OwnerReferenceBuilder& BlockOwnerDeletion(bool blockOwnerDeletion);

    OwnerReference Build();

private:
    OwnerReference ownerReference_;
};

struct ObjectMetaBuilder
{
    ObjectMetaBuilder& Name(const std::string& name);

    ObjectMetaBuilder& GenerateName(const std::string& generateName);

    ObjectMetaBuilder& Namespace(const std::string& nameSpace);

    ObjectMetaBuilder& Labels(const std::unordered_map<std::string, std::string>& labels);

    ObjectMetaBuilder& Finalizers(const std::vector<std::string>& finalizers);

    ObjectMetaBuilder& ManagedFields(const std::vector<ManagedFieldsEntry>& managedFields);

    ObjectMetaBuilder& OwnerReferences(const std::vector<OwnerReference>& ownerReferences);

    ObjectMeta Build();

private:
    ObjectMeta metadata_;
};

} // namespace kubecpp::model::internal::common

#endif // OBJECT_META_H_