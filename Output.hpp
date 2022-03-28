/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Output
*/

#ifndef OUTPUT_HPP_
#define OUTPUT_HPP_
#include "IComponent.hpp"
#include "Input.hpp"

namespace nts 
{
    class Output : public IComponent
    {
        public:
            Output();
            ~Output() = default;

            nts::Tristate getValue(std::size_t pin);
            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin);
            void dump(const std::string &name);
            void setValue(const std::string &value);

        protected:
        private:
            nts::Tristate _value;
            nts::IComponent *_links;
            std::map<size_t, size_t> _link;
    };
}

#endif /* !OUTPUT_HPP_ */
