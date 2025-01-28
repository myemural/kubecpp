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

#ifndef POD_SCHEDULING_NAME_H_
#define POD_SCHEDULING_NAME_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod
{

struct PodSchedulingGate
{
    Checked<std::string> Name{ "name", true, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static PodSchedulingGate ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::pod

#endif // POD_SCHEDULING_NAME_H_