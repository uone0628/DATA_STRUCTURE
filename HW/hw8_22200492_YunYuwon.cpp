#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
#define Size 100
#define Add_Head 1
#define Add_Tail 2
#define Delete_Head 3
#define Delete_Node 4
#define Show_list 5
#define Now_Data 6
#define Quit 7

class node {
public:
    string name;
    double score;
    node *link;
    void set_data();
};

class LinkedList {
private:
    node *head, *tail;
public:
    LinkedList();
    void add_to_head(node t);
    void add_to_tail(node t);
    void delete_from_head();
    int num_nodes();
    bool list_empty();
    void show_all_data();
    void delete_name_score();
    double max_score();
    double min_score();
    double average_score();
    void data_analysis();
};

void show_menu() {
    cout << "\n\n-------------------------" << endl; 
    cout << "실행할 기능을 선택하세요. " << endl; 
    cout << "-------------------------" << endl; 
    cout << "1. 첫 원소 추가" << endl;
    cout << "2. 끝 원소 추가" << endl; 
    cout << "3. 첫 원소 삭제" << endl;
    cout << "4. 특정 이름 원소 삭제" << endl;
    cout << "5. 전체 원소 출력" << endl;
    cout << "6. 현재 내용 분석" << endl;
    cout << "7. 끝내기" << endl;
    cout << "-------------------------" << endl; 
}

void node::set_data() {
    cout << "성명을 입력하세요 : ";
    cin >> name;
    cout << "점수를 입력하세요 : ";
    cin >> score;
}

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}

void LinkedList::add_to_head(node t) {
    node  *p;
    p =  new  node;
    (*p) = t;
    p-> link = head;
    head = p;
    if (tail == NULL)   
        tail = p;
    cout << "\n데이터가 추가되었습니다." << endl;
}

void LinkedList::add_to_tail(node t) {
    node  *p;
    p = new node;
    (*p) = t;
    p-> link = NULL;
    if (tail != NULL) 
        tail->link = p;
    else               
        head = p;
    tail = p;
    cout << "\n데이터가 추가되었습니다." << endl;
}

void LinkedList::delete_from_head() {
    node temp;
    node *t;
    t = head;
    temp = *head;
    head = head->link;
    delete t;
    if (head == NULL) 
        tail = NULL;
    cout << "데이터가 삭제되었습니다." << endl;
}

int LinkedList::num_nodes() {
    node *p;
    int count = 0;
    for ( p = head; p != NULL; p = p->link)
        count++;
    return count;
}

bool LinkedList::list_empty() {
    if (head == NULL)
        return true;
    else 
        return false;
}

void LinkedList::show_all_data() {
    node *p;
    if(list_empty())
        cout << "나타낼 데이터가 없습니다." << endl;
    else
        for ( p = head; p != NULL; p = p->link)
            cout<< p->name << " : " << p->score << endl;
}

void LinkedList::delete_name_score() {
    node *old, *new_;
    int check = 0;
    string n;

    if(list_empty()) {
        cout << "삭제 가능한 데이터가 없습니다." << endl;
        return;
    }
    else {
        cout << "삭제할 데이터의 이름을 입력하세요 : ";
        cin >> n;
    }

    if(head->name == n) {
        new_ = head;
        head = head->link;
        delete new_;
        cout << n << "의 정보가 삭제되었습니다." << endl;
        return;
    }

    old = head;
    new_ = head->link;

    while (new_ != NULL)
    {
        if(new_->name == n) {
            if(new_->link == NULL) {
                tail = old;
            }
            old->link = new_->link;
            delete new_;                         
            cout << n << "의 정보가 삭제되었습니다." << endl;
            return;        
        }
        else {
            old = new_;
            new_ = new_->link;
        } 
    }
    
    cout << "입력한 이름의 정보가 없습니다." << endl;
}

double LinkedList::max_score() {
    node *p;
    double max = head->score;

    for (p = head->link; p != NULL; p = p->link) {
        if (p->score > max)
            max = p->score;
    }
    return max;
}

double LinkedList::min_score() {
    node *p;
    double min = head->score;

    for (p = head->link; p != NULL; p = p->link) {
        if (p->score < min)
            min = p->score;
    }
    return min;
}

double LinkedList::average_score() {
    node *p;
    double sum;

    for (p = head; p != NULL; p = p->link) {
        sum += p->score;
    }

    return sum / num_nodes();
}

void LinkedList::data_analysis() {
    if(list_empty())
        cout << "분석할 데이터가 없습니다." << endl;
    else {
        cout << "-----------------" << endl; 
        cout << "  현재 내용 분석 " << endl; 
        cout << "-----------------" << endl; 
        cout << "전체 원소 수 : " << num_nodes() << endl;
        cout << "최대 점수 : " << max_score() <<endl; 
        cout << "최소 점수 : " << min_score() << endl;
        cout << "평균 점수 : " << average_score() << endl;
        cout << "-----------------" << endl; 
    }
}

int main() {
    LinkedList l = LinkedList();
    node d = node();
    
    string dname;
    int input;
    bool check;

    while (true) {
        show_menu();
        cout << "실행할 기능 번호 : ";
        cin >> input;
        cout << "-------------------------\n\n" << endl;
        check = false;

        switch(input) {
            case Add_Head :
                d.set_data();
                l.add_to_head(d);
                break;
            case Add_Tail :
                d.set_data();
                l.add_to_tail(d);
                break;
            case Delete_Head :
                l.delete_from_head();
                break;
            case Delete_Node :
                l.delete_name_score();
                break;
            case Show_list :
                l.show_all_data();
                break;
            case Now_Data :
                l.data_analysis();
                break;
            case Quit :
                cout << "종료합니다." << endl;
                check = true;
                break;
            default :
                cout << "1 ~ 7 범위 내에서 입력해 주세요.";
                break;
        }
        if (check) break;
    }
    return 0;
}