/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_
#include "IComponent.hpp"

namespace nts 
{
    class False : public IComponent
    {
        public:
            False();
            ~False() = default;

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin);
            void dump(const std::string &name);
            nts::Tristate getValue(std::size_t pin);
            void setValue(const std::string &value);

        protected:
        private:
            nts::Tristate _value;
            nts::IComponent *_links;
            std::map<size_t, size_t> _link;
    };
}

#endif /* !FALSE_HPP_ */
