/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Gate
*/

#include "Gate.hpp"

nts::Tristate gate::And(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if (a == nts::Tristate::FALSE || b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    else
        return (nts::Tristate::UNDEFINED);
}

nts::Tristate gate::Xor(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else
        return (nts::Tristate::TRUE);
}

nts::Tristate gate::Nor(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else
        return (nts::Tristate::UNDEFINED);
}

nts::Tristate gate::Or(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
     else if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    else
        return (nts::Tristate::UNDEFINED);
}

nts::Tristate gate::Inverter(nts::Tristate a)
{
    if (a == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else
        return (nts::Tristate::UNDEFINED);
}

nts::Tristate gate::Nand(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    else if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    else if (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    else if (a == nts::Tristate::FALSE || b == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    else
        return (nts::Tristate::UNDEFINED);
}