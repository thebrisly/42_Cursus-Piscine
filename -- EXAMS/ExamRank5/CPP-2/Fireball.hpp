#pragma once 

#include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        ~Fireball();

        virtual ASpell *clone() const;
};

/*Create the following two spells, on the same model as Fireball:

* Fireball (Name: "Fireball", Effects: "burnt to a crisp")
* Polymorph (Name: "Polymorph", Effects: "turned into a critter")*/