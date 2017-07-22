#include<stdio.h>
#include<string.h>
int matrix(int (*A)[2],int (*B)[2],int (*C)[2])
{
	int tmp[2][2];
	tmp[0][0]=(A[0][0]*B[0][0]+A[0][1]*B[1][0])%7;
	tmp[0][1]=(A[0][0]*B[0][1]+A[0][1]*B[1][1])%7;
	tmp[1][0]=(A[1][0]*B[0][0]+A[1][1]*B[1][0])%7;
	tmp[1][1]=(A[1][0]*B[0][1]+A[1][1]*B[1][1])%7;
	memcpy(C,tmp,4*sizeof(int));
}
	

int main()
{
	int A,B,N;
	scanf("%d%d%d",&B,&A,&N);
	int res[2][2]={0,1,0,1};
	int tmp0[2][2]={0,1,A,B};
	
	int i;
	if(N==1)
	{
		printf("1\n");
		return 0;
	}
	else
		N=N-2;
	while(N)
	{
		if(N&1)
			matrix(tmp0,res,res);
		matrix(tmp0,tmp0,tmp0);
		N=N>>1;
	}

	printf("%d\n",(res[1][1]%7+7)%7);
	return 0;
}
