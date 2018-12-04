/**
 *需求：
 *实现一个可以增删改查的宿舍管理系统
 */
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Sign{
	char studentId[10];
	char name[10];
	char dormitory[10];
	char phoneNumber[11];
	char familyAddress[10];
	struct Sign* next;
}pe;

pe *p,*q,*h;

void headShow() {
	printf("                                                     \n");
	printf("                    宿舍管理系统                     \n");
	printf("                                                     \n");
	printf("-----------------------------------------------------\n");
	printf("                                                     \n");
}

void menu() {
	printf("                                                 \n");
	printf("	请输入序号选择您所需的操作：                 \n");
	printf("                                                 \n");
	printf("                    1.信息录入                   \n");
	printf("                                                 \n");
	printf("                    2.信息查询                   \n");
	printf("                                                 \n");
	printf("                    3.查看信息                   \n");
	printf("                                                 \n");
	printf("                    4.信息修改                   \n");
	printf("                                                 \n");
	printf("                    5.退出系统                   \n");
	printf("                                                 \n");
}

void checkMenu(){
	printf("                                                        \n");
	printf("                    1.查询                        \n");
	printf("                    4.退出查询系统                      \n");
	printf("                                                        \n");
}

void Exit(){
	printf("                                                         \n");
	printf("---------------------------------------------------------\n");
	printf("                                                         \n");
	printf("                    欢迎下次使用，再见。                 \n");
	printf("                                                         \n");
	printf("---------------------------------------------------------\n");
	printf("                                                         \n");
	printf("                                                         \n");
}

/**
 *显示节点信息函数 
 */
void showPeInfo(pe* p){
	if (p != NULL){
		printf("%-10s %-10s %-10s %-11s %-10s\n",
		p->studentId,p->name,p->dormitory,p->phoneNumber,p->familyAddress);
    }
}

/**
 *遍历链表，将所有结点信息都显示出来
 */
void showAllPeInfo(pe* head){
	while (head != NULL){
		showPeInfo(head);
		head = head->next;
	} 
} 

/**
 *以追加的方式存储结点信息到指定文件
 */
void savePeInfo(pe* pp){
	FILE *fp = NULL;
	//使用 fopen( ) 函数来创建一个新的文件或者打开一个已有的文件
	fp = fopen("susheguanli.txt","a");  
	if(fp == NULL){
		printf("文件打开失败！\n");
	}
	//使用 int fprintf(FILE *fp,const char *format, ...) 函数来写把一个字符串写入到文件中
	fprintf(fp,"%s\t",pp->studentId);
	fprintf(fp,"%s\t",pp->name);
	fprintf(fp,"%s\t",pp->dormitory);
	fprintf(fp,"%s\t",pp->phoneNumber);
	fprintf(fp,"%s\n",pp->familyAddress);
	//使用 int fclose( FILE *fp ) 函数关闭文件
	fclose(fp); 
} 

/**
 *读取文件信息，并按指定格式存放在结构体中
 *返回该结构体的指针
 */
pe* loadPeInfo(FILE* fp){
	pe* p1;
	p1 = (pe*)malloc(sizeof(pe));
	fscanf(fp,"%s\t",&p1->studentId);
	if(feof(fp)){
		printf("文件为空！\n");
		p1 = NULL;
	} else{
		//fscanf从一个流中执行格式化输入,成功返回读入的参数的个数，失败返回EOF(-1)
		fscanf(fp,"%s\t",&p1->name);
        fscanf(fp,"%s\t",&p1->dormitory);
        fscanf(fp,"%s\t",&p1->phoneNumber);
        fscanf(fp,"%s\n",&p1->familyAddress);
        p1->next = NULL;
	}
	return p1;
}

/**
 *函数名: exit()
 *所在头文件：stdlib.h。
 *功能: 关闭所有文件，终止正在执行的进程。
 *exit(1)表示异常退出，这个1是返回给操作系统的。
 *exit(x)（x不为0）都表示异常退出。
 *exit(0)表示正常退出。
 */

