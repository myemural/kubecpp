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

#include "kubecpp/api/core_api.h"

#include <iostream>
#include <sstream>

#include "kubecpp/common/string_utils.h"
#include "kubecpp/model/pod.h"

namespace kubecpp::api::core::v1
{

namespace
{

inline constexpr const char* kResourceNameSingular = "pod";
inline constexpr const char* kResourceNamePlural   = "pods";
inline constexpr const char* kApiVersion           = "v1";

} // namespace

using namespace kubecpp::common;
using namespace kubecpp::common::constants;
using kubecpp::model::core::v1::Pod;
using kubecpp::model::internal::common::DeleteOptions;

template <>
ApiResult<Pod> CoreApi::Create<Pod>(const std::string& nameSpace, const Pod& resource, const QueryParams& queryParams) const
{
    // Build path
    std::string path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural });
    BuildQueryParams(path, queryParams);

    // Parse resource to Json
    const auto body = resource.ParseToJson();

    // Execute ApiClient
    const auto result = client_.Execute(client::HttpMethod::kPost, path, body);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod data = Pod::ParseFromJson(result.Body);
        return ApiResult<Pod>{ result.StatusCode, data };
    }

    return ApiResult<Pod>{ result.StatusCode };
}

template <>
ApiResult<Pod>
CoreApi::Get<Pod>(const std::string& name, const std::string& nameSpace, const PodGetFilter& filter, const QueryParams& queryParams) const
{
    // Build Path
    std::string path;
    switch(filter) {
    case PodGetFilter::kAll:
        path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name });
        break;
    case PodGetFilter::kEphemeralContainer:
        path = BuildPath(
        { kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name, "ephemeralcontainers" });
        break;
    case PodGetFilter::kStatus:
        path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name, "status" });
        break;
    }
    BuildQueryParams(path, queryParams);

    // Execute ApiClient
    auto result = client_.Execute(client::HttpMethod::kGet, path);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod data = Pod::ParseFromJson(result.Body);
        return ApiResult<Pod>{ result.StatusCode, data };
    }

    return ApiResult<Pod>{ result.StatusCode };
}

template <>
ApiResult<Pod::ListType> CoreApi::List<Pod>(const QueryParams& queryParams) const
{
    // Build Path
    std::string path = BuildPath({ kK8sApiKeyword, kApiVersion, kResourceNamePlural });
    BuildQueryParams(path, queryParams);

    // Execute ApiClient
    auto result = client_.Execute(client::HttpMethod::kGet, path);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod::ListType data = Pod::ListType::ParseFromJson(result.Body);
        return ApiResult<Pod::ListType>{ result.StatusCode, data };
    }

    return ApiResult<Pod::ListType>{ result.StatusCode };
}

template <>
ApiResult<Pod::ListType> CoreApi::List<Pod>(const std::string& nameSpace, const QueryParams& queryParams) const
{
    // Build Path
    std::string path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural });
    BuildQueryParams(path, queryParams);

    // Execute ApiClient
    auto result = client_.Execute(client::HttpMethod::kGet, path);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod::ListType data = Pod::ListType::ParseFromJson(result.Body);
        return ApiResult<Pod::ListType>{ result.StatusCode, data };
    }

    return ApiResult<Pod::ListType>{ result.StatusCode };
}

template <>
ApiResult<Pod> CoreApi::Delete<Pod>(const std::string& name,
const std::string& nameSpace,
const model::internal::common::DeleteOptions& options,
const QueryParams& queryParams) const
{
    // Create path
    std::string path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name });
    BuildQueryParams(path, queryParams);

    // Parse resource to Json
    const auto body = options.ParseToJson();

    // Execute ApiClient
    const auto result = client_.Execute(client::HttpMethod::kDelete, path, body);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod data = Pod::ParseFromJson(result.Body);
        return ApiResult<Pod>{ result.StatusCode, data };
    }

    return ApiResult<Pod>{ result.StatusCode };
}

template <>
ApiResult<Pod::ListType> CoreApi::DeleteCollection<Pod>(const std::string& nameSpace,
const model::internal::common::DeleteOptions& options,
const QueryParams& queryParams) const
{
    // Create path
    std::string path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural });
    BuildQueryParams(path, queryParams);

    // Parse resource to Json
    const auto body = options.ParseToJson();

    // Execute ApiClient
    const auto result = client_.Execute(client::HttpMethod::kDelete, path, body);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod::ListType data = Pod::ListType::ParseFromJson(result.Body);
        return ApiResult<Pod::ListType>{ result.StatusCode, data };
    }

    return ApiResult<Pod::ListType>{ result.StatusCode };
}

template <>
ApiResult<Pod> CoreApi::Update<Pod>(const std::string& name,
const std::string& nameSpace,
const Pod& newResource,
const PodUpdateFilter& filter,
const QueryParams& queryParams) const
{
    // Build Path
    std::string path;
    switch(filter) {
    case PodUpdateFilter::kAll:
        path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name });
        break;
    case PodUpdateFilter::kEphemeralContainer:
        path = BuildPath(
        { kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name, "ephemeralcontainers" });
        break;
    case PodUpdateFilter::kStatus:
        path = BuildPath({ kK8sApiKeyword, kApiVersion, kK8sNamespacesKeyword, nameSpace, kResourceNamePlural, name, "status" });
        break;
    }
    BuildQueryParams(path, queryParams);

    // Parse new resource to Json
    const auto body = newResource.ParseToJson();

    // Execute ApiClient
    auto result = client_.Execute(client::HttpMethod::kPut, path, body);

    // Convert body to resource type
    if(result.ErrorInfo.ErrorCode != 0L) {
        const Pod data = Pod::ParseFromJson(result.Body);
        return ApiResult<Pod>{ result.StatusCode, data };
    }

    return ApiResult<Pod>{ result.StatusCode };
}

template <>
ApiResult<Pod> CoreApi::Patch([[maybe_unused]] const std::string& name,
[[maybe_unused]] const std::string& nameSpace,
[[maybe_unused]] const std::string& patch,
[[maybe_unused]] const PodPatchFilter& filter,
[[maybe_unused]] const QueryParams& queryParams) const
{
    return ApiResult<Pod>{ 200 };
}

} // namespace kubecpp::api::core::v1