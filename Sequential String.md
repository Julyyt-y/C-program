顺序串
======

```C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

typedef struct{
	char str[MAXSIZE];
	int length;
}seqstring; 
 
/**
 *顺序串的插入
 */
seqstring strinsert(seqstring S,int i,seqstring T){
	int k;
	//处理非法情况 
	if(i<1 || i>S.length+1 || S.length+T.length>MAXSIZE-1){
		printf("cannot insert \n");
	}else{
		//S从第i个元素开始后移 
		for(k=S.length-1;k>=i-1;k--){
			S.str[T.length+k] = S.str[k];
		}
		//将T插入S的第i个元素开始的位置 
		for(k=0;k<T.length;k++){
			S.str[i+k-1] = T.str[k];
		}
		S.length = S.length + T.length;
		S.str[S.length] = '\0';
	}
	return S;
} 

/**
 *顺序串的删除
 */
seqstring strdelete(seqstring S,int i,int len){
	int k;
	//处理非法情况 
	if(i<1 || i>S.length || i+len-1>S.length){
		printf("cannot delete! \n");
	}else{
		for(k=i+len-1;k<S.length;k++){
			/* S从下标为 i+len-1 开始的元素前移 */
			S.str[k-len] = S.str[k]; 
		}
		S.length = S.length - len;
		S.str[S.length] = '\0';
	}
	return S;
}

/**
 *顺序串的连接
 */
 seqstring strconcat(seqstring S1,seqstring S2){
	int i;
	seqstring r;
	if(S1.length + S2.length > MAXSIZE){
		printf("cannot concate \n");
	}else{
		/* 将S1复制到 r 字符数组的前端 */
		for(i=0;i<S1.length;i++){
			r.str[i] = S1.str[i];
		} 
		/* 将S2复制到 r 字符数组的后端 */
		for(i=0;i<S2.length;i++){
			r.str[S1.length+i] = S2.str[i];
		}
		r.length = S1.length + S2.length;
		r.str[r.length] = '\0';
	}
	return (r);
}

/**
 *求子串运算（在顺序串中取一个长度为len的子串） 
 */
seqstring substring(seqstring S,int i,int len){
	int k;
	seqstring r;
	//处理非法情况 
	if(i<1 || i>S.length || i+len-1>S.length){
		printf("error \n");
		return (r);
	}else{
		//从第i个位置开始取长度为len的子串
		for(k=0;k<len;k++){
			r.str[k] = S.str[i+k-1];
		}
		r.length = len;
		r.str[r.length] = '\0';
	}
	return (r);
}

/**
 *串赋值(将一个值t赋值给串S)
 */ 
void strassign(seqstring &S,char s[]){
	int i = 0;
	while(s[i] != '\0'){
		S.str[i] = s[i];
		i++;
	}
	S.length = i;
} 

/**
 *串赋值(将一个顺序串t赋给顺序串S)
 */
seqstring strcopy(seqstring S,seqstring t){
	int i;
	for(i=0;i<t.length;i++){
		S.str[i] = t.str[i];
	}
	S.length = t.length;
	return S;
} 

/**
 *求串长
 */
int strlength(seqstring S){
	int i;
	for(i=0;S.str[i]!='\0';i++){
	}
	return i;
} 

/**
 *判断串相等
 */
int strequal(seqstring S,seqstring t){
	int i = 0;
	if(S.length != t.length){
		return 0;
	}
	else{
		for(i=0;i<S.length;i++){
			if(S.str[i] != t.str[i]){
				return 0;
			}
		}
		return 1;
	}
}
int main(){
	seqstring seq1,seq2,seq3,seq4,seq5; 
	printf("请输入第一个字符串：\n");
	gets(seq1.str);
	printf("请输入第二个字符串：\n");
	gets(seq2.str);
	seq1.length = strlength(seq1);
	seq2.length = strlength(seq2);
	printf("%d\n",seq1.length);
	printf("%s\n",seq1.str);
	printf("%s\n",seq2.str);
	
	int equal = strequal(seq1,seq2);
	if(equal == 1){
		printf("两顺序串相等\n");
	}else{
		printf("两顺序串不相等\n");
	}
	
	seq3 = substring(seq1,2,3);
	printf("从第2个位置开始，长度为3的子串为：\n");
	printf("%s\n",seq3.str);
	
	seq4 = strconcat(seq1,seq2);
	printf("两串相连后的串为：\n");
	printf("%s\n",seq4.str);
	
	seq4 = strdelete(seq4,3,5);
	printf("从第3个位置开始删除5个元素后的顺序串为：\n");
	printf("%s\n",seq4.str);
	
	seq5 = strinsert(seq4,4,seq1);
	printf("在第4个位置插入第一个顺序串后的顺序串为：\n");
	printf("%s\n",seq5.str);
	
	seq5 = strcopy(seq2,seq1);
	printf("将第一个顺序串赋给第二个顺序串后：\n");
	printf("%s\n",seq5.str);
	
	return 0;
}
