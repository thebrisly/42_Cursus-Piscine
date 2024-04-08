#pragma once 

#include "ATarget.hpp"

class Dummy : public ATarget
{
    public :
        Dummy();
        ~Dummy();

        virtual ATarget *clone() const;
};

/* When all this is done, create an implementation of ATarget called Dummy. Its
default constructor will set the name to "Dummy" and the effects to
"Dummyed". You will, of course, implement the clone() method. In the case of
Dummy, it will return a pointer to a new Dummy object.

In the same way, create a concrete ATarget called Dummy, the type of which
is "Target Practice Dummy". You must also implement its clone() method.*/