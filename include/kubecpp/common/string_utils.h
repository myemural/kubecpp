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

#ifndef STRING_UTILS_H_
#define STRING_UTILS_H_

#include <sstream>
#include <string>
#include <unordered_map>
#include <initializer_list>

#include "kubecpp/common/constants.h"

namespace kubecpp::common
{

inline std::string BuildPath(const std::initializer_list<std::string>& args)
{
    std::string path;
    std::ostringstream stream;
    for (const auto arg : args) {
        stream << arg << constants::kPathSeparator;
    }
    path = stream.str();
    path.pop_back();
    return path;
}

inline void BuildQueryParams(std::string& path, const std::unordered_map<std::string, std::string>& queryParams)
{
    if(!queryParams.empty()) {
        path += constants::kQuerySeparator;
        bool isFirst = true;
        for(const auto& [paramKey, paramValue] : queryParams) {
            if(!isFirst) {
                path += constants::kQueryAnd;
                isFirst = false;
            }
            path += paramKey;
            path += constants::kQueryEqual;
            path += paramValue;
        }
    }
}

} // namespace kubecpp::common

#endif // STRING_UTILS_H_