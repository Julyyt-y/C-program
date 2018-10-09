> 简单的通讯录

```C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	char name[10];
	char tel[11];
	struct Node *next;
}node;

node *p,*q,*h;

/**
 *显示结点信息函数
 */
void showNodeInfo(node *pp){
	if(pp != NULL){
		printf("姓名：%s，	电话：%s",pp->name,pp->tel);
		printf("\n"); 
	}
}

/**
 *遍历链表，将所有结点信息都显示出来 
 */
void showAllInfo(){
	node *list = h;
	while(list != NULL){ 
		showNodeInfo(list);
		list = list->next;
	}
} 

/**
 *查询匹配的结点
 */
node *select(char *nname,char *ntel){
	node *hh = h;
	node *pp = NULL;
	while(hh != NULL){
		if(nname != NULL){
			if(strcmp(nname,hh->name) == 0){
                pp = hh;
                break;
            }
		}
		if(ntel != NULL){
			if(strcmp(ntel,hh->tel) == 0){
                pp = hh;
                break;
            }
		}
		hh = hh->next;
	}
	return pp;
} 
 
/**
 *删除结点
 */
void delet(node *pp){
	node *qq = h;
	//第一种情况，当待删除的结点为头结点时 
	if(pp == h){
		h = h->next;
		free(pp);
	}
	//第二种情况，当待删除的结点不为头结点 
	else{
		while(qq != NULL){
			if(qq->next == pp){
				qq->next = pp->next;
				free(pp);
			}
			qq = qq->next;
		} 
	}
}

/**
 *信息删除
 */
void deleteInfomation(){
	char nname[10];
	int key;
	node *cp;
	printf("请输入您所需要删除的联系人的姓名："); 
	scanf("%s",nname);
	cp = select(nname,NULL);
	if(cp == NULL){
		printf("抱歉，系统中没有此联系人！\n");
	}
	else{
		printf("您要删除的联系人为：\n");
		showNodeInfo(cp);
		delet(cp);
		printf("删除成功。\n");
	}
} 

/**
 *信息录入
 */ 
void inputInfomation(){
	char ch;
	while(1){
		printf("请输入您要保存的好友的信息（您的所有好友的姓名不能重复呦~）：\n");
		node *qq = (node*)malloc(sizeof(node));
		printf("姓名：");
		scanf("%s",qq->name);
		printf("电话：");
		scanf("%s",qq->tel);
		//当链表为空时 
		if(h == NULL){
			h = p = qq;
            p->next = NULL;
		}
		//当链表不为空时
		else{
			p->next = qq;
            p = qq;
		} 
		printf("输入 0 结束输入，非 0 则继续：\n");
        ch=getchar();
        if(getchar()=='0'){
            break;
        }
	}
}

/**
 *信息查询函数
 */
void find(){
	node *sp = NULL;
	int key;
	printf("您可用   1姓名   2电话号码    来查询您要找的好友：\n");
	scanf("%d",&key);
	switch(key){
		case 1:
			char name[10];
			printf("请输入待查找姓名：");
            scanf("%s",name);
            sp = select(name,NULL);
            break;
        case 2:
        	char tel[11];
            printf("请输入待查找号码：");
            scanf("%s",tel);
            sp = select(NULL,tel);
            break;
        default:
        	printf("操作错误！\n");
        	break;
	}
	if(sp == NULL) {
		printf("系统没有您输入的信息！\n");
    } else {
        showNodeInfo(sp);
    }
} 

void menu()
{
    printf("                                  欢迎进入通讯录                                    \n");
    printf("                                                                                    \n");
    printf(" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  \n");
    printf("                                                                                    \n");
    printf("                            请输入序号选择您所需要的操作                            \n");
    printf("                                                                                    \n");
    printf("                                   1 信息录入                                       \n");
    printf("                                                                                    \n");
    printf("                                   2 信息查询                                       \n");
    printf("                                                                                    \n");
    printf("                                   3 信息查看                                       \n");
    printf("                                                                                    \n");
    printf("                                   4 信息删除                                       \n");
    printf("                                                                                    \n");
    printf("                                   5 退出系统                                       \n");
    printf("                                                                                    \n");
    printf(" ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  \n");
}
void checkMenu(){
    printf("                        通讯录                      \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                                                    \n");
    printf("                     1.查询                         \n");
    printf("                                                    \n");
    printf("                     2.退出查询系统                 \n");
    printf("                                                    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void Exit(){
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    printf("                                                   \n");
    printf("                                                   \n");
    printf("                  欢迎下次使用，再见               \n");
    printf("                                                   \n");
    printf("                                                   \n");
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
}

int main(){
	int main_key;
	int check_key;
	while(1){
		menu(); 
		printf("请根据菜单上的操作序号选择您所需的操作：");
		scanf("%d",&main_key);
		switch(main_key){
			case 1:
				inputInfomation();
				break;
			case 2:
				while(1){
					checkMenu();
					printf("请输入您所需的操作的序号：");
                    scanf("%d",&check_key);
                    if(check_key==1){
                        find();
                   	}
                    else if(check_key==2){
                       	break;
                    }
                    else{
                        printf("操作错误。请重新输入！\n");
                        getchar();
                    }
            	}
				break;
            case 3:
            	showAllInfo();
            	break;
            case 4:
            	deleteInfomation();
            	break;
            case 5:
				Exit();
				exit(0);
			default:
				printf("输入有误。请输入正确的操作序号！\n");
                break; 
		}
		system("pause"); // 暂停程序的执行，按任意键恢复执行 
	}
	return 0;
} 

/**
 *函数名: exit()
 *所在头文件：stdlib.h。
 *功能: 关闭所有文件，终止正在执行的进程。
 *exit(1)表示异常退出，这个1是返回给操作系统的。
 *exit(x)（x不为0）都表示异常退出。
 *exit(0)表示正常退出。
 */
 
 ```