//信息加载
void fileLoading(){
    FILE* fp;
    fp = fopen("susheguanli.txt","r+");
    //r+:文件必须存在，程序可以读和写入数据到文件
    if(fp == NULL){
        printf("打开文件失败!\n");
        exit(1);
    }
    // 逐条读取数据存入链表中，h头指针，p当前结点
    p = loadPeInfo(fp);
    if(p != NULL){
        h = p;	//读到的第一个结点的信息给头结点 
    }
    // EOF = end of file
    while(!feof(fp)){
        q = loadPeInfo(fp);
        q->next=NULL;
        p->next=q;
        p=q;
        //p指向读取到的信息链表的最后一个结点
    }
    fclose(fp);
}

/**
 *while(1)中1代表一个常量表达式，永远不会等于0,
 *循环会一直执行下去,
 *除非设置break等类似的跳出循环语句循环才会中止.
 */
// 录入信息
void inputInformation()
{
    FILE* fp;
    char ch;
    if((fp=fopen("susheguanli.txt","a"))==NULL){
        //a:文件必须存在，程序将在文件末尾"追加"或者说是写入数据
        printf("文件打开失败!\n");
        exit(1);
    }
    while(1){
        printf("请输入您要保存的学生信息（所有学生的学号不能重复）：\n");
        q=(pe*)malloc(sizeof(pe));
        q->next=NULL;
        printf("学号："); 
		scanf("%s",q->studentId);
        printf("姓名："); scanf("%s",q->name);
        printf("宿舍号："); scanf("%s",q->dormitory);
        printf("手机号："); scanf("%s",q->phoneNumber);
        printf("家庭住址："); scanf("%s",q->familyAddress);
        if(p == NULL){ // 说明之前文件为空，没有读取到信息，p为NULL
            h = p = q;
            p->next = NULL;
        }
        // 之前文件不为空，p指向读取到的信息链表的最后一个节点
        else {
            p->next = q;
            p = q;
        }
        savePeInfo(p);
        printf("输入 0 结束输入，非 0 则继续：\n");
        ch=getchar();
        if(getchar()=='0'){
            break;
        }
    }
    fclose(fp);
}

/**
 * 遍历链表与指定参数进行比较，返回匹配结点
 * 参数h    ：链表头结点
 * 参数name ：姓名
 * 参数phone：电话号码
 * 返回值：匹配结点，如没有匹配，返回NULL
 */
pe* selectPeInfo(pe* h1, char* name, char* studentId,char* dormitory){
    pe* p2 = NULL;
    while(h1 != NULL){
        if(name != NULL){
            if(strcmp(name,h1->name) == 0){
                p2 = h1;
                break;
            }
        }
        else if(studentId != NULL){
            if(strcmp(studentId,h1->studentId) == 0){
                p2 = h1;
                break;
            }
        }
        else if(dormitory != NULL){
        	if(strcmp(dormitory,h1->dormitory) == 0){
        		p2 = h1;
        		break;
			}
		}
        h1 = h1->next;
    }
    return p2;
}

/**
 * 二分法实现住宿信息的查询 
 */ 
