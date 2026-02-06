//
// Generated file, do not edit! Created by opp_msgtool 6.3 from src/Messages.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "Messages_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(InitialAccessRequest)

InitialAccessRequest::InitialAccessRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

InitialAccessRequest::InitialAccessRequest(const InitialAccessRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

InitialAccessRequest::~InitialAccessRequest()
{
}

InitialAccessRequest& InitialAccessRequest::operator=(const InitialAccessRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void InitialAccessRequest::copy(const InitialAccessRequest& other)
{
    this->ueId = other.ueId;
    this->signalStrength = other.signalStrength;
    this->posX = other.posX;
    this->posY = other.posY;
}

void InitialAccessRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->signalStrength);
    doParsimPacking(b,this->posX);
    doParsimPacking(b,this->posY);
}

void InitialAccessRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->signalStrength);
    doParsimUnpacking(b,this->posX);
    doParsimUnpacking(b,this->posY);
}

int InitialAccessRequest::getUeId() const
{
    return this->ueId;
}

void InitialAccessRequest::setUeId(int ueId)
{
    this->ueId = ueId;
}

double InitialAccessRequest::getSignalStrength() const
{
    return this->signalStrength;
}

void InitialAccessRequest::setSignalStrength(double signalStrength)
{
    this->signalStrength = signalStrength;
}

double InitialAccessRequest::getPosX() const
{
    return this->posX;
}

void InitialAccessRequest::setPosX(double posX)
{
    this->posX = posX;
}

double InitialAccessRequest::getPosY() const
{
    return this->posY;
}

void InitialAccessRequest::setPosY(double posY)
{
    this->posY = posY;
}

class InitialAccessRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_signalStrength,
        FIELD_posX,
        FIELD_posY,
    };
  public:
    InitialAccessRequestDescriptor();
    virtual ~InitialAccessRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(InitialAccessRequestDescriptor)

InitialAccessRequestDescriptor::InitialAccessRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(InitialAccessRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

InitialAccessRequestDescriptor::~InitialAccessRequestDescriptor()
{
    delete[] propertyNames;
}

bool InitialAccessRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<InitialAccessRequest *>(obj)!=nullptr;
}

const char **InitialAccessRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *InitialAccessRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int InitialAccessRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int InitialAccessRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_signalStrength
        FD_ISEDITABLE,    // FIELD_posX
        FD_ISEDITABLE,    // FIELD_posY
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *InitialAccessRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "signalStrength",
        "posX",
        "posY",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int InitialAccessRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "signalStrength") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "posX") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "posY") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *InitialAccessRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "double",    // FIELD_signalStrength
        "double",    // FIELD_posX
        "double",    // FIELD_posY
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **InitialAccessRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *InitialAccessRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int InitialAccessRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void InitialAccessRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'InitialAccessRequest'", field);
    }
}

const char *InitialAccessRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string InitialAccessRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_signalStrength: return double2string(pp->getSignalStrength());
        case FIELD_posX: return double2string(pp->getPosX());
        case FIELD_posY: return double2string(pp->getPosY());
        default: return "";
    }
}

void InitialAccessRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_signalStrength: pp->setSignalStrength(string2double(value)); break;
        case FIELD_posX: pp->setPosX(string2double(value)); break;
        case FIELD_posY: pp->setPosY(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessRequest'", field);
    }
}

omnetpp::cValue InitialAccessRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_signalStrength: return pp->getSignalStrength();
        case FIELD_posX: return pp->getPosX();
        case FIELD_posY: return pp->getPosY();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'InitialAccessRequest' as cValue -- field index out of range?", field);
    }
}

void InitialAccessRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_signalStrength: pp->setSignalStrength(value.doubleValue()); break;
        case FIELD_posX: pp->setPosX(value.doubleValue()); break;
        case FIELD_posY: pp->setPosY(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessRequest'", field);
    }
}

const char *InitialAccessRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr InitialAccessRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void InitialAccessRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessRequest *pp = omnetpp::fromAnyPtr<InitialAccessRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessRequest'", field);
    }
}

Register_Class(InitialAccessResponse)

InitialAccessResponse::InitialAccessResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

InitialAccessResponse::InitialAccessResponse(const InitialAccessResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

InitialAccessResponse::~InitialAccessResponse()
{
}

InitialAccessResponse& InitialAccessResponse::operator=(const InitialAccessResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void InitialAccessResponse::copy(const InitialAccessResponse& other)
{
    this->ueId = other.ueId;
    this->gNBId = other.gNBId;
    this->accepted = other.accepted;
    this->allocatedRBs = other.allocatedRBs;
    this->timeSlot = other.timeSlot;
    this->frequencySlot = other.frequencySlot;
}

void InitialAccessResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->gNBId);
    doParsimPacking(b,this->accepted);
    doParsimPacking(b,this->allocatedRBs);
    doParsimPacking(b,this->timeSlot);
    doParsimPacking(b,this->frequencySlot);
}

void InitialAccessResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->gNBId);
    doParsimUnpacking(b,this->accepted);
    doParsimUnpacking(b,this->allocatedRBs);
    doParsimUnpacking(b,this->timeSlot);
    doParsimUnpacking(b,this->frequencySlot);
}

int InitialAccessResponse::getUeId() const
{
    return this->ueId;
}

void InitialAccessResponse::setUeId(int ueId)
{
    this->ueId = ueId;
}

int InitialAccessResponse::getGNBId() const
{
    return this->gNBId;
}

void InitialAccessResponse::setGNBId(int gNBId)
{
    this->gNBId = gNBId;
}

bool InitialAccessResponse::getAccepted() const
{
    return this->accepted;
}

void InitialAccessResponse::setAccepted(bool accepted)
{
    this->accepted = accepted;
}

int InitialAccessResponse::getAllocatedRBs() const
{
    return this->allocatedRBs;
}

void InitialAccessResponse::setAllocatedRBs(int allocatedRBs)
{
    this->allocatedRBs = allocatedRBs;
}

int InitialAccessResponse::getTimeSlot() const
{
    return this->timeSlot;
}

void InitialAccessResponse::setTimeSlot(int timeSlot)
{
    this->timeSlot = timeSlot;
}

int InitialAccessResponse::getFrequencySlot() const
{
    return this->frequencySlot;
}

void InitialAccessResponse::setFrequencySlot(int frequencySlot)
{
    this->frequencySlot = frequencySlot;
}

class InitialAccessResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_gNBId,
        FIELD_accepted,
        FIELD_allocatedRBs,
        FIELD_timeSlot,
        FIELD_frequencySlot,
    };
  public:
    InitialAccessResponseDescriptor();
    virtual ~InitialAccessResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(InitialAccessResponseDescriptor)

InitialAccessResponseDescriptor::InitialAccessResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(InitialAccessResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

InitialAccessResponseDescriptor::~InitialAccessResponseDescriptor()
{
    delete[] propertyNames;
}

bool InitialAccessResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<InitialAccessResponse *>(obj)!=nullptr;
}

const char **InitialAccessResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *InitialAccessResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int InitialAccessResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int InitialAccessResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_gNBId
        FD_ISEDITABLE,    // FIELD_accepted
        FD_ISEDITABLE,    // FIELD_allocatedRBs
        FD_ISEDITABLE,    // FIELD_timeSlot
        FD_ISEDITABLE,    // FIELD_frequencySlot
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *InitialAccessResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "gNBId",
        "accepted",
        "allocatedRBs",
        "timeSlot",
        "frequencySlot",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int InitialAccessResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "gNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "accepted") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "allocatedRBs") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "timeSlot") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "frequencySlot") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *InitialAccessResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_gNBId
        "bool",    // FIELD_accepted
        "int",    // FIELD_allocatedRBs
        "int",    // FIELD_timeSlot
        "int",    // FIELD_frequencySlot
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **InitialAccessResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *InitialAccessResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int InitialAccessResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void InitialAccessResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'InitialAccessResponse'", field);
    }
}

