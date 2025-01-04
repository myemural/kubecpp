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

template <typename T>
class ApiResult
{
public:
    ApiResult(long responseCode, T data)
        : responseCode_{ responseCode }, data_{ std::move(data) }
    {}

    [[nodiscard]] T GetData() const
    {
        return data_;
    }

    [[nodiscard]] long GetResponseCode() const
    {
        return responseCode_;
    }

private:
    long responseCode_;
    T data_;
};

#endif // API_RESULT_H_