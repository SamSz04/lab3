#include <iostream>
#include <stdio.h>
#include <string>
#include "board.h"

using namespace std;


static int num_disk = 0;

int main()
{
    while(true){
        cout << "How many disks do you want? (1 ~ 5)" << endl;
        string input_num;
        getline(cin,input_num);
        if (input_num == "Q"){
            break;
        }
        if (input_num.size() == 1 && int(input_num[0]-'0')>=1 && int(input_num[0]-'0')<=5){
            num_disk =int(input_num[0]-'0');
            Board board(num_disk);
            while (true){
                cout << "Move a disk. Format: x y" << endl;
                string step;
                getline(cin,step);
                if (step == "Q") {
                    break;
                }
                else if (step.size()==3 && int(step[0]-'0')>=1 && int(step[0]-'0')<=3 && step[1]==' ' && int(step[2]-'0')>=1 && int(step[2]-'0')<=3)
                {
                    int from = int(step[0]-'0');
                    int to = int(step[2]-'0');
                    try{
                        board.move(from,to);
                    }
                    catch(const char* msg){
                        board.draw();
                    }
                }
                else if (step.size()==3 && step[0]=='0' && step[2]=='0' && step[1]==' '){
                    board.autoplay();
                }
                else{
                    board.draw();
                    continue;
                }
                if(board.win()) {
                    cout << "Congratulations! You win!" << endl;
                    break;
                }
            }
        }
        else continue;
    }
    return 0;
}
