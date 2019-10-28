#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;
typedef struct node{
	int Ikey;
	char name[10];
	struct node* next;
}TNODE;
TNODE *first, *last;

int LoadNode(TNODE *p);
void FreeNode(TNODE *p);
void PrintNode(TNODE *p);

void CreateList(){
	TNODE *p;
	int n=sizeof(TNODE);
	
	first=last=0;
	
	for(;;){
		if((p=(TNODE*)malloc(n))==0){
			printf("\n Memori Tidak Cukup");
			break;
		}
		if(LoadNode(p)!=1){
			FreeNode(p);
			break;
		}
		p->next=0;
		if(first==0){
			first=last=p;
		}else{
			last->next=p;
			last=p;
		}
	}
}

int LoadNode(TNODE *p){
	char opt;
	printf("\nMasukkan Node Baru?");
	opt=getche();
	opt=toupper(opt);
	if(opt!='N'){
		puts("\nMasukkan Data untuk Node : ");
		printf("\nIkey:\t");
		if(scanf("%d",&(p->Ikey))!=1)return 0;
		
		printf("\nname:\t");
		if(scanf("%s",&(p->name))!=1)return 0;
		return 0;
	}else{
		return -1;
	}
}

void FreeNode(TNODE *p){
	free(p);
}

void ViewAllList(){
	TNODE *p;
	p=first;
	while(p){
		PrintNode(p);
		p=p->next;
	}
}

TNODE* FindNode(int key){
	TNODE *p;
	p=first;
	while(p){
		if(p->Ikey==key)return p;
		p=p->next;
	}
}

void PrintNode(TNODE *p){
	if(p) printf("\n%d\t%s",p->Ikey,p->name);
}

TNODE* InsertBeforeFirst(){
	TNODE *p;
	int n=sizeof(TNODE);
	if(((p=(TNODE*)malloc(n))!=0)&&(LoadNode(p)==1)){
		if(first==0){
			p->next=0;
			first=last=p;
		}else{
			p->next=first;
			first=p;
		}
		return p;
	}
	if(p==0)
		printf("\nMemori Tidak Cukup");
	else
		FreeNode(p);
	return 0;
}

TNODE* InsertBeforeKey(int key){
	TNODE *p, *q, *q1;
	int n = sizeof(TNODE);
	
	q1=0;
	q=first;
	while(q){
		if(q->Ikey==key)break;
		q1=q;
		q=q->next;
	}
	if(q==0){
		printf("\nTidak ada node yang mempunyai kunci atau senarai kosong");
		return 0;
	}
	if(((p=(TNODE*)malloc(n))!=0)&&(LoadNode(p)==1)){
		if(q==first){
			p->next=first;
			first=p;
		}else{
			p->next=q;
			q1->next=p;
		}
	return p;
	}
	if(p==0)
		printf("\nMemori tidak cukup");
	else
		FreeNode(p);
	return 0;
}

TNODE* InsertAfterKey(int key){
	TNODE *p,*q;
	int n=sizeof(TNODE);
	q=first;
	while(q){
		if(q->Ikey==key)break;
		q=q->next;
	}
	if(q==0){
		printf("\nTidak ada Node yang mempunyai kunci atau seranai kosong");
		return 0;
	}
	if(((p=(TNODE*)malloc(n))!=0)&&(LoadNode(p)==1)){
		if(q==last){
			p->next=0;
			last->next=p;
			last=p;
		}else{
			p->next=q->next;
			q->next=p;
		}
	return p;
	}	
	if(p==0)
		printf("\nMemori tidak cukup")
	;else
		FreeNode(p);
	return 0;
}

TNODE* InsertAfterLast(){
	TNODE *p;
	int n=sizeof(TNODE);
	if(((p=(TNODE*)malloc(n))!=0)&&(LoadNode(p)==1)){
		p->next=0;
		if(first==0){
			first=last=p;
		}else{
			last->next=p;
			last=p;
		}
	return p;
	}	
	if(p==0)
		printf("\nMemori tidak cukup")
	;else
		FreeNode(p);
	return 0;
}

void RemoveFirst(){
	TNODE *p;
	if(first==0)
		return;
	if(first==last){
		FreeNode(first);
		first=last=0;
		return;
	}
	p=first;
	first=first->next;
	FreeNode(p);
}

void RemoveLast(){
	TNODE *p,*q;
	if(first==0)
		return;
	if(first==last){
		FreeNode(first);
		first=last=0;
		return;
	}
	q=0;
	p=first;
	while(p!=last){
		q=p;
		p=p->next;
	}
	p=last;
	FreeNode(p);
	q->next=0;
	last=q;
}

void RemoveByKey(int key){
	TNODE *p,*q;
	if(first==0)
		return;
	q=0;
	p=first;
	while(p){
		if(p->Ikey==key)break;
		q=p;
		p=p->next;
	}
	if(!p){
		printf("\nTidak Ada Node Yang Mempunyai Kunci")
		;return;
	}
	
	if(first==last){
		FreeNode(first);
		first=last=0;
		return;
	}
	if(p==first){
		first=first->next;
		FreeNode(p);
		return;
	}
	if(p==last){
		q->next=0;
		last=q
		;FreeNode(p);
		return;
	}
	q->next=p->next;
	FreeNode(p);
}
void DeleteList(){
	TNODE *p;
	p=first;
	while(p){
		first=first->next;
		FreeNode(p);
		p=first;
	}
	last=0;
}

main()
{
	CreateList();
	ViewAllList();
	InsertAfterLast();
	ViewAllList();
	RemoveFirst();
	ViewAllList();
	InsertAfterKey(1);
	ViewAllList();
	RemoveByKey(1);
	ViewAllList();
	DeleteList();
	ViewAllList();
}

