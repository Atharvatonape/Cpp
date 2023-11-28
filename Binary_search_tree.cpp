#include<iostream>
#include<vector>

using namespace std;

struct Node
{
    int data;
    Node* left ;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

//struct Node * root = new Node(NULL);

Node* init(struct Node* root, int val){
    if( root == NULL ) {
        return new Node(val);
    }
    else{
        if (root->data > val) {
            root->left = init(root->left, val);
        }
        else if (root->data < val) {
            root->right = init(root->right, val);
        }
    }
}

void inorder(struct Node* root){
    if (root == NULL ){
        return;
    }
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}


int main(){
    cout << "This is a Binary Search tree operation \n";
    Node* root = NULL;
    root = init(root, 5);
    init(root , 1);
    init(root , 3);
    init(root , 4);
    init(root , 2);
    init(root , 7);

    inorder(root);
    cout << "\n";




}
