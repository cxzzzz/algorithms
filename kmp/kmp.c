#include<stdio.h>
#include<string.h>
int kmp(char *A,char *B){
	int i,j,k;	
	int lenA=strlen(A);
	int lenB=strlen(B);
	int next[lenB+1];

	next [0]=-1;
	for(i=0;i<lenB-1;i++){
		k=i;
		while(k>=0&&B[next[k]+1]!=B[i+1])
			k=next[k];
		if(k>=0)
			next[i+1]=k+1;
		else
			next[i+1]=-1;
	}
/*	for(i=0;i<lenB;i++)
		printf("%d",next[i]);
		*/
	for(i=0,j=0;i<lenA&&j<lenB;i++,j++)
		if(A[i]!=B[j]){
			if(j<=0)
				j=-1;
			else{
			j=next[j-1];
			i--;
			}
		}
			
	if(j==lenB)return i-lenB;
	else
		return -1;
}




int main(){
	char A[100],B[100];
	int position;
	gets(A);
	gets(B);
	position=kmp(A,B);
	if(position>=0)
		printf("%d",position);
	else
		printf("there isn't substring in A");

	return 0;
}

	
