/**
 *需求：
 *根据二叉树的前序遍历顺序创建一棵二叉树，然后对此二叉树进行前、中、后序遍历
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *lchild,*rchild;
	struct node *parent;	//指向结点双亲的指针 
}bintnode;	
typedef bintnode *bintree;	//定义二叉树的根结点 
bintree root;	//指向二叉树根结点的指针 

typedef struct stack{
	bintree data[100];
	int tag[100];	//为栈中每个元素设置的标记，用于后序遍历 
	int top;		//栈顶指针 
}seqstack;
/**
 *入栈 
 */
void push(seqstack *s,bintree t){
	s->data[s->top] = t;
	s->top++;
}
/**
 *出栈 
 */
bintree pop(seqstack *s){
	if(s->top != 0){
		s->top--;
		return(s->data[s->top]);	//返回栈顶数据 
	}else{
		return NULL;
	}
}

/**
 *根据前序遍历规则创建一棵给定二叉树
 *（前序遍历中第一个结点是根结点，再左，再右） 
 */
bintree createbintree(){
	char ch;
	bintree t;
	if((ch=getchar())=='#'){
		t = NULL;
	}else{
		t = (bintnode *)malloc(sizeof(bintnode));
		t->data = ch;
		t->lchild = createbintree();
		t->rchild = createbintree();
	}
	return t;
} 

/**
 *二叉树的前序遍历（非递归实现） 
 *根——左（根的左子树）——右（根的右子树） 
 */
void preorder1(bintree t){
	seqstack s;
	s.top = 0;
	while((t) || (s.top!=0)){
		if(t){
			printf("%c",t->data); 
			push(&s,t);		//前序遍历先访问根结点，所以先进栈（保存结点） 
			t = t->lchild;
		}
		else{
			t = pop(&s);
			t = t->rchild;
		}
	}
} 

/**
 *二叉树的前序遍历（递归实现） 
 */
void preorder(bintree t){
	if(t){
		printf("%c",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

/**
 *二叉树的中序遍历（非递归实现） 
 *左（根的左子树）——根——右（根的右子树） 
 */
void inorder1(bintree t){
	seqstack s;
	s.top = 0;
	while((t!=NULL) || (s.top!=0)){
		if(t){
			push(&s,t);
			t = t->lchild;
		}
		else{
			t = pop(&s);
			printf("%c",t->data);
			t = t->rchild;
		}
	}
} 

/**
 *二叉树的中序遍历（递归实现） 
 */ 
void inorder(bintree t){
	if(t){
		inorder(t->lchild);
		printf("%c",t->data);
		inorder(t->rchild);
	}
} 

/**
 *二叉树的后序遍历（非递归实现） 
 *左（根的左子树）——右（根的右子树）——根 
 */
void postorder1(bintree t){
	seqstack s;
	s.top = 0;
	while((t) || (s.top!=0)){
		if(t){
			s.data[s.top] = t;
			s.tag[s.top] = 0;
			s.top++;
			t = t->lchild;
		}
		else{
			if(s.tag[s.top-1]==1){
				s.top--;
				t = s.data[s.top];
				printf("%c",t->data);
				t = NULL;
			}
			else{
				t = s.data[s.top-1];
				s.tag[s.top-1] = 1;
				t = t->rchild; 
			}
		}
	}
} 

/*
 *二叉树的后序遍历（递归实现） 
 */ 
void postorder(bintree t){
	if(t){
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c",t->data);
	}
} 
 
int main(){
	bintree s = createbintree(); 
	printf("二叉树前序遍历递归实现：");
	preorder(s);
	printf("\n");
	printf("二叉树前序遍历非递归实现：");
	preorder1(s);
	printf("\n");
	printf("二叉树中序遍历递归实现："); 
	inorder(s);
	printf("\n");
	printf("二叉树中序遍历非递归实现：");
	inorder1(s);
	printf("\n");
	printf("二叉树后序遍历递归实现：");
	postorder(s);
	printf("\n");
	printf("二叉树后序遍历非递归实现：");
	postorder1(s);
	printf("\n");
	
	return 0;
}
