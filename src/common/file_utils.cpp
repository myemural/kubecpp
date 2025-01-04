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

#include <fstream>
#include <iostream>
#include <sstream>

#ifndef WINDOWS_OS
#include <unistd.h>

#define KUBE_CONFIG_TEMPFILE_NAME_PATTERN "/tmp/kubeconfig-XXXXXX"

#else
#include <fcntl.h>
#include <io.h>

#define KUBE_CONFIG_TEMPFILE_NAME_PATTERN "\\kubeconfig-XXXXXX"

#endif

#include "kubecpp/common/base64_utils.h"

namespace kubecpp::common
{

std::string CreateCertKeyTempFile(const std::string& data)
{
    std::string decodedData = DecodeBase64(data);

// Create tempfile
#ifndef WINDOWS_OS
    char tempFileName[] = KUBE_CONFIG_TEMPFILE_NAME_PATTERN;
    const int fileDesc  = mkstemp(tempFileName);
#else
    const std::string tempDirectory = getenv("TEMP");
    std::string tempFileFullPath    = tempDirectory + KUBE_CONFIG_TEMPFILE_NAME_PATTERN;
    std::string fileName            = _mktemp(tempFileFullPath.data());
    const int fileDesc              = _sopen(fileName.c_str(), O_CREAT | O_WRONLY, _SH_DENYWR, _S_IREAD | _S_IWRITE);
#endif

    if(fileDesc == -1) {
        std::cerr << "File couldn't be opened: " << fileName << '\n';
        return {};
    }

// Write data to file
#ifndef WINDOWS_OS
    const int ret = write(fileDesc, decodedData.c_str(), decodedData.length());
    close(fileDesc);
#else
    const int ret = _write(fileDesc, decodedData.c_str(), decodedData.length());
    _close(fileDesc);
#endif

    if(ret == -1) {
        std::cerr << "File couldn't be written: " << fileName << '\n';
        return {};
    }

    return fileName;
}

void RemoveTempFile(const std::string& fileName)
{
    if(!fileName.empty()) {
        unlink(fileName.c_str());
    }
}

std::string ReadAllFile(const std::string& filePath)
{
    std::string result;
    const std::ifstream file(filePath);
    if(!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << '\n';
        return {};
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    result = buffer.str();
    return result;
}

} // namespace kubecpp::common