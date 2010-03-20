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

#include "PushbackInputStream.h"

#include <decaf/lang/System.h>

using namespace decaf;
using namespace decaf::io;
using namespace decaf::lang;
using namespace decaf::lang::exceptions;

////////////////////////////////////////////////////////////////////////////////
PushbackInputStream::PushbackInputStream( InputStream* stream, bool own )
 :  FilterInputStream( stream, own ), bufferSize( 1 ), pos( 1 ) {

    this->buffer = new unsigned char[1];
}

////////////////////////////////////////////////////////////////////////////////
PushbackInputStream::PushbackInputStream( InputStream* stream, int bufSize, bool own )
    throw( decaf::lang::exceptions::IllegalArgumentException )
 :  FilterInputStream( stream, own ), bufferSize( bufSize ), pos( bufSize ) {

    if( bufSize < 0 ) {
        throw IllegalArgumentException(
            __FILE__, __LINE__, "Size of Push Back buffer cannot be negative." );
    }

    this->buffer = new unsigned char[bufSize];
}

////////////////////////////////////////////////////////////////////////////////
PushbackInputStream::~PushbackInputStream() {
    try{

        close();
        delete [] this->buffer;
    }
    DECAF_CATCH_NOTHROW( Exception )
    DECAF_CATCHALL_NOTHROW()
}

////////////////////////////////////////////////////////////////////////////////
int PushbackInputStream::available() const throw ( decaf::io::IOException ) {

    try{
        return ( this->bufferSize - this->pos ) + inputStream->available();
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
long long PushbackInputStream::skip( long long num )
    throw ( decaf::io::IOException,
            decaf::lang::exceptions::UnsupportedOperationException ) {

    try{

        if( num <= 0 ) {
            return 0;
        }

        if( isClosed() ) {
            throw IOException(
                __FILE__, __LINE__, "Stream is closed" );
        }

        long long unread = bufferSize - pos;
        long long numSkipped = 0;

        if( unread != 0 ) {
            numSkipped += ( num < unread ) ? num : unread;
            pos += (int)numSkipped;
        }

        if( numSkipped < num ) {
            numSkipped += inputStream->skip( num - numSkipped );
        }

        return numSkipped;
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void PushbackInputStream::mark( int readLimit DECAF_UNUSED ) {
    // Nothing to do here.
}

////////////////////////////////////////////////////////////////////////////////
void PushbackInputStream::reset() throw ( decaf::io::IOException ) {
    throw IOException(
        __FILE__, __LINE__, "Reset is not Supported by the PushbackInputStream." );
}

////////////////////////////////////////////////////////////////////////////////
void PushbackInputStream::unread( unsigned char value )
    throw( decaf::io::IOException ) {

    try{

        if( pos == 0 ) {
            throw IOException(
                __FILE__, __LINE__, "No Space left in the unread buffer." );
        }

        buffer[--pos] = value;
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void PushbackInputStream::unread( const unsigned char* buffer, int size )
    throw( decaf::io::IOException,
           decaf::lang::exceptions::IndexOutOfBoundsException,
           decaf::lang::exceptions::NullPointerException ) {

    try{

        if( size < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "Given size of the buffer was negatiev." );
        }

        this->unread( buffer, size, 0, size );
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCH_RETHROW( NullPointerException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void PushbackInputStream::unread( const unsigned char* buffer, int size, int offset, int length )
    throw( decaf::io::IOException,
           decaf::lang::exceptions::IndexOutOfBoundsException,
           decaf::lang::exceptions::NullPointerException ) {

    try{

        if( length > pos ) {
            throw IOException(
                __FILE__, __LINE__, "No Space left in the unread buffer." );
        }

        if( size < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "size parameter out of Bounds: %d.", size );
        }

        if( offset > size || offset < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "offset parameter out of Bounds: %d.", offset );
        }

        if( length < 0 || length > size - offset ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "length parameter out of Bounds: %d.", length );
        }

        if( buffer == NULL ) {
            throw NullPointerException(
                __FILE__, __LINE__, "Buffer pointer passed was NULL." );
        }

        System::arraycopy( buffer, offset, this->buffer, pos - length, length );
        pos = pos - length;
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCH_RETHROW( IndexOutOfBoundsException )
    DECAF_CATCH_RETHROW( NullPointerException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int PushbackInputStream::doReadByte() throw ( decaf::io::IOException ) {

    try{

        if( isClosed() ) {
            throw IOException(
                __FILE__, __LINE__, "Stream is closed" );
        }

        if( pos < bufferSize ) {
            return buffer[pos++];
        }

        return inputStream->read();
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int PushbackInputStream::doReadArrayBounded( unsigned char* buffer, int size, int offset, int length )
    throw ( decaf::io::IOException,
            decaf::lang::exceptions::IndexOutOfBoundsException,
            decaf::lang::exceptions::NullPointerException ) {

    try{

        if( isClosed() ) {
            throw IOException(
                __FILE__, __LINE__, "Stream is closed" );
        }

        if( buffer == NULL ) {
            throw NullPointerException(
                __FILE__, __LINE__, "Buffer pointer passed was NULL." );
        }

        if( size < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "size parameter out of Bounds: %d.", size );
        }

        if( offset > size || offset < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "offset parameter out of Bounds: %d.", offset );
        }

        if( length < 0 || length > size - offset ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__, "length parameter out of Bounds: %d.", length );
        }

        int copiedBytes = 0;
        int copyLength = 0;
        int newOffset = offset;

        // Are there pushback bytes available?
        if( pos < bufferSize ) {
            copyLength = ( bufferSize - pos >= length ) ? length : bufferSize - pos;
            System::arraycopy( this->buffer, pos, buffer, newOffset, copyLength );
            newOffset += copyLength;
            copiedBytes += copyLength;
            // Use up the bytes in the local buffer
            pos += copyLength;
        }

        // Have we copied enough?
        if( copyLength == length ) {
            return length;
        }

        int inCopied = inputStream->read( buffer, size, newOffset, length - copiedBytes );
        if( inCopied > 0 ) {
            return inCopied + copiedBytes;
        }

        if( copiedBytes == 0 ) {
            return inCopied;
        }

        return copiedBytes;
    }
    DECAF_CATCH_RETHROW( IOException )
    DECAF_CATCH_RETHROW( IndexOutOfBoundsException )
    DECAF_CATCH_RETHROW( NullPointerException )
    DECAF_CATCHALL_THROW( IOException )
}