const char *InitialAccessResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string InitialAccessResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_gNBId: return long2string(pp->getGNBId());
        case FIELD_accepted: return bool2string(pp->getAccepted());
        case FIELD_allocatedRBs: return long2string(pp->getAllocatedRBs());
        case FIELD_timeSlot: return long2string(pp->getTimeSlot());
        case FIELD_frequencySlot: return long2string(pp->getFrequencySlot());
        default: return "";
    }
}

void InitialAccessResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_gNBId: pp->setGNBId(string2long(value)); break;
        case FIELD_accepted: pp->setAccepted(string2bool(value)); break;
        case FIELD_allocatedRBs: pp->setAllocatedRBs(string2long(value)); break;
        case FIELD_timeSlot: pp->setTimeSlot(string2long(value)); break;
        case FIELD_frequencySlot: pp->setFrequencySlot(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessResponse'", field);
    }
}

omnetpp::cValue InitialAccessResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_gNBId: return pp->getGNBId();
        case FIELD_accepted: return pp->getAccepted();
        case FIELD_allocatedRBs: return pp->getAllocatedRBs();
        case FIELD_timeSlot: return pp->getTimeSlot();
        case FIELD_frequencySlot: return pp->getFrequencySlot();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'InitialAccessResponse' as cValue -- field index out of range?", field);
    }
}

void InitialAccessResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_gNBId: pp->setGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_accepted: pp->setAccepted(value.boolValue()); break;
        case FIELD_allocatedRBs: pp->setAllocatedRBs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timeSlot: pp->setTimeSlot(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_frequencySlot: pp->setFrequencySlot(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessResponse'", field);
    }
}

const char *InitialAccessResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr InitialAccessResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void InitialAccessResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    InitialAccessResponse *pp = omnetpp::fromAnyPtr<InitialAccessResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'InitialAccessResponse'", field);
    }
}

Register_Class(RegistrationRequest)

RegistrationRequest::RegistrationRequest(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

RegistrationRequest::RegistrationRequest(const RegistrationRequest& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

RegistrationRequest::~RegistrationRequest()
{
}

RegistrationRequest& RegistrationRequest::operator=(const RegistrationRequest& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void RegistrationRequest::copy(const RegistrationRequest& other)
{
    this->ueId = other.ueId;
    this->gNBId = other.gNBId;
    this->imsi = other.imsi;
}

void RegistrationRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->gNBId);
    doParsimPacking(b,this->imsi);
}

void RegistrationRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->gNBId);
    doParsimUnpacking(b,this->imsi);
}

int RegistrationRequest::getUeId() const
{
    return this->ueId;
}

void RegistrationRequest::setUeId(int ueId)
{
    this->ueId = ueId;
}

int RegistrationRequest::getGNBId() const
{
    return this->gNBId;
}

void RegistrationRequest::setGNBId(int gNBId)
{
    this->gNBId = gNBId;
}

const char * RegistrationRequest::getImsi() const
{
    return this->imsi.c_str();
}

void RegistrationRequest::setImsi(const char * imsi)
{
    this->imsi = imsi;
}

class RegistrationRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_gNBId,
        FIELD_imsi,
    };
  public:
    RegistrationRequestDescriptor();
    virtual ~RegistrationRequestDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RegistrationRequestDescriptor)

RegistrationRequestDescriptor::RegistrationRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(RegistrationRequest)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

RegistrationRequestDescriptor::~RegistrationRequestDescriptor()
{
    delete[] propertyNames;
}

bool RegistrationRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RegistrationRequest *>(obj)!=nullptr;
}

const char **RegistrationRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RegistrationRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RegistrationRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int RegistrationRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_gNBId
        FD_ISEDITABLE,    // FIELD_imsi
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *RegistrationRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "gNBId",
        "imsi",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int RegistrationRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "gNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "imsi") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *RegistrationRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_gNBId
        "string",    // FIELD_imsi
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **RegistrationRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RegistrationRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RegistrationRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RegistrationRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RegistrationRequest'", field);
    }
}

const char *RegistrationRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RegistrationRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_gNBId: return long2string(pp->getGNBId());
        case FIELD_imsi: return oppstring2string(pp->getImsi());
        default: return "";
    }
}

void RegistrationRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_gNBId: pp->setGNBId(string2long(value)); break;
        case FIELD_imsi: pp->setImsi((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationRequest'", field);
    }
}

omnetpp::cValue RegistrationRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_gNBId: return pp->getGNBId();
        case FIELD_imsi: return pp->getImsi();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RegistrationRequest' as cValue -- field index out of range?", field);
    }
}

void RegistrationRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_gNBId: pp->setGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_imsi: pp->setImsi(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationRequest'", field);
    }
}

const char *RegistrationRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr RegistrationRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RegistrationRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationRequest *pp = omnetpp::fromAnyPtr<RegistrationRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationRequest'", field);
    }
}

Register_Class(RegistrationResponse)

RegistrationResponse::RegistrationResponse(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

RegistrationResponse::RegistrationResponse(const RegistrationResponse& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

RegistrationResponse::~RegistrationResponse()
{
}

RegistrationResponse& RegistrationResponse::operator=(const RegistrationResponse& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void RegistrationResponse::copy(const RegistrationResponse& other)
{
    this->ueId = other.ueId;
    this->authenticated = other.authenticated;
    this->ipAddress = other.ipAddress;
    this->sessionId = other.sessionId;
}

void RegistrationResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->authenticated);
    doParsimPacking(b,this->ipAddress);
    doParsimPacking(b,this->sessionId);
}

void RegistrationResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->authenticated);
    doParsimUnpacking(b,this->ipAddress);
    doParsimUnpacking(b,this->sessionId);
}

int RegistrationResponse::getUeId() const
{
    return this->ueId;
}

void RegistrationResponse::setUeId(int ueId)
{
    this->ueId = ueId;
}

bool RegistrationResponse::getAuthenticated() const
{
    return this->authenticated;
}

void RegistrationResponse::setAuthenticated(bool authenticated)
{
    this->authenticated = authenticated;
}

const char * RegistrationResponse::getIpAddress() const
{
    return this->ipAddress.c_str();
}

void RegistrationResponse::setIpAddress(const char * ipAddress)
{
    this->ipAddress = ipAddress;
}

int RegistrationResponse::getSessionId() const
{
    return this->sessionId;
}

void RegistrationResponse::setSessionId(int sessionId)
{
    this->sessionId = sessionId;
}

class RegistrationResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_authenticated,
        FIELD_ipAddress,
        FIELD_sessionId,
    };
  public:
    RegistrationResponseDescriptor();
    virtual ~RegistrationResponseDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(RegistrationResponseDescriptor)

RegistrationResponseDescriptor::RegistrationResponseDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(RegistrationResponse)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

RegistrationResponseDescriptor::~RegistrationResponseDescriptor()
{
    delete[] propertyNames;
}

bool RegistrationResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RegistrationResponse *>(obj)!=nullptr;
}

const char **RegistrationResponseDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *RegistrationResponseDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int RegistrationResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int RegistrationResponseDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_authenticated
        FD_ISEDITABLE,    // FIELD_ipAddress
        FD_ISEDITABLE,    // FIELD_sessionId
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *RegistrationResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "authenticated",
        "ipAddress",
        "sessionId",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int RegistrationResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "authenticated") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ipAddress") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *RegistrationResponseDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "bool",    // FIELD_authenticated
        "string",    // FIELD_ipAddress
        "int",    // FIELD_sessionId
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **RegistrationResponseDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *RegistrationResponseDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int RegistrationResponseDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void RegistrationResponseDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'RegistrationResponse'", field);
    }
}

