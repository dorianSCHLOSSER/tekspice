/*
** EPITECH PROJECT, 2021
** B-OOP-400-STG-4-1-tekspice-dorian.schlosser
** File description:
** Parse
*/

#include "Parse.hpp"

nts::Parse::Parse()
{
    _nbrInput = 0;
    _tickets = 0;
    _titleChip = false;
    _titleLinks = false;
    _type[0] = "input";
    _type[1] = "output";
    _type[2] = "4001";
    _type[3] = "true";
    _type[4] = "false";
    _type[5] = "clock";
    _type[6] = "4081";
    _type[7] = "4030";
    _type[8] = "4069";
    _type[9] = "4071";
    _type[10] = "4011";
}

//On check si le nom du fichier fini par .nts
void nts::Parse::checkName(const std::string &fileName)
{
    size_t pos = fileName.find_last_of('.');
    if (pos == std::string::npos) exit(84);
    std::string check = "";

    while (fileName[pos]) {
        check += fileName[pos];
        pos += 1;
    }
    if (check != ".nts") {
        std::cout << "ERROR file" << std::endl;
        exit(84);
    }
}

//On retire le surplus du fichier et on split les chipsets et les links
void nts::Parse::refreshFile(const std::string &fileName)
{
    std::string buffer = "";
    std::ifstream ifs (fileName);

    if (ifs.is_open()) {
        while (std::getline(ifs, buffer))
            cleanFile(buffer);
        ifs.close();
    }
    else exit(84);
    if (_titleLinks != true || _titleChip != true) {
        std::cout << "ERROR TITLE" << std::endl;
        exit(84);
    }
    checkTypeMapChip();
}

//Fonction appelé pour retirer le surplus et split
void nts::Parse::cleanFile(const std::string &buff)
{
    size_t pos = buff.find_first_of("#");
    if (buff == ".chipsets:") _titleChip = true;
    if (buff == ".links:") _titleLinks = true;
    if (pos == std::string::npos && buff != "" && buff != ".chipsets:" 
        && buff != ".links:") {
        if (_titleChip == true && _titleLinks == false)
            _mapChip.push_back(buff);
        if (_titleChip == true && _titleLinks == true)
            _mapLinks.push_back(buff);
    }
}

//On introduit les types et les noms dans un vecteur, en retirant les espaces
void nts::Parse::checkTypeMapChip()
{
    bool checkup;
    int i = 0;
    std::string check, check2;
    size_t pos, pos1, pos_start, pos_end;
    for (auto &line : _mapChip) {
        checkup = false;
        pos = line.find_first_of(" ");
        pos1 = line.find_first_of("\t");
        if (pos == std::string::npos && pos1 == std::string::npos) exit(84);
        if (pos < pos1) pos_start = pos;
        else pos_start = pos1;
        pos = line.find_last_of(" ");
        pos1 = line.find_last_of("\t");
        if (pos < pos1 && pos1 == std::string::npos) pos_end = pos;
        else if (pos < pos1 && pos1 != std::string::npos) pos_end = pos1;
        else if (pos > pos1 && pos == std::string::npos) pos_end = pos1;
        else if (pos > pos1 && pos != std::string::npos) pos_end = pos;
        check = line.substr(0, pos_start);
        check2 = line.substr(pos_end + 1);
        parseType(checkup, check2, check);
        _componentChip.push_back(std::make_pair(check, check2));
    }
    if (_nbrInput == 0) exit(84);
}

//on check les types et si ils existent on met les noms dans deux vecteurs (inputs et outputs)
void nts::Parse::parseType(bool checkup, const std::string &check2, const std::string &check)
{
    for (std::map<size_t, std::string>::const_iterator map = _type.begin() ; 
            map != _type.end() ; map++) {
                if (map->second == check)
                    checkup = true;
            }
        if (checkup == true && (check == "input" || check == "clock"))
            _input.push_back(check2);
        if (checkup == true && (check == "input" || check == "clock" || check == "true" || check == "false")) _nbrInput += 1;
        if (checkup == true && check == "output")
            _output.push_back(check2);
        if (checkup == true) {
            _all.push_back(check2);
        }
        if (checkup == false) {
            std::cout << "ERROR TYPE" << std::endl;
            exit(84);
        }
}

//on crée les components
void nts::Parse::parseComponent()
{
    for(auto &line : _componentChip) {
        nts::Component *comp = new Component();
            _allComp[line.second] = comp->createComponent(line.first, "");
    }
}

//on parse les liens, et on les split en deux dans deux vecteurs différents
void nts::Parse::parseLinks()
{
    int i = 0;
    size_t pos, pos1, pos2, pos3, pos_end;
    for (auto &line : _mapLinks) {
        std::string first, second;
        if (!std::regex_match(line, std::regex("[a-zA-Z0-9_]+:[0-9]+[\t ]+[a-zA-Z0-9_]+:[0-9]+")) &&
            !std::regex_match(line, std::regex("[a-zA-Z0-9_]+:[0-9]+[ ]+[a-zA-Z0-9_]+:[0-9]+"))) {
            std::cout << "ERROR PARSE LINKS" << std::endl;
            exit(84);
        }
        pos = line.find_first_of(":");
        first = line.substr(0, pos);
        if (pos + 3 == line.find_first_of(" ") || pos + 3 == line.find_first_of("\t"))
            second = line.substr(pos + 1, 2);
        else second = line.substr(pos + 1, 1);
        _linkFirst.push_back(std::make_pair(first, second));
        pos = line.find_last_of(":");
        pos1 = line.find_last_of(" ");
        pos2 = line.find_last_of("\t");
        if (pos1 == std::string::npos && pos2 == std::string::npos) exit(84);
        if (pos1 < pos2 && pos2 == std::string::npos) pos_end = pos1;
        else if (pos1 < pos2 && pos2 != std::string::npos) pos_end = pos2;
        else if (pos1 > pos2 && pos1 == std::string::npos) pos_end = pos2;
        else if (pos1 > pos2 && pos1 != std::string::npos) pos_end = pos1;
        pos3 = line.length() - pos;
        pos = pos - pos_end;
        first = line.substr(pos_end + 1, pos - 1);
        second = line.substr(pos_end + 1 + first.length() + 1, pos3);
        _linkSecond.push_back(std::make_pair(first, second));
    }
}

