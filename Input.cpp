/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Input
*/

#include "Input.hpp"

nts::Input::Input(const std::string &value)
{
    _links = NULL;
    if (value == "0") _value = nts::Tristate::FALSE;
    else if (value == "1") _value = nts::Tristate::TRUE;
    else _value = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Input::getValue(std::size_t pin)
{
    return (_value);
}

void nts::Input::setValue(const std::string &value)
{
    if (value == "0") _value = nts::Tristate::FALSE;
    else if (value == "1") _value = nts::Tristate::TRUE;
    else _value = nts::Tristate::UNDEFINED;
}

nts::Tristate nts::Input::compute(std::size_t pin) 
{
    if (_value == nts::Tristate::TRUE)
        return (_value);
    else if (_value == nts::Tristate::FALSE)
        return (_value);
    _value = nts::Tristate::UNDEFINED;
    return (_value);
}

void nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin) 
{
    if (pin == 1) {
        _link[pin] = otherPin;
        _links = &other;
    }
    else {
        std::cout << "ERROR LINK INPUT" << std::endl;
        exit(84);
    }
}

void nts::Input::dump(const std::string &name) 
{
    if (getValue(1) == nts::Tristate::UNDEFINED)
        std::cout << name << ":1= U" << std::endl;
    else
        std::cout << name << ":1= " << getValue(1) << std::endl;
}