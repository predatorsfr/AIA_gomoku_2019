//
// EPITECH PROJECT, 2019
// IA
// File description:
// 
//

#include "IA.hpp"

IA::IA(int length)
{
    if (length <= 1)
        std::cout << "ERROR message - unsupported size or other error" <<std::endl;
    for (int i = 0 ; i < length ; ++i) {
        std::vector<char> tab;
        map.push_back(tab);
        for (int j = 0 ; j < length ; ++j) {
            map[i].push_back('_');
        }
    }
    std::cout << "OK - everything is good" <<std::endl;
}

void IA::process(std::string str)
{
    std::size_t pos;
    int x;
    int y;

    if (str.find("TURN ") != std::string::npos) {
        std::string ask = str.substr(5);
        if ((pos = ask.find(",")) != std::string::npos) {
            x = std::stoi(ask.substr(0, (int)pos));
            y = std::stoi(ask.substr((int)pos + 1));
            map[--x][--y] = 'E';
            this->ask(x, y);
        }
    } else if (str == "BEGIN" || str == "BOARD") {
            std::cout <<"0,0"<<std::endl;
    } else if (str == "END")
            exit(0);
}

void IA::ask(int x, int y)
{
    char tab[3][3];
    int y2 = 0, x2 = 0;

    if (x == 0)
        x2++;
    if (y == 0)
        y2++;
    if (x == (int)map.size())
        x2--;
    if (y == (int)map.size())
        y2--;
    int beginx = x + x2 - 1;
    int beginy = y + y2 - 1;
    for(int i = 0 ; i < 3; i++)
        for (int j = 0 ; j < 3 ; j++)
            tab[i][j] = map[x + x2 + i - 1][y + y2 + j -1];
    Move move = findBestMove(tab);
    map[move.col + beginx][move.row + beginy] = 'A';
    std::cout << beginx + move.col + 1 << ","<< beginy + move.row + 1<<std::endl;

}
