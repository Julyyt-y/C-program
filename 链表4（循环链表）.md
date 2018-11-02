循环单链表
============

```C

#include <stdio.h>
#include <stdlib.h>

typedef struct cyclic_node{
	int info;
	struct cyclic_node *next;
}node;

int flag = 0;
/**
 *创建循环单链表
 */
node *cyclic_list(){
	node *head = NULL;
	node *p = NULL;
	node *tail;
	node *s;
	int x;
	scanf("%d",&x);
	while(x != flag){
		s = (node*)malloc(sizeof(node));
		s->info = x;
		if(head == NULL){
			head = s;
		}
		else{
			p->next = s;
		}
		p = s;
		scanf("%d",&x);
	}
	tail = p;
	tail->next = head->next;
	if(p != NULL){
		p->next = head;
	}
	return head;
}

/**
 *创建一个空的循环单链表 
 */
node *init(){
	return NULL;
} 

/**
 *创建循环单链表 
  */
node *creat(node *head){
	node *p = head;
	//找到最后一个结点 
	while(p->next){
		p = p->next;
	}
	//让最后一个结点指向头结点 
	p->next = head;
}

/**
 *获取循环单链表的最后一个结点的位置
 */
node *get_rear(node *head){
	node *p;
	if(!head){
		p = NULL;
	}
	else{
		p = head;
		while(p->next != head){
			p = p->next;
		}
	}
	if(p == NULL){
		printf("\n该链表为空！\n");
	}
	else{
		printf("%5d",p->info);
	}
	return p;
} 

/**
 *输出循环单链表中各个结点的值
 */
void print(node *head){
	node *p;
	if(!head){
		printf("\n此循环单链表是空的！\n");
	}
	else{
		printf("\n该循环单链表各个结点的值为：\n");
		printf("%5d",head->info);
		p = head->next;
		while(p != head){
			printf("%5d",p->info);
			p = p->next;
		}
	}
}

/**
 *在循环单链表中查找一个值为 x 的结点
 */
node *find(node *head,int x){
	node *q;
	//如果循环链表是空的 
	if(!head){
		printf("\n该循环单链表是空的，不能找到指定结点！\n");
		return NULL;
	}
	q = head;
	//没有找到并且没有找完整个表 
	while(q->next != head && q->info != x){
		q = q->next;
	}
	//找到之后打印该结点值并且打印该结点 
	if(q->info == x){
		printf("%5d",q->info); 
		return q;
	}
	else{
		return NULL;
	}
} 

/**
 *在循环链表第 i 个结点后面插入值为 x 的新结点
 */
node *insert(node *head,int x,int i){
	node *p,*q,*myrear;
	p = (node*)malloc(sizeof(node));
	p->info = x;
	if(i < 0){
		printf("\n无法找到指定位置！\n");
		free(p);
		return head;
	}
	//插入前该循环单链表为空表 
	if(i==0 && !head){
		p->next = p;
		head = p;
		return head;
	}
	//在非空循环单链表的最前面插入 
	if(i==0 && head){
		myrear = get_rear(head);
		p->next = head;
		myrear->next = p;
		return head;
	}
	//插入前该循环单链表为空表 
	if(i>0 && !head){
		printf("\n无法找到指定的插入位置！\n");
		free(p);
		return head;
	}
	if(i>0 && head){
		q = head;
		int j = 1;
		while(i!=j && q->next!=head){
			q = q->next;
			j++;
		}
		//没有找到第 i 个结点 
		if(i != j){
			printf("\n表中不存在第%d个结点，无法进行插入！\n",i);
			return head;
		}
		else{
			p->next = q->next;
			q->next = p;
			return head;
		}
	}
} 

/**
 *在循环单链表中删除一个值为 y 的结点
 */
node *dele(node *head,int y){
	node *pre = NULL,*q;
	if(!head){
		printf("\n循环单链表为空，无法做删除操作！\n");
		return head;
	}
	q = head;
	//找待删除节点q和q的前驱结点pre 
	while(q->next!=head  && q->info!=y){
		pre = q;
		q = q->next;
	}
	//没找待删除节点q和q的前驱结点pre  
	if(q->info != y){
		printf("\n没找到值为%d的结点！\n",y);
	}
	//找到了待删除节点q和q的前驱结点pre  
	else{
		//待删除节点不是头结点
		if(q != head){
			pre->next = q->next;
			free(q);
		}
		//待删除结点为头结点，分两种情况 
		else{
			//如果该循环链表只有一个结点 
			if(head->next == head){
				free(q);
				head = NULL;
			} 
			else{
				pre = head->next;
				while(pre->next != q){
					pre = pre->next;
				}
				head = head->next;
				pre->next = head;
				free(q);
			} 
		}
	}
	return head;
} 

int main(){
	node *list = cyclic_list();
	printf("\n该循环单链表的尾结点为："); 
	get_rear(list);
	print(list); 
	
	printf("\n删除了两个节点后：\n");
	dele(list,5);
	dele(list,6);
	print(list);
	
	printf("\n在第7个的结点后插入0：");
	insert(list,0,7);
	print(list); 
	
	printf("\n在尾结点后插入99：");
	insertNodeByTail(list,99);
	print(list);
	return 0;
} 

```
