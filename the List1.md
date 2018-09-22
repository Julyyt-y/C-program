链表
========

链表（一）
--------

```C

#include <stdio.h>
struct Student {						//声明结构体类型struct Student
	int num;
	float score;
	struct Student *next;
};
int main(){	
	struct Student a,b,c,*head,*p;	//定义3个结构体变量a,b,c作为链表的结点
	a.num = 10101; a.score = 89.5;		//对结点a的num和score成员赋值
	b.num = 10103; b.score = 90;		//对结点b的num和score成员赋值
	c.num = 10107; c.score = 85;		//对结点c的num和score成员赋值
	head = &a;					//将结点a的起始地址赋给头指针head
	a.next = &b;					//将结点b的起始地址赋给a结点的next成员
	b.next = &c;					//将结点c的起始地址赋给a结点的next成员
	c.next = NULL;					//c结点的next成员不存放其他结点地址
	p = head;	
						//使p指向a结点
	while(p != NULL){
		printf("%ld %5.1f\n",p->num,p->score);	//输出p指向的结点的数据
		p=p->next;    //使p指向下一结点
	} 				//输出完c结点后p的值为NULL，循环终止
	return 0;
}

```

链表（二）--插入节点
------------------

```C

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;                   //数据域，用于存储数据 
	struct Node *next;          //指针，可以用来访问节点数据，也可以遍历，指向下一个节点 
}pe;
//创建链表，（其实就是创建了一个节点(头结点)） 
pe* creatList(){
	//创建一个结构体指针去表示整个链表
	
	//给list分配内存空间 
	pe* list = (pe*)malloc(sizeof(pe));
	list->data = -11111;
	list->next = NULL;  //让list的下一个节点为空 
	return list;                       //返回创建的这个链表 
}
//创建节点 
pe* createNode(int data){
	pe* node = (pe*)malloc(sizeof(pe));
	node->data = data;
	node->next = NULL;
	return node;                      //返回创建的这个节点 
}
//在头结点处插入（头插法） 
void insertNodeByHead(pe* List,int data){
	//创建插入的节点 
	pe* newNode = createNode(data);
	//插入的代码 
	newNode->next = List->next;
	List->next = newNode;              //表头的下一个永远都是新的节点,表头不变 
}

//在尾节点处插入
void insertNodeByTail(pe* List,int data){
	//创建插入的节点 
	pe* newNode = createNode(data);
	while(List->next != NULL){
		List = List->next;
	}
	List->next = newNode;
	newNode->next = NULL;
} 

//链表的指定位置(前面)插入  （参数为指定位置前面的节点） 
void insertNodeByAppoin(pe* list,int data) {
	pe* p = list;
	pe* pNode = list->next;		//指定位置
	pe* newNode = createNode(6);
	//遍历链表找到指定位置和指定位置前面的节点 
	while(pNode->data != data){
		p = p->next;
		pNode = pNode->next;	
		
		if(pNode == NULL){
			printf("未找到指定位置，无法插入。");
			return;
		}
	}
	p->next = newNode;					//将 p 的next指向待插入的节点 
	newNode->next = pNode;				//将待插入节点的next指向原 p的next（即pNode） 
}

//打印链表 
void printList(pe *list){
	pe *p = list->next;
	while(p){
		printf("	%d\n",p->data);
		p = p->next;
	}
	printf("\n");
}

int main(){
	pe *List = creatList();
	insertNodeByHead(List,1);
	insertNodeByHead(List,2);
	insertNodeByHead(List,3);
	printList(List);
	insertNodeByTail(List,4);
	printList(List);
	insertNodeByAppoin(List,4);
	printList(List); 
	free(List); 
	return 0;
}

```

链表（三）--删除节点
==================

```C
/**
 * delete()和 free()的区别 
 *free和mall匹配：释放malloc出来动态内存
 *delete和new匹配：释放new出来的动态内存空间
 */
  
//删除链表的头结点 
void deleteNodeByHead(pe* list){
	list->next = list->next->next;
	delete(list->next);
}

//链表的指定位置删除(此处指定位置的参照点是data)
void deleteNodeByAppoin(pe *list,int posData){    //传入链表和指定位置的数据posData 
	pe *p = list;  //前面那个节点 
	pe *posNode = list->next;                 //posNode为指定位置节点 
	while(posNode->data != posData){
		p = posNode;
		posNode = p->next;
		//或者：
//		p = p->next;
//		posNode = posNode->next;
		if(posNode == NULL){
			printf("未找到指定位置,无法删除。"); 
			return; 
		} 
	}
	p->next = posNode->next;
	delete(posNode);
}

