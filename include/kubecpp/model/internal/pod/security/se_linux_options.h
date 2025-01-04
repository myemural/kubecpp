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

#ifndef SE_LINUX_OPTIONS_H_
#define SE_LINUX_OPTIONS_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::security
{

struct SELinuxOptions
{
    Checked<std::string> Level{ "level", false, "description" };
    Checked<std::string> Role{ "role", false, "description" };
    Checked<std::string> Type{ "type", false, "description" };
    Checked<std::string> User{ "user", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod::security

#endif // SE_LINUX_OPTIONS_H_