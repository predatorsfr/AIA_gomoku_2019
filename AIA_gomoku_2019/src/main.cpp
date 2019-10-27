//
// EPITECH PROJECT, 2019
// main
// File description:
// 
//

#include "IA.hpp"

int main(void)
{
    std::string stream;

    getline(std::cin, stream);
    if (stream.find("START ") != std::string::npos) {
        std::string ask = stream.substr(6);
        IA ia(stoi(ask));
        while(getline(std::cin, stream)) {
            ia.process(stream);
        } 
    }
}