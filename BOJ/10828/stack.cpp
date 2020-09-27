#include <iostream>
#include <string>
using namespace std; 

struct Stack
{
    // 스택에 필요한 메소드
    // 생성자
    // push, empty, pop, top
    int data[10000];
    int size;
    Stack() {
        size = 0;
    }
    
    void push(int num){
        data[size] = num;
        size += 1;
    }
    
    bool empty() {
        if (size == 0) return true;
        else return false;
    }

    int pop() {
        if(empty()) {
            return -1;
        } else {
            size -= 1;
            return data[size];
        }
    }

    int top() {
        if (empty()){
            return -1;
        } else {
            return data[size-1];
        }
    }
    
};
