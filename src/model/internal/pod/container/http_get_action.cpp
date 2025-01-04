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

#include "kubecpp/model/internal/pod/container/http_get_action.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod::container
{

std::string HTTPHeader::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, Value);
    return nlohmann::to_string(result);
}

std::string HTTPGetAction::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Port);
    CHECK_AND_SET_FIELD(result, Host);
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, HttpHeaders);
    CHECK_AND_SET_FIELD(result, Path);
    CHECK_AND_SET_FIELD(result, Scheme);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod::container