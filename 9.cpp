#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(){
    data=0;
    next=NULL;
    }
};

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head=head->next;
    }
    cout<<endl;
}

void reverseDisplay(Node* head){
    if(head==NULL){
        return;
    }
    reverseDisplay(head->next);
    cout<<head->data<<"\t";
}

int main(){
    Node* head=new Node();
    head->data=1;
    Node* second=new Node();
    head->next=second;
    second->data=2;
    Node* third=new Node();
    second->next=third;
    third->data=3;
    Node* fourth=new Node();
    third->next=fourth;
    fourth->data=4;
    display(head);
    reverseDisplay(head);
    return 0;
}
