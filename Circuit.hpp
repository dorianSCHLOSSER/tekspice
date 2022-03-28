/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_
#include "IComponent.hpp"
#include "Parse.hpp"


namespace nts {
    class Circuit {
        public:
            Circuit(int argc, char **argv);
            ~Circuit() = default;

            void start();

        protected:
        private:
            std::string _filename;
    };
}

#endif /* !CIRCUIT_HPP_ */
