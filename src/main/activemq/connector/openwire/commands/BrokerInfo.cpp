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
#include <activemq/connector/openwire/commands/BrokerInfo.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshalling code for OpenWire format for BrokerInfo
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
BrokerInfo::BrokerInfo()
{
    this->brokerId = NULL;
    this->brokerURL = "";
    this->brokerName = "";
    this->slaveBroker = false;
    this->masterBroker = false;
    this->faultTolerantConfiguration = false;
    this->duplexConnection = false;
    this->networkConnection = false;
    this->connectionId = 0;
}

////////////////////////////////////////////////////////////////////////////////
BrokerInfo::~BrokerInfo()
{
    delete this->brokerId;
    for( size_t ipeerBrokerInfos = 0; ipeerBrokerInfos < peerBrokerInfos.size(); ++ipeerBrokerInfos ) {
        delete peerBrokerInfos[ipeerBrokerInfos];
    }
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* BrokerInfo::cloneDataStructure() const {
    BrokerInfo* brokerInfo = new BrokerInfo();

    // Copy the data from the base class or classes
    brokerInfo->copyDataStructure( this );

    return brokerInfo;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    BaseCommand::copyDataStructure( src );

    const BrokerInfo* srcPtr = dynamic_cast<const BrokerInfo*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "BrokerInfo::copyDataStructure - src is NULL or invalid" );
    }
    this->setBrokerId( 
        dynamic_cast<BrokerId*>( 
            srcPtr->getBrokerId()->cloneDataStructure() ) );
    this->setBrokerURL( srcPtr->getBrokerURL() );
    for( size_t ipeerBrokerInfos = 0; ipeerBrokerInfos < srcPtr->getPeerBrokerInfos().size(); ++ipeerBrokerInfos ) {
        this->getPeerBrokerInfos().push_back( 
            dynamic_cast<BrokerInfo*>( 
                srcPtr->getPeerBrokerInfos()[ipeerBrokerInfos]->cloneDataStructure() ) );
    }
    this->setBrokerName( srcPtr->getBrokerName() );
    this->setSlaveBroker( srcPtr->isSlaveBroker() );
    this->setMasterBroker( srcPtr->isMasterBroker() );
    this->setFaultTolerantConfiguration( srcPtr->isFaultTolerantConfiguration() );
    this->setDuplexConnection( srcPtr->isDuplexConnection() );
    this->setNetworkConnection( srcPtr->isNetworkConnection() );
    this->setConnectionId( srcPtr->getConnectionId() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char BrokerInfo::getDataStructureType() const {
    return BrokerInfo::ID_BROKERINFO; 
}

////////////////////////////////////////////////////////////////////////////////
const BrokerId* BrokerInfo::getBrokerId() const {
    return brokerId;
}

////////////////////////////////////////////////////////////////////////////////
BrokerId* BrokerInfo::getBrokerId() {
    return brokerId;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerId(BrokerId* brokerId ) {
    this->brokerId = brokerId;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BrokerInfo::getBrokerURL() const {
    return brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
std::string& BrokerInfo::getBrokerURL() {
    return brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerURL(const std::string& brokerURL ) {
    this->brokerURL = brokerURL;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<BrokerInfo*>& BrokerInfo::getPeerBrokerInfos() const {
    return peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<BrokerInfo*>& BrokerInfo::getPeerBrokerInfos() {
    return peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setPeerBrokerInfos(const std::vector<BrokerInfo*>& peerBrokerInfos ) {
    this->peerBrokerInfos = peerBrokerInfos;
}

////////////////////////////////////////////////////////////////////////////////
const std::string& BrokerInfo::getBrokerName() const {
    return brokerName;
}

////////////////////////////////////////////////////////////////////////////////
std::string& BrokerInfo::getBrokerName() {
    return brokerName;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setBrokerName(const std::string& brokerName ) {
    this->brokerName = brokerName;
}

////////////////////////////////////////////////////////////////////////////////
const bool BrokerInfo::isSlaveBroker() const {
    return slaveBroker;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isSlaveBroker() {
    return slaveBroker;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setSlaveBroker(bool slaveBroker ) {
    this->slaveBroker = slaveBroker;
}

////////////////////////////////////////////////////////////////////////////////
const bool BrokerInfo::isMasterBroker() const {
    return masterBroker;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isMasterBroker() {
    return masterBroker;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setMasterBroker(bool masterBroker ) {
    this->masterBroker = masterBroker;
}

////////////////////////////////////////////////////////////////////////////////
const bool BrokerInfo::isFaultTolerantConfiguration() const {
    return faultTolerantConfiguration;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isFaultTolerantConfiguration() {
    return faultTolerantConfiguration;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setFaultTolerantConfiguration(bool faultTolerantConfiguration ) {
    this->faultTolerantConfiguration = faultTolerantConfiguration;
}

////////////////////////////////////////////////////////////////////////////////
const bool BrokerInfo::isDuplexConnection() const {
    return duplexConnection;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isDuplexConnection() {
    return duplexConnection;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setDuplexConnection(bool duplexConnection ) {
    this->duplexConnection = duplexConnection;
}

////////////////////////////////////////////////////////////////////////////////
const bool BrokerInfo::isNetworkConnection() const {
    return networkConnection;
}

////////////////////////////////////////////////////////////////////////////////
bool BrokerInfo::isNetworkConnection() {
    return networkConnection;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setNetworkConnection(bool networkConnection ) {
    this->networkConnection = networkConnection;
}

////////////////////////////////////////////////////////////////////////////////
const long long BrokerInfo::getConnectionId() const {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
long long BrokerInfo::getConnectionId() {
    return connectionId;
}

////////////////////////////////////////////////////////////////////////////////
void BrokerInfo::setConnectionId(long long connectionId ) {
    this->connectionId = connectionId;
}