const char *RegistrationResponseDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RegistrationResponseDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_authenticated: return bool2string(pp->getAuthenticated());
        case FIELD_ipAddress: return oppstring2string(pp->getIpAddress());
        case FIELD_sessionId: return long2string(pp->getSessionId());
        default: return "";
    }
}

void RegistrationResponseDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_authenticated: pp->setAuthenticated(string2bool(value)); break;
        case FIELD_ipAddress: pp->setIpAddress((value)); break;
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationResponse'", field);
    }
}

omnetpp::cValue RegistrationResponseDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_authenticated: return pp->getAuthenticated();
        case FIELD_ipAddress: return pp->getIpAddress();
        case FIELD_sessionId: return pp->getSessionId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'RegistrationResponse' as cValue -- field index out of range?", field);
    }
}

void RegistrationResponseDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_authenticated: pp->setAuthenticated(value.boolValue()); break;
        case FIELD_ipAddress: pp->setIpAddress(value.stringValue()); break;
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationResponse'", field);
    }
}

const char *RegistrationResponseDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr RegistrationResponseDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void RegistrationResponseDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    RegistrationResponse *pp = omnetpp::fromAnyPtr<RegistrationResponse>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'RegistrationResponse'", field);
    }
}

Register_Class(DataPacket)

DataPacket::DataPacket(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

DataPacket::DataPacket(const DataPacket& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

DataPacket::~DataPacket()
{
}

DataPacket& DataPacket::operator=(const DataPacket& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DataPacket::copy(const DataPacket& other)
{
    this->ueId = other.ueId;
    this->gNBId = other.gNBId;
    this->sessionId = other.sessionId;
    this->sequenceNumber = other.sequenceNumber;
    this->packetSize = other.packetSize;
    this->timestamp = other.timestamp;
    this->payload = other.payload;
    this->destinationIP = other.destinationIP;
    this->sourceIP = other.sourceIP;
}

void DataPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->gNBId);
    doParsimPacking(b,this->sessionId);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->packetSize);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->payload);
    doParsimPacking(b,this->destinationIP);
    doParsimPacking(b,this->sourceIP);
}

void DataPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->gNBId);
    doParsimUnpacking(b,this->sessionId);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->packetSize);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->payload);
    doParsimUnpacking(b,this->destinationIP);
    doParsimUnpacking(b,this->sourceIP);
}

int DataPacket::getUeId() const
{
    return this->ueId;
}

void DataPacket::setUeId(int ueId)
{
    this->ueId = ueId;
}

int DataPacket::getGNBId() const
{
    return this->gNBId;
}

void DataPacket::setGNBId(int gNBId)
{
    this->gNBId = gNBId;
}

int DataPacket::getSessionId() const
{
    return this->sessionId;
}

void DataPacket::setSessionId(int sessionId)
{
    this->sessionId = sessionId;
}

int DataPacket::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void DataPacket::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int DataPacket::getPacketSize() const
{
    return this->packetSize;
}

void DataPacket::setPacketSize(int packetSize)
{
    this->packetSize = packetSize;
}

double DataPacket::getTimestamp() const
{
    return this->timestamp;
}

void DataPacket::setTimestamp(double timestamp)
{
    this->timestamp = timestamp;
}

const char * DataPacket::getPayload() const
{
    return this->payload.c_str();
}

void DataPacket::setPayload(const char * payload)
{
    this->payload = payload;
}

const char * DataPacket::getDestinationIP() const
{
    return this->destinationIP.c_str();
}

void DataPacket::setDestinationIP(const char * destinationIP)
{
    this->destinationIP = destinationIP;
}

const char * DataPacket::getSourceIP() const
{
    return this->sourceIP.c_str();
}

void DataPacket::setSourceIP(const char * sourceIP)
{
    this->sourceIP = sourceIP;
}

class DataPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_gNBId,
        FIELD_sessionId,
        FIELD_sequenceNumber,
        FIELD_packetSize,
        FIELD_timestamp,
        FIELD_payload,
        FIELD_destinationIP,
        FIELD_sourceIP,
    };
  public:
    DataPacketDescriptor();
    virtual ~DataPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataPacketDescriptor)

DataPacketDescriptor::DataPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataPacket)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

DataPacketDescriptor::~DataPacketDescriptor()
{
    delete[] propertyNames;
}

bool DataPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataPacket *>(obj)!=nullptr;
}

const char **DataPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 9+base->getFieldCount() : 9;
}

unsigned int DataPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_gNBId
        FD_ISEDITABLE,    // FIELD_sessionId
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_packetSize
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_payload
        FD_ISEDITABLE,    // FIELD_destinationIP
        FD_ISEDITABLE,    // FIELD_sourceIP
    };
    return (field >= 0 && field < 9) ? fieldTypeFlags[field] : 0;
}

const char *DataPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "gNBId",
        "sessionId",
        "sequenceNumber",
        "packetSize",
        "timestamp",
        "payload",
        "destinationIP",
        "sourceIP",
    };
    return (field >= 0 && field < 9) ? fieldNames[field] : nullptr;
}

int DataPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "gNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "sessionId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "packetSize") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "destinationIP") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "sourceIP") == 0) return baseIndex + 8;
    return base ? base->findField(fieldName) : -1;
}

const char *DataPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_gNBId
        "int",    // FIELD_sessionId
        "int",    // FIELD_sequenceNumber
        "int",    // FIELD_packetSize
        "double",    // FIELD_timestamp
        "string",    // FIELD_payload
        "string",    // FIELD_destinationIP
        "string",    // FIELD_sourceIP
    };
    return (field >= 0 && field < 9) ? fieldTypeStrings[field] : nullptr;
}

const char **DataPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_gNBId: return long2string(pp->getGNBId());
        case FIELD_sessionId: return long2string(pp->getSessionId());
        case FIELD_sequenceNumber: return long2string(pp->getSequenceNumber());
        case FIELD_packetSize: return long2string(pp->getPacketSize());
        case FIELD_timestamp: return double2string(pp->getTimestamp());
        case FIELD_payload: return oppstring2string(pp->getPayload());
        case FIELD_destinationIP: return oppstring2string(pp->getDestinationIP());
        case FIELD_sourceIP: return oppstring2string(pp->getSourceIP());
        default: return "";
    }
}

void DataPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_gNBId: pp->setGNBId(string2long(value)); break;
        case FIELD_sessionId: pp->setSessionId(string2long(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2long(value)); break;
        case FIELD_packetSize: pp->setPacketSize(string2long(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2double(value)); break;
        case FIELD_payload: pp->setPayload((value)); break;
        case FIELD_destinationIP: pp->setDestinationIP((value)); break;
        case FIELD_sourceIP: pp->setSourceIP((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

omnetpp::cValue DataPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_gNBId: return pp->getGNBId();
        case FIELD_sessionId: return pp->getSessionId();
        case FIELD_sequenceNumber: return pp->getSequenceNumber();
        case FIELD_packetSize: return pp->getPacketSize();
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_payload: return pp->getPayload();
        case FIELD_destinationIP: return pp->getDestinationIP();
        case FIELD_sourceIP: return pp->getSourceIP();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataPacket' as cValue -- field index out of range?", field);
    }
}

void DataPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_gNBId: pp->setGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sessionId: pp->setSessionId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_packetSize: pp->setPacketSize(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(value.doubleValue()); break;
        case FIELD_payload: pp->setPayload(value.stringValue()); break;
        case FIELD_destinationIP: pp->setDestinationIP(value.stringValue()); break;
        case FIELD_sourceIP: pp->setSourceIP(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

const char *DataPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DataPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataPacket *pp = omnetpp::fromAnyPtr<DataPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataPacket'", field);
    }
}

Register_Class(DataAck)

DataAck::DataAck(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

DataAck::DataAck(const DataAck& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

DataAck::~DataAck()
{
}

DataAck& DataAck::operator=(const DataAck& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void DataAck::copy(const DataAck& other)
{
    this->ueId = other.ueId;
    this->sequenceNumber = other.sequenceNumber;
    this->success = other.success;
    this->latency = other.latency;
}

void DataAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->success);
    doParsimPacking(b,this->latency);
}

void DataAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->success);
    doParsimUnpacking(b,this->latency);
}

int DataAck::getUeId() const
{
    return this->ueId;
}

void DataAck::setUeId(int ueId)
{
    this->ueId = ueId;
}

int DataAck::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void DataAck::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

bool DataAck::getSuccess() const
{
    return this->success;
}

void DataAck::setSuccess(bool success)
{
    this->success = success;
}

double DataAck::getLatency() const
{
    return this->latency;
}

void DataAck::setLatency(double latency)
{
    this->latency = latency;
}

class DataAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_sequenceNumber,
        FIELD_success,
        FIELD_latency,
    };
  public:
    DataAckDescriptor();
    virtual ~DataAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(DataAckDescriptor)

