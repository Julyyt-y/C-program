单链表
=============

单链表的实现（不含头结点）
-------------------------

```C

#include <stdio.h>
#include <stdlib.h>

typedef struct link_node{
	int info;
	struct link_node *next;
}node;

/**
 *建立一个空链表
 */
node *init(){
	node *list = (node*)malloc(sizeof(node));
//	list->info = -1111;
//	list->next = NULL;
	list = NULL;
	return list;
}

/**
 *头插法：
 *在链表头部插入一个值为 x 的节点 
 */
void insertByFront(node* head,int x){
	node *p = (node*)malloc(sizeof(node));
	p->info = x;
	//插入 
	p->next = head;
	head = p;
} 
 
/**
 *尾插法
 */
void *insertByTail(node *head,int y){
	node *p;
	p = (node*)malloc(sizeof(node));
	p->info = y;
	while(head->next != NULL){
		head = head->next;
	}
	head->next = p;
	p->next = NULL;

} 
/**
 *输出单链表中各个结点的值
 */
void display(node *head){
	node *p;
	p = head;
	//或 p = NULL
	if(!p){
		printf("\n此单链表为空表！\n");
	}
	else{
		printf("\n此单链表各个结点的值为：\n");
		//或 p != NULL 
		while(p){
			printf("%5d",p->info);
			p = p->next;
		}
		printf("\n");
	}
}

/**
 *查找链表中第i个结点的值
 */
node *find_1(node *head,int i){
	int j = 1;
	node *p = head;
	if(i<1){
		return NULL;
	}
	while(p && i!=j){
		p = p->next;
		j++;
	}
	return p;
}

/**
 *查找链表中值为 X 的节点 
 */
void *find_2(node *head,int i){
	node *p;
	while(p && p->info!=i){
		p = p->next;
	}
	return p;
}

/**
 *在链表中第 i 个结点后插入一个值为 x 的结点
 */
node *insert(node *head,int x,int i){
	node *p,*q;
	q = find_1(head,i);	//查找第 i 个结点
	if(!q && i!=0){
		printf("\n找不到第%d个结点，不能插入%d！",i,x);
	} 
	else{
		p = (node*)malloc(sizeof(node));
		p->info = x;		//设置新结点
		//插入的结点作为单链表的第一个结点 
		if(i==0){
			p->next = head;
			head = p;
		} 
		//插入的结点不为头结点
		else{
			p->next = q->next;
			q->next = p;
		}
	}
	return head;
} 

/**
 *在链表中删除一个值为 x 的结点 
 */
node *dele(node *head,int x){
	node *pre = NULL;
	node *p;
	if(!head){
		printf("\n此链表是空的！\n");
		return head;
	}
	//找到待删除结点 p,pre是 p 的前一个结点 
	//找到了但是没有找全 
	while(p && p->info != x){
		pre = p;
		p = p->next;
	}
	//找到了待删除结点
	if(p){
		//pre等于空，说明要删除的结点为第一个结点 
		if(!pre){
			head = head->next;
		}
		else{
			pre->next = p->next;
		}
		free(p);
	}
	return head;
}

int main(){
	node *list = init();
	int a[8];

	display(list);
	insertByTail(list,1);
	display(list);
	for(int i=0;i<8;i++){
		scanf("%d",&a[i]);
		insertByTail(list,i);
	}
	display(list);
	return 0;
} 
