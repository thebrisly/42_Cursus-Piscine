/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 10:43:23 by brisly            #+#    #+#             */
/*   Updated: 2023/06/10 10:45:31 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
    const Animal* general = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    dog->makeSound(); //will output the cat sound!
    cat->makeSound(); //will output the dog sound
    general->makeSound();
    
    return 0;
}