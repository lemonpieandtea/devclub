#ifndef SPELL_H
#define SPELL_H

#include <string>
#include "exception.h"

#define SPELL_NAME "Rainbow"
#define SPELL_POINTS 0

class Spell {
    protected:
        std::string name;
        int spellPoints;
        
    public:
        Spell();
        Spell(const std::string& name, const int spellPoints);
        virtual ~Spell();
        
        const std::string& getName() const;
        int getSP() const;
};

#endif // SPELL_H
