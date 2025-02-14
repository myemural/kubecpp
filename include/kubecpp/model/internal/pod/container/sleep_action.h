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

#ifndef SLEEP_ACTION_H_
#define SLEEP_ACTION_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::container
{

struct SleepAction
{
    Checked<int64_t> Seconds{ "seconds", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static SleepAction ParseFromJson(const std::string& jsonData);
};

struct SleepActionBuilder
{
    SleepActionBuilder& Seconds(int64_t seconds);

    SleepAction Build();

private:
    SleepAction sleepAction_;
};

} // namespace kubecpp::model::internal::pod::container

#endif // SLEEP_ACTION_H_