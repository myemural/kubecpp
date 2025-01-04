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

#ifndef LABEL_KEY_VALUE_VALIDATOR_H_
#define LABEL_KEY_VALUE_VALIDATOR_H_

#include <regex>
#include <string>
#include <unordered_map>

#include "validator.h"

class LabelKeyValueValidator : public IValidator<std::unordered_map<std::string, std::string>>
{
public:
    bool Validate(const std::unordered_map<std::string, std::string>& newValue) override
    {
        return std::all_of(newValue.begin(), newValue.end(), [](const auto& item) {
            const bool isKeyPassed = (item.first.length() <= labelKeyMaxLength) &&
            std::regex_match(item.first, std::regex("[a-zA-Z0-9]+(-_/.[a-zA-Z0-9]+)*"));
            const bool isValuePassed = (item.second.length() <= labelKeyMaxLength) &&
            std::regex_match(item.second, std::regex("[a-zA-Z0-9]+(-_/.[a-zA-Z0-9]+)*"));
            return isKeyPassed && isValuePassed;
        });
    }

private:
    static inline int labelKeyMaxLength = 63;
};

#endif // LABEL_KEY_VALUE_VALIDATOR_H_