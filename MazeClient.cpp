#include<iostream>
#include"Maze.h"

int main(){
    Maze m;
    m.blockCell(2,3);m.blockCell(3,3);
    m.notvisited();
    std::cout<<m<<"\n";
    std::cout<<m.solveBacktracking()<<"\n";
    return 0;
}
