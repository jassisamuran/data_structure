#include<iostream>
using namespace std;
class node{
 public:
  int data;
  node *prev;
  node *next;
  node(int value){
    data=value;
    prev=NULL;
    next=NULL;
  }
};
void insert_at_head(node * &head,int value){
 node *ptr=new node(value);
 ptr->prev=NULL;
 ptr->next=head;
 if(head!=NULL){
  head->prev=ptr;
 }
 head=ptr;
}
void insert_at_tail(node *&head,int value){
 node *ptr=new node(value);
 if(head==NULL){
  head=ptr;
  return;
 }
 node *tmp=head;
 while(tmp->next!=NULL){
  tmp=tmp->next;
 }
 tmp->next=ptr;
 ptr->prev=tmp;
}
void print(node *&head){
 node *tmp=head;
 while(tmp!=NULL){
  cout<<tmp->data<<" ";
  tmp=tmp->next;
 }
}
void delete_at_head(node *&head){
 if(head==NULL)return;
 node *todelete=head;
 head=head->next;
 head->prev=NULL;
 delete todelete;
}
void delete_at_tail(node *&head){
 if(head==NULL)return;
 if(head->next==NULL){
  delete_at_head(head);
  return;
  }
 node *tmp=head;
 while(tmp->next!=NULL){
  tmp=tmp->next;
 }
 tmp->prev->next=NULL;
 tmp->prev=NULL;
 free(tmp);
}
void delete_at_position(node *&head,int n){
 if(n==1){
  delete_at_head(head);
  return;
 }
 node *tmp=head;
 while(tmp->next!=NULL && n!=1){
  tmp=tmp->next;
  n--;
 }
 tmp->prev->next=tmp->next;
 if(tmp->next!=NULL){
  tmp->next->prev=tmp->prev;
 }
 delete(tmp);
}
int main(){
	node *head=NULL;
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_tail(head,3);
	insert_at_tail(head,4);
	insert_at_tail(head,5);
	insert_at_tail(head,6);
	insert_at_tail(head,7);
	insert_at_tail(head,8);
	print(head);
	cout<<endl<<"delete at head"<<endl;
	delete_at_head(head);
	print(head);
	cout<<endl<<"delete at tail"<<endl;
   	delete_at_tail(head);
	print(head);
	delete_at_position(head,3);
	cout<<endl;
	print(head);
}
