#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

#define SIZE 5
#define Insert 1
#define Delete 2
#define ShowFront 3
#define Quit 4


class my_queue {
    string q[SIZE];
    int front, rear;
public : 
    my_queue();
    void insert_q(string x);
    string delete_q(); //delete 사용은 유의
    bool queue_full();
    bool queue_empty();
    void show_data();
};

void show_menu();

int main() {
    my_queue q = my_queue();

    string book;
    int input;
    bool check;
    
    while (true) {
        show_menu();
        cout << "\n     Select a command : ";
        cin >> input;
        cout << endl;
        check = false;

        switch(input) {
            case 1 :
                cout << "책 이름, 페이지 수, 가격을 입력하세요 : " << endl; 
                cin >> book;
                q.insert_q(book);
                break;
            case 2 :
                cout << q.delete_q() << endl;
                break;
            case 3 :
                q.show_data();
                break;
            case 4 :
                cout << "종료합니다." << endl;
                check = true;
                break;
            default :
                cout << "1 ~ 4 범위 내에서 입력해 주세요.";
                break;
        }
        if (check) break;
    }
}

void show_menu() {
    cout << "\n-- Menu --\n" << endl; 
    cout << "1. 책 정보 추가" << endl;
    cout << "2. 책 정보 삭제" << endl; 
    cout << "3. 첫 번째 책 정보 출력" << endl;
    cout << "4. 끝내기" << endl;
}

void my_queue::show_data() {
    cout << q[front] << endl;
}

my_queue::my_queue() {
    front = 0;
    rear = 0;
}

void my_queue::insert_q(string x) {
    if ( !queue_full() ) {
        q[rear] = x;
        rear = (rear+1) % SIZE;
    }
    else 
        cout << "정보를 저장할 공간이 없습니다." << endl;
}

string my_queue::delete_q() {
    string tmp;
    if ( !queue_empty() ) {
        tmp = q[front];
        front = (front+1) % SIZE;
        return tmp+"가 삭제되었습니다.";
    }
    else
        return "정보가 없습니다.";
}

bool my_queue::queue_full() {
    if ( (rear+1) % SIZE == front )
        return true;
    else
        return false;
}

bool my_queue::queue_empty() {
    if ( rear == front )
        return true;
    else
        return false;
}
