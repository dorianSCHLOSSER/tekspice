/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Output
*/

#include "Output.hpp"

nts::Output::Output()
{
    _value = nts::Tristate::UNDEFINED;
    _links = NULL;
}

nts::Tristate nts::Output::getValue(std::size_t pin)
{
    return (_value);
}

nts::Tristate nts::Output::compute(std::size_t pin) 
{
    if (_links) {
        if (_links->getValue(_link[pin]) == nts::Tristate::TRUE)
        _value = nts::Tristate::TRUE;
        else if (_links->getValue(_link[pin]) == nts::Tristate::FALSE)
        _value = nts::Tristate::FALSE;
        else
            _value = nts::Tristate::UNDEFINED;
    }
    return (_value);
}

void nts::Output::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin) 
{
    if (pin == 1) {
        _link[pin] = otherPin;
        _links = &other;
    }
    else {
        std::cout << "ERROR LINKS OUTPUT" << std::endl;
        exit(84);
    }
}

void nts::Output::dump(const std::string &name) 
{
    if (getValue(1) == nts::Tristate::UNDEFINED)
        std::cout << name << ":1= U" << std::endl;
    else
        std::cout << name << ":1= " << getValue(1) << std::endl;
}

void nts::Output::setValue(const std::string &value) {}