#include<stdio.h>
#include<string.h>
int main(){
	char a[1024],b[1024];
	scanf("%s%s",a,b);

	int	len_a=strlen(a);
	int len_b=strlen(b);
	

	int max[1024][1024],max_chuan[1024];
	int i,j;
	for (i=0;i<=len_a;i++)
		max[i][0]=0;
	for (j=0;j<=len_a;j++)
		max[0][j]=0;

	for (i=1;i<=len_a;i++)
		for(j=1;j<=len_b;j++)
		{
			if(a[i-1]==b[j-1])
				max[i][j]=max[i-1][j-1]+1;
			else
				max[i][j]=(max[i-1][j]>max[i][j-1])?max[i-1][j]:max[i][j-1];
		}
	
	int len=0;
	i=len_a,j=len_b;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1])
			max_chuan[len++]=a[i-1],i--,j--;
		else 
		{
			if(max[i-1][j]>max[i][j-1])i--;
			else j--;
		}
	}
	for(i=len-1;i>=0;i--)
		printf("%c",max_chuan[i]);
}
		

			
