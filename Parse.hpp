/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Parse
*/

#ifndef PARSE_HPP_
#define PARSE_HPP_
#include "IComponent.hpp"
#include "Component.hpp"

namespace nts {
    class Parse {
        public:
            Parse();
            ~Parse() = default;
            void checkName(const std::string &filename);
            void refreshFile(const std::string &filename);
            void cleanFile(const std::string &buff);
            void checkTypeMapChip();
            void parseComponent();
            void parseType(bool checkup, const std::string &check2, const std::string &check);
            void game();
            void parseLinks();
            void links();
            void checkLinks() const;
            void display();
            void charge();
            void sortComp();
            void terminalInput(const std::string &line);
            void displayAll();

        protected:
        private:
            bool _titleLinks;
            bool _titleChip;
            size_t _tickets;
            size_t _nbrInput;
            std::vector<std::string> _mapChip;
            std::vector<std::string> _mapLinks;
            std::map<size_t, std::string> _type;
            std::vector<std::string> _input;
            std::vector<std::string> _output;
            std::vector<std::pair<std::string, std::string>> _componentChip;
            std::map<std::string, std::unique_ptr<nts::IComponent>> _allComp;
            std::vector<std::pair<std::string, std::string>> _linkFirst;
            std::vector<std::pair<std::string, std::string>> _linkSecond;
            std::vector<std::pair<std::string, std::string>> _terminal;
            std::vector<std::string> _all;
    };
}
#endif /* !PARSE_HPP_ */
