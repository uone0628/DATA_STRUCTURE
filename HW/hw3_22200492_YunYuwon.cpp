#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
#define SIZE 100
#define EOS '$'

class op_stack
{
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

struct oper
{
    char *oper;
    int op_l;
};


string postfix(op_stack stack, string in, oper c);

bool is_operand(char ch, oper c);
int get_precedence(char op, oper c);

int main()
{
    string input;
    oper oper;
    oper.op_l = 7;
    oper.oper = (char*)malloc(sizeof(oper.op_l));
    
    char op[] = {'(', '$', '+', '-', '*', '/', '%'};
    for (int i = 0; i<oper.op_l; i++) 
        oper.oper[i] = op[i];

    op_stack stack1 = op_stack();
    stack1.push(EOS);
    cout << "postfix로 변환할 식을 입력하세요 : ";
    cin >> input;
    cout << "변환된 식은 " << postfix(stack1, input, oper) << "입니다.";
   
    return 0;
}

string postfix(op_stack stack, string in, oper c){

    char token;
    string out;

    for(int i = 0; i < in.length(); i++){
        token = in[i];
        
        if(is_operand(token, c)) {
            if(token == '(') {
                stack.push('(');
            }
            else {     
                while(get_precedence(stack.top_element(), c) >= get_precedence(token, c)) out += stack.pop();
                stack.push(token);
            }
        }
        else {
            if(token == ')') {
                while(stack.top_element() != '(') out += stack.pop();
                stack.pop();
            }
            else 
                out += token;
        }
    }
    while(stack.top_element() != '$') out += stack.pop();

    return out;
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

bool is_operand(char ch, oper c) {
    for(int i = 0; i < c.op_l; i++)
        if(ch == c.oper[i]) return true;
    
    return false;
}

int get_precedence(char op, oper c) {
    int get;
    for(int i = 0; i < c.op_l; i++)
        if(op == c.oper[i]) {
            get = (i/2);
            if(get >= 3) return 2;
        }
    return get;
}
