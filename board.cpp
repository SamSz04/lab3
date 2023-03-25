#include "board.h"

//Board类用来表示汉诺塔游戏的状态
Board::Board(int num_disk){     //初始化一个汉诺塔，即最初的状态
    Num_disk = num_disk;
    canvas.reset();
    canvas.init(num_disk);
    //要初始化第一根杆子!!
    while(num_disk>0){
        stack1.push(2*num_disk+1);
        --num_disk;
    }
    draw();
}

Board::~Board() {
    canvas.reset();
    for(int i=0;i<3;++i){
        stack[i]->~Stack();
    }
}

void Board::draw(){
    canvas.draw();
}

//重点！！！
void Board::move(int from, int to, bool log) {
    //异常情况1：from是空杆
    if (stack[from-1]->empty()) {
        throw "the from rode is already empty!";
        return;
    }
    //首先要获取from柱子上有几片圆盘以及圆盘高度
    int fromHeight = stack[from-1]->size();
    int w = stack[from-1]->top();
    int to_w;
    if (!stack[to-1]->empty()){
        to_w = stack[to-1]->top();
        //异常情况2：把大盘放在小盘上
        if (w > to_w){
            throw "invalid move!";
            return;
        }
    }
    //柱子1对应buffer[][5]
    //柱子2对应buffer[][20]
    //柱子3对应buffer[][35]

    //从from柱子移走
    for(int i=15*from-10-(w-1)/2;i<15*from-10-(w-1)/2+w;++i){
        canvas.buffer[11-2*fromHeight][i] = ' ';
    }
    canvas.buffer[11-2*fromHeight][15*from-10] = '|';

    int toHeight = stack[to-1]->size();
    //插入到to柱子
    for(int j=15*to-10-(w-1)/2;j<15*to-10-(w-1)/2+w;++j){
        canvas.buffer[9-2*toHeight][j] = '*';
    }
    //更新栈的信息
    stack[to-1]->push((stack[from-1]->t_top)->data);
    stack[from-1]->pop();
    //保存步骤到step栈中
    if(log){
        string s = to_string(from) + to_string(to);
        step.push(s);
    }
    draw();
}

bool Board::win() {
    return (stack[0]->empty() && stack[2]->empty() && stack[1]->size()==Num_disk);
}

void Board::autoplay() {
    while(!step.empty()){
        string reverse = step.top();
        int from = int(reverse[1]-'0');
        int to = int(reverse[0]-'0');
        cout << "Auto moving:" << from << "->" << to << endl;
        move(from,to,false);
        step.pop();
    }
    hanoi(Num_disk,1,2,3);
}


void Board::hanoi(int n, int from, int to, int tmp){
    if(n==1)
    {
        cout << "Auto moving:" << from << "->" << to << endl;
        move(from,to,false);
    }
    else{
        hanoi(n - 1, from, tmp, to);
        cout << "Auto moving:" << from << "->" << to << endl;
        move(from,to,false);  // move the nth disk from rod A to rod B
        hanoi(n - 1, tmp, to, from);
    }
}