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

#ifndef STATUS_H_
#define STATUS_H_

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct StatusCause
{
    Checked<std::string> Field{ "field", false, "description" };
    Checked<std::string> Message{ "message", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static StatusCause ParseFromJson(const std::string& jsonData);
};

struct StatusDetails
{
    Checked<std::vector<StatusCause>> Causes{ "causes", false, "description" };
    Checked<std::string> Group{ "group", false, "description" };
    Checked<std::string> Kind{ "kind", false, "description" };
    Checked<std::string> Name{ "name", false, "description" };
    Checked<int32_t> RetryAfterSeconds{ "retryAfterSeconds", false, "description" };
    Checked<std::string> Uid{ "uid", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static StatusDetails ParseFromJson(const std::string& jsonData);
};

struct Status
{
    Checked<std::string> ApiVersion{ "apiVersion", false, "description" };
    Checked<int32_t> Code{ "code", false, "description" };
    Checked<StatusDetails> Details{ "details", false, "description" };
    Checked<std::string> Kind{ "kind", false, "description" };
    Checked<std::string> Message{ "mesage", false, "description" };
    Checked<std::string> Reason{ "reason", false, "description" };
    Checked<std::string> StatusStr{ "status", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static Status ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::common

#endif // STATUS_H_