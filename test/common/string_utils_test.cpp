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

TEST(StringUtilsTest, BuildPath_WhenSimpleArgumentsProvided_ThenExpectCorrectBehavior)
{
    const std::string result = BuildPath({ "test", "path", "here" });
    ASSERT_STREQ(result.c_str(), "test/path/here");
}