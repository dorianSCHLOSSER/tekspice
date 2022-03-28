/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_
#include "IComponent.hpp"

namespace nts
{
    class Input : public IComponent
    {
        public:
            Input(const std::string &value);
            ~Input() = default;

            nts::Tristate getValue(std::size_t pin);
            void setValue(const std::string &value);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin);
            void dump(const std::string &name);

        protected:
            nts::Tristate _value;
            std::map<size_t, size_t> _link;
            nts::IComponent *_links;
        private:
    };
}

#endif /* !INPUTS_HPP_ */
