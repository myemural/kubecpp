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

#ifndef HOST_IP_H_
#define HOST_IP_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod::status
{

struct HostIP
{
    Checked<std::string> Ip{ "ip", true, "description" };
};

} // namespace kubecpp::model::internal::pod::status

#endif // HOST_IP_H_