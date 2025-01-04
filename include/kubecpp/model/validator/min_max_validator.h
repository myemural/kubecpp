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

#ifndef MIN_MAX_VALIDATOR_H_
#define MIN_MAX_VALIDATOR_H_

#include <string>
#include "validator.h"

template <typename T>
class MinMaxValidator : public IValidator<T>
{
    CHECK_ARITHMETIC(T);
    CHECK_NOT_BOOL(T);

public:
    MinMaxValidator(T minValue, T maxValue)
        : minValue_{ minValue }, maxValue_{ maxValue }
    {}

    virtual bool Validate(const T& newValue) override
    {
        return newValue >= minValue_ && newValue <= maxValue_;
    }

protected:
    T minValue_;
    T maxValue_;
};

template <>
class MinMaxValidator<std::string> : public IValidator<std::string>
{
public:
    MinMaxValidator(std::string minValue, std::string maxValue)
        : minValue_{ minValue }, maxValue_{ maxValue }
    {}

    virtual bool Validate(const std::string& newValue) override
    {
        long long val    = std::stoll(newValue);
        long long minVal = std::stoll(minValue_);
        long long maxVal = std::stoll(maxValue_);
        return val >= minVal && val <= maxVal;
    }

protected:
    std::string minValue_;
    std::string maxValue_;
};

template <typename T>
class MinMaxTestValidator final : public MinMaxValidator<T>
{
public:
    using MinMaxValidator<T>::MinMaxValidator;

    MinMaxTestValidator(T minValue, T maxValue, T testValue)
        : MinMaxValidator<T>{ minValue, maxValue }, testValue_{ testValue }
    {}

    virtual bool Validate(const T& newValue) override final
    {
        return newValue >= MinMaxValidator<T>::Validate(newValue) && newValue == testValue_;
    }

protected:
    T testValue_;
};

#endif // MIN_MAX_VALIDATOR_H_