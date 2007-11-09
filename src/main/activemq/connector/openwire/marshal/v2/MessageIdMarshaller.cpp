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

#include <activemq/connector/openwire/marshal/v2/MessageIdMarshaller.h>

#include <activemq/connector/openwire/commands/MessageId.h>

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
DataStructure* MessageIdMarshaller::createObject() const {
    return new MessageId();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char MessageIdMarshaller::getDataStructureType() const {
    return MessageId::ID_MESSAGEID;
}

///////////////////////////////////////////////////////////////////////////////
void MessageIdMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

        MessageId* info =
            dynamic_cast<MessageId*>( dataStructure );
        info->setProducerId( dynamic_cast< ProducerId* >(
            tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
        info->setProducerSequenceId( tightUnmarshalLong( wireFormat, dataIn, bs ) );
        info->setBrokerSequenceId( tightUnmarshalLong( wireFormat, dataIn, bs ) );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
int MessageIdMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        MessageId* info =
            dynamic_cast<MessageId*>( dataStructure );

        int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
        rc += tightMarshalCachedObject1( wireFormat, info->getProducerId(), bs );
        rc += tightMarshalLong1( wireFormat, info->getProducerSequenceId(), bs );
        rc += tightMarshalLong1( wireFormat, info->getBrokerSequenceId(), bs );

        return rc + 0;
    }
    AMQ_CATCH_RETHROW( decaf::decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageIdMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

        MessageId* info =
            dynamic_cast<MessageId*>( dataStructure );
        tightMarshalCachedObject2( wireFormat, info->getProducerId(), dataOut, bs );
        tightMarshalLong2( wireFormat, info->getProducerSequenceId(), dataOut, bs );
        tightMarshalLong2( wireFormat, info->getBrokerSequenceId(), dataOut, bs );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageIdMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
        MessageId* info =
            dynamic_cast<MessageId*>( dataStructure );
        info->setProducerId( dynamic_cast< ProducerId* >( 
            looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
        info->setProducerSequenceId( looseUnmarshalLong( wireFormat, dataIn ) );
        info->setBrokerSequenceId( looseUnmarshalLong( wireFormat, dataIn ) );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void MessageIdMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( decaf::io::IOException ) {

    try {

        MessageId* info =
            dynamic_cast<MessageId*>( dataStructure );
         BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

        looseMarshalCachedObject( wireFormat, info->getProducerId(), dataOut );
        looseMarshalLong( wireFormat, info->getProducerSequenceId(), dataOut );
        looseMarshalLong( wireFormat, info->getBrokerSequenceId(), dataOut );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

