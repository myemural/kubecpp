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

#ifndef DELETE_OPTIONS_H_
#define DELETE_OPTIONS_H_

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct PreconditionsType
{
    Checked<std::string> ResourceVersion{ "resourceVersion", false, "description" };
    Checked<std::string> Uid{ "uid", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct DeleteOptions
{
    Checked<std::string> ApiVersion{ "apiVersion", false, "description" };
    Checked<std::vector<std::string>> DryRun{ "dryRun", false, "description" };
    Checked<int64_t> GracePeriodSeconds{ "gracePeriodSeconds", false, "description" };
    Checked<std::string> Kind{ "kind", false, "description" };
    Checked<bool> OrphanDependents{ "orphanDependents", false, "description" };
    Checked<PreconditionsType> Preconditions{ "preconditions", false, "description" };
    Checked<std::string> PropagationPolicy{ "propagationPolicy", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct PreConditionsBuilder
{
    PreConditionsBuilder& ResourceVersion(const std::string& resourceVersion);

    PreConditionsBuilder& Uid(const std::string& uid);

    PreconditionsType Build();

private:
    PreconditionsType preconditions_;
};

struct DeleteOptionsBuilder
{
    DeleteOptionsBuilder& ApiVersion(const std::string& apiVersion);

    DeleteOptionsBuilder& DryRun(const std::vector<std::string>& dryRun);

    DeleteOptionsBuilder& GracePeriodSeconds(int64_t gracePeriodSeconds);

    DeleteOptionsBuilder& Kind(const std::string& kind);

    DeleteOptionsBuilder& OrphanDependents(bool orphanDependents);

    DeleteOptionsBuilder& Preconditions(const PreconditionsType& preconditions);

    DeleteOptionsBuilder& PropagationPolicy(const std::string& propagationPolicy);

    DeleteOptions Build();

private:
    DeleteOptions deleteOptions_;
};

} // namespace kubecpp::model::internal::common

#endif // DELETE_OPTIONS_H_