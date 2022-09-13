#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(){
    data=0;
    prev=next=NULL;
    }
};
int main(){
    Node* head=new Node();
    Node* second=new Node();
    Node* third=new Node();
    head->data=5;
    head->prev=NULL;
    head->next=second;
    second->data=6;
    second->prev=head;
    second->next=third;
    third->data=8;
    third->prev=second;
    third->next=NULL;
    //Print
    Node* temp=head;
    Node* temp2=third;
    cout<<"Printing in forward direction...\n";
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
    cout<<"\n";
    cout<<"Printing in backward direction...\n";
    while(temp2!=NULL){
        cout<<temp2->data<<"\t";
        temp2=temp2->prev;
    }
    return 0;
}
