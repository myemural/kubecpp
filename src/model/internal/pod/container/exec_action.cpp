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

#include "kubecpp/model/internal/pod/container/exec_action.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string ExecAction::ParseToJson() const
{
    return ParseFieldsToJson(Command);
}

ExecAction ExecAction::ParseFromJson(const std::string& jsonData)
{
    ExecAction result;
    ParseFieldsFromJson(jsonData, result.Command);
    return result;
}

ExecActionBuilder& ExecActionBuilder::Command(const std::vector<std::string>& command)
{
    execAction_.Command = command;
    return *this;
}

ExecAction ExecActionBuilder::Build()
{
    return std::move(execAction_);
}


} // namespace kubecpp::model::internal::pod::container