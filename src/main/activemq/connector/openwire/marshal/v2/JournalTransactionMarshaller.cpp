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

#include <activemq/connector/openwire/marshal/v2/JournalTransactionMarshaller.h>

#include <activemq/connector/openwire/commands/JournalTransaction.h>

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
DataStructure* JournalTransactionMarshaller::createObject() const {
    return new JournalTransaction();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char JournalTransactionMarshaller::getDataStructureType() const {
    return JournalTransaction::ID_JOURNALTRANSACTION;
}

///////////////////////////////////////////////////////////////////////////////
void JournalTransactionMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

        JournalTransaction* info =
            dynamic_cast<JournalTransaction*>( dataStructure );
        info->setTransactionId( dynamic_cast< TransactionId* >(
            tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
        info->setType( dataIn->readByte() );
        info->setWasPrepared( bs->readBoolean() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
int JournalTransactionMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        JournalTransaction* info =
            dynamic_cast<JournalTransaction*>( dataStructure );

        int rc = BaseDataStreamMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
        rc += tightMarshalNestedObject1( wireFormat, info->getTransactionId(), bs );
        bs->writeBoolean( info->getWasPrepared() );

        return rc + 1;
    }
    AMQ_CATCH_RETHROW( decaf::decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTransactionMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

        JournalTransaction* info =
            dynamic_cast<JournalTransaction*>( dataStructure );
        tightMarshalNestedObject2( wireFormat, info->getTransactionId(), dataOut, bs );
        dataOut->write( info->getType() );
        bs->readBoolean();
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTransactionMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( decaf::io::IOException ) {

    try {

        BaseDataStreamMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
        JournalTransaction* info =
            dynamic_cast<JournalTransaction*>( dataStructure );
        info->setTransactionId( dynamic_cast< TransactionId* >( 
            looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
        info->setType( dataIn->readByte() );
        info->setWasPrepared( dataIn->readBoolean() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

///////////////////////////////////////////////////////////////////////////////
void JournalTransactionMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( decaf::io::IOException ) {

    try {

        JournalTransaction* info =
            dynamic_cast<JournalTransaction*>( dataStructure );
         BaseDataStreamMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

        looseMarshalNestedObject( wireFormat, info->getTransactionId(), dataOut );
        dataOut->write( info->getType() );
        dataOut->writeBoolean( info->getWasPrepared() );
    }
    AMQ_CATCH_RETHROW( decaf::io::IOException )
    AMQ_CATCH_EXCEPTION_CONVERT( exceptions::ActiveMQException, decaf::io::IOException )
    AMQ_CATCHALL_THROW( decaf::io::IOException )
}

