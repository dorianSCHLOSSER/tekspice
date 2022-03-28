/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** main
*/

#include "Component.hpp"
#include "Gate.hpp"
#include "IComponent.hpp"
#include "Parse.hpp"
#include "Circuit.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "ERROR ARGUMENTS : ./nanotekspace [FILE].nts" << std::endl;
        exit(84); 
    }
    nts::Circuit *circuit = new nts::Circuit(argc, argv);
    circuit->start();

    return (0);
}