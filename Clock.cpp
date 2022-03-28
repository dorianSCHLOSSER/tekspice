/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Clock
*/

#include "Clock.hpp"

nts::Clock::Clock(const std::string &value)
{
    _check = 0;
    _links = NULL;
    if (value == "0") _value = nts::Tristate::FALSE;
    else if (value == "1") _value = nts::Tristate::TRUE;
    else _value = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    if (_value == nts::Tristate::UNDEFINED) {
        _check = 0;
        return (_value);
    }
    if (_check == 0) {
        _check += 1;
        return (_value);
    }
    if (_value == nts::Tristate::FALSE)
        _value = nts::Tristate::TRUE;
    else if (_value == nts::Tristate::TRUE)
        _value = nts::Tristate::FALSE;
    else
        _value = nts::Tristate::UNDEFINED;
    return (_value);
}

void nts::Clock::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin)
{
    if (pin == 1) {
        _link[pin] = otherPin;
        _links = &other;
    }
    else {
        std::cout << "ERROR PIN CLOCK" << std::endl;
        exit(84);
    }
}

void nts::Clock::dump(const std::string &name)
{
    if (getValue(1) == nts::Tristate::UNDEFINED)
        std::cout << name << ":1= U" << std::endl;
    else
        std::cout << name << ":1= " << getValue(1) << std::endl;
}

nts::Tristate nts::Clock::getValue(std::size_t pin)
{
    return (_value);
}

void nts::Clock::setValue(const std::string &value)
{
    if (value == "0") _value = nts::Tristate::FALSE;
    else if (value == "1") _value = nts::Tristate::TRUE;
    else _value = nts::Tristate::UNDEFINED;
}