#include<iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int power;
    Node* next;
    Node(int c,int p){
        coeff=c;
        power=p;
        next=NULL;
    }
};

void display(Node* head){
    while(head!=NULL){
        if(head->power==0){
            cout<<head->coeff;
        }else{
            if(head->next==NULL){
               cout<<head->coeff<<"x^"<<head->power;
            }else{
                cout<<head->coeff<<"x^"<<head->power<<"+";
            }
        }
        head=head->next;
    }
    cout<<endl;
}

void insertNode(int n,int p,Node** head){
    Node* temp=new Node(n,p);
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

void addPoly(Node** sum,Node* head1,Node* head2){
    while((head1!=NULL)&&(head2!=NULL)){
        if(head1->power>head2->power){
            insertNode(head1->coeff,head1->power,sum);
            head1=head1->next;
        }
        else if(head1->power<head2->power){
            insertNode(head2->coeff,head2->power,sum);
            head2=head2->next;
        }
        else{
            insertNode(head1->coeff+head2->coeff,head1->power,sum);
            head1=head1->next;
            head2=head2->next;
        }
    }
    while(head1!=NULL){
        insertNode(head1->coeff,head1->power,sum);
        head1=head1->next;
    }
    while(head2!=NULL){
        insertNode(head2->coeff,head2->power,sum);
        head2=head2->next;
    }
}

int main(){
    Node* head1=NULL;
    insertNode(23,3,&head1);
    insertNode(5,2,&head1);
    insertNode(3,1,&head1);
    insertNode(7,0,&head1);
    display(head1);
    Node* head2=NULL;
    insertNode(4,4,&head2);
    insertNode(5,3,&head2);
    insertNode(6,1,&head2);
    insertNode(7,0,&head2);
    display(head2);
    Node* head3=NULL;
    addPoly(&head3,head1,head2);
    display(head3);
    return 0;
}
