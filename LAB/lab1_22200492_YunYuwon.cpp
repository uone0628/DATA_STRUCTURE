#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class node {
public: 
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

class my_list {
    node    *head, *tail;
public:
    my_list();
    void add_to_head(node t);
    void add_to_tail(node t);
    node delete_from_head();
    int num_nodes();
    bool list_empty();
    void show_all_data();
    void delete_low_score(double  n);
};

int main() {
    my_list a;
    node tmp;
        tmp.set_data("Kim", 83.5);
        a.add_to_head(tmp);
        tmp.set_data("Lee", 58.2);
        a.add_to_head(tmp);
        tmp.set_data("Park", 91.3);
        a.add_to_head(tmp);
        tmp.set_data("Choi", 55.1);
        a.add_to_head(tmp);
        tmp.set_data("Ryu", 77.1);
        a.add_to_head(tmp);
        tmp.set_data("Yang", 41.3);
        a.add_to_head(tmp);
        tmp.set_data("Hong", 78.2);
        a.add_to_head(tmp);

        cout << "The list before deletion \n";
        a.show_all_data();
        
        a.delete_low_score(60.0);
        
        cout << "\n\nThe list after deletion \n";
        a.show_all_data();

    return 0;
}

my_list:: my_list() {
    head = NULL;
    tail = NULL;
}

void my_list:: add_to_head(node t) {
    node  *p;
    p =  new  node;
    (*p) = t;
    p-> link = head;
    head = p;
    if (tail == NULL)   
        tail = p;
}

void my_list:: add_to_tail(node  t) {
    node  *p;
    p = new node;
    (*p) = t;
    p-> link = NULL;
    if (tail != NULL) 
        tail->link = p;
    else               
        head = p;
    tail = p;
}

node my_list:: delete_from_head() {
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

int my_list:: num_nodes() {
    node *t;
    int count = 0;
    for (t = head; t != NULL; t = t->link)
        count++;
    return   count;
}

bool my_list:: list_empty() {
    if (head == NULL)
        return true;
    else 
        return false;
}

void my_list::show_all_data() {
    node *p;
    for ( p = head; p != NULL; p = p->link)
        cout<< p->name << " : " << p->score << endl;
}

void my_list::delete_low_score(double  n) {
    node *old_, *new_, *t;
    int count = num_nodes();

    if(head == NULL) return;

    new_ = head;
    old_ = NULL;

    for(int i = 0; i < count; i++) {
        t = new_;
        if(new_->score < n && old_ == NULL) {
            new_ = new_->link;
            head = new_;
            delete t;
        }
        else if(new_->score < n && old_ != NULL) {
            new_ = new_->link;
            old_->link = new_;
            delete t;
        }
        else {
            old_ = new_;
            new_ = new_->link;
        }
    }
    
    
}

void node::set_data(string s, double n) {
    name = s;
    score = n;
}