//pe* findDichotomy(pe* h,char* name,char* studentId,char* dormitory){
//	int sum = 0;  //统计链表结点总数
//	int flag_1 = 0; //等于0表示没有匹配的数据，等于1表示有匹配的数据
//	int flag_2 = 0;
//	int flag_3 = 0;
//	
//	pe* p =NULL;
//	
//	while(h != NULL){    //计算总结点数 
//		sum++;
//		h = h->next;
//	}
//	char* a[sum];  //定义 3 个长度为结点总数的数组 
//	char* b[sum];
//	char* c[sum]; 
//	for(int i=0;i<sum;i++){    //将每个结点的姓名赋给 a 数组 
//		a[i] = h->name;
//		h = h->next;
//	}
//	for(int i=0;i<sum;i++){    //将每个结点的学号赋给 b 数组 
//		b[i] = h->studentId;
//		h = h->next;
//	}
//	for(int i=0;i<sum;i++){    //将每个结点的宿舍号赋给 c 数组 
//		a[i] = h->dormitory;
//		h = h->next;
//	}
//	
//	for(int i=0;i<sum;i++){
//		for(int j=0;j<sum-i-1;j++){
//			if(strcmp(a[i],a[j]) > 0){
//				char* temp_1 = a[i];
//				a[i] = a[j];
//				a[j] = temp_1;
//			}
//			if(strcmp(b[i],b[j]) > 0){
//				char* temp_2 = b[i];
//				b[i] = b[j];
//				b[j] = temp_2;
//			}
//			if(strcmp(c[i],c[j]) > 0){
//				char* temp_3 = c[i];
//				c[i] = c[j];
//				c[j] = temp_3;
//			}
//		}
//	}
//	int low = 0;
//	int high = sum-1;
//	int mid = (low + mid) / 2;
//	while(low <= high){
//		if(name != NULL){
//			if(strcmp(name,a[mid])<0){
//				high = mid - 1;
//			}else if(strcmp(name,a[mid])>0){
//				low = mid + 1;
//			}else{
//				flag_1 = 1; 
//			}
//		}
//		
//		else if(studentId != NULL){
//			if(strcmp(studentId,b[mid])<0){
//				high = mid - 1;
//			}else if(strcmp(studentId,b[mid])>0){
//				low = mid + 1;
//			}else{
//				flag_2 = 1; 
//			}
//		}
//		else if(dormitory != NULL){
//			if(studentId != NULL){
//				if(strcmp(studentId,b[mid])<0){
//					high = mid - 1;
//				}else if(strcmp(studentId,b[mid])>0){
//					low = mid + 1;
//				}else{
//					flag_2 = 1; 
//				}
//			}
//		}
//	}
//	if(flag_1 == 1){
//		p = selectPeInfo(h,name,NULL,NULL);
//	}else if(flag_2 == 1){
//		p = selectPeInfo(h,NULL,studentId,NULL);
//	}else if(flag_3 == 1){
//		p = selectPeInfo(h,NULL,NULL,dormitory);
//	}else{
//		printf("系统中没有该学生信息！");
//	}
//	return p;
//} 
//void sortNodesByStudentId(){
//	node* p1 = h;
//	node* p2 = p1->next;
//	node* pre = NULL;
//	int i = 1;
//	while(p2){
//		if(strcmp(p1->studentId,p2->studentId) > 0){
//			if(p1 && i==1){
//				p1->next = p2->next;
//				p2->next = p1;
//			}
//			else{
//				pre->next = p1->next;
//				p1->next = p2->next;
//				p2->next = p1;
//			} 
//		}
//		pre = p1;
//		p1 = p1->next;
//		p2 = p2->next;
//		i++;
//	}
//}


/**
 *查询函数 
 */
void Find()
{
//    FILE* fp;
    pe* sp = NULL;
    int key;
    printf("您可用   1姓名   2学号    3宿舍号    来查询您要找的学生：\n");
    scanf("%d",&key);
    switch(key){
        case 1:
            char name[10];
            printf("请输入待查找姓名：");
            scanf("%s",name);
//            sp = findDichotomy(h,name,NULL,NULL);
			sp = selectPeInfo(h,name,NULL,NULL);
            break;
        case 2:
            char studentId[10];
            printf("请输入待查找学号：");
            scanf("%s",studentId);
//            sp = findDichotomy(h,NULL,studentId,NULL);
			sp = selectPeInfo(h,NULL,studentId,NULL);
            break;
        case 3:
        	char dromitory[10];
        	printf("请输入待查找宿舍号：");
			scanf("%s",dromitory);
//			sp = findDichotomy(h,NULL,NULL,dromitory); 
			sp = selectPeInfo(h,NULL,NULL,dromitory);
        default:
            printf("操作错误。\n");
            break;
    }
    if(sp != NULL) {
        printf("学号\t   姓名    宿舍号     手机号\t     家庭住址\n");
        showPeInfo(sp);
    } else {
        printf("系统没有您输入的信息！\n");
    }
}

