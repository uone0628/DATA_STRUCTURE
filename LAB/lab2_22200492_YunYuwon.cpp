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
    void insert_node(node   t);
};

int main() {
    my_list    thelist;
    node   tmp;
        tmp.set_data("Kim", 73.5);
        thelist.insert_node(tmp);
        tmp.set_data("Lee", 82.2);
        thelist.insert_node(tmp);
        tmp.set_data("Park", 51.3);
        thelist.insert_node(tmp);
        tmp.set_data("Choi", 95.1);
        thelist.insert_node(tmp);
        tmp.set_data("Ryu", 71.3);
        thelist.insert_node(tmp);
        tmp.set_data("Yang", 58.2);
        thelist.insert_node(tmp);
        tmp.set_data("Hong", 83.5);
        thelist.insert_node(tmp);

        cout << " The list after insertions \n";
        thelist.show_all_data();       

        return 0;

}

my_list:: my_list() {
    head = NULL;
    tail = NULL;
}

void my_list::insert_node(node   t) {
    node *new_, *old_, *p;
    p = new node;

    if(head == NULL || t.score < head->score) {
        add_to_head(t);
        return;
    }

    new_ = head;
    old_ = NULL;

    while(new_->link != NULL) {
        if(t.score < new_->score) {
            *p = t;
            p->link = new_;
            old_->link = p;
            return;
        }
        else {
            old_ = new_;
            new_ = new_->link;
        }
    }

    if(t.score > new_->score) {
        *p = t;
        p->link = NULL;
        new_->link = p;
        return;
    }
    else {
        *p = t;
        p->link = new_;
        old_->link = p;
        return;
    }
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

void my_list::show_all_data() {
    node *p;
    for ( p = head; p != NULL; p = p->link)
        cout<< p->name << " : " << p->score << endl;
}

void node::set_data(string s, double n) {
    name = s;
    score = n;
}