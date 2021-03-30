#include "Maze.h"
#include <iostream>
#include<string>
using namespace std;

// Creates a Maze with no blocked cells; start = (0, 0); goal = (SIZE, SIZE)
Maze::Maze(){
  for (int row = 0; row < SIZE; row++) {
    for (int col = 0; col < SIZE; col++) {
          maze[row][col] = EMPTY;
    }
  }
  startCellRow = startCellCol = 0;
  endCellRow = endCellCol = SIZE-1;
  setStartCell(0,0);
  setEndCell(SIZE-1, SIZE-1);
}

// Puts obstacle on the cell (row, col)
void Maze::blockCell(int row, int col){
  maze[row][col] = BLOCKED;
}

// Sets start cell to (row, col)
void Maze::setStartCell(int row, int col){
  maze[startCellRow][startCellCol] = EMPTY;
  startCellRow = row;
  startCellCol = col;
  maze[startCellRow][startCellCol] = START;
}

// Sets goal cell to (row, col)
void Maze::setEndCell(int row, int col){
  maze[endCellRow][endCellCol] = EMPTY;
  endCellRow = row;
  endCellCol = col;
  maze[endCellRow][endCellCol] = END;
}

// is position (row, col) clear?
bool Maze::isClear(int row, int col) const{
  return maze[row][col] == EMPTY;
}

// returns the size of the Maze
int Maze::size() const{
  return SIZE;
}

// clear the maze: erase all obstacles
void Maze::clearAllCells(){
    for (int row = 0; row < SIZE; row++) {
      for (int col = 0; col < SIZE; col++) {
        if (maze[row][col]!= 'S' || maze[row][col]!= 'G')
            maze[row][col] = EMPTY;
      }
    }
}

// overloaded output operator
std::ostream& operator<< (std::ostream &out, const Maze &m){
  for (int row = 0; row <= m.size()+1; row++) out << "_";
  for (int row = 0; row < m.size(); row++) {
    out << "\n|";
    for (int col = 0; col < m.size(); col++) {
      out << m.maze[row][col];
    }
    out << "|\n";
  }
  for (int row = 0; row <= m.size()+1; row++) out << "-";
  return out;
}

std::string Maze::solveBacktracking(){
//your code here
  std::stack<char> result;
  rowmp.push(0);
  colmp.push(0);
  mazepatha[0][0]=1;
  while(!rowmp.empty()){
  if(mazepatha[rowmp.top()][colmp.top()]==2){
      std::string temp="";
      while(!result.empty()){
        temp.push_back(result.top());
        result.pop();
      }
      std::string results="";
      for(auto i=temp.rbegin();i!=temp.rend();i++){
        results.push_back(*i);
        results.push_back(62);
        results.push_back(62);
      }
      results=results.substr(0,results.length()-2);
      return results;
    }
    else if((mazepatha[rowmp.top()][colmp.top()+1]==0||mazepatha[rowmp.top()][colmp.top()+1]==2)&&colmp.top()+1<7){
        if(mazepatha[rowmp.top()][colmp.top()+1]!=2)
          mazepatha[rowmp.top()][colmp.top()+1]=1;
        rowmp.push(rowmp.top());
        colmp.push(colmp.top()+1);
        result.push('E');
    }
    else{
      if((mazepatha[rowmp.top()+1][colmp.top()]==0||mazepatha[rowmp.top()+1][colmp.top()]==2)&&rowmp.top()+1<7){
        if(mazepatha[rowmp.top()+1][colmp.top()]!=2)
          mazepatha[rowmp.top()+1][colmp.top()]=1;
        rowmp.push(rowmp.top()+1);
        colmp.push(colmp.top());
        result.push('S');
      }
       else if((mazepatha[rowmp.top()][colmp.top()-1]==0||mazepatha[rowmp.top()][colmp.top()-1]==2)&&colmp.top()-1>-1){
        if(mazepatha[rowmp.top()][colmp.top()-1]!=2)
          mazepatha[rowmp.top()][colmp.top()-1]=1;
        rowmp.push(rowmp.top());
        colmp.push(colmp.top()-1);
        result.push('W');
       
      }
        else if(((mazepatha[rowmp.top()+1][colmp.top()]!=0||rowmp.top()+1==7)&&(mazepatha[rowmp.top()][colmp.top()+1]!=0||colmp.top()+1==7)&&
    (mazepatha[rowmp.top()-1][colmp.top()]!=0||rowmp.top()-1==-1)&&(mazepatha[rowmp.top()][colmp.top()-1]!=0||colmp.top()-1==-1))){
        mazepatha[rowmp.top()][colmp.top()]=1;
        rowmp.pop();
        colmp.pop();
        result.pop();
    
      }
       else if((mazepatha[rowmp.top()-1][colmp.top()]==0||mazepatha[rowmp.top()-1][colmp.top()]==2)&&rowmp.top()-1>-1){
        if(mazepatha[rowmp.top()-1][colmp.top()]!=2)
          mazepatha[rowmp.top()-1][colmp.top()]=1;
        rowmp.push(rowmp.top()-1);
        colmp.push(colmp.top());
        result.push('N');
      }
    }
  }
  return "unsolvable";
}

void Maze:: notvisited(){
  for(int i=0;i<SIZE;i++){
    for(int j=0;j<SIZE;j++){
      if(maze[i][j]==BLOCKED)
        mazepatha[i][j]=-1;
      else if(maze[i][j]==END)
        mazepatha[i][j]=2;
      else
        mazepatha[i][j]=0;
    }
  }
}
