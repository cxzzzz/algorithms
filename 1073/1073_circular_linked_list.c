#include<stdio.h>
#include<malloc.h>
typedef struct node{

	int num;
	struct node * next;
}
NODE;


int main()
{
	NODE* head;
	int n,i,j,k,mod;
	scanf("%d",&n);
	scanf("%d",&mod);
	NODE* Next,* pre;

	for (i=0;i<n;i++){		
		Next=(NODE*)malloc(sizeof(NODE));
		Next->num=i;
		if(i==0){
			head=Next;
		}
		if(!i==0){
		pre->next=Next;
		}
		pre=Next;
	}
	pre->next=head;
	Next=pre;
	while(Next->next!=Next){
		for(i=0;i<mod-1;i++){
			Next=Next->next;
		}
		NODE *temp=Next->next->next;
		free(Next->next);
		Next->next=temp;
	}
	
	printf("%d",Next->num+1);
}
		