DataAckDescriptor::DataAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(DataAck)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

DataAckDescriptor::~DataAckDescriptor()
{
    delete[] propertyNames;
}

bool DataAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DataAck *>(obj)!=nullptr;
}

const char **DataAckDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *DataAckDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int DataAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int DataAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_success
        FD_ISEDITABLE,    // FIELD_latency
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *DataAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "sequenceNumber",
        "success",
        "latency",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int DataAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "latency") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *DataAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_sequenceNumber
        "bool",    // FIELD_success
        "double",    // FIELD_latency
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **DataAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *DataAckDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int DataAckDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void DataAckDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'DataAck'", field);
    }
}

const char *DataAckDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DataAckDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_sequenceNumber: return long2string(pp->getSequenceNumber());
        case FIELD_success: return bool2string(pp->getSuccess());
        case FIELD_latency: return double2string(pp->getLatency());
        default: return "";
    }
}

void DataAckDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2long(value)); break;
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        case FIELD_latency: pp->setLatency(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataAck'", field);
    }
}

omnetpp::cValue DataAckDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_sequenceNumber: return pp->getSequenceNumber();
        case FIELD_success: return pp->getSuccess();
        case FIELD_latency: return pp->getLatency();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'DataAck' as cValue -- field index out of range?", field);
    }
}

void DataAckDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        case FIELD_latency: pp->setLatency(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataAck'", field);
    }
}

const char *DataAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr DataAckDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void DataAckDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    DataAck *pp = omnetpp::fromAnyPtr<DataAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'DataAck'", field);
    }
}

Register_Class(MeasurementReport)

MeasurementReport::MeasurementReport(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MeasurementReport::MeasurementReport(const MeasurementReport& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MeasurementReport::~MeasurementReport()
{
    delete [] this->neighborGNBIds;
    delete [] this->neighborSignalStrengths;
}

MeasurementReport& MeasurementReport::operator=(const MeasurementReport& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MeasurementReport::copy(const MeasurementReport& other)
{
    this->ueId = other.ueId;
    this->servingGNBId = other.servingGNBId;
    this->servingSignalStrength = other.servingSignalStrength;
    delete [] this->neighborGNBIds;
    this->neighborGNBIds = (other.neighborGNBIds_arraysize==0) ? nullptr : new int[other.neighborGNBIds_arraysize];
    neighborGNBIds_arraysize = other.neighborGNBIds_arraysize;
    for (size_t i = 0; i < neighborGNBIds_arraysize; i++) {
        this->neighborGNBIds[i] = other.neighborGNBIds[i];
    }
    delete [] this->neighborSignalStrengths;
    this->neighborSignalStrengths = (other.neighborSignalStrengths_arraysize==0) ? nullptr : new double[other.neighborSignalStrengths_arraysize];
    neighborSignalStrengths_arraysize = other.neighborSignalStrengths_arraysize;
    for (size_t i = 0; i < neighborSignalStrengths_arraysize; i++) {
        this->neighborSignalStrengths[i] = other.neighborSignalStrengths[i];
    }
    this->currentLoad = other.currentLoad;
}

void MeasurementReport::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->servingGNBId);
    doParsimPacking(b,this->servingSignalStrength);
    b->pack(neighborGNBIds_arraysize);
    doParsimArrayPacking(b,this->neighborGNBIds,neighborGNBIds_arraysize);
    b->pack(neighborSignalStrengths_arraysize);
    doParsimArrayPacking(b,this->neighborSignalStrengths,neighborSignalStrengths_arraysize);
    doParsimPacking(b,this->currentLoad);
}

void MeasurementReport::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->servingGNBId);
    doParsimUnpacking(b,this->servingSignalStrength);
    delete [] this->neighborGNBIds;
    b->unpack(neighborGNBIds_arraysize);
    if (neighborGNBIds_arraysize == 0) {
        this->neighborGNBIds = nullptr;
    } else {
        this->neighborGNBIds = new int[neighborGNBIds_arraysize];
        doParsimArrayUnpacking(b,this->neighborGNBIds,neighborGNBIds_arraysize);
    }
    delete [] this->neighborSignalStrengths;
    b->unpack(neighborSignalStrengths_arraysize);
    if (neighborSignalStrengths_arraysize == 0) {
        this->neighborSignalStrengths = nullptr;
    } else {
        this->neighborSignalStrengths = new double[neighborSignalStrengths_arraysize];
        doParsimArrayUnpacking(b,this->neighborSignalStrengths,neighborSignalStrengths_arraysize);
    }
    doParsimUnpacking(b,this->currentLoad);
}

int MeasurementReport::getUeId() const
{
    return this->ueId;
}

void MeasurementReport::setUeId(int ueId)
{
    this->ueId = ueId;
}

int MeasurementReport::getServingGNBId() const
{
    return this->servingGNBId;
}

void MeasurementReport::setServingGNBId(int servingGNBId)
{
    this->servingGNBId = servingGNBId;
}

double MeasurementReport::getServingSignalStrength() const
{
    return this->servingSignalStrength;
}

void MeasurementReport::setServingSignalStrength(double servingSignalStrength)
{
    this->servingSignalStrength = servingSignalStrength;
}

size_t MeasurementReport::getNeighborGNBIdsArraySize() const
{
    return neighborGNBIds_arraysize;
}

int MeasurementReport::getNeighborGNBIds(size_t k) const
{
    if (k >= neighborGNBIds_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborGNBIds_arraysize, (unsigned long)k);
    return this->neighborGNBIds[k];
}

void MeasurementReport::setNeighborGNBIdsArraySize(size_t newSize)
{
    int *neighborGNBIds2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = neighborGNBIds_arraysize < newSize ? neighborGNBIds_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighborGNBIds2[i] = this->neighborGNBIds[i];
    for (size_t i = minSize; i < newSize; i++)
        neighborGNBIds2[i] = 0;
    delete [] this->neighborGNBIds;
    this->neighborGNBIds = neighborGNBIds2;
    neighborGNBIds_arraysize = newSize;
}

void MeasurementReport::setNeighborGNBIds(size_t k, int neighborGNBIds)
{
    if (k >= neighborGNBIds_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborGNBIds_arraysize, (unsigned long)k);
    this->neighborGNBIds[k] = neighborGNBIds;
}

