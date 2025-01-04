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

#ifndef ENV_VAR_H_
#define ENV_VAR_H_

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/common/object_field_selector.h"
#include "kubecpp/model/internal/common/resource_field_selector.h"

namespace kubecpp::model::internal::pod::container
{

struct SecretKeySelector
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct ConfigMapKeySelector
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct EnvVarSource
{
    Checked<ConfigMapKeySelector> ConfigMapKeyRef{ "configMapKeyRef", false, "description" };
    Checked<common::ObjectFieldSelector> FieldRef{ "fieldRef", false, "description" };
    Checked<common::ResourceFieldSelector> ResourceFieldRef{ "resourceFieldRef", false, "description" };
    Checked<SecretKeySelector> SecretKeyRef{ "secretKeyRef", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct EnvVar
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Value{ "value", false, "description" };
    Checked<EnvVarSource> ValueFrom{ "valueFrom", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod::container

#endif // ENV_VAR_H_