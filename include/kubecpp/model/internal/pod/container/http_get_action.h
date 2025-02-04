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

#ifndef HTTP_GET_ACTION_H_
#define HTTP_GET_ACTION_H_

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct HTTPHeader
{
    Checked<std::string> Name{ "name", true, "description" };
    Checked<std::string> Value{ "value", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static HTTPHeader ParseFromJson(const std::string& jsonData);
};

struct HTTPGetAction
{
    Checked<std::string> Port{ "port", true, "description" }; // IntOrString
    Checked<std::string> Host{ "host", false, "description" };
    Checked<std::vector<HTTPHeader>> HttpHeaders{ "httpHeaders", false, "description" };
    Checked<std::string> Path{ "path", false, "description" };
    Checked<std::string> Scheme{ "scheme", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static HTTPGetAction ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::pod::container

#endif // HTTP_GET_ACTION_H_