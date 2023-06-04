#include <iostream>
using namespace std;

#define SIZE 5

// class data {
// public:
//     char s;
//     void set_data();
// };

class my_stack {
private:
    char a[SIZE];
    int top;
public:
    my_stack();
    void push(char x);
    char pop();
    bool stack_full();
    bool stack_empty();
};

my_stack::my_stack() {
    top = 0;
}

void my_stack::push(char x) {
    a[top] = x;
    top++;
}

char my_stack::pop() {
    top--;
    return a[top];
}

bool my_stack::stack_full() {
    if(top >= SIZE)
        return true;
    else
        return false;
}

bool my_stack::stack_empty() {
    if(top == 0)
        return true;
    else
        return false;
}

int main() {
    my_stack s = my_stack();
    

    return 0;
}