/**
 *存储所有结点信息到指定文件（原文件将会被清空重建）
 */
void saveAllPeInfo(pe* sh){
	FILE* fp;
	if((fp = fopen("susheguanli.txt","w+")) == NULL){
		//w+打开一文本文件允许读写文件。若文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
		printf("打开文件失败！\n");
	}
	while(sh != NULL){
		//fprintf(fp, "%d", buffer);将格式化的数据写入文件
		fprintf(fp,"%s\t",sh->studentId);
		fprintf(fp,"%s\t",sh->name);
		fprintf(fp,"%s\t",sh->dormitory);
		fprintf(fp,"%s\t",sh->phoneNumber);
		fprintf(fp,"%s\n",sh->familyAddress);
		sh = sh->next;
	}
	fclose(fp);
}

/**
 *显示所有结点信息函数
 */
void showAllInformation(){
	headShow();
	printf("学号	姓名	宿舍号	手机号	家庭住址\n");
	printf("                                        \n");
	showAllPeInfo(h);
	printf("\n");
} 

/**
 *删除结点函数
 *参数为待删除结点 
 */
void deletePeInfo(pe* dp){
	pe* q = h; //定义一个q，让他去找dp节点的前一个结点 
	//第一种情况：待删除的节点为头结点 
	if(dp == h){
		h = h->next;  //将头指针指向头结点的下一个结点 
		free(dp);  //释放头结点（待删除结点） 
	} else{
		//第二种情况：待删除节点不为头结点 
		while(q != NULL){
			if(q->next == dp){
				q->next = dp->next;
				free(dp);
			}
			q = q->next;
		} 
	} 
} 

/**
 *信息修改
 */
void changeInformation(){
	pe* cp = NULL;  //cp为要修改的结点信息 
	char changeId[10];
	headShow();
	printf("请输入您要修改的学生的学号："); 
	scanf("%s",changeId);
	cp = selectPeInfo(h,NULL,changeId,NULL);
	if(cp == NULL){
		printf("系统中没有此学生，请重新输入！");
	}else{
		printf("您要修改的学生为：");
		showPeInfo(cp);
		int m;
		printf("请确认您要修改的是此学生信息吗   0否	 1是：\n");
		scanf("%d",&m);
		switch(m){
			case 0:
				break;
			case 1:
				int n;
				printf("请选择您所要进行的操作	 1修改	 2删除：");
				scanf("%d",&n);
				switch(n){
					case 1:
						printf("请输入您要修改成的信息：\n");
						printf("学号：");
						scanf("%s",&cp->studentId);
						printf("姓名：");
						scanf("%s",&cp->name);
						printf("宿舍号：");
						scanf("%s",&cp->dormitory);
						printf("手机号：");
						scanf("%s",&cp->phoneNumber);
						printf("家庭住址：");
						scanf("%s",&cp->familyAddress);
						break;
					case 2:
						deletePeInfo(cp);
						break;
					default:
						break;
				}
			default:
				break;
		}
	}
	saveAllPeInfo(cp);  //存储所有结点信息，更新文件 
}

/**
 *对所有的住宿信息按 A姓名  B学号  C宿舍号 进行排序 
 */
