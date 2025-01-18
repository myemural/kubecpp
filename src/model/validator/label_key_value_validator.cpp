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

#include "kubecpp/model/validator/label_key_value_validator.h"

#include <regex>

namespace kubecpp::model::validator
{

bool LabelKeyValueValidator::Validate(const std::unordered_map<std::string, std::string>& newValue)
{
    return std::all_of(newValue.begin(), newValue.end(), [](const auto& item) {
        const bool isKeyPassed = (item.first.length() <= labelKeyMaxLength) &&
        std::regex_match(item.first, std::regex("[a-zA-Z0-9]+(-_/.[a-zA-Z0-9]+)*"));
        const bool isValuePassed = (item.second.length() <= labelKeyMaxLength) &&
        std::regex_match(item.second, std::regex("[a-zA-Z0-9]+(-_/.[a-zA-Z0-9]+)*"));
        return isKeyPassed && isValuePassed;
    });
}

} // namespace kubecpp::model::validator