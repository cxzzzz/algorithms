#include<stdio.h>
#include<string.h>
int main()
{
	char str[1001];
	scanf("%s",str);
	int len=strlen(str);

	int a[len][len];
	int i,j,max=0;
	for(i=0;i<len;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(j==i)a[i][j]=1;
			else if(j+1==i && str[j]==str[i])a[i][j]=2;
			else if(j+1==i && str[j]!=str[i])a[i][j]=1;
			else
			{
				if(str[j]==str[i])a[i][j]=a[i-1][j+1]+2;
				else a[i][j]=a[i-1][j]>a[i][j+1]?a[i-1][j]:a[i][j+1];
			}
			max=max>a[i][j]?max:a[i][j];
		}
	}
//	printf("%d",max);
	printf("%d",len-max);
}