void MeasurementReport::insertNeighborGNBIds(size_t k, int neighborGNBIds)
{
    if (k > neighborGNBIds_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborGNBIds_arraysize, (unsigned long)k);
    size_t newSize = neighborGNBIds_arraysize + 1;
    int *neighborGNBIds2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborGNBIds2[i] = this->neighborGNBIds[i];
    neighborGNBIds2[k] = neighborGNBIds;
    for (i = k + 1; i < newSize; i++)
        neighborGNBIds2[i] = this->neighborGNBIds[i-1];
    delete [] this->neighborGNBIds;
    this->neighborGNBIds = neighborGNBIds2;
    neighborGNBIds_arraysize = newSize;
}

void MeasurementReport::appendNeighborGNBIds(int neighborGNBIds)
{
    insertNeighborGNBIds(neighborGNBIds_arraysize, neighborGNBIds);
}

void MeasurementReport::eraseNeighborGNBIds(size_t k)
{
    if (k >= neighborGNBIds_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborGNBIds_arraysize, (unsigned long)k);
    size_t newSize = neighborGNBIds_arraysize - 1;
    int *neighborGNBIds2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborGNBIds2[i] = this->neighborGNBIds[i];
    for (i = k; i < newSize; i++)
        neighborGNBIds2[i] = this->neighborGNBIds[i+1];
    delete [] this->neighborGNBIds;
    this->neighborGNBIds = neighborGNBIds2;
    neighborGNBIds_arraysize = newSize;
}

size_t MeasurementReport::getNeighborSignalStrengthsArraySize() const
{
    return neighborSignalStrengths_arraysize;
}

double MeasurementReport::getNeighborSignalStrengths(size_t k) const
{
    if (k >= neighborSignalStrengths_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborSignalStrengths_arraysize, (unsigned long)k);
    return this->neighborSignalStrengths[k];
}

void MeasurementReport::setNeighborSignalStrengthsArraySize(size_t newSize)
{
    double *neighborSignalStrengths2 = (newSize==0) ? nullptr : new double[newSize];
    size_t minSize = neighborSignalStrengths_arraysize < newSize ? neighborSignalStrengths_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        neighborSignalStrengths2[i] = this->neighborSignalStrengths[i];
    for (size_t i = minSize; i < newSize; i++)
        neighborSignalStrengths2[i] = 0;
    delete [] this->neighborSignalStrengths;
    this->neighborSignalStrengths = neighborSignalStrengths2;
    neighborSignalStrengths_arraysize = newSize;
}

void MeasurementReport::setNeighborSignalStrengths(size_t k, double neighborSignalStrengths)
{
    if (k >= neighborSignalStrengths_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborSignalStrengths_arraysize, (unsigned long)k);
    this->neighborSignalStrengths[k] = neighborSignalStrengths;
}

void MeasurementReport::insertNeighborSignalStrengths(size_t k, double neighborSignalStrengths)
{
    if (k > neighborSignalStrengths_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborSignalStrengths_arraysize, (unsigned long)k);
    size_t newSize = neighborSignalStrengths_arraysize + 1;
    double *neighborSignalStrengths2 = new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborSignalStrengths2[i] = this->neighborSignalStrengths[i];
    neighborSignalStrengths2[k] = neighborSignalStrengths;
    for (i = k + 1; i < newSize; i++)
        neighborSignalStrengths2[i] = this->neighborSignalStrengths[i-1];
    delete [] this->neighborSignalStrengths;
    this->neighborSignalStrengths = neighborSignalStrengths2;
    neighborSignalStrengths_arraysize = newSize;
}

void MeasurementReport::appendNeighborSignalStrengths(double neighborSignalStrengths)
{
    insertNeighborSignalStrengths(neighborSignalStrengths_arraysize, neighborSignalStrengths);
}

void MeasurementReport::eraseNeighborSignalStrengths(size_t k)
{
    if (k >= neighborSignalStrengths_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)neighborSignalStrengths_arraysize, (unsigned long)k);
    size_t newSize = neighborSignalStrengths_arraysize - 1;
    double *neighborSignalStrengths2 = (newSize == 0) ? nullptr : new double[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        neighborSignalStrengths2[i] = this->neighborSignalStrengths[i];
    for (i = k; i < newSize; i++)
        neighborSignalStrengths2[i] = this->neighborSignalStrengths[i+1];
    delete [] this->neighborSignalStrengths;
    this->neighborSignalStrengths = neighborSignalStrengths2;
    neighborSignalStrengths_arraysize = newSize;
}

double MeasurementReport::getCurrentLoad() const
{
    return this->currentLoad;
}

void MeasurementReport::setCurrentLoad(double currentLoad)
{
    this->currentLoad = currentLoad;
}

class MeasurementReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_servingGNBId,
        FIELD_servingSignalStrength,
        FIELD_neighborGNBIds,
        FIELD_neighborSignalStrengths,
        FIELD_currentLoad,
    };
  public:
    MeasurementReportDescriptor();
    virtual ~MeasurementReportDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(MeasurementReportDescriptor)

MeasurementReportDescriptor::MeasurementReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MeasurementReport)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MeasurementReportDescriptor::~MeasurementReportDescriptor()
{
    delete[] propertyNames;
}

bool MeasurementReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MeasurementReport *>(obj)!=nullptr;
}

const char **MeasurementReportDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MeasurementReportDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MeasurementReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int MeasurementReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_servingGNBId
        FD_ISEDITABLE,    // FIELD_servingSignalStrength
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_neighborGNBIds
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_neighborSignalStrengths
        FD_ISEDITABLE,    // FIELD_currentLoad
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *MeasurementReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "servingGNBId",
        "servingSignalStrength",
        "neighborGNBIds",
        "neighborSignalStrengths",
        "currentLoad",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int MeasurementReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "servingGNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "servingSignalStrength") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "neighborGNBIds") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "neighborSignalStrengths") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "currentLoad") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *MeasurementReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_servingGNBId
        "double",    // FIELD_servingSignalStrength
        "int",    // FIELD_neighborGNBIds
        "double",    // FIELD_neighborSignalStrengths
        "double",    // FIELD_currentLoad
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **MeasurementReportDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *MeasurementReportDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int MeasurementReportDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_neighborGNBIds: return pp->getNeighborGNBIdsArraySize();
        case FIELD_neighborSignalStrengths: return pp->getNeighborSignalStrengthsArraySize();
        default: return 0;
    }
}

void MeasurementReportDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_neighborGNBIds: pp->setNeighborGNBIdsArraySize(size); break;
        case FIELD_neighborSignalStrengths: pp->setNeighborSignalStrengthsArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MeasurementReport'", field);
    }
}

const char *MeasurementReportDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MeasurementReportDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_servingGNBId: return long2string(pp->getServingGNBId());
        case FIELD_servingSignalStrength: return double2string(pp->getServingSignalStrength());
        case FIELD_neighborGNBIds: return long2string(pp->getNeighborGNBIds(i));
        case FIELD_neighborSignalStrengths: return double2string(pp->getNeighborSignalStrengths(i));
        case FIELD_currentLoad: return double2string(pp->getCurrentLoad());
        default: return "";
    }
}

void MeasurementReportDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_servingGNBId: pp->setServingGNBId(string2long(value)); break;
        case FIELD_servingSignalStrength: pp->setServingSignalStrength(string2double(value)); break;
        case FIELD_neighborGNBIds: pp->setNeighborGNBIds(i,string2long(value)); break;
        case FIELD_neighborSignalStrengths: pp->setNeighborSignalStrengths(i,string2double(value)); break;
        case FIELD_currentLoad: pp->setCurrentLoad(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MeasurementReport'", field);
    }
}

omnetpp::cValue MeasurementReportDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_servingGNBId: return pp->getServingGNBId();
        case FIELD_servingSignalStrength: return pp->getServingSignalStrength();
        case FIELD_neighborGNBIds: return pp->getNeighborGNBIds(i);
        case FIELD_neighborSignalStrengths: return pp->getNeighborSignalStrengths(i);
        case FIELD_currentLoad: return pp->getCurrentLoad();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MeasurementReport' as cValue -- field index out of range?", field);
    }
}

void MeasurementReportDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_servingGNBId: pp->setServingGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_servingSignalStrength: pp->setServingSignalStrength(value.doubleValue()); break;
        case FIELD_neighborGNBIds: pp->setNeighborGNBIds(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_neighborSignalStrengths: pp->setNeighborSignalStrengths(i,value.doubleValue()); break;
        case FIELD_currentLoad: pp->setCurrentLoad(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MeasurementReport'", field);
    }
}

const char *MeasurementReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr MeasurementReportDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MeasurementReportDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MeasurementReport *pp = omnetpp::fromAnyPtr<MeasurementReport>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MeasurementReport'", field);
    }
}

Register_Class(HandoverCommand)

HandoverCommand::HandoverCommand(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

HandoverCommand::HandoverCommand(const HandoverCommand& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

HandoverCommand::~HandoverCommand()
{
}

HandoverCommand& HandoverCommand::operator=(const HandoverCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void HandoverCommand::copy(const HandoverCommand& other)
{
    this->ueId = other.ueId;
    this->sourceGNBId = other.sourceGNBId;
    this->targetGNBId = other.targetGNBId;
    this->reason = other.reason;
}

void HandoverCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->sourceGNBId);
    doParsimPacking(b,this->targetGNBId);
    doParsimPacking(b,this->reason);
}

void HandoverCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->sourceGNBId);
    doParsimUnpacking(b,this->targetGNBId);
    doParsimUnpacking(b,this->reason);
}

int HandoverCommand::getUeId() const
{
    return this->ueId;
}

void HandoverCommand::setUeId(int ueId)
{
    this->ueId = ueId;
}

int HandoverCommand::getSourceGNBId() const
{
    return this->sourceGNBId;
}

void HandoverCommand::setSourceGNBId(int sourceGNBId)
{
    this->sourceGNBId = sourceGNBId;
}

int HandoverCommand::getTargetGNBId() const
{
    return this->targetGNBId;
}

void HandoverCommand::setTargetGNBId(int targetGNBId)
{
    this->targetGNBId = targetGNBId;
}

int HandoverCommand::getReason() const
{
    return this->reason;
}

void HandoverCommand::setReason(int reason)
{
    this->reason = reason;
}

class HandoverCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_sourceGNBId,
        FIELD_targetGNBId,
        FIELD_reason,
    };
  public:
    HandoverCommandDescriptor();
    virtual ~HandoverCommandDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(HandoverCommandDescriptor)

HandoverCommandDescriptor::HandoverCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HandoverCommand)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

HandoverCommandDescriptor::~HandoverCommandDescriptor()
{
    delete[] propertyNames;
}

bool HandoverCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HandoverCommand *>(obj)!=nullptr;
}

const char **HandoverCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HandoverCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HandoverCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int HandoverCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_sourceGNBId
        FD_ISEDITABLE,    // FIELD_targetGNBId
        FD_ISEDITABLE,    // FIELD_reason
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *HandoverCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "sourceGNBId",
        "targetGNBId",
        "reason",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int HandoverCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourceGNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "targetGNBId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "reason") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *HandoverCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_sourceGNBId
        "int",    // FIELD_targetGNBId
        "int",    // FIELD_reason
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **HandoverCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *HandoverCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int HandoverCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void HandoverCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HandoverCommand'", field);
    }
}

const char *HandoverCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HandoverCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_sourceGNBId: return long2string(pp->getSourceGNBId());
        case FIELD_targetGNBId: return long2string(pp->getTargetGNBId());
        case FIELD_reason: return long2string(pp->getReason());
        default: return "";
    }
}

void HandoverCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_sourceGNBId: pp->setSourceGNBId(string2long(value)); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(string2long(value)); break;
        case FIELD_reason: pp->setReason(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverCommand'", field);
    }
}

omnetpp::cValue HandoverCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_sourceGNBId: return pp->getSourceGNBId();
        case FIELD_targetGNBId: return pp->getTargetGNBId();
        case FIELD_reason: return pp->getReason();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HandoverCommand' as cValue -- field index out of range?", field);
    }
}

void HandoverCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sourceGNBId: pp->setSourceGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_reason: pp->setReason(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverCommand'", field);
    }
}

const char *HandoverCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr HandoverCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HandoverCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverCommand *pp = omnetpp::fromAnyPtr<HandoverCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverCommand'", field);
    }
}

Register_Class(HandoverAck)

HandoverAck::HandoverAck(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

HandoverAck::HandoverAck(const HandoverAck& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

HandoverAck::~HandoverAck()
{
}

HandoverAck& HandoverAck::operator=(const HandoverAck& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void HandoverAck::copy(const HandoverAck& other)
{
    this->ueId = other.ueId;
    this->targetGNBId = other.targetGNBId;
    this->success = other.success;
}

void HandoverAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->ueId);
    doParsimPacking(b,this->targetGNBId);
    doParsimPacking(b,this->success);
}

void HandoverAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->ueId);
    doParsimUnpacking(b,this->targetGNBId);
    doParsimUnpacking(b,this->success);
}

int HandoverAck::getUeId() const
{
    return this->ueId;
}

void HandoverAck::setUeId(int ueId)
{
    this->ueId = ueId;
}

int HandoverAck::getTargetGNBId() const
{
    return this->targetGNBId;
}

void HandoverAck::setTargetGNBId(int targetGNBId)
{
    this->targetGNBId = targetGNBId;
}

bool HandoverAck::getSuccess() const
{
    return this->success;
}

void HandoverAck::setSuccess(bool success)
{
    this->success = success;
}

class HandoverAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ueId,
        FIELD_targetGNBId,
        FIELD_success,
    };
  public:
    HandoverAckDescriptor();
    virtual ~HandoverAckDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(HandoverAckDescriptor)

HandoverAckDescriptor::HandoverAckDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(HandoverAck)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

HandoverAckDescriptor::~HandoverAckDescriptor()
{
    delete[] propertyNames;
}

bool HandoverAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HandoverAck *>(obj)!=nullptr;
}

const char **HandoverAckDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *HandoverAckDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int HandoverAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int HandoverAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ueId
        FD_ISEDITABLE,    // FIELD_targetGNBId
        FD_ISEDITABLE,    // FIELD_success
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *HandoverAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ueId",
        "targetGNBId",
        "success",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int HandoverAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ueId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "targetGNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "success") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *HandoverAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ueId
        "int",    // FIELD_targetGNBId
        "bool",    // FIELD_success
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **HandoverAckDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *HandoverAckDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int HandoverAckDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void HandoverAckDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'HandoverAck'", field);
    }
}

const char *HandoverAckDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HandoverAckDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return long2string(pp->getUeId());
        case FIELD_targetGNBId: return long2string(pp->getTargetGNBId());
        case FIELD_success: return bool2string(pp->getSuccess());
        default: return "";
    }
}

void HandoverAckDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(string2long(value)); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(string2long(value)); break;
        case FIELD_success: pp->setSuccess(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverAck'", field);
    }
}

omnetpp::cValue HandoverAckDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: return pp->getUeId();
        case FIELD_targetGNBId: return pp->getTargetGNBId();
        case FIELD_success: return pp->getSuccess();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'HandoverAck' as cValue -- field index out of range?", field);
    }
}

void HandoverAckDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        case FIELD_ueId: pp->setUeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_success: pp->setSuccess(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverAck'", field);
    }
}

const char *HandoverAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr HandoverAckDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void HandoverAckDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    HandoverAck *pp = omnetpp::fromAnyPtr<HandoverAck>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'HandoverAck'", field);
    }
}

