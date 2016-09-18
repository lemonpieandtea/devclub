#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "unit.h"
#include "spell.h"

#define SP 100

class SpellCaster : public Unit {
    protected:
        int spellPoints;
        int maxSpellPoints;
        Spell* spell;
        
        virtual void cast();
        
    public:
        SpellCaster();
        SpellCaster(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints, const Spell& spell);
        virtual ~SpellCaster();
        
        int getSP() const;
        int getMaxSP() const;
        const Spell& getSpell() const;
};

#endif // SPELL_CASTER_H
