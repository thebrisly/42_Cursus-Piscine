#pragma once

#include <iostream>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
    private : 
        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

        std::map<std::string, ATarget *> arr;

    public :
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *atarget_ptr);
        void forgetTargetType(std::string const &type);
        ATarget *createTarget(std::string const &type);
};