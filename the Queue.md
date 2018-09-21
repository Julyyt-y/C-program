顺序队列的实现
===================

```C

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
	int a[MAXSIZE];
	int front;				//头 ，指示的是队首结点在数组中元素得下标 
	int rear;				//尾 ，指示的是队尾结点在数组元素下标的下一个位置 
}sequence_queue; 

/**
 * 初始化函数
 */
void init(sequence_queue* sq){
	sq->front = sq->rear = 0;
} 

/**
 * 判断队列是否为空
 */
int empty(sequence_queue* sq){
	if(sq->front == sq->rear){
		printf("\n This queue is empty ! \n"); //此处打印只是为了可以在屏幕上看出队列是否为空 
	}
	return 0;
	//队列为空的条件是 队首==队尾 
} 

/**
 * 打印队列的结点值
 */
void display(sequence_queue* sq){
	if(empty(sq)){
		printf("\n This queue is empty ! \n");
	}
	else{
		for(int i=sq->front;i<sq->rear;i++){
			printf("%5d",sq->a[i]);
		}
	}
} 

/**
 * 取得队列的队首结点值
 */
int get(sequence_queue* sq){
	if(empty(sq)){
		printf("\n This queue is empty ! \n");
		exit(1);
	}
	else{
		printf("%5d",sq->a[sq->front]);
		return (sq->a[sq->front]);
	}
} 

/**
 * 队列的插入（入队）操作
 */
void insert(sequence_queue* sq,int x){
	if(sq->rear == MAXSIZE){
		printf("\n This queue is full ! \n");
		exit(1);
	}
	sq->a[sq->rear] = x;
	sq->rear = sq->rear + 1;		//队列只能在队尾进行入队操作 
} 

/**
 * 队列的删除（出对）操作
 */
void dele(sequence_queue* sq){
	if(sq->front == sq->rear){
		printf("\n This queue is empty! Can not do delete operation ! \n");
		exit(1);
	}
	sq->front ++;		//队列只能在队首进行出队操作 
} 

int main(){
	sequence_queue queue;
	int a[8];
	
	init(&queue);
	empty(&queue);
	for(int i=0;i<8;i++){
		scanf("%d",&a[i]);
		insert(&queue,a[i]);
	} 
	insert(&queue,1);
	insert(&queue,2);
	insert(&queue,3);
	insert(&queue,4);
	insert(&queue,5);
	printf("\n该队列为：\n");
	display(&queue);
	dele(&queue);
	printf("\n删除一个元素后该队列的队首为：\n");
	get(&queue);
	dele(&queue);
	printf("\n再删除一个元素后该队列为：\n");
	display(&queue);
}  

```
