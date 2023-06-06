/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:50:11 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 10:15:01 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/*std::string replace_word(std::string to_search, std::string to_replace, std::string base)
{
    std::string new_line;
    int current = 0;
    int previous = 0;

    while (temp[current])
    {
        while (to_search[j])

    }
    return (new_line);
}*/

void if_in_of(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
    std::string     temp;
    (void) s1; // a enlever
    (void) s2; // a enlever
    
    while (getline(ifs, temp))
    {
        //temp = replace_word(s1, s2, temp);
        ofs << temp << std::endl;
    }
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::ifstream   infile;
        std::ofstream   outfile;

        std::string     filename =  argv[1];
        std::string     s1 = argv[2];
        std::string     s2 = argv[3];

        infile.open(filename.c_str()); // a voir si a 42 je peux enlever ce c_str() -> chez moi je peux pas faire sans
        if (!infile) {
            std::cout << "This file does not exist. Quitting the program... Try again" << std::endl;
            return (1);
        }

        std::string     filename2 = filename + ".replace";
        outfile.open(filename2.c_str()); // a voir si a 42 je peux enlever ce c_str() -> chez moi je peux pas faire sans
        if (!outfile.is_open()) {
            std::cout << "Failed to create the output file. Quitting the program... Try again" << std::endl;
            return 1;
        }
        
        if_in_of(infile, outfile, s1, s2);

        infile.close();
        outfile.close();
    }
    else
        std::cout << "Wrong number of args." << std::endl;
}