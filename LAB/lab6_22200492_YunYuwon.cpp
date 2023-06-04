#include <iostream>
#include <string>

using namespace std;

class  node {
public :
     string  name;
     double  score;
     node  *left, *right;
     void set_data(string s, double n);
};

void node::set_data(string s, double n)
{
        name = s;
        score = n;
}

class my_tree {
public :
        int   node_count;  // 현재 node 수
        node   *root;   // root를 가리키는 pointer
        my_tree();   // 초기화
        int insert_root(node t); // root로 node내용 t추가
        int insert_left(string tname, node t); // tname의 node 왼쪽에 t 추가
        int insert_right(string tname, node t); // tname의 node 왼쪽에 t 추가

        double score_sum();     // 모든 node의 score 합
        double score_average();   // 모든 node의 core 평균
        void  print_data_inorder();  // inorder 순서로 모든 node의 값 출력
        void  print_data_preorder(); // preorder 순서로 모든 node의 값 출력
        void  print_data_postorder(); // postorder 순서로 모든 node의 값 출력
        double max_score();
        double get_score_byname(string t);
        int n_d2_nodes();
        int n_d1_nodes();
        int n_leaf_nodes();
};

my_tree::my_tree()
{
        node_count = 0;
        root = NULL;
}

double sum_allnodes(node *p)
{
        if (p == NULL)
                return 0;
        return sum_allnodes(p->left) + sum_allnodes(p->right) + p->score;
}

double my_tree::score_sum()
{
        return sum_allnodes(root);
}

double my_tree::score_average()
{
        return score_sum() / node_count;
}

int  my_tree::insert_root(node t)
{
        if (root != NULL)
                return 0;
        node *p;
        p = new node;
        (*p) = t;
        p->left = NULL;
        p->right = NULL;
        root = p;
        node_count++;
        return 1;
}

int node_insert_left(node *p, string tname, node tnode)
{
        int result;
        if (p == NULL) return 0;
        if (p->name == tname) {
                if (p->left != NULL)
                        return -1;
                node *t;
                t = new node;
                (*t) = tnode;
                t->left = NULL;
                t->right = NULL;
                p->left = t;
                return 1;
        }
        else {
                result = node_insert_left(p->left, tname, tnode);
                if (result != 0)
                        return result;
                return node_insert_left(p->right, tname, tnode);
        }

}

int node_insert_right(node *p, string tname, node tnode)
{
        int result;
        if (p == NULL) return 0;
        if (p->name == tname) {
                if (p->right != NULL)
                        return -1;
                node *t;
                t = new node;
                (*t) = tnode;
                t->right = NULL;
                t->left = NULL;
                p->right = t;
                return 1;
        }
        else {
                result = node_insert_right(p->right, tname, tnode);
                if (result != 0)
                        return result;
                return node_insert_right(p->left, tname, tnode);
        }

}

int  my_tree::insert_left(string tname, node tnode)
{
        int result;

        result = node_insert_left(root, tname, tnode);
        if (result == 1)
                node_count++;
        return result;

}

int  my_tree::insert_right(string tname, node tnode)
{
        int result;

        result = node_insert_right(root, tname, tnode);
        if (result == 1)
                node_count++;
        return result;
}

void inorder_print(node *p)
{
    if (p == NULL) return;

    inorder_print(p->left);
    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->right);
}

void my_tree::print_data_inorder()
{
        inorder_print(root);
}

void postorder_print(node *p)
{
    if (p == NULL) return;

    inorder_print(p->left);
    inorder_print(p->right);
    cout << p->name << " : " << p->score << "\n";
}


void my_tree::print_data_postorder()
{
      postorder_print(root);
}

void preorder_print(node *p)
{
    if (p == NULL) return;

    cout << p->name << " : " << p->score << "\n";
    inorder_print(p->left);
    inorder_print(p->right);
}

void my_tree::print_data_preorder()
{
       preorder_print(root);
}

double find_max(node *p) 
{
    double max, lmax, rmax;

    if (p == NULL) return 0;
    max = p->score;
    lmax = find_max(p->left);
    rmax = find_max(p->right);

    if(lmax > max)
        max = lmax;
    if(rmax > max)
        max = rmax;
    return max;
}

double my_tree::max_score() 
{
    return find_max(root);
}

double find_score_byname(node *p, string t) {
    double nscore = -1;

    if (p == NULL) return -1;
    if(p->name == t)
        nscore = p->score;
    else 
        nscore = find_score_byname(p->left, t);
    if(nscore == -1)
        nscore = find_score_byname(p->right, t);
    return nscore;
}

double my_tree::get_score_byname(string t) 
{
    return find_score_byname(root, t);
}

int find_d2(node *p) {
    int check = 0;
    int count = 0;
    if(p == NULL) return 0;
    if(p->left != NULL) check++;
    if(p->right != NULL) check++;
    if(check == 2) count++;
    return find_d2(p->left) + find_d2(p->right) + count;
}

int my_tree::n_d2_nodes() {
    return find_d2(root);
}

int find_d1(node *p) {
    int check = 0;
    int count = 0;
    if(p == NULL) return 0;
    if(p->left != NULL) check++;
    if(p->right != NULL) check++;
    if(check == 1) count++;
    return find_d1(p->left) + find_d1(p->right) + count;
}

int my_tree::n_d1_nodes() {
    return find_d1(root);
}
        
int find_leaf(node *p) {
    int check = 0;
    int count = 0;
    if(p == NULL) return 0;
    if(p->left == NULL) check++;
    if(p->right == NULL) check++;
    if(check == 2) count++;
    return find_leaf(p->left) + find_leaf(p->right) + count;
}

int my_tree::n_leaf_nodes() {
    return find_leaf(root);
}

int main()
{
        my_tree  thetree;
        node  tmp;
        tmp.set_data("Kim", 81.1);
        thetree.insert_root(tmp);
        tmp.set_data("Lee", 86.2);
        thetree.insert_left("Kim", tmp);
        tmp.set_data("Park", 79.4);
        thetree.insert_right("Kim", tmp);
        tmp.set_data("Choi", 77.8);
        thetree.insert_left("Lee", tmp);
        tmp.set_data("Ryu", 92.2);
        thetree.insert_right("Lee", tmp);
        tmp.set_data("Cho", 68.6);
        thetree.insert_right("Park", tmp);
        tmp.set_data("Yang", 72.8);
        thetree.insert_left("Ryu", tmp);
        tmp.set_data("Jung", 62.3);
        thetree.insert_left("Cho", tmp);

        cout << "The number of degree-2 nodes : " << thetree.n_d2_nodes() << endl;
        cout << "The number of degree-1 nodes : " << thetree.n_d1_nodes() << endl;
        cout << "The number of leaf nodes : " << thetree.n_leaf_nodes() << endl;     

        return 0;

}