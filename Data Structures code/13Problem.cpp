  #include<bits/stdc++.h>
 using namespace std;
 
 struct node{
    int data;
    node* left;
    node* right;
 } *root,*rootp;
 
 void printInorder(node* root)
{
    //cout<<"in"<<endl;
    if(root!=NULL){
        printInorder(root->left);
        cout<<root->data<<";";
        printInorder(root->right);
    }
}
 void insert(){
    root=new node;
    cout<<"enter the root element:";
    int val;
    cin>>val;
    root->data=val;
    root->left=NULL;
    root->right=NULL;
    queue<node*> q;
    q.push(root);
    rootp=root;
    while(!q.empty()){
        cout<<"enter left child:";
        int val;
        cin>>val;
        if(val!=-1){
            node* temp=new node;
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            q.front()->left=temp;
            q.push(temp);
        }
        cout<<"enter right child:";
        cin>>val;
        if(val!=-1){
            node* temp=new node;
            temp->data=val;
            temp->left=NULL;
            temp->right=NULL;
            q.front()->right=temp;
            q.push(temp);
        }
        q.pop();
    }
 }
 
 bool checkBinarySearchTree(node* root){
         if (root == NULL)
         return 1;
         if (root->left != NULL && root->left->data > root->data && rootp->data<root->data)
         return 0;
     
  
         if (root->right != NULL && root->right->data < root->data && rootp->data>root->data)
         return 0;
          if (!checkBinarySearchTree(root->left) || !checkBinarySearchTree(root->right))
          return 0;
         
         return true;
 }
 int main(){
   insert();
   cout<<"INORDER TRAVERSAL:";
   printInorder(root);
   cout<<"\nis the given tree  binary search tree? ( 0 represents false and 1 represents true ) :"<<checkBinarySearchTree(root);
    
 }
