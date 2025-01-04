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

#ifndef LABEL_SELECTOR_H_
#define LABEL_SELECTOR_H_

#include <map>

#include <vector>

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::common
{

struct LabelSelectorRequirement
{
    Checked<std::string> Key{ "key", true, "description" };
    Checked<std::string> Operator{ "operator", true, "description" };
    Checked<std::vector<std::string>> Values{ "values", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct LabelSelector
{
    Checked<std::vector<LabelSelectorRequirement>> MatchExpressions{ "matchExpressions", false, "description" };
    Checked<std::map<std::string, std::string>> MatchLabels{ "matchLabels", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
};

struct LabelSelectorRequirementBuilder
{
    LabelSelectorRequirementBuilder& Key(const std::string& key);

    LabelSelectorRequirementBuilder& Operator(const std::string& oprtr);

    LabelSelectorRequirementBuilder& Values(const std::vector<std::string>& values);

    LabelSelectorRequirement Build();

private:
    LabelSelectorRequirement labelSelectorRequirement_;
};

struct LabelSelectorBuilder
{
    LabelSelectorBuilder& MatchExpressions(const std::vector<LabelSelectorRequirement>& matchExpressions);

    LabelSelectorBuilder& MatchLabels(const std::map<std::string, std::string>& matchLabels);

    LabelSelector Build();

private:
    LabelSelector labelSelector_;
};

} // namespace kubecpp::model::internal::common

#endif // LABEL_SELECTOR_H_