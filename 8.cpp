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

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"\t";
        head=head->next;
    }
    cout<<endl;
}

void startinsert(int n,Node** head){
    Node* temp=new Node(n);
    if(*head==NULL){
        (*head)=temp;
    }
    else{
        temp->next=*head;
        (*head)=temp;
    }
}
void endinsert(int n,Node* head){
    while(head->next!=NULL){
        head=head->next;
    }
    Node* temp=new Node(n);
    head->next=temp;
}
void midinsert(int n,int k,Node* head){
    for(int i=0;i<k-1;i++){
        head=head->next;
    }
    Node* temp=new Node(n);
    temp->next=head->next;
    head->next=temp;
}
void startdelete(Node** head)
{
    (*head)=(*head)->next;   
}
void enddelete(Node* head)
{
    while(head->next->next!=NULL){
        head=head->next;
    }
    head->next=NULL;
}
void middelete(int k,Node* head)
{
    for (int  i = 0; i < k-1; i++)
    {
        head=head->next;
    }
    head->next=head->next->next;
    
}
int main(){
    Node* head=NULL;
    int ans;
    while(1){

    cout<<"------------------------------\n1.Insert element at start\n2.Insert element at end\n3.Insert element at an index\n4.Delete element at start\n5.Delete element at end\n6.Delete element at an index\n7.Quit\n------------------------------\nChoose operation{1,2,3,4,5,6,7}:\n";
    cin>>ans;
    int n;
    switch (ans)
    {
    case 1:
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        startinsert(n,&head);
        break;
    case 2:
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        endinsert(n,head);
        break;
    case 3:
        int index1;
        cout<<"Enter the number to be inserted:\n";
        cin>>n;
        cout<<"Enter the index to be inserted at:\n";
        cin>>index1;
        midinsert(n,index1,head);
        break;
    case 4:
        startdelete(&head);
        break;
    case 5:
        enddelete(head);
        break;
    case 6:
        int index2;
        cout << "Enter the index to be deleted at:\n";
        cin >> index2;
        middelete(index2,head);
        break;
    case 7:
        cout<<"Quitting...";
        exit(0);
    default:
        cout<<"Wrong entry..."<<endl;
        break;
    }
    display(head);
    }
    return 0;
}