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

#ifndef PROBE_H_
#define PROBE_H_

#include "kubecpp/common/checked.h"
#include "kubecpp/model/internal/pod/container/exec_action.h"
#include "kubecpp/model/internal/pod/container/grpc_action.h"
#include "kubecpp/model/internal/pod/container/http_get_action.h"
#include "kubecpp/model/internal/pod/container/tcp_socket_action.h"

namespace kubecpp::model::internal::pod::container
{

struct Probe
{
    Checked<ExecAction> Exec{ "exec", false, "description" };
    Checked<HTTPGetAction> HttpGet{ "httpGet", false, "description" };
    Checked<TCPSocketAction> TcpSocket{ "tcpSocket", false, "description" };
    Checked<int32_t> InitialDelaySeconds{ "initialDelaySeconds", false, "description" };
    Checked<int64_t> TerminationGracePeriodSeconds{ "terminationGracePeriodSeconds", false, "description" };
    Checked<int32_t> PeriodSeconds{ "periodSeconds", false, "description" };
    Checked<int32_t> TimeoutSeconds{ "timeoutSeconds", false, "description" };
    Checked<int32_t> FailureThreshold{ "failureThreshold", false, "description" };
    Checked<int32_t> SuccessThreshold{ "successThreshold", false, "description" };
    Checked<GRPCAction> Grpc{ "grpc", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static Probe ParseFromJson(const std::string& jsonData);
};

} // namespace kubecpp::model::internal::pod::container

#endif // PROBE_H_