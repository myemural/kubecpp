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

#ifndef LIFECYCLE_H_
#define LIFECYCLE_H_

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/pod/container/exec_action.h"
#include "kubecpp/model/internal/pod/container/http_get_action.h"
#include "kubecpp/model/internal/pod/container/sleep_action.h"
#include "kubecpp/model/internal/pod/container/tcp_socket_action.h"

namespace kubecpp::model::internal::pod::container
{

struct LifecycleHandler
{
    Checked<ExecAction> Exec{ "exec", false, "description" };
    Checked<HTTPGetAction> HttpGet{ "httpGet", false, "description" };
    Checked<SleepAction> Sleep{ "sleep", false, "description" };
    Checked<TCPSocketAction> TcpSocket{ "tcpSocket", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct Lifecycle
{
    Checked<LifecycleHandler> PostStart{ "postStart", false, "description" };
    Checked<LifecycleHandler> PreStop{ "preStop", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

} // namespace kubecpp::model::internal::pod::container

#endif // LIFECYCLE_H_