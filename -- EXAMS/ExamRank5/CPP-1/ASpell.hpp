#pragma once

#include <iostream>

class ATarget;

class ASpell 
{
    private:
        std::string name;
        std::string effects;

    public:
        ASpell();
        ASpell(std::string const &name, std::string const &effects);
        ASpell(ASpell const &other);
        ASpell &operator=(ASpell const &other);
        virtual ~ASpell();

        std::string getName() const;
        std::string getEffects() const;

        void launch(ATarget const &target_ref) const;

        virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"