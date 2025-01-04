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

#ifndef POD_H_
#define POD_H_

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/list_meta.h"
#include "kubecpp/model/internal/common/object_meta.h"
#include "kubecpp/model/internal/pod/pod_spec.h"
#include "kubecpp/model/internal/pod/pod_status.h"

namespace kubecpp::model::core::v1
{

struct PodList;

struct Pod
{
    using ListType = PodList;

    Checked<std::string> ApiVersion{ "apiVersion", true, "description" };
    Checked<std::string> Kind{ "kind", true, "description" };
    Checked<internal::common::ObjectMeta> Metadata{ "metadata", true, "description" };
    Checked<internal::pod::PodSpec> Spec{ "spec", true, "description" };
    Checked<internal::pod::PodStatus> Status{ "status", false, "description" }; // Read-only

    [[nodiscard]] std::string ParseToJson() const;
    static Pod ParseFromJson(const std::string& jsonData);
};

struct PodList
{
    Checked<std::vector<Pod>> Items{ "items", true, "description" };
    Checked<std::string> ApiVersion{ "apiVersion", true, "description" };
    Checked<std::string> Kind{ "kind", true, "description" };
    Checked<internal::common::ListMeta> Metadata{ "metadata", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PodList ParseFromJson(const std::string& jsonData);
};

struct PodBuilder
{
    PodBuilder& ApiVersion(const std::string& apiVersion);

    PodBuilder& Kind(const std::string& kind);

    PodBuilder& Metadata(const internal::common::ObjectMeta& objectMeta);

    PodBuilder& Spec(const internal::pod::PodSpec& podSpec);

    Pod Build();

private:
    Pod pod_;
};

} // namespace kubecpp::model::core::v1

#endif // POD_H_