#include<iostream>
using namespace std;
class Node{
 public:
  int data;
  Node *next;
  Node(int val){
   data=val;
   next=NULL;
  }
};
Node *insert_at_head(Node *head,int val){
  Node *newnode=new Node(val);
  newnode->next=head;
  head=newnode;
  return head;
}
Node *insert_at_tail(Node *head,int val){
 Node *newnode=new Node(val);
 if(head==NULL){return insert_at_head(head,val);}
 Node *tmp=head;
 while(tmp->next!=NULL){
  tmp=tmp->next;
 }
 tmp->next=newnode;
 return head;
}
void display(Node *head){
 while(head!=NULL){
  cout<<head->data<<" ";
  head=head->next;
 }
}

int main(){
  Node *head=NULL;
  head=insert_at_head(head,2);
  head=insert_at_head(head,1);
  head=insert_at_tail(head,3);
  head=insert_at_tail(head,4);
  head=insert_at_tail(head,5);
  head=insert_at_tail(head,6);
  display(head);
}
