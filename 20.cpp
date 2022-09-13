#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(){
        left=NULL;
        right=NULL;
    }
};

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

int main() {
    Node* root=new Node();
    root->data=1;
    Node* second=new Node();
    second->data=2;
    Node* third=new Node();
    third->data=3;
    Node* fourth=new Node();
    fourth->data=4;
    Node* fifth=new Node();
    fifth->data=5;
    Node* sixth=new Node();
    sixth->data=6;
    Node* seventh=new Node();
    seventh->data=7;
    Node* eigth=new Node();
    eigth->data=8;
    Node* ninth=new Node();
    ninth->data=9;
    Node* tenth=new Node();
    tenth->data=10;

    root->left=second;
    root->right=third;
    second->left=fourth;
    second->right=fifth;
    third->left=sixth;
    third->right=seventh;
    fourth->left=eigth;
    fourth->right=ninth;
    seventh->left=tenth;
    cout<<"Preorder..."<<endl;
    Preorder(root);
    cout<<endl;
    cout<<"Postorder..."<<endl;
    Postorder(root);
    cout<<endl;
    cout<<"Inorder..."<<endl;
    Inorder(root);
    cout<<endl;
    return 0;
}
