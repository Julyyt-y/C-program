链式串
============

```C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node *next;
}linkstrnode;
typedef linkstrnode *linkstring;	//指向结点的指针类型

/**
 *链式串的创建(尾插法)
 */ 
void strcreate(linkstring *S){
	char ch;
	linkstrnode *p,*r;
	*S = NULL;
	//用 r 始终指向当前链式串的最后一个结点 
	r = NULL;
	while((ch = getchar()) != '\n'){
		p = (linkstrnode *)malloc(sizeof(linkstrnode));
		p->data = ch;
		//新结点插入空表的情况 
		if(*S == NULL){
			*S = p;
		}
		//新结点插入非空表的情况 
		else{
			r->next = p;
		}
		r = p;
	} 
	if(r != NULL){
		r->next = NULL;
	}
} 

/**
 *链式串的插入（在S串的第i个位置插入T串） 
 */
void strinsert(linkstring *S,int i,linkstring T){
	int k;
	linkstring p,q;
	p = *S,k = 1;
	//用 p 查找第 i-1 个元素
	while(p && k<i-1){
		p = p->next;
		k++;
	}
	if(!p){
		printf("error \n");
	}
	else{
		q = T;
		//用 q 查找 T 中最后一个元素的位置 
		while(q && q->next){
			q = q->next;
		}
		//将 T 连接到 S 中的第 i 个位置上 
		q->next = p->next;
		p->next = T;
	}
}

/**
 *链式串的删除
 */
void strdelet(linkstring *S,int i,int len){
	int k;
	linkstring p,q,r;
	p = *S;
	q = NULL;
	k = 1;
	//用 p 查找 S 的第 i 个元素，q 始终跟踪 p 的前驱 
	while(p && k<i){
		q = p;
		p = p->next;
		k++; 
	}
	//S 的第 i 个元素不存在 
	if(!p){
		printf("error \n"); 
	}
	else{
		k = 1;
		//p从第i个元素开始查找长度问len子串的最后元素 
		while(k<len && p){
			p = p->next;
			k++;
		}
		//被删除子串位于S的最前面 
		if(!p){
			r = *S;
			*S = p->next;
		} 
		//被删除子串位于S的中间或最后的情况 
		else{
			r = q->next;
			q->next = p->next;
		}
		p->next = NULL;
		//循环回收被删除子串所占空间 
		while(r != NULL){
			p = r;
			r = r->next;
			free(p);
		}
	}
} 

/**
 *链式串的连接
 */
void strconcat(linkstring *S1,linkstring S2){
	linkstring p;
	//如果S1串为空串 
	if(!(*S1)){
		*S1 = S2;
		return;
	}
	else{
		//如果S1和S2均不为空串 
		if(S2){
			//用p查找S1的最后一个字符的位置 
			p = *S1;
			while(p->next){
				p = p->next;
			}
			//将S2串连到S1串的后面 
			p->next = S2;
		}
	} 
} 

/**
 *求字串运算
 */
linkstring substring(linkstring S,int i,int len){
	int k;
	linkstring p,q,r,t;
	p = S;
	k = 1;
	//用p查找S中的第i个字符 
	while(p && k<i){
		p = p->next;
		k++;
	}
	//第i个字符不存在 
	if(!p){
		printf("error \n");
		return (NULL);
	} 
	else{
		r = (linkstring)malloc(sizeof(linkstrnode));
		r->data = p->data;
		r->next = NULL;
		//用q始终指向子串的最后一个字符的位置 
		k = 1;
		q = r;
		//取长度为len的子串 
		while(p->next && k<len){
			p = p->next;
			k++;
			t = (linkstring)malloc(sizeof(node));
			t->data = p->data;
			q->next = t;
			q = t;
		}
		if(k<len){
			printf("error \n");
			return NULL;
		}
		//处理子串尾部 
		else{
			q->next = NULL;
			return (r);
		}
	}
}

/**
 *打印链式串各结点值
 */
void print(linkstring *S){
	linkstring p = *S;
	while(p != NULL){
		printf("%c",p->data);
		p = p->next;
	}
	printf("\n");
} 

int main(){
	linkstring string1,string2,string3;
	printf("请输入第一个链式串：\n");
	strcreate(&string1);
	printf("请输入第二个链式串：\n");
	strcreate(&string2);
	print(&string1);
	
	printf("在第一个链式串中从第2个元素开始删除4个元素：\n");
	strdelet(&string1,2,4);
	print(&string1);
	
	printf("将第一个链式串和第二个链式串连接：\n");
	strconcat(&string1,string2);
	print(&string1);
	
	printf("从第一个链式串的第3个位置开始取长度为6的子串（第三个链式串）：\n");
	string3 = substring(string1,3,6);
	print(&string3); 
	
	printf("在第三个链式串的第3个位置插入第二个链式串：\n");
	strinsert(&string3,3,string2);
	print(&string3); 

	return 0;
}

```
链式串的其它操作
===================

>
> 需求：比较两链式串的大小（遇大则大）
>

```C

int compare(linkstring *s1,linkstring *s2){
	linkstring p1 = *s1;
	linkstring p2 = *s2;
	for(p1,p2;p1!=NULL&&p2!=NULL;p1=p1->next,p2=p2->next){
		if(p1->data > p2->data){
			return 1;
		}
		if(p1->data < p2->data){
			return -1;
		}
	}
	if(p1==NULL && p2!=NULL){
		return -1;
	}
	if(p1 == NULL && p2==NULL){
		return 0;
	} if(p1 != NULL && p2 == NULL){
		return 1;
	}
} 

```
