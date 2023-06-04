#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define SIZE 100

class op_stack {
private:
    char s[SIZE];
    int top;
public:
    op_stack();
    void push(char x);
    char pop();
    bool empty();
    // char top_element();
};

string kinga (op_stack stack, string input);
string check (op_stack stack, string input);

int main() {
    string input;
    
    op_stack stack = op_stack();
    
    cout << "판단할 단어를 입력하세요 : ";
    getline(cin, input);
    input = kinga(stack, input);
    cout << "입력한 단어는 Palindrome가 " << check(stack, input);
}

string kinga (op_stack stack, string input) {
    char token;
    string output;

    for(int i = 0; i < input.length(); i++) {
        token = input[i];

        if('A' <= token && token <= 'Z' || 'a' <= token && token <= 'z')
            stack.push(token);
    }

    for(int i = 0; !stack.empty(); i++) {
        output += stack.pop();
    }

    return output;
}

string check (op_stack stack, string input) {
    char token;
    char top;

    for(int i = 0; i < input.length()/2; i++) {
        token = input[i];
        stack.push(token);
    }

    for(int i = input.length() - input.length()/2; i < input.length(); i++) {
        token = input[i];
        top = stack.pop();

        if ('A' <= token && token <= 'Z') token += 32;
        if ('A' <= top && top <= 'Z') top += 32;

        if(token != top) return "아닙니다.";
    }

    return "맞습니다.";
}

op_stack::op_stack() {
    top = 0;
}

void op_stack::push(char x) {
    s[top] = x;
    top++;
}

char op_stack::pop() {
    return (s[--top]);
}

bool op_stack::empty() { 
    return (top == 0); 
}

// char op_stack::top_element() { 
//     return (s[top - 1]); 
// }