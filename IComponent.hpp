/*
** EPITECH PROJECT, 2021
** Boostrap-NanoTEkSpice
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_
#include <iostream>
#include <memory>
#include <map>
#include <functional>
#include <fstream>
#include <vector>
#include <regex>
#include <unistd.h>
#include <csignal>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin) = 0;
            virtual void dump(const std::string &name) = 0;
            virtual nts::Tristate getValue(std::size_t pin) = 0;
            virtual void setValue(const std::string &value) = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