//on check si les noms des liens marchent
void nts::Parse::checkLinks() const
{
    bool check = false;
    for (auto &map : _linkFirst) {
        for (auto &mapComp : _componentChip) {
            if (mapComp.second == map.first) check = true;
        }
        if (check != true)  {
            std::cout << "ERROR CHECK LINKS" << std::endl;
            exit(84);
        }
        check = false;
    }
    check = false;
    for (auto &map : _linkSecond) {
        for (auto &mapComp : _componentChip) {
            if (mapComp.second == map.first) check = true;
        }
        if (check != true)  {
            std::cout << "ERROR CHECK LINKS" << std::endl;
            exit(84);
        }
        check = false;
    }
}

//on fait les liens et on vérifie si tous les pins sont corrects
void nts::Parse::links()
{
    auto &mapSecond = _linkSecond;
    int i = 0;
    for (auto &map : _linkFirst) {
        _allComp[map.first]->setLink(atoi(map.second.c_str()), *_allComp[mapSecond[i].first], atoi(mapSecond[i].second.c_str()));
        _allComp[mapSecond[i].first]->setLink(atoi(mapSecond[i].second.c_str()), *_allComp[map.first], atoi(map.second.c_str()));
        i += 1;
    }
}

//charge les liens
void nts::Parse::charge()
{
    auto &mapSecond = _linkSecond;
    int i = 0;
    for (auto &map : _linkFirst) {
        _allComp[mapSecond[i].first]->compute(atoi(mapSecond[i].second.c_str()));
        _allComp[map.first]->compute(atoi(map.second.c_str()));
        _allComp[mapSecond[i].first]->compute(atoi(mapSecond[i].second.c_str()));
        i += 1;
    }
}

//function de trie
void nts::Parse::sortComp()
{
    std::sort(_input.begin(), _input.end());
    std::sort(_output.begin(), _output.end());
    std::sort(_all.begin(), _all.end());
}

//display
void nts::Parse::display()
{
    std::cout << "tick: " << _tickets << std::endl;
    std::cout << "input(s):" << std::endl;
    for (auto &map : _input) {
        if (_allComp[map]->compute(1) == nts::Tristate::UNDEFINED) {
            std::cout << "  " << map << ": " << "U" << std::endl;
        }
        else
            std::cout << "  " << map << ": " << _allComp[map]->compute(1) << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &map : _output) {
        if (_allComp[map]->getValue(1) == nts::Tristate::UNDEFINED) {
            std::cout << "  " << map << ": " << "U" << std::endl;
        }
        else
            std::cout << "  " << map << ": " << _allComp[map]->getValue(1) << std::endl;
    }
}

void nts::Parse::displayAll()
{
    std::cout << "tick: " << _tickets << std::endl;
    std::cout << "ALL:" << std::endl;
    for (auto &map : _all) {
        _allComp[map]->dump(map);
    }
}

void signalHandler(int signum) {
    std::cout << "Interrupt signal (" << signum << ") received" << std::endl;
    exit(0);
}

//note dans le terminal
void nts::Parse::game()
{
    std::cout << "> ";
    for (std::string line ; std::getline(std::cin, line);) {
        if (line == "simulate") {
            _tickets += 1;
            for (auto &map : _terminal)
                _allComp[map.first]->setValue(map.second);
            charge();
            _terminal.clear();
        }
        if (line == "display")
            display();
        if (line == "exit")
            exit(0);
        if (line == "dump")
            displayAll();
        if (line == "loop") {
            for (auto &map : _terminal)
                    _allComp[map.first]->setValue(map.second);
            std::signal(SIGINT, signalHandler);
            while(1) {
                _tickets += 1;
                charge();
                display();
                _terminal.clear();
                sleep(1);
            }
        }
        terminalInput(line);
        std::cout << "> ";
    }
}

void nts::Parse::terminalInput(const std::string &line)
{
    if (!std::regex_match(line, std::regex("[a-zA-Z0-9_]+=+[0-1U]+"))) return;
    size_t pos;
    std::string name;
    std::string value;
    bool checkName = false;
    pos = line.find_first_of("=");
    name = line.substr(0, pos);
    value = line.substr(pos + 1, 1);
    for (auto &map : _input) {
        if (map == name) 
            checkName = true;
    }
    if (checkName != true && (value != "U" || value != "1" || value != "0")) return;
    if (value == "U")
        _terminal.push_back(std::make_pair(name, "-1"));
    else
        _terminal.push_back(std::make_pair(name, value));
}