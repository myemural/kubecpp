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

#include <string>
#include <unordered_map>

#include "validator.h"

namespace kubecpp::model::validator
{

class LabelKeyValueValidator : public IValidator<std::unordered_map<std::string, std::string>>
{
public:
    bool Validate(const std::unordered_map<std::string, std::string>& newValue) override;

private:
    static inline size_t labelKeyMaxLength = 63;
};

} // namespace kubecpp::model::validator

#endif // LABEL_KEY_VALUE_VALIDATOR_H_