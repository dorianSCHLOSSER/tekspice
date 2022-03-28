/*
** EPITECH PROJECT, 2021
** Boostrap-NanoTEkSpice
** File description:
** Component
*/

#include "Component.hpp"

nts::Component::Component() {
    _constr["input"] = std::bind(&nts::Component::createInput, this, std::placeholders::_1);
    _constr["output"] = std::bind(&nts::Component::createOutput, this, std::placeholders::_1);
    _constr["4001"] = std::bind(&nts::Component::create4001, this, std::placeholders::_1);
    _constr["true"] = std::bind(&nts::Component::createTrue, this, std::placeholders::_1);
    _constr["false"] = std::bind(&nts::Component::createFalse, this, std::placeholders::_1);
    _constr["clock"] = std::bind(&nts::Component::createClock, this, std::placeholders::_1);
    _constr["4081"] = std::bind(&nts::Component::create4081, this, std::placeholders::_1);
    _constr["4030"] = std::bind(&nts::Component::create4030, this, std::placeholders::_1);
    _constr["4069"] = std::bind(&nts::Component::create4069, this, std::placeholders::_1);
    _constr["4071"] = std::bind(&nts::Component::create4071, this, std::placeholders::_1);
    _constr["4011"] = std::bind(&nts::Component::create4011, this, std::placeholders::_1);
}

nts::Component::~Component(){}

std::unique_ptr<nts::IComponent> nts::Component::createComponent(const std::string &type, const std::string &value)
{
    return (_constr[type](value));
}

std::unique_ptr<nts::IComponent> nts::Component::createInput(const std::string &value) const noexcept 
{
    return (std::make_unique<Input>(value));
}

std::unique_ptr<nts::IComponent> nts::Component::createOutput(const std::string &value) const noexcept 
{
    return (std::make_unique<Output>());
}

std::unique_ptr<nts::IComponent> nts::Component::create4001(const std::string &value) const noexcept
{
    return (std::make_unique<C4001>());
}

std::unique_ptr<nts::IComponent> nts::Component::createTrue(const std::string &value) const noexcept
{
    return (std::make_unique<True>());
}

std::unique_ptr<nts::IComponent> nts::Component::createFalse(const std::string &value) const noexcept
{
    return (std::make_unique<False>());
}

std::unique_ptr<nts::IComponent> nts::Component::createClock(const std::string &value) const noexcept
{
    return (std::make_unique<Clock>(value));
}

std::unique_ptr<nts::IComponent> nts::Component::create4081(const std::string &value) const noexcept
{
    return (std::make_unique<C4081>());
}

std::unique_ptr<nts::IComponent> nts::Component::create4030(const std::string &value) const noexcept
{
    return (std::make_unique<C4030>());
}

std::unique_ptr<nts::IComponent> nts::Component::create4069(const std::string &value) const noexcept
{
    return (std::make_unique<C4069>());
}

std::unique_ptr<nts::IComponent> nts::Component::create4071(const std::string &value) const noexcept
{
    return (std::make_unique<C4071>());
}

std::unique_ptr<nts::IComponent> nts::Component::create4011(const std::string &value) const noexcept
{
    return (std::make_unique<C4011>());
}