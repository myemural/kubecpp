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

#include "kubecpp/model/internal/common/list_meta.h"

#include "kubecpp/common/json_utils.h"

#include "nlohmann/json.hpp"

namespace kubecpp::model::internal::common
{

std::string ListMeta::ParseToJson() const
{
    nlohmann::json result;
    CHECK_AND_SET_FIELD(result, Continue);
    CHECK_AND_SET_FIELD(result, RemainingItemCount);
    CHECK_AND_SET_FIELD(result, ResourceVersion);
    CHECK_AND_SET_FIELD(result, SelfLink);
    return nlohmann::to_string(result);
}

ListMeta ListMeta::ParseFromJson(const std::string& jsonData)
{
    ListMeta result;
    nlohmann::json data       = nlohmann::json::parse(jsonData);
    result.Continue           = data[result.Continue.GetKeyName()].template get<std::string>();
    result.RemainingItemCount = data[result.RemainingItemCount.GetKeyName()].template get<int64_t>();
    result.ResourceVersion    = data[result.ResourceVersion.GetKeyName()].template get<std::string>();
    result.SelfLink           = data[result.SelfLink.GetKeyName()].template get<std::string>();

    return result;
}

ListMetaBuilder& ListMetaBuilder::Continue(const std::string& cont)
{
    listMeta_.Continue = cont;
    return *this;
}

ListMetaBuilder& ListMetaBuilder::RemainingItemCount(int64_t remainingItemCount)
{
    listMeta_.RemainingItemCount = remainingItemCount;
    return *this;
}

ListMetaBuilder& ListMetaBuilder::ResourceVersion(const std::string& resourceVersion)
{
    listMeta_.ResourceVersion = resourceVersion;
    return *this;
}

ListMetaBuilder& ListMetaBuilder::SelfLink(const std::string& selfLink)
{
    listMeta_.SelfLink = selfLink;
    return *this;
}

ListMeta ListMetaBuilder::Build()
{
    return std::move(listMeta_);
}

} // namespace kubecpp::model::internal::common