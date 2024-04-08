#pragma once

#include "ASpell.hpp"
#include <iostream>
#include <map>

class SpellBook
{
    private :
        std::map<std::string, ASpell *> arr;

        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

    public :
        SpellBook();
        ~SpellBook();

        void learnSpell(Aspell *aspell_ptr);
        void forgetSpell(std::string const &name);
        ASpell* createSpell(std::string const &name);

};

/*Now, make a SpellBook class, in canonical form, that can't be copied or instantiated
by copy. It will have the following functions:

* void learnSpell(ASpell*), that COPIES a spell in the book
* void forgetSpell(string const &), that deletes a spell from the book, except
  if it isn't there
* ASpell* createSpell(string const &), that receives a string corresponding to
  the name of a spell, creates it, and returns it.*/