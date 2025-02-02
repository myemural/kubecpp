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

#ifndef JSON_UTILS_H_
#define JSON_UTILS_H_

#include <exception>
#include <type_traits>
#include <unordered_map>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"

template <typename T>
inline void SetField(rapidjson::Writer<rapidjson::StringBuffer>& writer, const Checked<T>& field)
{
    if(field.HasValue()) {
        writer.Key(field.GetKeyName().c_str());
        if constexpr(std::is_same_v<std::string, T>) {
            writer.String(field.GetValue().c_str());
        } else if constexpr(std::is_same_v<std::int32_t, T>) {
            writer.Int(field.GetValue());
        } else if constexpr(std::is_same_v<std::int64_t, T>) {
            writer.Int64(field.GetValue());
        } else if constexpr(std::is_same_v<bool, T>) {
            writer.Bool(field.GetValue());
        } else {
            const auto& fieldJson = field.GetValue().ParseToJson();
            writer.RawValue(fieldJson.c_str(), fieldJson.length(), rapidjson::kObjectType);
        }
    } else if(field.IsRequired()) {
        throw std::runtime_error(field.GetKeyName());
    }
}

template <typename T>
inline void SetField(rapidjson::Writer<rapidjson::StringBuffer>& writer, const Checked<std::vector<T>>& field)
{
    if(field.HasValue()) {
        writer.Key(field.GetKeyName().c_str());
        writer.StartArray();
        if constexpr(std::is_same_v<std::string, T>) {
            for(const auto& item : field.GetValue()) {
                writer.String(item.c_str());
            }
        } else if constexpr(std::is_same_v<std::int64_t, T>) {
            for(const auto& item : field.GetValue()) {
                writer.Int64(item);
            }
        } else {
            for(const auto& item : field.GetValue()) {
                const auto& itemJson = item.ParseToJson();
                writer.RawValue(itemJson.c_str(), itemJson.length(), rapidjson::kObjectType);
            }
        }
        writer.EndArray();
    } else if(field.IsRequired()) {
        throw std::runtime_error(field.GetKeyName());
    }
}

template <typename T>
inline void SetField(rapidjson::Writer<rapidjson::StringBuffer>& writer, const Checked<std::unordered_map<std::string, T>>& field)
{
    if(field.HasValue()) {
        writer.Key(field.GetKeyName().c_str());
        writer.StartObject();
        if constexpr(std::is_same_v<std::string, T>) {
            for(const auto& item : field.GetValue()) {
                writer.Key(item.first.c_str());
                writer.String(item.second.c_str());
            }
        } else {
            for(const auto& item : field.GetValue()) {
                writer.Key(item.first.c_str());
                const auto& itemJson = item.second.ParseToJson();
                writer.RawValue(itemJson.c_str(), itemJson.length(), rapidjson::kObjectType);
            }
        }
        writer.EndObject();
    } else if(field.IsRequired()) {
        throw std::runtime_error(field.GetKeyName());
    }
}

template <typename... Fields>
inline std::string ParseFieldsToJson(Fields&&... fields)
{
    rapidjson::StringBuffer lStringBuffer;
    rapidjson::Writer lWriter(lStringBuffer);

    lWriter.StartObject();
    (SetField(lWriter, fields), ...);
    lWriter.EndObject();

    return lStringBuffer.GetString();
}

template <typename T>
inline void GetField(const rapidjson::Document& doc, Checked<T>& field)
{
    if(const auto it = doc.FindMember(field.GetKeyName().c_str()); it != doc.MemberEnd()) {
        if constexpr(std::is_same_v<std::string, T>) {
            field = it->value.GetString();
        } else if constexpr(std::is_same_v<std::int32_t, T>) {
            field = it->value.GetInt();
        } else if constexpr(std::is_same_v<std::int64_t, T>) {
            field = it->value.GetInt64();
        } else if constexpr(std::is_same_v<bool, T>) {
            field = it->value.GetBool();
        } else {
            const auto& obj = it->value;
            rapidjson::StringBuffer sb;
            rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
            obj.Accept(writer);
            std::string s = sb.GetString();
            field         = T::ParseFromJson(s);
        }
    }
}

template <typename T>
inline void GetField(const rapidjson::Document& doc, Checked<std::vector<T>>& field)
{
    if(const auto it = doc.FindMember(field.GetKeyName().c_str()); it != doc.MemberEnd()) {
        if constexpr(std::is_same_v<std::string, T>) {
            std::vector<T> arrayField;
            for(const auto& item : it->value.GetArray()) {
                arrayField.push_back(item.GetString());
            }
            field = std::move(arrayField);
        } else {
            std::vector<T> arrayField;
            for(const auto& item : it->value.GetArray()) {
                rapidjson::StringBuffer sb;
                rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
                item.Accept(writer);
                std::string s = sb.GetString();
                arrayField.push_back(T::ParseFromJson(s));
            }
            field = std::move(arrayField);
        }
    }
}

template <typename T>
inline void GetField(const rapidjson::Document& doc, Checked<std::unordered_map<std::string, T>>& field)
{
    if(const auto it = doc.FindMember(field.GetKeyName().c_str()); it != doc.MemberEnd()) {
        if constexpr(std::is_same_v<std::string, T>) {
            std::unordered_map<std::string, T> mapField;
            for(const auto& item : it->value.GetObject()) {
                mapField[item.name.GetString()] = item.value.GetString();
            }
            field = std::move(mapField);
        } else {
            /// TODO: Will be implemented.
        }
    }
}

template <typename... Fields>
inline void ParseFieldsFromJson(const std::string& jsonData, Fields&&... fields)
{
    rapidjson::Document documentJson;
    documentJson.Parse(jsonData.data());
    (GetField(documentJson, fields), ...);
}

#endif // JSON_UTILS_H_