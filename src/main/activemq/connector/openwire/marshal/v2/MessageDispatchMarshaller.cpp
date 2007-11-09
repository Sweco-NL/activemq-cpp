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

#include <activemq/connector/openwire/marshal/v2/MessageDispatchMarshaller.h>

#include <activemq/connector/openwire/commands/MessageDispatch.h>

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
DataStructure* MessageDispatchMarshaller::createObject() const {
    return new MessageDispatch();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char MessageDispatchMarshaller::getDataStructureType() const {
    return MessageDispatch::ID_MESSAGEDISPATCH;
}

///////////////////////////////////////////////////////////////////////////////
void MessageDispatchMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

        MessageDispatch* info =
            dynamic_cast<MessageDispatch*>( dataStructure );
        info->setConsumerId( dynamic_cast< ConsumerId* >(
            tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
        info->setDestination( dynamic_cast< ActiveMQDestination* >(
            tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
        info->setMessage( dynamic_cast< Message* >(
            tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
        info->setRedeliveryCounter( dataIn->readInt() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
int MessageDispatchMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        MessageDispatch* info =
            dynamic_cast<MessageDispatch*>( dataStructure );

        int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
        rc += tightMarshalCachedObject1( wireFormat, info->getConsumerId(), bs );
        rc += tightMarshalCachedObject1( wireFormat, info->getDestination(), bs );
        rc += tightMarshalNestedObject1( wireFormat, info->getMessage(), bs );

        return rc + 4;
    }
    AMQ_CATCH_RETHROW( decaf::decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageDispatchMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

        MessageDispatch* info =
            dynamic_cast<MessageDispatch*>( dataStructure );
        tightMarshalCachedObject2( wireFormat, info->getConsumerId(), dataOut, bs );
        tightMarshalCachedObject2( wireFormat, info->getDestination(), dataOut, bs );
        tightMarshalNestedObject2( wireFormat, info->getMessage(), dataOut, bs );
        dataOut->writeInt( info->getRedeliveryCounter() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageDispatchMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( decaf::io::IOException ) {

    try {

        BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
        MessageDispatch* info =
            dynamic_cast<MessageDispatch*>( dataStructure );
        info->setConsumerId( dynamic_cast< ConsumerId* >( 
            looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
        info->setDestination( dynamic_cast< ActiveMQDestination* >( 
            looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
        info->setMessage( dynamic_cast< Message* >( 
            looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
        info->setRedeliveryCounter( dataIn->readInt() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageDispatchMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( decaf::io::IOException ) {

    try {

        MessageDispatch* info =
            dynamic_cast<MessageDispatch*>( dataStructure );
         BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

        looseMarshalCachedObject( wireFormat, info->getConsumerId(), dataOut );
        looseMarshalCachedObject( wireFormat, info->getDestination(), dataOut );
        looseMarshalNestedObject( wireFormat, info->getMessage(), dataOut );
        dataOut->writeInt( info->getRedeliveryCounter() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

