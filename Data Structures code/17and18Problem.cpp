// #include <bits/stdc++.h>
// using namespace std;
// template <typename T>
// class AVLTreeNode
// {
// public:
//     T data;
//     AVLTreeNode *left;
//     AVLTreeNode *right;
//     int height;
//     AVLTreeNode(T data)
//     {
//         this->data = data;
//         left = NULL;
//         right = NULL;
//         height = 1;
//     }
//     ~AVLTreeNode()
//     {
//         delete left;
//         delete right;
//     }
// };
// int height(AVLTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     return root->height;
// }

// AVLTreeNode<int> *rightRotate(AVLTreeNode<int> *root)
// {
//     AVLTreeNode<int> *newRoot = root->left;
//     AVLTreeNode<int> *temp = newRoot->right;
//     newRoot->right = root;
//     root->left = temp;
//     root->height = max(height(root->left), height(root->right)) + 1;
//     newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
//     return newRoot;
// }

// AVLTreeNode<int> *leftRotate(AVLTreeNode<int> *root)
// {
//     AVLTreeNode<int> *newRoot = root->right;
//     AVLTreeNode<int> *temp = newRoot->left;
//     newRoot->left = root;
//     root->right = temp;
//     root->height = max(height(root->left), height(root->right)) + 1;
//     newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;
//     return newRoot;
// }
// int calcBalanceFactor(AVLTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     return height(root->left) - height(root->right);
// }

// AVLTreeNode<int> *insert(AVLTreeNode<int> *root, int data)
// {
//     AVLTreeNode<int> *newNode = new AVLTreeNode<int>(data);
//     if (root == NULL)
//         return newNode;
//     if (data < root->data)
//         root->left = insert(root->left, data);
//     else if (data > root->data)
//         root->right = insert(root->right, data);
//     else
//         return root;
//     root->height = 1 + max(height(root->left), height(root->right));
//     int BF = calcBalanceFactor(root);
//     // LL
//     if (BF > 1 && data < root->left->data)
//         return rightRotate(root);
//     // RR
//     if (BF < -1 && data > root->right->data)
//         return leftRotate(root);
//     // LR
//     if (BF > 1 && data > root->left->data)
//     {
//         root->left = leftRotate(root->left);
//         return rightRotate(root);
//     }
//     // RL
//     if (BF < -1 && data < root->right->data)
//     {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }
//     return root;
// }
// int countLeafNodes(AVLTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     if (root->left == NULL && root->right == NULL)
//         return 1;
//     else
//         return countLeafNodes(root->left) + countLeafNodes(root->right);
// }
// void printLevelWise(AVLTreeNode<int> *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<AVLTreeNode<int> *> PendingNodes;
//     PendingNodes.push(root);
//     while (PendingNodes.size() != 0)
//     {
//         AVLTreeNode<int> *front = PendingNodes.front();
//         PendingNodes.pop();
//         cout << front->data << ":";
//         if (front->left != NULL)
//         {
//             cout << "L:" << front->left->data << ",";
//             PendingNodes.push(front->left);
//         }
//         if (front->right != NULL)
//         {
//             cout << "R:" << front->right->data;
//             PendingNodes.push(front->right);
//         }
//         cout << endl;
//     }
// }
// int main()
// {
//     // 10 10 20 30 40 50 15 75 25 100 45
//     int n;
//     cin >> n;
//     AVLTreeNode<int> *root = NULL;
//     for (int i = 0; i < n; i++)
//     {
//         int data;
//         cin >> data;
//         root = insert(root, data);
//     }
//     printLevelWise(root);
//     cout << "No of leaf nodes : ";
//     cout << countLeafNodes(root) << endl;
// }


#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
};

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int BalanceFactor(Node *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);

    else if (data > node->data)
        node->right = insert(node->right, data);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = BalanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

unsigned int getLeafCount(Node *node)
{
    if (node == NULL)
        return 0;

    if (node->left == NULL && node->right == NULL)
        return 1;

    else
        return getLeafCount(node->left) + getLeafCount(node->right);
}

int main()
{
    Node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 15);
    root = insert(root, 75);
    root = insert(root, 25);
    root = insert(root, 100);
    root = insert(root, 45);

    
    cout << "\n\nPreorder traversal of the constructed AVL tree is: " << endl;
    preOrder(root);
    cout << endl;
    
    cout<<"Leaf Count of the Tree is: "<<getLeafCount(root)<<endl<<endl<<endl;
    
    return 0;
}