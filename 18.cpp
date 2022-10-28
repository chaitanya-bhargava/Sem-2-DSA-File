#include<iostream>
using namespace std;
class Node{
public:
    int data;
    int priority;
    Node* next;
    Node(int d,int p){
    priority=p;
    data=d;
    next=NULL;
    }
};
class Queue{
private:
    Node* head;
public:
    void enqueue(int n,int p){
        Node* temp=new Node(n,p);
        if(head==NULL){
            head=temp;
        }else if(head->priority<p){
            temp->next=head;
            head=temp;
        }
        else{
        Node* temp2=head;
        while((temp2->next!=NULL)&&(temp2->next->priority>p)){
            temp2=temp2->next;
        }
        temp->next=temp2->next;
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
    q1.enqueue(5,2);
    q1.enqueue(6,5);
    q1.enqueue(7,1);
    q1.enqueue(8,8);
    q1.enqueue(9,4);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    return 0;
}
