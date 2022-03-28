#include "game.h"
#include"tag.h"
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include <random>
#include<array>
game::game()
{
    start_game();
}

void game::start_game(){
    score = 0;
    do{
        std::array<int,16> a{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
        srand(time(NULL));
        std::shuffle(a.begin(), a.end(), std::default_random_engine(rand()));
        int n = 0;
        for (auto i = 0; i < 4; i++){
            for (auto j = 0; j < 4; j++){
                    table[i][j] = a[n];
                    cpytable[i][j]= a[n];
                    n++;
            }
        }
    }while(!isPossible());
}
void game::restart_game(){
    score = 0;
        for (auto i = 0; i < 4; i++){
            for (auto j = 0; j < 4; j++){
                table[i][j] = cpytable[i][j];
        }
    }
}
int game::getScore() const{
    return score;
}
void game::addScore(){
    score++;
}
int game::getElement(int i, int j) const{
    return table[i][j];
}
void game::setVoid(const QTableWidgetItem *p){
    voidCell = p;
}
void game::setElement(int i, int j, int data){
    table[i][j] = data;
}
void game::reCalc(int i, int j){
    table[getVoidi()][getVoidj()]=table[i][j];
    table[i][j]=0;
}
bool game::isFinished(){
    int res[16];
    int n = 0;
    for (auto i = 0; i < 4; i++){
        for (auto j = 0; j < 4; j++){
            res[n] = table[i][j];
            n++;
        }
    }
    for(int i = 0; i < 15;i++){
        if(res[i]!=i+1){
            return false;
        }
    }
    return true;
}
bool game::isPossible()const{
    int a[16];
    int n = 0;
    for (auto i = 0; i < 4; i++){
        for (auto j = 0; j < 4; j++){
            a[n] = table[i][j];
            n++;
    }
}
    int sum = 0;
    for (int i=0; i<16; i++){
        if (a[i]){
            for (int j=0; j<i; j++){
                if (a[j] > a[i]){
                    sum++;
                }
            }
        }
    }
    for (int i=0; i<16; i++){
        if (a[i] == 0){
            sum += 1 + i / 4;
        }
    }
    if(sum%2 == 0){
        return true;
    }else{
        return false;
    }
}

