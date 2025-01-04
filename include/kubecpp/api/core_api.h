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

#ifndef CORE_API_H_
#define CORE_API_H_

#include <unordered_map>

#include "kubecpp/client/api_client.h"
#include "kubecpp/common/api_result.h"
#include "kubecpp/model/internal/common/delete_options.h"

namespace kubecpp::api::core::v1
{

/// TODO: Log is not handling for now
enum class PodGetFilter : std::uint8_t { kAll, kStatus, kEphemeralContainer, kLog };

enum class PodUpdateFilter : std::uint8_t { kAll, kStatus, kEphemeralContainer };

enum class PodPatchFilter : std::uint8_t { kAll, kStatus, kEphemeralContainer };

using QueryParams = std::unordered_map<std::string, std::string>;

class CoreApi
{
public:
    explicit CoreApi(const client::ApiClient& client)
        : client_{ client }
    {}

    template <typename T>
    ApiResult<T> Create(const T& resource, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<T> Create(const std::string& nameSpace, const T& resource, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<T> Create(std::string podName, std::string nameSpace, const T& resource, const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T> Get(const std::string& name, const FilterType& filter, const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T>
    Get(const std::string& name, const std::string& nameSpace, const FilterType& filter, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<typename T::ListType> List(const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<typename T::ListType> List(const std::string& nameSpace, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<T>
    Delete(const std::string& name, const model::internal::common::DeleteOptions& options, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<T> Delete(const std::string& name,
    const std::string& nameSpace,
    const model::internal::common::DeleteOptions& options,
    const QueryParams& queryParams = {}) const;

    template <typename T, typename ReturnType>
    ApiResult<ReturnType>
    DeleteCollection(const model::internal::common::DeleteOptions& options, const QueryParams& queryParams = {}) const;

    template <typename T>
    ApiResult<typename T::ListType> DeleteCollection(const std::string& nameSpace,
    const model::internal::common::DeleteOptions& options,
    const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T>
    Update(const std::string& name, const T& newResource, const FilterType& filter, const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T> Update(const std::string& name,
    const std::string& nameSpace,
    const T& newResource,
    const FilterType& filter,
    const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T>
    Patch(const std::string& name, const std::string& patch, const FilterType& filter, const QueryParams& queryParams = {}) const;

    template <typename T, typename FilterType>
    ApiResult<T> Patch(const std::string& name,
    const std::string& nameSpace,
    const std::string& patch,
    const FilterType& filter,
    const QueryParams& queryParams = {}) const;

private:
    client::ApiClient client_;
};

} // namespace kubecpp::api::core::v1

#endif // CORE_API_H_