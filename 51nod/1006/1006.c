#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define LEN_MAX 1000
char chuan1[LEN_MAX],chuan2[LEN_MAX];
int len1,len2;

int xunhuan(int i,char **biao);
int main(){
	gets(chuan1);
	gets(chuan2);
	len1=strlen(chuan1);
	len2=strlen(chuan2);
	char **biao=(char **)malloc(sizeof(char*)*len2);
	int i;
	for(i=0;i<len2;i++){
		biao[i]=(char*)malloc(sizeof(char)*(len1+1));
		biao[i][0]='\0';
	}
	xunhuan(len1-1,biao);
	printf("%s\n",biao[len2-1]);
	
}

int length(char *biao){
	int len=0;
	while(biao[len++]!='\0');
	return len-1;
}
int copy(char *biao1,char *biao2){
	int length=0;
	while('\0'!=(biao2[length]=biao1[length]))
		length++;
}
int add(char a,char *biao){
	int len=length(biao);
	biao[len]=a;
	biao[len+1]='\0';
}

int xunhuan(int i,char  **biao){
	if(i>0)
		xunhuan(i-1,biao);
	int	max_without_i_k;
	int max_with_i_k;
	int j,k;

	
		for(k=len2-1;k>=0;k--)
		{
			max_without_i_k=length(biao[k]);
			for(j=k;j>=0;j--)
				if(chuan1[i]==chuan2[j])
					break;
			if(j>=1)
				max_with_i_k=length(biao[j-1])+1;
			else if(j==0)
				max_with_i_k=1;
			else
				max_with_i_k=0;
			if(max_without_i_k<max_with_i_k){
				if(j>0)
					copy(biao[j-1],biao[k]);
				add(chuan1[i],biao[k]);
			}
		}
	
}

