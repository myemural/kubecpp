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

#include "kubecpp/model/internal/pod/container/sleep_action.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod::container
{

std::string SleepAction::ParseToJson() const
{
    return ParseFieldsToJson(Seconds);
}

SleepAction SleepAction::ParseFromJson(const std::string& jsonData)
{
    SleepAction result;
    ParseFieldsFromJson(jsonData, result.Seconds);
    return result;
}

SleepActionBuilder& SleepActionBuilder::Seconds(int64_t seconds)
{
    sleepAction_.Seconds = seconds;
    return *this;
}

SleepAction SleepActionBuilder::Build()
{
    return std::move(sleepAction_);
}

} // namespace kubecpp::model::internal::pod::container