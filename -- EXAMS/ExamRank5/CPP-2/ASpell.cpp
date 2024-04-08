#include "ASpell.hpp"

ASpell::ASpell() { }

ASpell::ASpell(std::string const &name, std::string const &effects) 
{
    this->name = name;
    this->effects = effects;
}

ASpell::ASpell(ASpell const &other) { *this = other; }

ASpell &ASpell::operator=(ASpell const &other)
{
    this->name = other.name;
    this->effects = other.effects;
    return (*this);
}

ASpell::~ASpell() { }

std::string ASpell::getName() const { return (this->name); }

std::string ASpell::getEffects() const { return (this->effects); }

void ASpell::launch(ATarget const &target_ref) const 
{
    target_ref.getHitBySpell((*this));
}