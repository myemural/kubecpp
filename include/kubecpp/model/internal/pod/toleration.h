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

#ifndef TOLERATION_H_
#define TOLERATION_H_

#include "kubecpp/common/checked.h"

namespace kubecpp::model::internal::pod
{

struct Toleration
{
    Checked<std::string> Key{ "key", false, "description" };
    Checked<std::string> Operator{ "operator", false, "description" };
    Checked<std::string> Value{ "value", false, "description" };
    Checked<std::string> Effect{ "effect", false, "description" };
    Checked<int64_t> TolerationSeconds{ "tolerationSeconds", false, "description" };

    [[nodiscard]] std::string ParseToJson() const;
    static Toleration ParseFromJson(const std::string& jsonData);
};

struct TolerationBuilder
{
    TolerationBuilder& Key(const std::string& key);

    TolerationBuilder& Operator(const std::string& oprt);

    TolerationBuilder& Value(const std::string& value);

    TolerationBuilder& Effect(const std::string& effect);

    TolerationBuilder& TolerationSeconds(int64_t tolerationSeconds);

    Toleration Build();

private:
    Toleration toleration_;
};

} // namespace kubecpp::model::internal::pod

#endif // TOLERATION_H_