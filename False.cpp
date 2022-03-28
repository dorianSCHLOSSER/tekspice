/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** False
*/

#include "False.hpp"

nts::False::False()
{
    _value = nts::Tristate::FALSE;
    _links = NULL;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
    _value = nts::Tristate::FALSE;
    return (nts::Tristate::FALSE);
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin)
{
    if (pin == 1) {
        _link[pin] = _link[otherPin];
        _links = &other;
    }
    else {
        std::cout << "ERROR PIN FALSE" << std::endl;
        exit(84);
    }
}

void nts::False::dump(const std::string &name)
{
    if (getValue(1) == nts::Tristate::UNDEFINED)
        std::cout << name << ":1= U" << std::endl;
    else
        std::cout << name << ":1= " << getValue(1) << std::endl;
}

nts::Tristate nts::False::getValue(std::size_t pin)
{
    return (_value);
}

void nts::False::setValue(const std::string &value)
{
    _value = nts::Tristate::FALSE;
}
