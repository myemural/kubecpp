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

#ifndef API_RESULT_H_
#define API_RESULT_H_

#include <optional>
#include <variant>

template <typename SuccessType, typename FailType>
class ApiResult
{
public:
    explicit ApiResult(long responseCode)
        : isNetworkError{ true }, responseCode_{ responseCode }
    {}

    ApiResult(long responseCode, SuccessType data)
        : isNetworkError{ false }, responseCode_{ responseCode }, data_{ std::move(data) }
    {}

    ApiResult(long responseCode, FailType data)
        : isNetworkError{ false }, responseCode_{ responseCode }, data_{ std::move(data) }
    {}

    [[nodiscard]] bool HasData() const
    {
        return !isNetworkError;
    }

    [[nodiscard]] bool IsFailed() const
    {
        return std::holds_alternative<FailType>(data_);
    }

    [[nodiscard]] SuccessType GetSuccessData() const
    {
        return std::get<SuccessType>(data_);
    }

    [[nodiscard]] FailType GetFailData() const
    {
        return std::get<FailType>(data_);
    }

    [[nodiscard]] long GetResponseCode() const
    {
        return responseCode_;
    }

private:
    bool isNetworkError;
    long responseCode_;
    std::variant<SuccessType, FailType> data_;
};

#endif // API_RESULT_H_