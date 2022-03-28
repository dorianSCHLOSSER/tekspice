/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Gate
*/

#ifndef GATE_HPP_
#define GATE_HPP_
#include "IComponent.hpp"

namespace gate
{
    nts::Tristate And(nts::Tristate a, nts::Tristate b);
    nts::Tristate Xor(nts::Tristate a, nts::Tristate b);
    nts::Tristate Nor(nts::Tristate a, nts::Tristate b);
    nts::Tristate Or(nts::Tristate a, nts::Tristate b);
    nts::Tristate Inverter(nts::Tristate a);
    nts::Tristate Nand(nts::Tristate a, nts::Tristate b);
}

#endif /* !GATE_HPP_ */
