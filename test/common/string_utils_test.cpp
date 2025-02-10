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

#include "kubecpp/common/string_utils.h"

#include "gtest/gtest.h"

using namespace kubecpp::common;

TEST(StringUtilsTest, BuildPath_WhenEmptyArgumentProvided_ThenExpectEmptyString)
{
    const std::string result = BuildPath({});
    ASSERT_TRUE(result.empty());
}

TEST(StringUtilsTest, BuildPath_WhenArgumentsProvided_ThenExpectPathString)
{
    const std::string result = BuildPath({ "test1", "test2", "test3" });
    ASSERT_STREQ(result.c_str(), "test1/test2/test3");
}

TEST(StringUtilsTest, BuildQueryParams_WhenEmptyArgumentProvided_ThenExpectEmptyString)
{
    std::string path;
    BuildQueryParams(path, {});
    ASSERT_TRUE(path.empty());
}

TEST(StringUtilsTest, BuildQueryParams_WhenSingleArgumentProvided_ThenExpectPathPlusQueryString)
{
    std::string path = "test1/test2";
    BuildQueryParams(path, { { "param1", "value1" } });
    ASSERT_STREQ(path.c_str(), "test1/test2?param1=value1");
}

TEST(StringUtilsTest, BuildQueryParams_WhenMultipleArgumentsProvided_ThenExpectPathPlusQueryString)
{
    std::string path = "test1/test2";
    BuildQueryParams(path, { { "param1", "value1" }, { "param2", "value2" }, { "param3", "value3" } });
    ASSERT_STREQ(path.c_str(), "test1/test2?param1=value1&param2=value2&param3=value3");
}