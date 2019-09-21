/*
1.)Middle element in the stack.
2.) Pop from the middle of the stack and print that element
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node* next,*prev;
}*mid=NULL;
int cnt=0;
void print(node *head){
	if(head)
		while(head!=NULL)
			{
				cout<<head->data<<" ";
				head=head->next;
			}
}
void push(node *&head,int val){
	node *new_node=new node;
	if(head==NULL){
	
		new_node->data=val;
		new_node->next=NULL;
		new_node->prev=NULL;
		head=new_node;
	}
	else{
		new_node->data=val;
		new_node->prev=NULL;
		new_node->next=head;
		head->prev=new_node;
		head=new_node;
	}
	cnt++;
	if(cnt==1)
		mid=new_node;
	else{
		if(cnt&1){
			mid=mid->prev;
		}
	}
}
void middle_elem(){
	if(mid)
		cout<<"Current middle Element is "<<mid->data<<"\n";
	else
		cout<<"stack is emtpy\n";
}
void pop_mid_elem(){
	cnt=cnt-1;
	mid->prev->next=mid->next;
	mid->next->prev=mid->prev;
	node *curr=mid;
	cout<<curr->data<<"\n";
	if(cnt&1){
		mid=curr->prev;
	}
	else{
		mid=curr->next;
	}
	free(curr);
}
void pop(node *&head){
	node *curr=head;
	if(head){
	int temp=curr->data;
	head=head->next;
	free(curr);
	cout<<temp<<"\n";
	cnt=cnt-1;
	if(!(cnt&1))
	mid=mid->next;
	}
	else
	{
		cout<<"Underflow\n";
	}
}
int main(){
	freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\inputf.in","r",stdin);
	freopen("Z:\\LPU\\FYear\\Practice_Contest_CF_CL\\outputf.in","w",stdout);
	node *head=NULL;
	cout<<"1 to insert an element into the stack\n";
	cout<<"2 to pop an element form the stack\n";
	cout<<"3 to print the middle element\n";
	cout<<"4 to pop the middle element\n";
	while(1){
		int x;
		cin>>x;
		if(x==0)
			break;
		else if(x==1){
			int val;
			cin>>val;
			push(head,val);
		}
		else if(x==2){
			cout<<"Element poped is ";
			pop(head);
		}
		else if(x==3){
			
			middle_elem();
			continue;
		}
		else if(x==4){
			cout<<"Poped middle element is ";//
			pop_mid_elem();
		}
		cout<<"Current stack looks like this\n";
		print(head);
		cout<<"\n";
	}
}
