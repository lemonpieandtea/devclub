#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

class Exception {
    protected:
        std::string message;
    public:
        Exception(const std::string& message);
        virtual ~Exception();
        
        const std::string& getMessage() const;
};

class UnitSetHPException : public Exception {
    public:
        UnitSetHPException(const std::string& message);
};

class UnitSetAPException : public Exception {
    public:
        UnitSetAPException(const std::string& message);
};

class UnitAttackException : public Exception {
    public:
        UnitAttackException(const std::string& message);
};

class SpellCasterSetSPException : public Exception {
    public:
        SpellCasterSetSPException(const std::string& message);
};

class SpellCasterCastException : public Exception {
    public:
        SpellCasterCastException(const std::string& message);
};

class SpellException : public Exception {
    public:
        SpellException(const std::string& message);
};

#endif // EXCEPTION_H
