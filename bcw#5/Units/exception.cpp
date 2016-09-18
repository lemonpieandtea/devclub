#include "exception.h"

Exception::Exception(const std::string& message) : message(message) {}

Exception::~Exception() {}

const std::string& Exception::getMessage() const {
    return message;
}

UnitSetHPException::UnitSetHPException(const std::string& message) : Exception(message) {}

UnitSetAPException::UnitSetAPException(const std::string& message) : Exception(message) {}

UnitAttackException::UnitAttackException(const std::string& message) : Exception(message) {}

SpellCasterSetSPException::SpellCasterSetSPException(const std::string& message) : Exception(message) {}

SpellCasterCastException::SpellCasterCastException(const std::string& message) : Exception(message) {}

SpellException::SpellException(const std::string& message) : Exception(message) {}
