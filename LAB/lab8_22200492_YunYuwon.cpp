#include <iostream>
using namespace std;

#define HSIZE 100
#define Add 1
#define Delete 2
#define Show_Data 3
#define Quit 4

class element {
public:
    string name;
    double score;  // Key
    void set_data();
};

void element::set_data()
{
    cout << "성명을 입력하세요 : ";
    cin >> name;
    cout << "점수를 입력하세요 : ";
    cin >> score;
}

class my_heap {
    element h[HSIZE];
    int csize; // the number of elements
public:
    my_heap();
    int h_size();  
    void insert_heap(element t);
    element delete_heap();
    bool heap_full();
    bool heap_empty();
    void show_data();
};

my_heap::my_heap()
{
    csize = 0;
}

int my_heap::h_size()
{
    return csize;
}  

void my_heap::insert_heap(element t)
{
    int k;

    if(heap_full()) {
        cout << "데이터를 추가할 공간이 없습니다." << endl;
        return;
    }
    
    csize++;
    k = csize;
    
    while ((k != 1) && (t.score > h[k / 2].score)) {
        h[k] = h[k / 2];
        k /= 2;
    }
    
    h[k] = t;
    cout << "\n데이터가 추가되었습니다." << endl;
}

element my_heap::delete_heap()
{
    element t;
    element tmp;
    int parent, child;

    if(heap_empty()) {
        cout << "삭제할 데이터가 없습니다." << endl;
        return t;
    }

    t = h[1];  // for return value
    tmp = h[csize];  // 끝원소
    csize--;
    parent = 1;   // root
    child = 2;     // root의 left child
    
    while (child <= csize) {
        if ((child < csize) && (h[child].score < h[child + 1].score))
            child++; // right child를 선택
        if (tmp.score >= h[child].score)
            break;
        h[parent] = h[child];
        parent = child; // 한단계 아래로
        child *= 2;
    }
    
    h[parent] = tmp;
    cout << "데이터" << t.name << " : " << t.score << "가 삭제되었습니다.";
    return t;
}

bool my_heap::heap_full()
{
    // return (csize >= HSIZE-1);
    if (csize >= HSIZE-1)
        return true;
    else 
        return false;
}

bool my_heap::heap_empty()
{
    // return (csize == 0);
    if (csize == 0)
        return true;
    else 
        return false;
}

void show_menu() {
    cout << "\n\n-------------------------" << endl; 
    cout << "실행할 기능을 선택하세요. " << endl; 
    cout << "-------------------------" << endl; 
    cout << "1. 데이터 추가" << endl;
    cout << "2. 데이터 삭제" << endl;
    cout << "3. 데이터 내용 분석" << endl;
    cout << "4. 끝내기" << endl;
    cout << "-------------------------" << endl; 
}

void my_heap::show_data()
{
    if(heap_empty()) {
        cout << "분석할 데이터가 없습니다." << endl;
        return;
    }

    cout << "-----------------" << endl; 
    cout << "  현재 내용 분석 " << endl; 
    cout << "-----------------" << endl; 
    cout << "데이터 개수 -> " << h_size() << endl;
    cout << "루트 데이터 -> \n" << h[1].name << " : " << h[1].score <<endl;
    cout << "-----------------" << endl; 
}

int main() 
{
    my_heap h1;
    element temp;
    
    int input;
    bool check;

    while (true) {
        show_menu();
        cout << "실행할 기능 번호 : ";
        cin >> input;
        cout << "-------------------------\n\n" << endl;
        check = false;

        switch(input) {
            case Add :
                temp.set_data();
                h1.insert_heap(temp);
                break;
            case Delete :
                temp = h1.delete_heap();
                break;
            case Show_Data :
                h1.show_data();
                break;
            case Quit :
                cout << "종료합니다." << endl;
                check = true;
                break;
            default :
                cout << "1 ~ 4 범위 내에서 입력해 주세요.";
                break;
        }
        if (check) break;
    }
    return 0;

    
    

    return 0;
}