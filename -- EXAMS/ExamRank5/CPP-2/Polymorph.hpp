#pragma once 

#include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();

        virtual ASpell *clone() const;
};

/*Create the following two spells, on the same model as Polymorph:

* Fireball (Name: "Fireball", Effects: "burnt to a crisp")
* Polymorph (Name: "Polymorph", Effects: "turned into a critter")*/