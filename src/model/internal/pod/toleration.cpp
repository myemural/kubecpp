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

#include "kubecpp/model/internal/pod/toleration.h"

#include "kubecpp/common/json_utils.h"

namespace kubecpp::model::internal::pod
{

std::string Toleration::ParseToJson() const
{
    return ParseFieldsToJson(Key, Operator, Value, Effect, TolerationSeconds);
}

Toleration Toleration::ParseFromJson(const std::string& jsonData)
{
    Toleration result;
    ParseFieldsFromJson(jsonData, result.Key, result.Operator, result.Value, result.Effect, result.TolerationSeconds);
    return result;
}

TolerationBuilder& TolerationBuilder::Key(const std::string& key)
{
    toleration_.Key = key;
    return *this;
}

TolerationBuilder& TolerationBuilder::Operator(const std::string& oprt)
{
    toleration_.Operator = oprt;
    return *this;
}

TolerationBuilder& TolerationBuilder::Value(const std::string& value)
{
    toleration_.Value = value;
    return *this;
}

TolerationBuilder& TolerationBuilder::Effect(const std::string& effect)
{
    toleration_.Effect = effect;
    return *this;
}

TolerationBuilder& TolerationBuilder::TolerationSeconds(int64_t tolerationSeconds)
{
    toleration_.TolerationSeconds = tolerationSeconds;
    return *this;
}

Toleration TolerationBuilder::Build()
{
    return std::move(toleration_);
}

} // namespace kubecpp::model::internal::pod