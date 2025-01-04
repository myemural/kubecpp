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

#include "kubecpp/model/internal/pod/container/env_var.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod::container
{

std::string SecretKeySelector::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Key);
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Optional);
    return nlohmann::to_string(result);
}

std::string ConfigMapKeySelector::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Key);
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Optional);
    return nlohmann::to_string(result);
}

std::string EnvVarSource::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, ConfigMapKeyRef);
    CHECK_AND_SET_OBJECT_FIELD(result, FieldRef);
    CHECK_AND_SET_OBJECT_FIELD(result, ResourceFieldRef);
    CHECK_AND_SET_OBJECT_FIELD(result, SecretKeyRef);
    return nlohmann::to_string(result);
}

std::string EnvVar::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Value);
    CHECK_AND_SET_OBJECT_FIELD(result, ValueFrom);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod::container