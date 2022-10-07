#include<iostream>
#include<string>
using namespace std;
class Node{
	public:
		int coefficient;
		int power;
		char variable;
		Node *next;
	Node(){
		coefficient=0;
		variable=0;
		power=0;
		next=NULL;
	}
	Node(int c,char v,int p){
		coefficient=c;
		variable=v;
		power=p;
		next=NULL;
	}
	
};
class singlilinked{
	public:
		Node *head;
		singlilinked(){
			head=NULL;
		}
		void insertion(int c,char v,int p){
			Node *temp=head;
			Node *Newnode=new Node(c,v,p);
			if(head==NULL){
				head=Newnode;
			}
			else{
				while(temp->next!=NULL){
					temp=temp->next;
				}
				temp->next=Newnode;
			}
		}
	void sort(){
		Node *temp;
		Node *curr;
		for(curr=head;curr!=NULL;curr=curr->next){
			for(temp=curr->next;temp!=NULL;temp=temp->next){
				if(curr->power>temp->power&&curr->variable==temp->variable){
					int power=curr->power;
					curr->power=temp->power;
					temp->power=power;
					int coeff=curr->coefficient;
					curr->coefficient=temp->coefficient;
					temp->coefficient=coeff;
					char v=curr->variable;
					curr->variable=temp->variable;
					temp->variable=v;
					
					
				}
			
			}
		}
	}
	void display(){
		Node *temp=head;
		if(head==NULL){
			cout<<"empty"<<endl;
		}
		int n=0;
		while(temp!=NULL){
			temp=temp->next;
			n++;
		}
		Node *curr=head;
		cout<<n<<endl;
			while(curr!=NULL){
			cout<<curr->coefficient<<" "<<curr->variable<<" "<<curr->power<<endl;
			curr=curr->next;
			
		}
	}
	
	
};
void add(singlilinked *sa,singlilinked *sb,int n1,int n2){
	Node *temp=sa->head;
	Node *curr=sb->head;
	int node;
	if(temp==NULL){
		sa->display();
	}
	if(curr==NULL){
		sb->display();
	}
	
	
	singlilinked sadd;
	while(temp!=NULL){
		curr=sb->head;
		int count=0;
		while(curr!=NULL){
			if(temp->power==curr->power&&temp->variable==curr->variable){
				sadd.insertion(curr->coefficient+temp->coefficient,curr->variable,curr->power);
				count++;
				break;
				}
				curr=curr->next;}
			if(count!=1){
				sadd.insertion(temp->coefficient,temp->variable,temp->power);
			}
	
				temp=temp->next;
	}
	temp=sb->head;
	
	while(temp!=NULL){
		curr=sa->head;
		int count=0;
		while(curr!=NULL){
			if(temp->power==curr->power&&temp->variable==curr->variable){
				
				count++;
				break;
				}
				curr=curr->next;}
			if(count!=1){
				sadd.insertion(temp->coefficient,temp->variable,temp->power);
			}
	
				temp=temp->next;
	}
	

	sadd.sort();
	sadd.display();}
	
	
	

int main(){
	int n;
	cin>>n;
	singlilinked s1,s2;
	int c,p;
	char v;
	for(int i=0;i<n;i++){
		cin>>c;
		cin>>v;
		cin>>p;
		s1.insertion(c,v,p);
		
		
	}
		int k;
		cin>>k;
		for(int i=0;i<k;i++){
		cin>>c;
		cin>>v;
		cin>>p;
		s2.insertion(c,v,p);
		
		
	}
	s1.sort();
	s2.sort();
	add(&s1,&s2,n,k);
	}
