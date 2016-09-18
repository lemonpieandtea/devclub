#include "spellCaster.h"

void SpellCaster::cast() {
    if ( spellPoints < spell->getSP() ) {
        throw SpellCasterCastException("Not enought spell points");
    }
    
    spellPoints -= spell->getSP();
}

SpellCaster::SpellCaster() : Unit(), spellPoints(SP) ,maxSpellPoints(SP) {
    this->spell = new Spell();
}

SpellCaster::SpellCaster(const std::string& name, const int hitPoints, const int attackPower, const int spellPoints, const Spell& spell) {
    if ( spellPoints < 0 ) {
        throw SpellCasterSetSPException("Spell points less than zero");
    }
    this->name = name;
    this->spellPoints = spellPoints;
    this->maxSpellPoints = spellPoints;
    this->spell = new Spell(spell.getName(), spell.getSP());
}

SpellCaster::~SpellCaster() {
    delete spell;
}

int SpellCaster::getSP() const {
    return spellPoints;
}

int SpellCaster::getMaxSP() const {
    return maxSpellPoints;
}

const Spell& SpellCaster::getSpell() const {
    return *spell;
}
