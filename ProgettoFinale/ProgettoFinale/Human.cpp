//Bino Matteo

#include "Human.h"

Human::Human(std::string name)
    : Player(name)
{
}

std::string Human::getPositioningInput(const int length)
{
    std::string input = getInput();

    std::vector<std::string> elems = HUtils::divideString(input);

    if(elems.size() != 2) throw std::invalid_argument("input non valido.");

    return input;
}

std::string Human::getPlayInput(std::vector<Ship*>* ships)
{
    std::string input = getInput();
    std::vector<std::string> elems = HUtils::divideString(input);
    if (elems.size() != 2) throw std::invalid_argument("input non valido.");

    return input;
}

std::string Human::getInput()
{
    std::string input;

    std::getline(std::cin, input, '\n');

    std::cin.clear();
    std::fflush(stdin);

    std::transform(input.begin(), input.end(), input.begin(), ::toupper);

    return input;
}

std::vector<std::string> HUtils::divideString(std::string input, char separator)
{
    std::vector<std::string> v = std::vector<std::string>();

    std::stringstream ss(input);
    char c;
    std::string s = "";
    while (ss.get(c)) {
        if (c != ' ')s += c;
        else if (s != "") {
            v.push_back(s);
            s = "";
        }
    }
    if (s != "") v.push_back(s);

    return v;
}
