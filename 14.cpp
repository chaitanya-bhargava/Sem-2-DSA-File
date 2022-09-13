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
class Stack{
private:
    Node* head;
public:
    void push(int n){
        Node* temp=new Node();
        temp->next=head;
        temp->data=n;
        head=temp;
    }
    int pop(){
        if(head==NULL){
            cout<<"Stack Underflow...\n";
            return -1;
        }else{
        int x=head->data;
        head=head->next;
        return x;
        }
    }
    Stack(){
        head=NULL;
    }
};
int main(){
    Stack s1;
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    cout<<s1.pop()<<endl;
    s1.pop();
    return 0;
}
