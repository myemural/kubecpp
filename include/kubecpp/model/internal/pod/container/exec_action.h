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

#ifndef EXEC_ACTION_H_
#define EXEC_ACTION_H_

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct ExecAction
{
    Checked<std::vector<std::string>> Command{ "command", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static ExecAction ParseFromJson(const std::string& jsonData);
};

struct ExecActionBuilder
{
    ExecActionBuilder& Command(const std::vector<std::string>& command);

    ExecAction Build();

private:
    ExecAction execAction_;
};

} // namespace kubecpp::model::internal::pod::container

#endif // EXEC_ACTION_H_