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

namespace kubecpp::model::internal::pod::container
{

std::string HTTPHeader::ParseToJson() const
{
    return ParseFieldsToJson(Name, Value);
}

HTTPHeader HTTPHeader::ParseFromJson(const std::string& jsonData)
{
    HTTPHeader result;
    ParseFieldsFromJson(jsonData, result.Name, result.Value);
    return result;
}

std::string HTTPGetAction::ParseToJson() const
{
    return ParseFieldsToJson(Port, Host, HttpHeaders, Path, Scheme);
}

HTTPGetAction HTTPGetAction::ParseFromJson(const std::string& jsonData)
{
    HTTPGetAction result;
    ParseFieldsFromJson(jsonData, result.Port, result.Host, result.HttpHeaders, result.Path, result.Scheme);
    return result;
}

} // namespace kubecpp::model::internal::pod::container