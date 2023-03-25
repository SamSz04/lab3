#pragma once

#include <iostream>

using namespace std;

class Canvas{
public:
    static const int HEIGHT = 11, WIDTH = 41;
    char buffer[HEIGHT][WIDTH];

    void draw() const{      //打印出当前的汉诺塔状态
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++)
                cout << buffer[i][j];
            cout << endl;
        }
    }
    void init(int n){
        //先画出全部的｜和-
        int i,j,k;
        for(j=0;j<WIDTH;++j){
            buffer[10][j] = '-';
        }
        for(i=0;i<HEIGHT;++i){
            buffer[i][5] = buffer[i][20] = buffer[i][35] = '|';
        }
        //再将盘子画进去(从下往上)
        i=0;
        while(n > 0){
            for(k=5-n;k<n+6;++k){
                buffer[9-i][k] = '*';
            }
            --n;
            i += 2;
        }
    }
    void reset(){
        for (int i = 0; i < HEIGHT; i++)
            for (int j = 0; j < WIDTH; j++)
                buffer[i][j] = ' ';
    }
};