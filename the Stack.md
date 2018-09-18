栈
===

栈的实现
-------------

```C

#include <stdio.h> 
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct{
	datatype a[MAXSIZE];
	int top;
}sequence_stack;

/**
 *栈的初始化
 */
void init1(sequence_stack* st){
	st->top = 0;
} 

/**
 *判断栈是否为空
 */
int empty1(sequence_stack* st){
	return(st->top ? 0:1);
}

/**
 *取得栈顶节点值（栈顶元素） 
 */
datatype read(sequence_stack* st){
	if(empty1(st)){
		printf("\n此栈是空的！\n");
	} else{
		printf("%d\n",st->a[st->top-1]);
		return st->a[st->top - 1];
	}
} 

/**
 *栈的插入操作
 */
void push1(sequence_stack* st,datatype x){
	if(st->top == MAXSIZE){
		printf("\n 此栈已满！\n");
		exit(1);
	}
	st->a[st->top] = x;
	st->top ++;
} 

/**
 *栈的删除操作 
 */
void pop(sequence_stack* st){
	if(st->top == 0){
		printf("\n 此栈为空！\n");
		exit(1);
	}
	st->top --;
}
/**
 *打印栈中所有元素 
 */
void print(sequence_stack* st){
	int i;
    if(st->top == 0){
    	printf("\n 此栈为空！！\n");
	} else{
		while(st->top != NULL){
			printf("%5d",st->a[st->top]);
			st->top --;
		}
	}
} 


int main(){
	
	sequence_stack stack;
	
	init1(&stack);
	push1(&stack,1);
	read(&stack);
	push1(&stack,2);
	read(&stack);
	push1(&stack,3);
	read(&stack);
	push1(&stack,4);
	read(&stack);
	push1(&stack,5);
	read(&stack);
	pop(&stack);
	pop(&stack);
	printf("删除了两个元素后的栈顶元素：\n");
	read(&stack);

	return 0;
}

```
