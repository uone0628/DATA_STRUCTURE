#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
#define S_SIZE 100

/*
모든 sorting은 학번을 기준으로 만들었습니다.
컴파일 할 때 컴파일 에러가 떴었지만 g++ -std=c++2a hw9_22200492_YunYuwon.cpp -o a.out 이렇게
컴파일 버전을 바꾸니 정상적으로 실행이 되었습니다. 이미 너무나 잘 아시는 문제 및 해결 방법이겠지만 
컴파일 에러 때문에 감점이 생길 가능성이 있을 것 같아 말씀드리는 점 양해 부탁드립니다... 감사합니다!
*/

class s_record {
public:
    string s_id;    // 학번 (Key)
    string name;    // 성명
    double  score;  // 점수
    s_record();
    s_record(string s1, string s2, double n);
};

s_record::s_record()
{

}

s_record::s_record(string s1, string s2, double n)
{
    s_id = s1;
    name = s2;
    score = n;
}

void insertion_sort(s_record a[], int n) 
{
    for (int j = 1; j < n; j++) {
        s_record temp = a[j];
        int k = j-1;
        while ((k >= 0)&&(a[k].s_id > temp.s_id)) {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = temp;
    }
}

void bubble_sort(s_record a[], int n)
{
    s_record temp;
    for (int j = n-1; j >= 1; j--) {
        for (int k = 0; k< j; k++) {
            if (a[k].s_id > a[k+1].s_id) {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
}

void selection_sort(s_record a[], int n)
{
    s_record temp;
    for (int j = 0; j < n; j++) {
        int min_i = j;
        for (int k = j + 1; k < n; k++) 
            if (a[k].s_id < a[min_i].s_id)
                min_i = k;
        temp = a[j];
        a[j] = a[min_i];
        a[min_i] = temp;
    }
}

void quick_sort(s_record a[], int left, int right)
{
    s_record pivot, temp;
    int i, j;
    
    if (left >= right) 
        return;
    
    i = left;
    j = right + 1;
    pivot = a[left];
    
    do {
        do {
            i++;
        } while ((i <= right) && (a[i].s_id < pivot.s_id));
        
        do {
            j--;
        } while (a[j].s_id > pivot.s_id);
        
        if (i < j)
            swap(a[i], a[j]);
    } while (i < j);
    
    swap(a[left], a[j]);
    quick_sort(a, left, j - 1);
    quick_sort(a, j + 1, right);
}

void adjust(s_record a[], int root, int n) {
    int child;
    string root_key;
    s_record root_data;
    
    root_data = a[root];
    root_key = a[root].s_id;
    child = 2 * root;

    while (child <= n) {
        if (child < n && a[child].s_id < a[child + 1].s_id)
            child++;
        
        if (root_key >= a[child].s_id)
            break;

        a[child / 2] = a[child];
        child *= 2;
    }

    a[child / 2] = root_data;
}

void heap_sort(s_record a[], int n)
{
    int i;
    s_record b[S_SIZE], temp;
    for (i = 0; i < n; i++) 
        b[i + 1] =  a[i];
    for (i = n / 2; i > 0; i--)
        adjust(b, i, n);
    for (i = n - 1; i > 0; i--) {
        temp = b[1];
        b[1] = b[i + 1];
        b[i + 1] = temp;
        adjust(b, 1, i);
    }

    for (i = 0; i < n; i++)
        a[i] = b[i + 1];
}

void adjust2(s_record a[], int root, int n) {
    int child;
    string root_key;
    s_record root_data;
    
    root_data = a[root];
    root_key = a[root].s_id;
    child = 2 * root + 1;

    while (child <= n) {
        if (child < n && a[child].s_id < a[child + 1].s_id)
            child++;
        
        if (root_key >= a[child].s_id)
            break;

        a[(child - 1)/ 2] = a[child];
        child = 2 * child + 1;
    }

    a[(child - 1) / 2] = root_data;
}

void heap_sort2(s_record a[], int n)
{
    int i;
    s_record temp;
    int size = n - 1;
    for (i = (size - 1) / 2; i >= 0; i--)
        adjust2(a, i, size);
    for (i = size; i > 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        adjust2(a, 0, i - 1);
    }
}

void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
    int i, j, k, t;
    i = n1;
    j = n3;
    k = n1;
    while ((i <= n2) && (j <= n4)) {
        if (a[i].s_id <= a[j].s_id)
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i > n2)
        for (t = j; t <= n4; t++)
            b[t] = a[t];
    else
        for (t = i; t <= n2; t++)
            b[k+t-i] = a[t];
}

void merge_pass(s_record a[], s_record b[], int n, int s)
{
    int i, j;
    for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
        merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
    
    if (i + s  <= n)
        merge(a, b, i, i + s - 1, i + s, n);
    else 
        for (j=i; j<= n; j++)
            b[j] = a[j];
}

void merge_sort(s_record a[], int n)
{
    int s = 1;
    s_record b[S_SIZE];
    while (s < n) {
        merge_pass(a, b, n-1, s);
        s *= 2;
        merge_pass(b, a, n-1, s);
        s *= 2;
    }
}

void show_thelist(s_record a[], int n)
{
    for (int i = 0;i < n; i++) {
        cout << a[i].s_id << "  :  ";
        cout << a[i].name << "  :  ";
        cout << a[i].score << endl;
    }
}

int main()
{
    s_record s_list[12] = { {"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8 }, {"21900333", "Park", 9.2 },

                            { "21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4  }, {"21700248", "Cho ", 6.3 },

                            { "21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9  }, {"21800369", "Kang", 6.3 },

                            { "21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1  }, {"21700678", "Seo ", 7.9 } };

    int n = 12;

    cout << "< The result of after sorting >" << endl;
    show_thelist(s_list, n); //sort 하기 전 배열

    // insertion_sort(s_list, n);
    // cout << "\n< The result of the insertion sorting >" << endl;
    // show_thelist(s_list, n);

    // bubble_sort(s_list, n);
    // cout << "\n< The result of the bubble sorting >" << endl;
    // show_thelist(s_list, n);

    // selection_sort(s_list, n);
    // cout << "\n< The result of the selection sorting >" << endl;
    // show_thelist(s_list, n);

    // quick_sort(s_list, 0, n-1);
    // cout << "\n< The result of the quick sorting >" << endl;
    // show_thelist(s_list, n);

    // heap_sort(s_list, n);
    // cout << "\n< The result of the heap sorting >" << endl;
    // show_thelist(s_list, n);

    merge_sort(s_list, n);
    cout << "\n< The result of the merge sorting >" << endl;
    show_thelist(s_list, n);

    return 0;
}

