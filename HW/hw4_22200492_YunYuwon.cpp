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
    char top_element();
};

string check (op_stack stack, string input);
int isbracket(char token, char o[]);

int main() {
    string input;
    
    op_stack stack = op_stack();
    
    cout << "판단할 식을 입력하세요 : ";
    getline(cin,input);
    cout << "입력한 식은 " << check(stack, input) << "입니다.";
}

string check (op_stack stack, string input) {
    char token;
    char p;
    int pre, check_brac;
    char o[6] =  {'(','{','[',')','}',']'};

    for(int i = 0; i <= input.length(); i++) {
        token = input[i];
        pre = isbracket(token,o);
        if(0 <= pre && pre <= 5) {

            if(pre < 3) stack.push(token);
            
            else {
                p = stack.pop();
                check_brac = isbracket(p, o) + 3;
                if( pre != check_brac) return "괄호 불일치";
            }
        
        }   

    }
    
    if(stack.empty()) 
        return "정상";
    else 
        return "닫는 괄호 누락";
}

int isbracket(char token, char o[]){
    for(int i = 0; i < 6; i++ ){
        if(token == o[i]) return i;
    }
    return 7;
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

char op_stack::top_element() { 
    return (s[top - 1]); 
}