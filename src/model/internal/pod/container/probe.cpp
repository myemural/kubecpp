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

#include "kubecpp/model/internal/pod/container/probe.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::pod::container
{

std::string Probe::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_OBJECT_FIELD(result, Exec);
    CHECK_AND_SET_OBJECT_FIELD(result, HttpGet);
    CHECK_AND_SET_OBJECT_FIELD(result, TcpSocket);
    CHECK_AND_SET_FIELD(result, InitialDelaySeconds);
    CHECK_AND_SET_FIELD(result, TerminationGracePeriodSeconds);
    CHECK_AND_SET_FIELD(result, PeriodSeconds);
    CHECK_AND_SET_FIELD(result, TimeoutSeconds);
    CHECK_AND_SET_FIELD(result, FailureThreshold);
    CHECK_AND_SET_FIELD(result, SuccessThreshold);
    CHECK_AND_SET_OBJECT_FIELD(result, Grpc);
    return nlohmann::to_string(result);
}

} // namespace kubecpp::model::internal::pod::container