#pragma once

#include <cassert>

template <typename T> class Stack{
private:
    struct StackNode{
        T data;
        StackNode* next;
        StackNode(const T &x,StackNode* n= nullptr){data=x;next=n;}
        StackNode():next(nullptr){}
        ~StackNode(){}
    };
    int s_size = 0;
 public:
    StackNode* t_top;       //±íÊ¾Õ»¶¥Ö¸Õë£¡£¡

    Stack(){
        t_top = nullptr;
    }
    
    ~Stack() {
        StackNode* tmp;
        while(t_top!= nullptr){
            tmp = t_top;
            t_top = t_top->next;
            --s_size;
            delete tmp;
        }
    }
    int size() {
        return s_size;
    }
    
    bool empty() {
        return size() == 0;
    }
    
    void push(T t) {
        t_top = new StackNode(t,t_top);
        ++ s_size;
    }
    
    void pop() {
        StackNode* tmp = t_top;
        t_top = t_top -> next;
        delete tmp;
        -- s_size;
    }
    
    T& top() const {
        return t_top->data;
    }
};
