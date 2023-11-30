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
Node *insert_at_position(Node *head,int val,int position){
  Node *newnode=new Node(val);
  Node *tmp=head;
  if(head==NULL)return insert_at_head(head,val);
  while(tmp->next!=NULL && --position!=1){
    tmp=tmp->next;
  }
  Node *mn=tmp->next;
  tmp->next=newnode;
  tmp->next->next=mn;
  return head;

}
Node *reverse(Node *head){
  if(head->next==NULL){ return head;}
  Node *tmp=reverse(head->next);
  head->next->next=head;
  head->next=NULL;
  return tmp;
}
Node *reverse_iterative(Node* head){
  Node *cur=head;
  Node *nextptr=NULL;
  Node *prev=NULL;

  while(cur!=NULL){
    nextptr=cur->next;
    cur->next=prev;

    prev=cur;
    cur=nextptr;
  }
 return prev;

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
  head=insert_at_position(head,34,3);
  cout<<endl<<"insertion data at positon"<<endl;
  display(head);
  head=reverse(head);
  cout<<"after reversing linkedlist"<<endl;
  display(head);
  cout<<endl<<"by iterative apporach"<<endl;
  head=reverse_iterative(head);
  display(head);
}
