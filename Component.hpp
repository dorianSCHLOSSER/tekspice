/*
** EPITECH PROJECT, 2021
** Boostrap-NanoTEkSpice
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_
#include "IComponent.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "C4001.hpp"
#include "True.hpp"
#include "False.hpp"
#include "Clock.hpp"
#include "C4081.hpp"
#include "C4030.hpp"
#include "C4069.hpp"
#include "C4071.hpp"
#include "C4011.hpp"

namespace nts
{
    class Component
    {
        public:
            Component();
            ~Component();

            std::unique_ptr<IComponent> createComponent(const std::string &type, const std::string &value);

        protected:
        private:
            std::map<std::string, std::function<std::unique_ptr<IComponent> (const std::string &)> >_constr;
            std::unique_ptr<IComponent> createInput(const std::string &value) const noexcept;
            std::unique_ptr<IComponent> createOutput(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> createTrue(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> createFalse(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> createClock(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4081(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4030(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4069(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4071(const std::string &value) const noexcept;
            std::unique_ptr<nts::IComponent> create4011(const std::string &value) const noexcept;
    };
}

#endif /* !COMPONENT_HPP_ */
