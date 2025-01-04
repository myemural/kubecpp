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

#define CHECK_INTEGRAL(Type)       static_assert(std::is_integral_v<Type> == true, "T is not an integral type")
#define CHECK_NOT_INTEGRAL(Type)   static_assert(std::is_integral_v<Type> == false, "T is an integral type")
#define CHECK_FLOATING(Type)       static_assert(std::is_floating_point_v<Type> == true, "T is not a floating-point type")
#define CHECK_NOT_FLOATING(Type)   static_assert(std::is_floating_point_v<Type> == false, "T is a floating-point type")
#define CHECK_ARITHMETIC(Type)     static_assert(std::is_arithmetic_v<Type> == true, "T is not an arithmetic type")
#define CHECK_NOT_ARITHMETIC(Type) static_assert(std::is_arithmetic_v<Type> == false, "T is an arithmetic type")
#define CHECK_BOOL(Type)           static_assert(std::is_same_v<Type, bool> == true, "T is not a bool type")
#define CHECK_NOT_BOOL(Type)       static_assert(std::is_same_v<Type, bool> == false, "T is a bool type")

#define CHECK_AND_SET_FIELD(result, x)                  \
    if((x).HasValue()) {                                \
        (result)[(x).GetKeyName()] = (x).GetValue();    \
    } else if((x).IsRequired()) {                       \
        throw std::exception((x).GetKeyName().c_str()); \
    }

#define CHECK_AND_SET_OBJECT_FIELD(result, x)                                             \
    if((x).HasValue()) {                                                                  \
        (result)[(x).GetKeyName()] = nlohmann::json::parse((x).GetValue().ParseToJson()); \
    } else if((x).IsRequired()) {                                                         \
        throw std::exception((x).GetKeyName().c_str());                                   \
    }

#define CHECK_AND_SET_FIELD_CONTAINER(result, x)        \
    if((x).HasValue()) {                                \
        const nlohmann::json itemJson((x).GetValue());  \
        (result)[(x).GetKeyName()] = itemJson;          \
    } else if((x).IsRequired()) {                       \
        throw std::exception((x).GetKeyName().c_str()); \
    }

#define CHECK_AND_SET_OBJECT_FIELD_LIST(result, x)                                     \
    if((x).HasValue()) {                                                               \
        for(const auto& item : (x).GetValue()) {                                       \
            const nlohmann::json itemJson = nlohmann::json::parse(item.ParseToJson()); \
            (result)[(x).GetKeyName()].push_back(itemJson);                            \
        }                                                                              \
    } else if((x).IsRequired()) {                                                      \
        throw std::exception((x).GetKeyName().c_str());                                \
    }

#endif // JSON_UTILS_H_