Register_Class(LoadReport)

LoadReport::LoadReport(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

LoadReport::LoadReport(const LoadReport& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

LoadReport::~LoadReport()
{
}

LoadReport& LoadReport::operator=(const LoadReport& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void LoadReport::copy(const LoadReport& other)
{
    this->gNBId = other.gNBId;
    this->currentLoad = other.currentLoad;
    this->connectedUEs = other.connectedUEs;
    this->availableRBs = other.availableRBs;
    this->averageLatency = other.averageLatency;
}

void LoadReport::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->gNBId);
    doParsimPacking(b,this->currentLoad);
    doParsimPacking(b,this->connectedUEs);
    doParsimPacking(b,this->availableRBs);
    doParsimPacking(b,this->averageLatency);
}

void LoadReport::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->gNBId);
    doParsimUnpacking(b,this->currentLoad);
    doParsimUnpacking(b,this->connectedUEs);
    doParsimUnpacking(b,this->availableRBs);
    doParsimUnpacking(b,this->averageLatency);
}

int LoadReport::getGNBId() const
{
    return this->gNBId;
}

void LoadReport::setGNBId(int gNBId)
{
    this->gNBId = gNBId;
}

double LoadReport::getCurrentLoad() const
{
    return this->currentLoad;
}

void LoadReport::setCurrentLoad(double currentLoad)
{
    this->currentLoad = currentLoad;
}

int LoadReport::getConnectedUEs() const
{
    return this->connectedUEs;
}

void LoadReport::setConnectedUEs(int connectedUEs)
{
    this->connectedUEs = connectedUEs;
}

int LoadReport::getAvailableRBs() const
{
    return this->availableRBs;
}

void LoadReport::setAvailableRBs(int availableRBs)
{
    this->availableRBs = availableRBs;
}

double LoadReport::getAverageLatency() const
{
    return this->averageLatency;
}

void LoadReport::setAverageLatency(double averageLatency)
{
    this->averageLatency = averageLatency;
}

class LoadReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_gNBId,
        FIELD_currentLoad,
        FIELD_connectedUEs,
        FIELD_availableRBs,
        FIELD_averageLatency,
    };
  public:
    LoadReportDescriptor();
    virtual ~LoadReportDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(LoadReportDescriptor)

LoadReportDescriptor::LoadReportDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoadReport)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

LoadReportDescriptor::~LoadReportDescriptor()
{
    delete[] propertyNames;
}

bool LoadReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoadReport *>(obj)!=nullptr;
}

const char **LoadReportDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoadReportDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoadReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int LoadReportDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_gNBId
        FD_ISEDITABLE,    // FIELD_currentLoad
        FD_ISEDITABLE,    // FIELD_connectedUEs
        FD_ISEDITABLE,    // FIELD_availableRBs
        FD_ISEDITABLE,    // FIELD_averageLatency
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *LoadReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "gNBId",
        "currentLoad",
        "connectedUEs",
        "availableRBs",
        "averageLatency",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int LoadReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "gNBId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "currentLoad") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "connectedUEs") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "availableRBs") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "averageLatency") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *LoadReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_gNBId
        "double",    // FIELD_currentLoad
        "int",    // FIELD_connectedUEs
        "int",    // FIELD_availableRBs
        "double",    // FIELD_averageLatency
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **LoadReportDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LoadReportDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LoadReportDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LoadReportDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoadReport'", field);
    }
}

const char *LoadReportDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoadReportDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: return long2string(pp->getGNBId());
        case FIELD_currentLoad: return double2string(pp->getCurrentLoad());
        case FIELD_connectedUEs: return long2string(pp->getConnectedUEs());
        case FIELD_availableRBs: return long2string(pp->getAvailableRBs());
        case FIELD_averageLatency: return double2string(pp->getAverageLatency());
        default: return "";
    }
}

void LoadReportDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: pp->setGNBId(string2long(value)); break;
        case FIELD_currentLoad: pp->setCurrentLoad(string2double(value)); break;
        case FIELD_connectedUEs: pp->setConnectedUEs(string2long(value)); break;
        case FIELD_availableRBs: pp->setAvailableRBs(string2long(value)); break;
        case FIELD_averageLatency: pp->setAverageLatency(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadReport'", field);
    }
}

omnetpp::cValue LoadReportDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: return pp->getGNBId();
        case FIELD_currentLoad: return pp->getCurrentLoad();
        case FIELD_connectedUEs: return pp->getConnectedUEs();
        case FIELD_availableRBs: return pp->getAvailableRBs();
        case FIELD_averageLatency: return pp->getAverageLatency();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoadReport' as cValue -- field index out of range?", field);
    }
}

void LoadReportDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: pp->setGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_currentLoad: pp->setCurrentLoad(value.doubleValue()); break;
        case FIELD_connectedUEs: pp->setConnectedUEs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_availableRBs: pp->setAvailableRBs(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_averageLatency: pp->setAverageLatency(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadReport'", field);
    }
}

const char *LoadReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr LoadReportDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoadReportDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadReport *pp = omnetpp::fromAnyPtr<LoadReport>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadReport'", field);
    }
}

Register_Class(LoadBalanceCommand)

LoadBalanceCommand::LoadBalanceCommand(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

LoadBalanceCommand::LoadBalanceCommand(const LoadBalanceCommand& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

LoadBalanceCommand::~LoadBalanceCommand()
{
}

LoadBalanceCommand& LoadBalanceCommand::operator=(const LoadBalanceCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void LoadBalanceCommand::copy(const LoadBalanceCommand& other)
{
    this->overloadedGNBId = other.overloadedGNBId;
    this->targetGNBId = other.targetGNBId;
    this->ueIdToMove = other.ueIdToMove;
}

void LoadBalanceCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->overloadedGNBId);
    doParsimPacking(b,this->targetGNBId);
    doParsimPacking(b,this->ueIdToMove);
}

void LoadBalanceCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->overloadedGNBId);
    doParsimUnpacking(b,this->targetGNBId);
    doParsimUnpacking(b,this->ueIdToMove);
}

int LoadBalanceCommand::getOverloadedGNBId() const
{
    return this->overloadedGNBId;
}

void LoadBalanceCommand::setOverloadedGNBId(int overloadedGNBId)
{
    this->overloadedGNBId = overloadedGNBId;
}

int LoadBalanceCommand::getTargetGNBId() const
{
    return this->targetGNBId;
}

void LoadBalanceCommand::setTargetGNBId(int targetGNBId)
{
    this->targetGNBId = targetGNBId;
}

int LoadBalanceCommand::getUeIdToMove() const
{
    return this->ueIdToMove;
}

void LoadBalanceCommand::setUeIdToMove(int ueIdToMove)
{
    this->ueIdToMove = ueIdToMove;
}

class LoadBalanceCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_overloadedGNBId,
        FIELD_targetGNBId,
        FIELD_ueIdToMove,
    };
  public:
    LoadBalanceCommandDescriptor();
    virtual ~LoadBalanceCommandDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(LoadBalanceCommandDescriptor)

LoadBalanceCommandDescriptor::LoadBalanceCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(LoadBalanceCommand)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

LoadBalanceCommandDescriptor::~LoadBalanceCommandDescriptor()
{
    delete[] propertyNames;
}

bool LoadBalanceCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LoadBalanceCommand *>(obj)!=nullptr;
}

const char **LoadBalanceCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *LoadBalanceCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int LoadBalanceCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int LoadBalanceCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_overloadedGNBId
        FD_ISEDITABLE,    // FIELD_targetGNBId
        FD_ISEDITABLE,    // FIELD_ueIdToMove
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *LoadBalanceCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "overloadedGNBId",
        "targetGNBId",
        "ueIdToMove",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int LoadBalanceCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "overloadedGNBId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "targetGNBId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "ueIdToMove") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *LoadBalanceCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_overloadedGNBId
        "int",    // FIELD_targetGNBId
        "int",    // FIELD_ueIdToMove
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **LoadBalanceCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *LoadBalanceCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int LoadBalanceCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void LoadBalanceCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'LoadBalanceCommand'", field);
    }
}

