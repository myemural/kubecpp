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

#ifndef CHECKED_H_
#define CHECKED_H_

#include <optional>
#include <stdexcept>
#include <string>

#include "kubecpp/model/validator/null_validator.h"

template <typename Type, typename ValidatorType = kubecpp::model::validator::NullValidator<Type>>
class Checked
{
public:
    using InternalType = Type;

    struct FieldProps
    {
        std::string KeyName;
        bool IsRequired;
        std::string KeyDescription;
    };

    template <typename... Args>
    Checked(const std::string& keyName, bool isRequired, const std::string& description, Args&&... args)
        : fieldProps_{ keyName, isRequired, description }, validator_{ std::forward<Args>(args)... }, value_{ std::nullopt }
    {}

    Checked& operator=(const Type& val)
    {
        if constexpr(!std::is_same_v<ValidatorType, kubecpp::model::validator::NullValidator<Type>>) {
            if(!validator_.Validate(val)) {
                throw std::runtime_error(std::string("Invalid value in " + fieldProps_.KeyDescription));
            }
        }
        value_ = val;
        return *this;
    }

    Checked& operator=(Type&& val)
    {
        if constexpr(!std::is_same_v<ValidatorType, kubecpp::model::validator::NullValidator<Type>>) {
            if(!validator_.Validate(val)) {
                throw std::runtime_error(std::string("Invalid value in " + fieldProps_.KeyDescription));
            }
        }
        value_ = std::move(val);
        return *this;
    }

    [[nodiscard]] bool HasValue() const noexcept
    {
        return value_.has_value();
    }

    void Unset() noexcept
    {
        value_.reset();
    }

    [[nodiscard]] std::string GetKeyName() const
    {
        return fieldProps_.KeyName;
    }

    [[nodiscard]] bool IsRequired() const
    {
        return fieldProps_.IsRequired;
    }

    [[nodiscard]] Type GetValue() const noexcept
    {
        return value_.value_or(Type{});
    }

private:
    FieldProps fieldProps_;
    ValidatorType validator_;
    std::optional<Type> value_;
};

#endif // CHECKED_H_