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

#ifndef DNS_LABEL_NAME_VALIDATOR_H_
#define DNS_LABEL_NAME_VALIDATOR_H_

#include <regex>
#include <string>

#include "validator.h"

class DnsLabelNameValidator : public IValidator<std::string>
{
public:
    ~DnsLabelNameValidator() override = default;

    bool Validate(const std::string& newValue) override
    {
        return (newValue.length() <= dnsLabelMaxLength) && std::regex_match(newValue, std::regex(dnsLabelRegexPattern));
    }

private:
    static inline int dnsLabelMaxLength            = 63;
    static inline const char* dnsLabelRegexPattern = "[a-z0-9]+(-[a-z0-9]+)*";
};

#endif // DNS_LABEL_NAME_VALIDATOR_H_