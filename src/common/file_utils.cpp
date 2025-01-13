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

#include "kubecpp/common/file_utils.h"

#include <algorithm>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>

#include "kubecpp/common/base64_utils.h"

namespace kubecpp::common
{

namespace
{
const std::string kCharacterSet("abcdefghijklmnopqrstuvwxyz"
                                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "0123456789");

#ifdef WINDOWS_OS
inline constexpr const char kEnvVarValueDelim = ';';
#else
inline constexpr const char kEnvVarValueDelim = ':';
#endif
} // namespace

std::string CreateTempFile(const std::string& filePrefix, const std::string& data)
{
    std::string decodedData = DecodeBase64(data);

    // Create filename postfix
    std::string postfix("        ");
    std::random_device randomDevice;
    std::mt19937 engine(randomDevice());
    std::uniform_int_distribution<std::size_t> dist(0, kCharacterSet.length() - 1);
    std::for_each(postfix.begin(), postfix.end(), [&dist, &engine](char& c) { c = kCharacterSet[dist(engine)]; });

    // Create tempfile
    const auto tempFileName = filePrefix + "-" + postfix;
    const auto tempFilePath = std::filesystem::temp_directory_path().append(tempFileName);
    std::ofstream file(tempFilePath);
    if(!file.is_open()) {
        std::cerr << "Failed to open file: " << tempFilePath << '\n';
        return {};
    }
    file << decodedData;
    file.close();

    return tempFilePath.string();
}

void RemoveFile(const std::string& fileName)
{
    if(!fileName.empty()) {
        std::filesystem::remove(fileName);
    }
}

std::string ReadAllFile(const std::string& filePath)
{
    std::string result;
    const std::ifstream file(filePath);
    if(!file.is_open()) {
        throw std::runtime_error(std::string("Failed to open file: " + filePath));
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    result = buffer.str();
    return result;
}

std::vector<std::string> GetEnvVarValues(const std::string& envVarName)
{
    std::vector<std::string> result;

    char* envValue = std::getenv(envVarName.c_str());
    if(envValue) {
        std::stringstream ss{ envValue };
        std::string value;

        while(getline(ss, value, kEnvVarValueDelim)) {
            result.push_back(value);
        }
    }

    return result;
}

} // namespace kubecpp::common