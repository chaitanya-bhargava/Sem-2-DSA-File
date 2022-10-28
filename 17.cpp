#include <iostream>
using namespace std;

class Queue{
    private:
    int arr[10];
    int front,rear;
    public:
    bool isEmpty(){
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(((front==0)&&(rear==9))||(rear==(front-1)%9)){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int a){
        if(isFull()){
            cout<<"Queue is full\n";
        }else if(front==-1){
            front=rear=0;
            arr[rear]=a;
        }else if(rear==9 && front!=0){
        rear=0;
        arr[rear]=a;
        }else{
            rear++;
            arr[rear]=a;
        }
        }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }
        int x=arr[front];
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }else if(front==9){
            front=0;
        }else{
            front++;
        }
        return x;
        }
    void display(){
        for(int i=front;i<rear+1;i++){
            cout<<arr[i]<<"\n";
        }
        cout<<endl;
    }
    Queue(){
        front=-1;
        rear=-1;
        for(int i=0;i<10;i++){
            arr[i]=0;
        }
    }
};



int main(){
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.display();
    cout<<q1.dequeue()<<" dequed."<<endl;
    cout<<q1.dequeue()<<" dequed."<<endl;
    cout<<endl;
    q1.display();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.display();
    return 0;
}
