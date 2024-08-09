Hello Laura, 

First, I want to thank you for creating a diary and walk-through for projects at 42. That helps me a lot!

I am now preparting for the exam rank 02 and going through the exercises and the code. 
I've wrote my own solution, then checked yours, and realized that yours doesn't consider cases when arguments 2 and 3 contain more than 1 characters, which is not a char but a string. 
From school example:

$>./search_and_replace "zaz" "art" "zul" | cat -e
$

If I compile your code, the output would be 
zzz$

Which is wrong. 
Please review my proposed solution, you are welcome to amend it in a shorter version if you can think of one (I just adore how much your code is simple and easy-to- read). So, you are welcome to update your code, so other folks don't fall into this trap.

Thank you in advance and again, for all the contributions you've made to make the cursus more understandable!
Hugs)

#include <unistd.h>

int ft_strlen(char *str)
{
            int i;

            i = 0;
            while (str[i])
            {
                        i++;
            }
            return (i);
}

int main(int argc, char **argv)
{
            int i;

            i = 0;
            if (argc == 4 && ft_strlen(&argv[2][0]) == 1 && ft_strlen(&argv[3][0]) == 1)
            {
				while (argv[1][i])
				{
					if (argv[1][i] == argv[2][0])
					{
						argv[1][i] = argv[3][0];
					}
					write(1, &argv[1][i], 1);
					i++;
				}
			}
            write(1, "\n", 1);
            return (0);
}
