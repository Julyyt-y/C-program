二叉树
======

二叉树（一）--二叉树的建立
------------------------

```C

#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{  //树的节点 
	int data;
	struct treeNode* left;
	struct treeNode* right;
}TreeNode;

typedef struct{  //树根 
	TreeNode* root;
}Tree; 

//创建树的函数
//第一个参数是这个树的树根。如链表：链表，如果头插法的话把头传到函数里面就可以了
//第二个参数是值，也就是之前节点的data
void insert(Tree* tree,int value){
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));  //创建一个节点 
	node->data = value;
	node->left = NULL;
	node->right = NULL; 
	//如果树根是空，则把刚创建好的这个节点给树根 
	if(tree->root == NULL){
		tree->root = node;
	}else{
		//如果树根（树）不是空的话我们给一个约束条件
		//即 左儿子 < 父节点 < 右儿子 
		TreeNode* temp = tree->root;
		while(temp != NULL){
			if(value < temp->data){
				//如果左节点为空，直接将node赋给左节点
				//否则将temp的左儿子赋给temp，进行和前面重复的操作
				if(temp->left == NULL){
					temp->left = node;
					return; 
				}else{
					temp = temp->left;
				}
			}else{
				if(temp->right == NULL){
					temp->right = node;
					return;
				}else{
					temp = temp->right;
				}
			}
		}
	}
	return;
} 

```

二叉树（二） - 遍历
---------------------

```C

//树的中序遍历
void inorder(TreeNode* node){
	if(node != NULL){
		inorder(node->left);
		printf("%d ",node->data);
		inorder(node->right);
	}
} 

//树的先序遍历
void traverseOrder(TreeNode* node){
	if(node != NULL){
		printf("%d ",node->data);
		traverseOrder(node->left);
		traverseOrder(node->right);
	}
} 
