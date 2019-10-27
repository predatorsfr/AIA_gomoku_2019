//
// EPITECH PROJECT, 2019
// IA
// File description:
// 
//

#ifndef IA_HPP
#define IA_HPP
#include <vector>
#include <iostream>
#include <string>

class IA
{
public:
    IA(int length);
    ~IA(){};
    void process(std::string str);
    void ask(int x, int y);
private:
    std::vector<std::vector<char>> map;
    int length;
};

struct Move 
{ 
    int row, col; 
}; 

Move findBestMove(std::vector<std::vector<char>> map);



#endif
