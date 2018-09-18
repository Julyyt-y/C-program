顺序表
==============

顺序表的实现
---------------

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

顺序表的应用之节点排序(1)
---------------------

 > 需求：
 > 将顺序表(a1,a2,…,an)重新排列以a1为界的两部分：
 > a1前面的值均比a1小，a1后面的值均比a1大（这里假设数据元素的类型具有可比性，不妨设为整型）。
 
 ```C
 
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;
typedef struct{
	datatype a[MAXSIZE];
	int size;
}List; 

/**
 *初始化顺序表
 */ 
void init(List* l){
	l->size = 0;
} 

/**
 *在顺序表的后部进行插入操作
 */
void insert(List* l,int x){
	if(l->size == 0){
		printf("This sequence table is empty！\n");
	}
	l->a[l->size] = x;
	l->size = l->size + 1;
} 

/**
 *需求:（使a1前面的值均比a1小，a1后面的值均比a1大） 
 *实现方法：若an小于a1：先将a1和an保存（赋给另一个变量），
 *a1~an都往后挪一个位置，再把原先a1的值赋给第一个结点 。 
 */ 
void sort(List* l){
	int temp1,temp2;
	temp1 = l->a[0];
	for(int i=0;i<l->size;i++){
		if(l->a[i] < temp1){
			temp2 = l->a[i];
			for(int j=i;j>0;j--){
				l->a[j] = l->a[j-1];
			}
			l->a[0] = temp2;
		}
	}
} 

/**
 *打印顺序表
 */
void print(List* l){
	int i;
    if(!l->size){
    	printf("\n顺序表为空！\n");
	} else{
		for(i=0;i<l->size;i++){
			printf("%5d  ",l->a[i]);
		}
	}
	printf("\n"); 
} 

int main(){
	List list;
	
	init(&list);
	insert(&list,5);
	insert(&list,4);
	insert(&list,6);
	insert(&list,0);
	insert(&list,9);
	insert(&list,2);
	insert(&list,3);
	insert(&list,8);
	printf("原顺序表：\n"); 
	print(&list);
	sort(&list);
	printf("排序后的顺序表：\n");
	print(&list);
	
	return 0;
	
}

```

顺序表的应用之排序（2）
------------------------

```C

/**
 *需求： 
 *有顺序表A和B，其元素均按从小到大的升序排列，
 *编写一个算法，将它们合并成一个顺序表C，要求C的元素也按从小到大的升序排列。
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int datatype;

typedef struct{
	datatype a[MAXSIZE];
	int size;
}List; 

/**
 * 顺序表初始化
 */ 
void init(List* l){
	l->size = 0;
}

/**
 * 在顺序表的尾部进行插入操作
 */
void insert(List* l,datatype x){
	if(l->size == MAXSIZE){
		printf("\n此顺序表已满！\n");
		exit(1);
	}
	l->a[l->size] = x;
	l->size = l->size + 1;
} 

/**
 * 打印顺序表各结点的值 
 */ 
void print(List* l){
	if(!l->size){
		printf("\n此顺序表是空的！\n");
	}
	else{
		for(int i=0;i<l->size;i++){
			printf("%5d",l->a[i]);
		}
	}
}

/**
 *排序
 */ 
void sort(List* l_1,List* l_2,List* l){
	
	int i=0,j=0,k=0;
	
	while(i < l_1->size && j < l_2->size){
		if(l_1->a[i] < l_2->a[j]){
			l->a[k++] = l_1->a[i++];
		}
		else{
			l->a[k++] = l_2->a[j++]; 
		}
	}
	while(i < l_1->size){
		l->a[k++] = l_1->a[i++];
	}
	while(j < l_2->size){
		l->a[k++] = l_2->a[j++];
	}
	l->size = k;
	
}

int main(){
	
	List list1;
	List list2;
	List l;
	int a[5];
	
	init(&list1);
	init(&list2);
	init(&l);
	
	for(int i=0;i<5;i++){
		scanf("%d",&a[i]);
		insert(&list1,a[i]);
	}
	print(&list1);
	
	for(int j=0;j<5;j++){
		scanf("%d",&a[j]);
		insert(&list2,a[j]);
	}
	print(&list2);
	printf("\n");
	
	sort(&list1,&list2,&l);
	print(&l);
	
	return 0;
}

```


