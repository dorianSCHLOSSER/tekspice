/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** C4081
*/

#ifndef C4081_HPP_
#define C4081_HPP_
#include "IComponent.hpp"
#include "Gate.hpp"

namespace nts
{
    class C4081 : public IComponent
    {
        public:
            C4081();
            ~C4081() = default;

            nts::Tristate compute(std::size_t pin);
            void setLink(std::size_t pin, nts::IComponent &other, std::
            size_t otherPin);
            void dump(const std::string &name);
            nts::Tristate getValue(std::size_t pin);
            void setValue(const std::string &value);
        protected:
        private:
            std::map<size_t, nts::Tristate> _valMap;
            std::map<size_t, std::pair<size_t, size_t> > _valOut;
            std::map<size_t, size_t> _link;
            nts::IComponent *_links[14];
    };
}
#endif /* !C4081_HPP_ */
