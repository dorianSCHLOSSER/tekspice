/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** C4071
*/

#include "C4071.hpp"

nts::C4071::C4071()
{
    for (int i = 0 ; i < 14 ; i++) {
        _valMap[i] = nts::Tristate::UNDEFINED;
        _links[i] = NULL;
    }
    _valOut[3] = std::make_pair(1, 2);
    _valOut[4] = std::make_pair(5, 6);
    _valOut[10] = std::make_pair(8, 9);
    _valOut[11] = std::make_pair(12, 13);
}

nts::Tristate nts::C4071::compute(std::size_t pin)
{
    if (pin == 3 || pin == 4 || pin == 10 || pin == 11) {
        if (_links[_valOut[pin].first - 1] && _links[_valOut[pin].second - 1]) {
        _valMap[pin - 1] = gate::Or(_links[_valOut[pin].first - 1]->getValue(_valOut[pin].first), _links[_valOut[pin].second - 1]->getValue(_valOut[pin].second));
        return (_valMap[pin - 1]);
        }
    }
    else if (_links[pin - 1]) {
        _valMap[pin - 1] = _links[pin - 1]->getValue(_link[pin]);
        return (_valMap[pin - 1]);
    }
    exit(84);
}

void nts::C4071::setLink(std::size_t pin, nts::IComponent &other, std::
size_t otherPin)
{
    if (pin >= 1 && pin <= 14) {
        if (pin == 14 || pin == 7) {
            std::cout << "ERROR PIN 4071" << std::endl;
            exit(84);
        }
        _link[pin] = otherPin;
        _links[pin - 1] = &other;
    }
    else {
        std::cout << "ERROR PIN 4071" << std::endl;
        exit(84);
    }
}

nts::Tristate nts::C4071::getValue(std::size_t pin)
{
    return (_valMap[pin - 1]);
}

void nts::C4071::dump(const std::string &name) 
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

void nts::C4071::setValue(const std::string &value) {}