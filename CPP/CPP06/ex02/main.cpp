#include "Base.hpp"
#include <ctime>

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 2;

    if (random == 0)
        return new A;
    else if (random == 1)
        return new B;
    else if (random == 2)
        return new C;
    return new A;
}


int main()
{
    Base    *no_name;
    no_name = generate();

    (void) no_name;

    //identify(no_name);
    //identify(&no_name);

    //delete (no_name);
}