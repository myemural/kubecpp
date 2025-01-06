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

#ifndef NULL_VALIDATOR_H_
#define NULL_VALIDATOR_H_

#include "validator.h"

template <typename T>
class NullValidator final : public IValidator<T>
{
public:
    bool Validate([[maybe_unused]] const T& newValue) final
    {
        return true;
    }
};

#endif // NULL_VALIDATOR_H_