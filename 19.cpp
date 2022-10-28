#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int n){
    data=n;
    next=NULL;
    prev=NULL;
    }
};
class Queue{
private:
    Node* head;
    Node* tail;
public:
    void insertRear(int n){
        Node* temp=new Node(n);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
        }
    }
    int deleteFront(){
        if(head==NULL){
            cout<<"Queue Underflow...\n";
            return -1;
        }else if(head==tail){
            int x=head->data;
            head=NULL;
            tail=NULL;
            return x;;
        }
        else{
        int x=head->data;
        head=head->next;
        return x;
        }
    }
    void insertFront(int n){
        Node* temp=new Node(n);
        if(head==NULL){
            head=temp;
            tail=temp;
        }else{
        temp->next=head;
        head->prev=temp;
        head=temp;
        }
    }
    int deleteRear(){
        if(head==NULL){
            cout<<"Queue Underflow...\n";
            return -1;
        }else if(head==tail){
            int x=head->data;
            head=NULL;
            tail=NULL;
            return x;
        }
        else{
        int x=tail->data;
        tail=tail->prev;
        return x;
        }
    }
    Queue(){
        head=NULL;
        tail=NULL;
    }
};
int main(){
    Queue q1;
    q1.insertRear(5);
    q1.insertFront(6);
    q1.insertRear(7);
    q1.insertFront(8);
    q1.insertFront(9);
    q1.insertFront(10);
    q1.insertRear(11);
    cout<<q1.deleteRear()<<endl;
    cout<<q1.deleteRear()<<endl;
    cout<<q1.deleteFront()<<endl;
    cout<<q1.deleteFront()<<endl;
    cout<<q1.deleteFront()<<endl;
    cout<<q1.deleteFront()<<endl;
    cout<<q1.deleteRear()<<endl;
    cout<<q1.deleteFront()<<endl;
    return 0;
}
