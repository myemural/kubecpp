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

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

#include "kubecpp/model/validator/validator.h"

template <typename Type>
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

    Checked(const std::string& keyName, bool isRequired, const std::string& description)
        : fieldProps_{ keyName, isRequired, description }, value_{ std::nullopt }
    {}

    Checked(const std::string& keyName,
    bool isRequired,
    const std::string& description,
    std::shared_ptr<kubecpp::model::validator::IValidator<Type>> validator)
        : fieldProps_{ keyName, isRequired, description }, value_{ std::nullopt }, validator_{ std::move(validator) }
    {}

    Checked& operator=(const Type& val)
    {
        if(validator_ && !validator_->Validate(val)) {
            throw std::runtime_error(std::string("Invalid value in " + fieldProps_.KeyDescription));
        }
        value_ = val;
        return *this;
    }

    Checked& operator=(Type&& val)
    {
        if(validator_ && !validator_->Validate(val)) {
            throw std::runtime_error(std::string("Invalid value in " + fieldProps_.KeyDescription));
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
    std::optional<Type> value_;
    std::shared_ptr<kubecpp::model::validator::IValidator<Type>> validator_;
};

#endif // CHECKED_H_