//using manacher 
#include<stdio.h>
#include<string.h>
int main()
{
	char temp[1001],a[2048];int p[2048];
	scanf("%s",temp);
	int len,i=0,j,k;
	len=strlen(temp);
	a[i++]='@';
	for(;i<len+1;i++)
	{
		a[2*i-1]='#';
		a[2*i]=temp[i-1];
	}
	a[2*i-1]='#';
	a[2*i]='$';
	len=strlen(a);
	int m_right=0,m_position;
	int max=0,max_position;
//	printf("%s",a);
	for(i=1;i<len-1;i++)
	{
		p[i]=(i>=m_right)?1:(i+p[2*m_position]<=m_right+1)?p[2*m_position+i]:m_right-i+1;
		while(a[i+p[i]]==a[i-p[i]])p[i]++;
		if(m_right<i+p[i])m_right=i+p[i]-1,m_position=i;
		max=(max>=p[i])?max:p[i];
	}
	printf("%d",(max*2-1)/2);
}
	
