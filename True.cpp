/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** True
*/

#include "True.hpp"

nts::True::True()
{
    _value = nts::Tristate::TRUE;
    _links = NULL;
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    _value = nts::Tristate::TRUE;
    return (nts::Tristate::TRUE);
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin)
{
    if (pin == 1) {
        _link[pin] = otherPin;
        _links = &other;
    }
    else {
        std::cout << "ERROR PIN TRUE" << std::endl;
        exit(84);
    }
}

void nts::True::dump(const std::string &name)
{
    if (getValue(1) == nts::Tristate::UNDEFINED)
        std::cout << name << ":1= U" << std::endl;
    else
        std::cout << name << ":1= " << getValue(1) << std::endl;
}

nts::Tristate nts::True::getValue(std::size_t pin)
{
    return (_value);
}

void nts::True::setValue(const std::string &value)
{
    _value = nts::Tristate::TRUE;
}