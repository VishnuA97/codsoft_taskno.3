#include<iostream>
#include<cstdlib>
using namespace std;


char grid_pos[3][3]={{'1','2','3',}, {'4','5','6'}, {'7','8','9'}};
int row, column;
int pos;
char turn = 'X';
bool draw = false;


void grid(){
    cout<<"         |       |       "<<"\n";
    cout<<"     "<<grid_pos[0][0]<<"   |   "<<grid_pos[0][1]<<"   |  "<<grid_pos[0][2] <<"\n";
    cout<<"         |       |       "<<"\n";
    cout<<" -------------------------"<<"\n";
    cout<<"         |       |       "<<"\n";
    cout<<"     "<<grid_pos[1][0]<<"   |   "<<grid_pos[1][1]<<"   |  "<<grid_pos[1][2] <<"\n";
    cout<<"         |       |       "<<"\n";
    cout<<" -------------------------"<<"\n";
    cout<<"         |       |       "<<"\n";
    cout<<"     "<<grid_pos[2][0]<<"   |   "<<grid_pos[2][1]<<"   |  "<<grid_pos[2][2] <<"\n";
    cout<<"         |       |       "<<"\n";
}

void grid_update(){
    
    if(turn == 'X'){
        cout<<"palyerX Enter Postion"<<"\n";
    }
    else if(turn == 'O' ){
        cout<<"palyerO Enter Postion"<<"\n";
    }
    cin>>pos;

    switch(pos){
    case 1: 
        row=0; column=0;
        break;
    case 2: 
        row=0; column=1;
        break;
    case 3: 
        row=0; column=2;
        break;
    case 4: 
        row=1; column=0;
        break;
    case 5: 
        row=1; column=1;
        break;
    case 6: 
        row=1; column=2;
        break;
    case 7: 
        row=2; column=0;
        break;
    case 8: 
        row=2; column=1;
        break;
    case 9: 
        row=2; column=2;
        break;
    default:
        cout<<"ERROR!!!Invalid grid position."<<"\n";
    }


    if(turn=='X' && grid_pos[row][column]!='X' &&  grid_pos[row][column]!='O'){
        grid_pos[row][column] = 'X';
        turn = 'O';
    }
    else if(turn=='O' && grid_pos[row][column]!='X' &&  grid_pos[row][column]!='O'){
        grid_pos[row][column] = 'O';
        turn = 'X';
    }
    else{
        cout<<"Postion already occupied"<<"\n";
        grid_update();
    }
    grid();

}

bool game_status(){
    for(int i=0; i<3; i++){
        if(grid_pos[i][0]==grid_pos[i][1] && grid_pos[i][0]==grid_pos[i][2] || grid_pos[0][i]==grid_pos[1][i] && grid_pos[0][i]==grid_pos[2][i])
        return false;
    }
    if(grid_pos[0][0]==grid_pos[1][1] && grid_pos[0][0]==grid_pos[2][2] || grid_pos[0][2]==grid_pos[1][1] && grid_pos[0][2]==grid_pos[2][0])
    return false;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
            if(grid_pos[i][j]!='X' && grid_pos[i][j]!='O')
            return true;
        }
    }
    draw = true;
    return false;
}   

int main(){

    char pos;

    cout<<"Welcome to Tic-Tac-Toe!"<<"\n";
    cout<<"Instructions: "<<"\n";
    cout<<"     * This is a layout of the grid that you will be using to play the game."<<"\n";
    cout<<"     * Keep the grid Postions in mind while playing as you will be asked to choose the postions in each turn"<<"\n";
    cout<<"     * You can always scroll up  and check the postions if you want to"<<"\n";
    grid();
    cout<<"     * Tick-Tac-Toe is a two player game."<<"\n";
    cout<<"     * There will be a playerX and playerO."<<"\n";
    cout<<"     * Each player will take turn to input hte symbol given to them"<<"\n";
    cout<<"     * First to finish a row in any direction wins."<<"\n";
    cout<<"     * Game starts with PlayerX.Enjoy!!"<<"\n";

    while(game_status()){
        grid_update();
        game_status();
    }
    if(turn=='X' && draw==false){
        cout<<"PlayerX Wins!!!"<<"\n";
    }
    else if(turn=='O' && draw==false){
        cout<<"PlayerO Wins!!!"<<"\n";
    }
    else {
        cout<<"Game Over!!! No Winner"<<"\n";
    }
    return 0;
}

