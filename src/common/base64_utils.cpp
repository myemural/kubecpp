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

#include "kubecpp/common/base64_utils.h"

#include <vector>

namespace kubecpp::common
{

namespace
{

inline constexpr const char* kBase64Chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                            "abcdefghijklmnopqrstuvwxyz"
                                            "0123456789+/";

/// TODO: BEGIN can be generalized later.
inline bool CheckBase64(std::string_view input)
{
    return (input.find("BEGIN") == std::string_view::npos);
}

} // namespace

/**
 * Decodes the given BASE64 string to a normal string.
 * Source: https://gist.github.com/williamdes/308b95ac9ef1ee89ae0143529c361d37
 **/
std::string DecodeBase64(std::string_view input)
{
    if(!CheckBase64(input)) {
        return std::string(input);
    }

    std::string out;

    std::vector<int> temp(256, -1);
    for(size_t i = 0; i < 64; i++) {
        temp[kBase64Chars[i]] = static_cast<int>(i);
    }

    int val  = 0;
    int valb = -8;
    for(const auto character : input) {
        if(temp[character] == -1) {
            break;
        }
        val = (val << 6) + temp[character];
        valb += 6;
        if(valb >= 0) {
            out.push_back(static_cast<char>((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

} // namespace kubecpp::common