pe* sortPeInfo(char key){  
	FILE* fp;
    pe* pfirst;      //排列后有序链的表头指针
    pe* ptail;       // 排列后有序链的表尾指针   
    pe* pminBefore;  // 保留键值更小的结点的前驱结点的指针  
    pe* pmin;        // 存储最小结点 
    pe* p3;           // 当前比较的结点 
		
    pfirst = NULL; 
    
//    if((fp=fopen("susheguanli.txt","a"))==NULL){
//        //a:文件必须存在，程序将在文件末尾"追加"或者说是写入数据	
//        printf("文件打开失败!\n");
//        exit(1);
//    }
    
    printf("请选择按	A姓名	B学号	C宿舍 	进行排序，然后您可以查看所有学生信息\n"); 
    while (h != NULL){    //在链表中找键值最小的结点 
    	//注意：这里for语句就是体现选择排序思想的地方 
        for (p3 = h, pmin = h; p3->next != NULL; p3 = p3->next) //循环遍历链表中的结点，找出此时最小的结点 
        {   
			if(key == 'B'){
            	if (strcmp(p3->next->studentId , pmin->studentId)<0) //找到一个比当前min小的结点 
            	{  
                	pminBefore = p3;           //保存找到节点的前驱结点：显然p->next的前驱结点是 p 
                	pmin = p3->next;     //保存键值更小的结点  
            	}
			}else if(key == 'A'){
				if (strcmp(p3->next->name , pmin->name)<0) //找到一个比当前min小的结点 
            	{  
                	pminBefore = p3;           //保存找到节点的前驱结点：显然p->next的前驱结点是 p 
                	pmin = p3->next;     //保存键值更小的结点  
            	} 
			}else if(key == 'C'){
				if (strcmp(p3->next->dormitory , pmin->dormitory)<0) //找到一个比当前min小的结点 
            	{  
                	pminBefore = p3;           //保存找到节点的前驱结点：显然p->next的前驱结点是 p 
                	pmin = p3->next;     //保存键值更小的结点 
            	}
			}
        }  
    
    //上面for语句结束后，就要做两件事；一是把它放入有序链表中；二是根据相应的条件判断，安排它离开原来的链表  
      
        //第一件事 
        if (pfirst == NULL)     // 如果有序链表目前还是一个空链表 
        {  
            pfirst = pmin;      // 第一次找到键值最小的结点 
            ptail = pmin;      // 注意：尾指针让它指向最后的一个结点 
        }  
        else                    // 有序链表中已经有结点 
        {  
            ptail->next = pmin; // 把刚找到的最小结点放到最后，即让尾指针的next指向它
            ptail = pmin;       // 尾指针也要指向它
        }  
  
        //第二件事 
        if (pmin == h)        // 如果找到的最小结点就是第一个结点 
        {  
            h = h->next;   // 显然让head指向原head->next,即第二个结点 
        }  
        else //如果不是第一个结点 
        {  
            pminBefore->next = pmin->next; //前次最小结点的next指向当前pmin的next,这样就让pmin离开了原链表  
        }  
    }  
  
    if (pfirst != NULL)     //循环结束得到有序链表first 
    {  
        ptail->next = NULL; //单向链表的最后一个结点的next应该指向NULL 
    }  
    h = pfirst; 
//	
//	fclose(fp);
	 
    return h;
}  

/**
 *主函数
 */
int main(){
	int key;
	int check_key;
	char c;
	fileLoading();
	while(1){
		menu();
		printf("请根据菜单上的操作序号来选择您所需的操作：");
		scanf("%d",&key);
		switch(key){
			case 1:
				inputInformation();
				break;
			case 2:
				while(1){
					checkMenu();
					printf("请根据序号选择您所需的操作：");
					scanf("%d",&check_key);
					if(check_key == 1){
						Find();
						break;
					}
					else if(check_key == 2){
						break;
					} 
					else{
						printf("操作错误。请重新输入！");
						getchar();
					}
					showPeInfo(p);
				}
				break;
			case 3:
				while(1){
					printf("请选择按	A姓名	B学号	C宿舍 	进行排序，然后您可以查看所有学生信息\n");
					scanf("%c",&c);
					getchar();
					if(c == 'B'){
						sortPeInfo('B');
					}
					else if(c == 'A'){
						sortPeInfo('A');
					}else if(c == 'C'){
						sortPeInfo('C');
					}else{
						showAllInformation();
						break;
					}
					showAllInformation();
				}
				break;
			case 4:
				changeInformation();
				break;	
			case 5:
				Exit();
				exit(0);
			default:
				break;		
		}
		system("pause"); // 暂停程序的执行，按任意键恢复执行
	}
	return 0;
} 
