#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int n){
        data=n;
        next=NULL;
    }
};

class Queue{
    private:
    int arr[1000];
    int front,rear;
    public:
    bool isEmpty(){
        if((rear==-1)||(rear==(front-1))){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if((rear-front)==999){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int a){
        if(isFull()){
            cout<<"Queue is full\n";
        }else{
        rear++;
        arr[rear]=a;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return -1;
        }else{
        int x=arr[front];
        front++;
        return x;
        }
    }
    void display(){
        for(int i=front;i<rear+1;i++){
            cout<<arr[i]<<"\n";
        }
        cout<<endl;
    }
    Queue(){
        front=0;
        rear=-1;
        for(int i=0;i<1000;i++){
            arr[i]=0;
        }
    }
};

void insertNode(int n,Node** head){
    Node* temp=new Node(n);
    if((*head)==NULL){
        (*head)=temp;
    }else{
    Node* temp2=(*head);
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp;
    }
}


void display(Node* head){
    while(head!=NULL){
        cout<<"->"<<head->data;
        head=head->next;
    }
    cout<<endl;
}
void addEdge(int n,int m,Node* g1[]){
        insertNode(m,&g1[n]);
        insertNode(n,&g1[m]);
    }
void printGraph(Node** g1,int n){
        for(int i=0;i<n;i++){
            cout<<i<<endl;;
            display(g1[i]);
        }
    }

int minEdge(Node** g1,int u,int v,int n){
    int visited[n];
    int distance[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        distance[i]=0;
    }
    Queue q;
    q.enqueue(u);
    visited[u]=1;
    while(!q.isEmpty()){
        int x=q.dequeue();
        Node* temp=g1[x];
        while(temp!=NULL){
            if(visited[temp->data]==1){
            temp=temp->next;
                continue;
            }
            distance[temp->data]=distance[x]+1;
            q.enqueue(temp->data);
            visited[temp->data]=1;
            temp=temp->next;
        }
    }
    return distance[v];
}

int main(){
    int n;
    cout<<"Enter number of vertices:"<<endl;
    cin>>n;
    Node* g1[n];
    for(int i=0;i<n;i++){
        g1[i]=NULL;
    }
    cout<<"Enter number of edges:"<<endl;
    int m;
    cin>>m;
    cout<<"Enter pair of vertices:"<<endl;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v,g1);
    }
    printGraph(g1,n);
    cout<<minEdge(g1,0,3,n);
    return 0;
}
