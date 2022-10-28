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
    return 0;
}
