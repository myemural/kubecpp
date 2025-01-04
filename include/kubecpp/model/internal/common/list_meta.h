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

#ifndef LIST_META_H_
#define LIST_META_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct ListMeta
{
    Checked<std::string> Continue{ "continue", false, "description" };
    Checked<int64_t> RemainingItemCount{ "remainingItemCount", false, "description" };
    Checked<std::string> ResourceVersion{ "resourceVersion", false, "description" };
    Checked<std::string> SelfLink{ "selfLink", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    ListMeta ParseFromJson(const std::string& jsonData);
};

struct ListMetaBuilder
{
    ListMetaBuilder& Continue(const std::string& cont);

    ListMetaBuilder& RemainingItemCount(int64_t remainingItemCount);

    ListMetaBuilder& ResourceVersion(const std::string& resourceVersion);

    ListMetaBuilder& SelfLink(const std::string& selfLink);

    ListMeta Build();

private:
    ListMeta listMeta_;
};

} // namespace kubecpp::model::internal::common

#endif // LIST_META_H_