#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>

class NotFoundException : public std::exception
{
    public :
        virtual const char* what() const throw()
        {
            return ("Sorry, no occurrence is found :'(");
        }
};

/* If you look at the evaluation sheet it says:

It HAS to use STL algorithms.
If it does not (like manual search using iterators for example), count it as wrong.

So that means that i need to use functions from the standard template library to make this function. I will use the function find()
So here we go :
*/

template<typename T>
void easyfind(T &container, int to_find) 
{
	typename T::iterator    result;     //Iterators are used to point at the memory addresses of STL containers

    result = std::find(container.begin(), container.end(), to_find);   
    if (result == container.end())
        throw (NotFoundException());
    else
    {
        int index = std::distance(container.begin(), result);
        std::cout << "Value found in container at position " << index << std::endl;
    }
}

#endif