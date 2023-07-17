#include <bits/stdc++.h>
using namespace std;

class node{    
    public:
        int data;
        node* Lchild;
        node* Rchild;
  
    node (int data){
        this -> data = data;
        Lchild = NULL;
        Rchild = NULL;
    }
}*root, *copy_root;
 
void BinaryTree (){
    int value;
    
    cout << "Enter the Root value -->\t";
    cin >> value;
    
    node* temp = new node (value);
    root = temp;
    queue <node*> q;
    q.push (root);
    
    while (!q.empty()){
        cout << "Enter the Left Child value:";
        cin >> value;
        if (value != -1){
            temp = new node (value);
            q.front () -> Lchild = temp;
            q.push (temp);
        }
        
        cout << "Enter the Right child value:";
        cin >> value;
        if (value != -1){
            temp = new node (value);
            q.front () -> Rchild = temp;
            q.push (temp);
        }
        q.pop();
    }   
}

void CopyBinaryTree (queue <node*> q_c){
    
    node* temp = new node (q_c.front () -> data);
    copy_root = temp;
    queue <node*> q;
    q.push (copy_root);
    q_c.pop();
    
    while (!q_c.empty()){
        if (q_c.front () != NULL){
            temp = new node (q_c.front () -> data);
            q.front () -> Lchild = temp;
            q.push (temp); 
        }
            q_c.pop();
        if (q_c.front () != NULL){   
            temp = new node (q_c.front () -> data);
            q.front () -> Rchild = temp;
            q.push (temp);
        }
            q_c.pop();
        q.pop();
    }
}
 

queue<node*> LevelOrderTraversal (node *n){
    cout << n -> data << " ";
    
    queue <node*> q_c;
    queue <node*> q;
    q_c.push (n);
    
    if (n -> Lchild != NULL){
        q.push (n -> Lchild);  
    }
    q_c.push (n -> Lchild);
    
    if (n -> Rchild != NULL){
        q.push (n -> Rchild);  
    }
    q_c.push (n -> Rchild);
    
    while (!q.empty()){
    
        cout << q.front () -> data << " ";
        if (q.front () -> Lchild != NULL){
            q.push (q.front () -> Lchild); 
        }
        q_c.push (q.front () -> Lchild);
        
        if (q.front () -> Rchild != NULL){
            q.push (q.front () -> Rchild); 
        }
        q_c.push (q.front () -> Rchild);
        q.pop ();
    }
    return q_c;
}
int main (){
    
    BinaryTree ();
    
    queue <node*> q_c;
    
    cout << "Level Order Traversal of Original Tree -->\t";
    q_c = LevelOrderTraversal (root);
    
    cout << "\n";

    CopyBinaryTree (q_c);

    cout << "Level Order Traversal of Mirror Tree -->\t";
    q_c = LevelOrderTraversal (copy_root);
}
