/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:03:08 by brisly            #+#    #+#             */
/*   Updated: 2023/09/11 13:03:10 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

void print_struct(Data *data)
{
    std::cout << "Age : " << data->age << std::endl;
    std::cout << "Surname : " << data->surname << std::endl;
    std::cout << "Hungry : " << data->hungry << std::endl;
    std::cout << "\n";
}

int main()
{
    Data data_test;

    data_test.surname = "Glutonus";
    data_test.age = 23;
    data_test.hungry = 1;
    print_struct(&data_test);

    uintptr_t serialize_test = Serializer::serialize(&data_test);
    Data *data_deserialized = Serializer::deserialize(serialize_test);
    print_struct(data_deserialized);
}

/*
Les termes "serialize" et "deserialize" sont couramment utilisés 
en programmation pour désigner le processus de conversion des données
 d'un format structuré (comme un objet, une structure ou une classe) en une 
 forme qui peut être facilement stockée ou transmise, 
 puis la conversion de ces données stockées ou transmises en leur format d'origine.

Serialize (Sérialiser) : Cela signifie prendre des données dans un format donné, 
tel qu'un objet ou une structure, et les convertir en une séquence de bits 
ou de caractères, généralement dans un format spécifique, 
qui peut être stockée dans un fichier, envoyée sur un réseau ou stockée
 dans une base de données. La sérialisation est souvent utilisée 
 pour la persistance des données, la communication entre systèmes, 
 ou la transmission de données sur un réseau.

Deserialize (Désérialiser) : Cela signifie prendre les données sérialisées 
(généralement sous forme de bits ou de caractères) et les reconvertir en leur format d'origine,
 comme un objet, une structure ou une classe. 
 La désérialisation est le processus inverse de la sérialisation, 
 utilisé pour extraire et utiliser les données stockées ou transmises.
*/