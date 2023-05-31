This file will be my notes file. You will be able to see the process I go through to learn C++. I'm starting from scratch, with absolutely no background in this language. My only coding knowledge at the moment is C (and a bit of web)!

So let's get started :)

<h2> .cpp & .hpp </h2>

Typically C++ source code files are given the suffix:

.cpp (ex: hello.cpp) or
.hpp (ex: hello.hpp)

In the .cpp you will put your functions and in the .hpp the Class declarations.


<h2> Compilation & Execution </h2>

C++ is a compiled language. That means that to get a program to run, you must first translate it from the human-readable form to something a machine can “understand.”
That translation is done by a program called a compiler. 

To compile a c++ programme you can either use c++ or g++ (instead of gcc in C). For example:

  [ g++ hello.cpp -o hello ]

To execute this program you can just write: ./hello (name of the exectuable) on your terminal.



<h2> Variables </h2>

It's juste like in C. 

int i = 0;
float i = 10.0; etc.


<h2> Standard input & output library </h2>

In order to use some useful variables that will allow us to interact with the terminal, we need to include a library:
#include <iostream>

This will allow us to use std::cout, std::cin or even more things. Here is an example:


int main() {
  
  double tempf;
  double tempc;
  
  std::cout << "What's the temp in Fahrenheit ? ";        //asking the user for the temp
  std::cin >> tempf;                                      //will put the input in the tempf variable
  
  tempc = (tempf - 32) / 1.8;
  
  std::cout << "The temp is " << tempc << " degrees Celsius.\n";  //printing the temp in celsius in the terminal (output)
  
}


<h2> Classes and Objects </h2>

Sometimes you want to work with more complexe variables. We used to use intergers, strings or booleans to define something... It can work for a name, some numerical things like age or a date, but what if we want to create a variable that is really more complexe... like a person. How do you define a person in programming ? It's not just a string. Its name is a string, but the person is not just that. You can't neither define it with an integer - maybe just its age.

That's why classes are useful. You can define more complexes things whithin a class. 

For example, if you create a Class "Person" you can give it a name, an age, a birth day, a gender, and so many other things. 

An object is just an instance for a class. For example, me, Laura, i'm a Person. My friend Simon, is a Person. We are all persons. In coding we would be called objects, or instance of the class "Person". 

Here are some useful things that i learned about classes:

- Components of a class are called class members.
- You can access class members using the dot operator (object.class_member).
- Attributes, also known as member data, consist of information about an instance of the class.
- Methods, also known as member functions, are functions that you can use with an instance of the class.