/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:50:11 by brisly            #+#    #+#             */
/*   Updated: 2023/06/06 11:55:38 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replace_word(const std::string& to_search, const std::string& to_replace, const std::string& base) 
{
    std::string final_string = base;
    size_t found = 0;
    size_t search_len = to_search.length();
    size_t replace_len = to_replace.length();

    while ((found = final_string.find(to_search, found)) != std::string::npos) //if s1 is found, found = position of the first occurence
    {
        final_string = final_string.substr(0, found) + to_replace + final_string.substr(found + search_len);
        found += replace_len; //adter the word has been replaced, we start again by this position
    }

    return final_string;
}

void if_in_of(std::ifstream &ifs, std::ofstream &ofs, std::string s1, std::string s2)
{
    std::string     temp;
    
    while (getline(ifs, temp)) //takes the entire line of ifs and puts it in temp
    {
        temp = replace_word(s1, s2, temp);
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
            std::cout << "\033[31mThis file does not exist. Try again\033[0m" << std::endl;
            return (1);
        }

        std::string     filename2 = filename + ".replace";
        outfile.open(filename2.c_str()); // a voir si a 42 je peux enlever ce c_str() -> chez moi je peux pas faire sans
        if (!outfile.is_open()) {
            std::cout << "\033[31mFailed to create the output file. Quitting the program... Try again\033[0m" << std::endl;
            return 1;
        }
        
        if_in_of(infile, outfile, s1, s2);

        infile.close();
        outfile.close();
    }
    else
        std::cout << "Wrong number of args." << std::endl;
}