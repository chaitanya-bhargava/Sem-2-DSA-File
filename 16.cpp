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
class Queue{
private:
    Node* head;
public:
    void enqueue(int n){
        Node* temp=new Node();
        temp->data=n;
        if(head==NULL){
            head=temp;
        }else{
        Node* temp2=head;
        while(temp2->next!=NULL){
            temp2=temp2->next;
        }
        temp2->next=temp;
        }
    }
    int dequeue(){
        if(head==NULL){
            cout<<"Queue Underflow...\n";
            return -1;
        }else{
        int x=head->data;
        head=head->next;
        return x;
        }
    }
    Queue(){
        head=NULL;
    }
};
int main(){
    Queue q1;
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    return 0;
}
