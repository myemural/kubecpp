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

#include "kubecpp/model/internal/common/status.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::common
{

std::string StatusCause::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Field);
    CHECK_AND_SET_FIELD(result, Message);
    CHECK_AND_SET_FIELD(result, Reason);
    return nlohmann::to_string(result);
}

std::string StatusDetails::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD_LIST(result, Causes);
    CHECK_AND_SET_FIELD(result, Group);
    CHECK_AND_SET_FIELD(result, Kind);
    CHECK_AND_SET_FIELD(result, Name);
    CHECK_AND_SET_FIELD(result, RetryAfterSeconds);
    CHECK_AND_SET_FIELD(result, Uid);
    return nlohmann::to_string(result);
}

std::string Status::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, ApiVersion);
    CHECK_AND_SET_FIELD(result, Code);
    CHECK_AND_SET_OBJECT_FIELD(result, Details);
    CHECK_AND_SET_FIELD(result, Kind);
    CHECK_AND_SET_FIELD(result, Message);
    CHECK_AND_SET_FIELD(result, Reason);
    CHECK_AND_SET_FIELD(result, StatusStr);
    return nlohmann::to_string(result);
}

Status Status::ParseFromJson(const std::string& jsonData)
{
    Status result;
    nlohmann::json data = nlohmann::json::parse(jsonData);
    return result;
}

} // namespace kubecpp::model::internal::common