顺序表
==============

```C

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct{
	datatype a[MAXSIZE];
	int size;
}sequence_list;

/**
 *置空表
 */
void init(sequence_list* slt){
	slt->size = 0;
}

/**
 *在顺序表的后部进行插入操作
 */
void append(sequence_list* slt,datatype x){
	if(slt->size == MAXSIZE){
		printf("顺序表已满！");
	}
	slt->a[slt->size] = x;
	slt->size = slt->size + 1;
}

/**
 *打印顺序表的各结点值
 */
void display(sequence_list* slt){
    int i;
    if(!slt->size){
    	printf("\n顺序表为空！\n");
	} else{
		for(i=0;i<slt->size;i++){
			printf("%5d  ",slt->a[i]);
		}
	}
}

/**
 *判断顺序表是否为空
 */
int empty(sequence_list* slt){
	return (slt->size == 0 ? 1:0);
} 

/**
 *查找顺序表中值为X的结点的位置
 */
int find(sequence_list* slt,datatype x){
	int i = 0;
	while(i<slt->size && slt->a[i] != x){
		printf("%5d",slt->a[x]);		//打印在屏幕上是为了看到找到了该节点的值 
		return (i<slt->size ? i:-1);
	}
} 

/**
 *取得顺序表中第i个结点（指定节点）的值
 */
datatype get(sequence_list* slt,int i){
	if(i<0 || i>slt->size){
		printf("\n指定位置的结点不存在！");
	} else{
		printf("%5d ",slt->a[i]); 	//打印在屏幕上是为了看到找到了该节点的值 
		return slt->a[i];
	}
} 

/**
 *在顺序表的中间某个位置插入
 */
void insert(sequence_list* slt,datatype x,int position){
	int i;
	if(slt->size == MAXSIZE){
		printf("\n顺序表已满，无法插入！");
		exit(1);
	}
	if(position<0 || position>slt->size){
		printf("\n指定的插入位置不存在！");
		exit(1);
	}
	for(i-slt->size;i>position;i--){
		slt->a[i] = slt->a[i-1];		//从i处空出一个位置（插入） 
	}
	slt->a[position] = x;
	slt->size++;
} 

/**
 *在顺序表的中间某个位置删除
 */
void delet(sequence_list* slt,int position){
	int i;
	if(slt->size == 0){
		printf("\n该顺序表是空的！");
		exit(1);
	}
	if(position<0 || position>slt->size){
		printf("\n指定的位置不存在！");
		exit(1);
	}
	for(i=position;i<slt->size-1;i++){
		slt->a[i] = slt->a[i+1];
	}
	slt->size--;
} 

int main(){
	sequence_list list;
	
	init(&list);
	append(&list,1);
	append(&list,2);
	append(&list,3);
	append(&list,4);
	append(&list,5);
	display(&list);
	printf("\n查找第3个结点元素：\n");
	find(&list,2);
	printf("\n在第4个元素前插入元素7后的顺序表：\n");
	insert(&list,7,3);
	display(&list);
	printf("\n获取第4个结点的元素：\n");
	get(&list,3);
	printf("\n删除第4个元素的值后的顺序表：\n");
	delet(&list,3); 
	display(&list);
	
	return 0;
}

```
