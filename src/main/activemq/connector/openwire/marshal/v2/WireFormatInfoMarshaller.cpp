/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/connector/openwire/marshal/v2/WireFormatInfoMarshaller.h>

#include <activemq/connector/openwire/commands/WireFormatInfo.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;
using namespace decaf;
using namespace decaf::io;

///////////////////////////////////////////////////////////////////////////////
DataStructure* WireFormatInfoMarshaller::createObject() const {
    return new WireFormatInfo();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char WireFormatInfoMarshaller::getDataStructureType() const {
    return WireFormatInfo::ID_WIREFORMATINFO;
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

        WireFormatInfo* info =
            dynamic_cast<WireFormatInfo*>( dataStructure );
        info->beforeUnmarshal( wireFormat );

        info->setMagic( tightUnmarshalConstByteArray( dataIn, bs, 8 ) );
        info->setVersion( dataIn->readInt() );
        info->setMarshalledProperties( tightUnmarshalByteArray( dataIn, bs ) );

        info->afterUnmarshal( wireFormat );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
int WireFormatInfoMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        WireFormatInfo* info =
            dynamic_cast<WireFormatInfo*>( dataStructure );

        info->beforeMarshal( wireFormat );
        int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
        bs->writeBoolean( info->getMarshalledProperties().size() != 0 );
        rc += info->getMarshalledProperties().size() == 0 ? 0 : (int)info->getMarshalledProperties().size() + 4;

        return rc + 12;
    }
    AMQ_CATCH_RETHROW( decaf::decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

        WireFormatInfo* info =
            dynamic_cast<WireFormatInfo*>( dataStructure );
        dataOut->write( (const unsigned char*)(&info->getMagic()[0]), 8 );
        dataOut->writeInt( info->getVersion() );
        if( bs->readBoolean() ) {
            dataOut->writeInt( (int)info->getMarshalledProperties().size() );
            dataOut->write( (const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size() );
        }
        info->afterMarshal( wireFormat );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
        WireFormatInfo* info =
            dynamic_cast<WireFormatInfo*>( dataStructure );
        info->beforeUnmarshal( wireFormat );
        info->setMagic( looseUnmarshalConstByteArray( dataIn, 8 ) );
        info->setVersion( dataIn->readInt() );
        info->setMarshalledProperties( looseUnmarshalByteArray( dataIn ) );
        info->afterUnmarshal( wireFormat );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void WireFormatInfoMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( decaf::io::IOException ) {

    try {

        WireFormatInfo* info =
            dynamic_cast<WireFormatInfo*>( dataStructure );
        info->beforeMarshal( wireFormat );
         BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

        dataOut->write( (const unsigned char*)(&info->getMagic()[0]), (int)8 );
        dataOut->writeInt( info->getVersion() );
        dataOut->write( info->getMarshalledProperties().size() != 0 );
        if( info->getMarshalledProperties().size() != 0 ) {
            dataOut->writeInt( (int)info->getMarshalledProperties().size() );
            dataOut->write( (const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size() );
        }
        info->afterMarshal( wireFormat );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

