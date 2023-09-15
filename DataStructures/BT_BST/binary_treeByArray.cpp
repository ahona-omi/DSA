#include<bits/stdc++.h>
using namespace std;
#define MAX 1000


class sectionA{
public:
  string name;
  int id;
  double mark;
  sectionA(string name, int id, double mark){
      this->name = name;
      this->id = id;
      this->mark = mark;
  }
};

//_____________
class Array_base_BST {
    private:
        sectionA* tree[MAX]={nullptr};
        int size;

    public:
        Array_base_BST() {
            this->size = 0;
        }
        bool isEmpty() {
            return tree[0] == nullptr;
        }
        //to get size of the tree
        int get_size(){
            return this->size;
        }

    private:
        //left child index
        int L_C(int i){
            return 2*i+1;
        }
        //right child index
        int R_C(int i){
            return 2*i+2;
        }
        int parent(int i){
            return (i-1)/2;
        }


    public:
    //_____________insert__________________
     void insert(sectionA* stu) {
        if (tree[(MAX)-1] != nullptr) {return;} //overflow
        if (isEmpty()) {
            tree[0] = stu;
        }
        else {  // lc = left child index
                // rc = right child index
                //  cur= current index
            int cur = 0;
            while (true) {
                //inserting node < tree root
                if (stu->mark < tree[cur]->mark) {
                    int lc = L_C(cur);
                    if (lc >= MAX) return;//overflow
                    if (tree[lc] == nullptr) {
                        tree[lc] = stu;
                        break;
                    } else {
                        cur = lc;
                    }
                } else {
                    int rc = R_C(cur);
                    if (rc >= MAX) return;
                    if (tree[rc] == nullptr) {
                        tree[rc] = stu;
                        break;
                    } else {
                        cur = rc;
                    }
                }
            }
        }
        size++;
    }


    //_________search by id________________
    bool search(int id) {
        int cur = 0;
        while (cur < MAX && tree[cur] != nullptr) {
            if (id == tree[cur]->id) return true;
            else if (id < tree[cur]->id) cur = L_C(cur);
            else cur = R_C(cur);
        }
        return false;
    }

    //_________inorder successor_____________
    int inorderSuccessorIndex(int cur) {
        //right child's left most value
        int successorIndex = R_C(cur);//right child
        //left most 
        while (tree[L_C(successorIndex)] != nullptr){
             successorIndex = L_C(successorIndex);
        }
        return successorIndex;
    }

    //_________delete____________________
    void Delete(double mark) {
        //no elmnt
        if (isEmpty()) return;
        int cur = 0;
        int parentIndex = -1;
        //some elmnts
        while (cur < MAX && tree[cur] != nullptr) {
            if (mark == tree[cur]->mark){ //is found
                // 0 lchild, 0 rchild
                 if (tree[L_C(cur)] == nullptr && tree[R_C(cur)] == nullptr){ 
                    tree[cur] = nullptr;
                 }
                 // 1 child - lc
                  else if (tree[L_C(cur)] != nullptr && tree[R_C(cur)] == nullptr) {
                    tree[cur] = tree[L_C(cur)];//replace
                    tree[L_C(cur)] = nullptr;//dlt R_C
                  }
                  // 1 child - rc
                  else if (tree[L_C(cur)] == nullptr && tree[R_C(cur)] != nullptr) {
                    tree[cur] = tree[R_C(cur)];//replace
                    tree[R_C(cur)] = nullptr;//dlt R_C
                  }
                  // 2/+ child
                  else {
                    int successorIndex = inorderSuccessorIndex(cur);
                    sectionA* successorValue = tree[successorIndex];
                    Delete(successorValue->mark);
                    tree[cur] = successorValue;
                  }
                size--;
                return;
            }
            else if ( mark< tree[cur]->mark) {
                parentIndex = cur;
                cur = L_C(cur);
            }
            else {
                parentIndex = cur;
                cur = R_C(cur);
            }
        }
    }
    //_____________print__________________
     void inorder(int cur) {
        if (cur >= MAX || tree[cur] == nullptr) return;
        inorder(L_C(cur));
        cout<<"id: "<<tree[cur]->id<<"\t NAME: "<< tree[cur]->name <<"\tmark: "<<tree[cur]->mark<<"\n";
        inorder(R_C(cur));
    }
};


int main(){
    sectionA* sec[5];
    sec[0] = new sectionA("Eusha", 111, 50.5);
    sec[1] = new sectionA("Choya", 112, 87);
    sec[2] = new sectionA("Shoron", 113, 40);
    sec[3] = new sectionA("Ajua", 114, 95);
    sec[4] = new sectionA("Saad", 115, 74.5);

    Array_base_BST bst;
    for(int i =0;i<5;i++){
        bst.insert(sec[i]);
    }
    //cout<<"size="<<bst.get_size()<<"\n";
    //bst.Delete(40);
    //cout<<"size="<<bst.get_size()<<"\n";
    bst.inorder(0);
}