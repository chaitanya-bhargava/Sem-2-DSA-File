#include<iostream>

using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(){
        data=0;
        left=right=NULL;
    }
};

void addElem(int n,Node** root){
    Node* newnode=new Node();
    newnode->data=n;
    if((*root)==NULL){
        *root=newnode;
    }
    else{
        Node* temp=*root;
        if(n<temp->data){
            if(temp->left==NULL){
                temp->left=newnode;
                return;
            }
            temp=temp->left;
            addElem(n,&temp);
        }
        else if(n>temp->data){
            if(temp->right==NULL){
                temp->right=newnode;
                return;
            }
            temp=temp->right;
            addElem(n,&temp);
        }
        else{
            cout<<"Duplicate values not allowed";
        }
    }
}



void Preorder(Node* root){
        Node* temp=root;
        if(temp==NULL){
            return;
        }
        cout<<temp->data<<"\t";
        Preorder(temp->left);
        Preorder(temp->right);
}

void Postorder(Node* root){
        Node* temp=root;
        if(temp==NULL){
            return;
        }
        Postorder(temp->left);
        Postorder(temp->right);
        cout<<temp->data<<"\t";
}

void Inorder(Node* root){
        Node* temp=root;
        if(temp==NULL){
            return;
        }
        Inorder(temp->left);
        cout<<temp->data<<"\t";
        Inorder(temp->right);
}

int main(){
    Node* root=NULL;
    int arr[]={13,12,5,8,4,0,1002,2003,54,98};
    for(int i=0;i<10;i++){
        addElem(arr[i],&root);
    }
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Inorder(root);
    cout<<endl;
    return 0;
}
