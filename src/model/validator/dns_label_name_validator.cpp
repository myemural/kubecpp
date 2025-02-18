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

#include "kubecpp/model/validator/dns_label_name_validator.h"

#include <regex>

namespace kubecpp::model::validator
{

bool DnsLabelNameValidator::Validate(const std::string& newValue)
{
    return (newValue.length() <= kDnsLabelMaxLength) && std::regex_match(newValue, std::regex(dnsLabelRegexPattern));
}

} // namespace kubecpp::model::validator