const char *LoadBalanceCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LoadBalanceCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        case FIELD_overloadedGNBId: return long2string(pp->getOverloadedGNBId());
        case FIELD_targetGNBId: return long2string(pp->getTargetGNBId());
        case FIELD_ueIdToMove: return long2string(pp->getUeIdToMove());
        default: return "";
    }
}

void LoadBalanceCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        case FIELD_overloadedGNBId: pp->setOverloadedGNBId(string2long(value)); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(string2long(value)); break;
        case FIELD_ueIdToMove: pp->setUeIdToMove(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadBalanceCommand'", field);
    }
}

omnetpp::cValue LoadBalanceCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        case FIELD_overloadedGNBId: return pp->getOverloadedGNBId();
        case FIELD_targetGNBId: return pp->getTargetGNBId();
        case FIELD_ueIdToMove: return pp->getUeIdToMove();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'LoadBalanceCommand' as cValue -- field index out of range?", field);
    }
}

void LoadBalanceCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        case FIELD_overloadedGNBId: pp->setOverloadedGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_targetGNBId: pp->setTargetGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ueIdToMove: pp->setUeIdToMove(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadBalanceCommand'", field);
    }
}

const char *LoadBalanceCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr LoadBalanceCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void LoadBalanceCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    LoadBalanceCommand *pp = omnetpp::fromAnyPtr<LoadBalanceCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'LoadBalanceCommand'", field);
    }
}

Register_Class(PolicyUpdate)

PolicyUpdate::PolicyUpdate(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

PolicyUpdate::PolicyUpdate(const PolicyUpdate& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

PolicyUpdate::~PolicyUpdate()
{
}

PolicyUpdate& PolicyUpdate::operator=(const PolicyUpdate& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void PolicyUpdate::copy(const PolicyUpdate& other)
{
    this->gNBId = other.gNBId;
    this->loadThreshold = other.loadThreshold;
    this->signalThreshold = other.signalThreshold;
    this->enableLoadBalancing = other.enableLoadBalancing;
    this->enableHandover = other.enableHandover;
}

void PolicyUpdate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->gNBId);
    doParsimPacking(b,this->loadThreshold);
    doParsimPacking(b,this->signalThreshold);
    doParsimPacking(b,this->enableLoadBalancing);
    doParsimPacking(b,this->enableHandover);
}

void PolicyUpdate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->gNBId);
    doParsimUnpacking(b,this->loadThreshold);
    doParsimUnpacking(b,this->signalThreshold);
    doParsimUnpacking(b,this->enableLoadBalancing);
    doParsimUnpacking(b,this->enableHandover);
}

int PolicyUpdate::getGNBId() const
{
    return this->gNBId;
}

void PolicyUpdate::setGNBId(int gNBId)
{
    this->gNBId = gNBId;
}

double PolicyUpdate::getLoadThreshold() const
{
    return this->loadThreshold;
}

void PolicyUpdate::setLoadThreshold(double loadThreshold)
{
    this->loadThreshold = loadThreshold;
}

double PolicyUpdate::getSignalThreshold() const
{
    return this->signalThreshold;
}

void PolicyUpdate::setSignalThreshold(double signalThreshold)
{
    this->signalThreshold = signalThreshold;
}

bool PolicyUpdate::getEnableLoadBalancing() const
{
    return this->enableLoadBalancing;
}

void PolicyUpdate::setEnableLoadBalancing(bool enableLoadBalancing)
{
    this->enableLoadBalancing = enableLoadBalancing;
}

bool PolicyUpdate::getEnableHandover() const
{
    return this->enableHandover;
}

void PolicyUpdate::setEnableHandover(bool enableHandover)
{
    this->enableHandover = enableHandover;
}

class PolicyUpdateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_gNBId,
        FIELD_loadThreshold,
        FIELD_signalThreshold,
        FIELD_enableLoadBalancing,
        FIELD_enableHandover,
    };
  public:
    PolicyUpdateDescriptor();
    virtual ~PolicyUpdateDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(PolicyUpdateDescriptor)

PolicyUpdateDescriptor::PolicyUpdateDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PolicyUpdate)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

PolicyUpdateDescriptor::~PolicyUpdateDescriptor()
{
    delete[] propertyNames;
}

bool PolicyUpdateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PolicyUpdate *>(obj)!=nullptr;
}

const char **PolicyUpdateDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PolicyUpdateDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PolicyUpdateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int PolicyUpdateDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_gNBId
        FD_ISEDITABLE,    // FIELD_loadThreshold
        FD_ISEDITABLE,    // FIELD_signalThreshold
        FD_ISEDITABLE,    // FIELD_enableLoadBalancing
        FD_ISEDITABLE,    // FIELD_enableHandover
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *PolicyUpdateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "gNBId",
        "loadThreshold",
        "signalThreshold",
        "enableLoadBalancing",
        "enableHandover",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int PolicyUpdateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "gNBId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "loadThreshold") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "signalThreshold") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "enableLoadBalancing") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "enableHandover") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *PolicyUpdateDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_gNBId
        "double",    // FIELD_loadThreshold
        "double",    // FIELD_signalThreshold
        "bool",    // FIELD_enableLoadBalancing
        "bool",    // FIELD_enableHandover
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **PolicyUpdateDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *PolicyUpdateDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int PolicyUpdateDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PolicyUpdateDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PolicyUpdate'", field);
    }
}

const char *PolicyUpdateDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PolicyUpdateDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: return long2string(pp->getGNBId());
        case FIELD_loadThreshold: return double2string(pp->getLoadThreshold());
        case FIELD_signalThreshold: return double2string(pp->getSignalThreshold());
        case FIELD_enableLoadBalancing: return bool2string(pp->getEnableLoadBalancing());
        case FIELD_enableHandover: return bool2string(pp->getEnableHandover());
        default: return "";
    }
}

void PolicyUpdateDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: pp->setGNBId(string2long(value)); break;
        case FIELD_loadThreshold: pp->setLoadThreshold(string2double(value)); break;
        case FIELD_signalThreshold: pp->setSignalThreshold(string2double(value)); break;
        case FIELD_enableLoadBalancing: pp->setEnableLoadBalancing(string2bool(value)); break;
        case FIELD_enableHandover: pp->setEnableHandover(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PolicyUpdate'", field);
    }
}

omnetpp::cValue PolicyUpdateDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: return pp->getGNBId();
        case FIELD_loadThreshold: return pp->getLoadThreshold();
        case FIELD_signalThreshold: return pp->getSignalThreshold();
        case FIELD_enableLoadBalancing: return pp->getEnableLoadBalancing();
        case FIELD_enableHandover: return pp->getEnableHandover();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PolicyUpdate' as cValue -- field index out of range?", field);
    }
}

void PolicyUpdateDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        case FIELD_gNBId: pp->setGNBId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_loadThreshold: pp->setLoadThreshold(value.doubleValue()); break;
        case FIELD_signalThreshold: pp->setSignalThreshold(value.doubleValue()); break;
        case FIELD_enableLoadBalancing: pp->setEnableLoadBalancing(value.boolValue()); break;
        case FIELD_enableHandover: pp->setEnableHandover(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PolicyUpdate'", field);
    }
}

const char *PolicyUpdateDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr PolicyUpdateDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PolicyUpdateDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PolicyUpdate *pp = omnetpp::fromAnyPtr<PolicyUpdate>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PolicyUpdate'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

