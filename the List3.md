带头结点的单链表
======================

```C

#include <stdio.h>
#include <stdlib.h>

typedef struct NodeLink{
	int info;
	NodeLink *next;
}node; 

/**
 *建立一个带空的头结点额的单链表 
 */
node *initLink(){
	node *head = (node*)malloc(sizeof(node));
	head->next = NULL;
	return head;
}

void display(node *head){
	node *p;
	p = head->next;
	if(!p){
		printf("\n此带头结点的单链表是空表！\n");
	}
	else{
		printf("\n此带头结点的单链表的各个结点的值为：\n");
		while(p){
			printf("%5d",p->info);
			p = p->next;
		}
	}
} 

/**
 *在带头结点的单链表中查找第 i 个结点地址
 */
node *find(node *head,int i){
	int j = 0;
	node *p = head;
	if(i<0){
		printf("\n此带头结点的单链表不存在第%d个结点！\n",i);
		return NULL;
	}
	else if(i = 0){
		printf("\n此带头结点的单链表的第%d个结点的值为%d。\n",i,p->info);
		return p;
	}
	while(p&&i!=j){
		p = p->next;
		j ++;
	}
	if(p==NULL){
		printf("\n此带头结点的单链表不存在第%d个结点！\n",i);
	}
	return p;
}

/**
 *在带头结点的单链表中的第 i 个结点后插入一个值为 x 的新结点
 */
node *insert(node *head,int i,int x){
	node *p,*q;
	//查找第 i 个结点，i==0表示新结点要插在头结点后面，此时 q 指向的事头结点 
	q = find(head,i);
	if(!q){
		printf("\n此带头结点的单链表中不存在第%d个结点！不能进行插入！\n",i);
		return head; 
	} 
	p = (node*)malloc(sizeof(node));
	p->info = x;
	p->next = q->next;
	q->next = p;
	return head;
} 

/**
 *删除带头结点的链表中一个值为 x 的结点
 */
node *delet(node *head,int x){
	node *pre = head;
	node *q = head->next;
	while(q&&q->info!=x){
		pre = q;
		q = q->next;
	}
	if(q){
		pre->next = q->next;
		free(q);
	}
	return head;
} 

int main(){
	node *list = initLink();
	display(list);
	insert(list,0,1);
	insert(list,1,2);
	insert(list,2,3);
	insert(list,3,4);
	insert(list,4,5);
	display(list);
	delet(list,4);
	printf("\n删除值为4的结点后的链表为：");
	display(list); 
	return 0;
}

```
