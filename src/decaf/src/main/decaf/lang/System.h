/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _DECAF_LANG_SYSTEM_H_
#define _DECAF_LANG_SYSTEM_H_

#include <decaf/util/Config.h>
#include <decaf/lang/Exception.h>
#include <decaf/internal/AprPool.h>
#include <string>

namespace decaf{
namespace lang{

    class DECAF_API System {
    private:

        static internal::AprPool aprPool;

    public:

        System();
        virtual ~System() {}

    public:  // Static Methods

        /**
         * Reads an environment value from the system and returns it as a
         * string object
         * @param name - the env var to read
         * @return a string with the value from the var or ""
         * @throws an Exception if an error occurs while reading the Env.
         */
        static std::string getenv( const std::string& name )
            throw ( lang::Exception );

    };

}}

#endif /*_DECAF_LANG_SYSTEM_H_*/
