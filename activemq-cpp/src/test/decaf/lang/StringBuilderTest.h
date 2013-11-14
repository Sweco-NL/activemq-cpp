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

#ifndef _DECAF_LANG_STRINGBUILDERTEST_H_
#define _DECAF_LANG_STRINGBUILDERTEST_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

namespace decaf {
namespace lang {

    class StringBuilderTest : public CppUnit::TestFixture {
    private:

        CPPUNIT_TEST_SUITE( StringBuilderTest );
        CPPUNIT_TEST( testDefaultConstructor );
        CPPUNIT_TEST( testConstructorInt );
        CPPUNIT_TEST( testConstructorString );
        CPPUNIT_TEST( testAppendBoolean );
        CPPUNIT_TEST( testAppendChar );
        CPPUNIT_TEST( testAppendCharArray );
        CPPUNIT_TEST( testAppendCharArrayIntInt );
        CPPUNIT_TEST( testAppendCharSequence );
        CPPUNIT_TEST( testAppendCharSequenceIntInt );
        CPPUNIT_TEST( testAppendShort );
        CPPUNIT_TEST( testAppendInt );
        CPPUNIT_TEST( testAppendLong );
        CPPUNIT_TEST( testAppendDouble );
        CPPUNIT_TEST( testAppendFloat );
        CPPUNIT_TEST( testAppendString );
        CPPUNIT_TEST( testAppendStringBuffer );
        CPPUNIT_TEST( testAppendRawPointer );
        CPPUNIT_TEST( testAppendPointer );
        CPPUNIT_TEST( testCapacity );
        CPPUNIT_TEST( testCharAt );
        CPPUNIT_TEST( testDeleteRange );
        CPPUNIT_TEST( testDeleteCharAt );
        CPPUNIT_TEST( testEnsureCapacity );
        CPPUNIT_TEST( testGetChars );
        CPPUNIT_TEST( testIndexOfString );
        CPPUNIT_TEST( testIndexOfStringInt );
        CPPUNIT_TEST( testLastIndexOfString );
        CPPUNIT_TEST( testLastIndexOfStringInt );
        CPPUNIT_TEST_SUITE_END();

    public:

        StringBuilderTest();
        virtual ~StringBuilderTest();

        void testDefaultConstructor();
        void testConstructorInt();
        void testConstructorString();
        void testAppendBoolean();
        void testAppendChar();
        void testAppendCharArray();
        void testAppendCharArrayIntInt();
        void testAppendCharSequence();
        void testAppendCharSequenceIntInt();
        void testAppendShort();
        void testAppendInt();
        void testAppendLong();
        void testAppendDouble();
        void testAppendFloat();
        void testAppendString();
        void testAppendStringBuffer();
        void testAppendRawPointer();
        void testAppendPointer();
        void testCapacity();
        void testCharAt();
        void testDeleteRange();
        void testDeleteCharAt();
        void testEnsureCapacity();
        void testGetChars();
        void testIndexOfString();
        void testIndexOfStringInt();
        void testLastIndexOfString();
        void testLastIndexOfStringInt();

    };

}}

#endif /* _DECAF_LANG_STRINGBUILDERTEST_H_ */
