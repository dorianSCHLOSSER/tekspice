/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** C4069
*/

#include "C4069.hpp"

nts::C4069::C4069()
{
    for (int i = 0 ; i < 14 ; i++) {
        _valMap[i] = nts::Tristate::UNDEFINED;
        _links[i] = NULL;
    }
    _valOut[2] = 1;
    _valOut[4] = 3;
    _valOut[6] = 5;
    _valOut[8] = 9;
    _valOut[10] = 11;
    _valOut[12] = 13;
}

nts::Tristate nts::C4069::compute(std::size_t pin)
{
    if (pin == 2 || pin == 4 || pin == 6 || pin == 8 || pin == 10 || pin == 12) {
        if (_links[_valOut[pin] - 1]) {
        _valMap[pin - 1] = gate::Inverter(_links[_valOut[pin] - 1]->getValue(_valOut[pin]));
        return (_valMap[pin - 1]);
        }
    }
    else if (_links[pin - 1]) {
        _valMap[pin - 1] = _links[pin - 1]->getValue(_link[pin]);
        return (_valMap[pin - 1]);
    }
    exit(84);
}

void nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin)
{
    if (pin >= 1 && pin <= 14) {
        if (pin == 14 || pin == 7) {
            std::cout << "ERROR PIN 4069" << std::endl;
            exit(84);
        }
        _link[pin] = otherPin;
        _links[pin - 1] = &other;
    }
    else {
        std::cout << "ERROR PIN 4069" << std::endl;
        exit(84);
    }
}

nts::Tristate nts::C4069::getValue(std::size_t pin)
{
    return (_valMap[pin - 1]);
}

void nts::C4069::dump(const std::string &name) 
{
    for (int i = 0 ; i < 14 ; i++) {
        if (i != 14 && i != 7 && i != 0) {
        if (getValue(i) == nts::Tristate::UNDEFINED)
            std::cout << name << ":" << i << "= U" << std::endl;
        else
            std::cout << name << ":" << i << "= " << getValue(i) << std::endl;
        }
    }
}

void nts::C4069::setValue(const std::string &value) {}