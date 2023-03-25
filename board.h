#pragma once

#include "canvas.h"
#include "stack.h"

class Board {
    int Num_disk;
    Canvas canvas;
    Stack<int> stack1,stack2,stack3;
    //此时，栈类中的第i个节点的数据域data保存柱子第i层圆盘的长度（3，5，7，9，11）
    //调用size函数可获得当前柱子的高度，即插入了几片圆盘
    //empty函数可反映柱子是否为空（可用于异常处理）
    //push函数模拟了将圆盘插入该柱子中
    //pop函数模拟了将圆盘从该柱子移走
    Stack<int>* stack[3] = {&stack1,&stack2,&stack3};
    Stack<string> step;         //用于存储用户输入的步骤
public:
    Board(int num_disk);
    ~Board();
    void draw();
    void move(int from, int to, bool log = true);
    bool win();
    void autoplay();
    void hanoi(int n, int from, int to, int tmp);
};
