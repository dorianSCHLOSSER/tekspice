/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Circuit
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(int argc, char **argv)
{
    _filename = argv[1];
}

void nts::Circuit::start()
{
    nts::Parse *FileNts = new nts::Parse();
    FileNts->checkName(_filename);
    FileNts->refreshFile(_filename);
    FileNts->parseComponent();
    FileNts->parseLinks();
    FileNts->checkLinks();
    FileNts->links();
    FileNts->charge();
    FileNts->sortComp();
    FileNts->game();
}