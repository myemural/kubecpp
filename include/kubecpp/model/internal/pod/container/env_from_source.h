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

#ifndef ENV_FROM_SOURCE_H_
#define ENV_FROM_SOURCE_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct SecretEnvSource
{
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct ConfigMapEnvSource
{
    Checked<std::string> Name{ "name", false, "description" };
    Checked<bool> Optional{ "optional", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct EnvFromSource
{
    Checked<ConfigMapEnvSource> ConfigMapRef{ "configMapRef", false, "description" };
    Checked<std::string> Prefix{ "prefix", false, "description" };
    Checked<SecretEnvSource> SecretRef{ "secretRef", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod::container

#endif // ENV_FROM_SOURCE_H_