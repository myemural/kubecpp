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

#include "kubecpp/model/internal/common/delete_options.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::common
{

std::string PreconditionsType::ParseToJson() const
{
    return ParseFieldsToJson(ResourceVersion, Uid);
}

std::string DeleteOptions::ParseToJson() const
{
    return ParseFieldsToJson(ApiVersion, DryRun, GracePeriodSeconds, Kind, OrphanDependents, Preconditions, PropagationPolicy);
}

PreConditionsBuilder& PreConditionsBuilder::ResourceVersion(const std::string& resourceVersion)
{
    preconditions_.ResourceVersion = resourceVersion;
    return *this;
}

PreConditionsBuilder& PreConditionsBuilder::Uid(const std::string& uid)
{
    preconditions_.Uid = uid;
    return *this;
}

PreconditionsType PreConditionsBuilder::Build()
{
    return std::move(preconditions_);
}

DeleteOptionsBuilder& DeleteOptionsBuilder::ApiVersion(const std::string& apiVersion)
{
    deleteOptions_.ApiVersion = apiVersion;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::DryRun(const std::vector<std::string>& dryRun)
{
    deleteOptions_.DryRun = dryRun;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::GracePeriodSeconds(int64_t gracePeriodSeconds)
{
    deleteOptions_.GracePeriodSeconds = gracePeriodSeconds;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::Kind(const std::string& kind)
{
    deleteOptions_.Kind = kind;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::OrphanDependents(bool orphanDependents)
{
    deleteOptions_.OrphanDependents = orphanDependents;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::Preconditions(const PreconditionsType& preconditions)
{
    deleteOptions_.Preconditions = preconditions;
    return *this;
}

DeleteOptionsBuilder& DeleteOptionsBuilder::PropagationPolicy(const std::string& propagationPolicy)
{
    deleteOptions_.PropagationPolicy = propagationPolicy;
    return *this;
}

DeleteOptions DeleteOptionsBuilder::Build()
{
    return std::move(deleteOptions_);
}

} // namespace kubecpp::model::internal::common
