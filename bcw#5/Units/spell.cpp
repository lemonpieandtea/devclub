#include "spell.h"

Spell::Spell() : name(SPELL_NAME), spellPoints(SPELL_POINTS) {}

Spell::Spell(const std::string& name, const int spellPoints) : name(name) {
    if ( spellPoints < 0 ) {
        throw SpellException("Spell points less than zero");
    }
    this->spellPoints = spellPoints;
}

Spell::~Spell() {}

const std::string& Spell::getName() const {
    return name;
}

int Spell::getSP() const {
    return spellPoints;
}
