#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
#define SIZE 100

class node {
public:
    char token;
    node *link;
    void set_data(char t);
};

class LinkedList {
    private:
        node *head,*tail;
    public:
        LinkedList();
        void add_to_head(node t);
        node delete_from_head();
        int num_nodes();
        bool list_empty();
        void show_all_data();
        node get_head();
};

class op_stack {
    private:
        LinkedList s;
    public:
        void push(char x);
        char pop();
        bool empty();
        char top();
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

string kinga (op_stack stack, string input) { // 띄어쓰기를 제외하고 판단하기 위한 함수
    char token;
    string output;

    for (int i = 0; i < input.size(); i++) 
        if(input[i] != ' ') output += input[i];

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

void op_stack::push(char x) {
    node t;
    t.set_data(x);
    s.add_to_head(t);
}

char op_stack::pop() {
    return s.delete_from_head().token;
}

bool op_stack::empty() { 
    return s.list_empty();
}

char op_stack::top(){
    return s.get_head().token;
}

LinkedList:: LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList:: add_to_head(node t) {
    node  *p;
    p =  new  node;
    (*p) = t;
    p-> link = head;
    head = p;
    if (tail == NULL)   
        tail = p;
}

node LinkedList:: delete_from_head() {
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) 
        tail = NULL;
    return temp;
}

int LinkedList:: num_nodes() {
    node *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return   count;
}

bool LinkedList:: list_empty() {
    if (head == NULL)
        return true;
    else 
        return false;
}

void LinkedList::show_all_data() {
    node *p;
    for ( p = head; p != NULL; p = p->link)
        cout<< p->token << endl;
}

node LinkedList::get_head(){
    return *head;
}

void node::set_data(char t) {
    token = t;
}