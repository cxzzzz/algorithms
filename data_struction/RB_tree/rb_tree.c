#include<stdio.h>
#include<malloc.h>
typedef struct node{
	struct node* p;//parent
	struct node* l;//left son
	struct node* r;//right son
	int value;//value
	char color;//'r' is red,'b' is black
}NODE;
NODE NIL={NULL,NULL,NULL,0,'b'},
     *root_t;

NODE* search(NODE * root,int value)
{	
	NODE* position=NULL;
	while(root!=&NIL)
	{
		if( root->value== value)
		{
			position=root;
			break;
		}
		else if(root->value<value)
			root=root->r;
		else
			root=root->l;
	}
	return position;
}

int left_rotate(NODE* top)//top node
{
	NODE* topp=top;
	if (top->p->r==top){
		top->p->r=top->r;
		top->r->p=top->p;
		top->r=top->p->r->l;
		top->r->p=top;
		top->p->r->l=top;
		top->p=top->p->r;


	if (topp==root_t)
		root_t=top->p;
	}
	else
	{
		top->p->l=top->r;
		top->r->p=top->p;
		top->r=top->p->l->l;
		top->r->p=top;
		top->p->l->l=top;
		top->p=top->p->l;

	if (topp==root_t)
		root_t=top->p;
	}
}

int right_rotate(NODE* top)//top node
{
	NODE* topp=top;
	if (top->p->r==top){
		top->p->r=top->l;
		top->l->p=top->p;
		top->l=top->p->r->r;
		top->l->p=top;
		top->p->r->r=top;
		top->p=top->p->r;

	if (topp==root_t)
		root_t=top->p;
	
	}
	else
	{
		top->p->l=top->l;
		top->l->p=top->p;
		top->l=top->p->l->r;
		top->l->p=top;
		top->p->l->r=top;
		top->p=top->p->r;
	if (topp==root_t)
		root_t=top->p;
	
	}
}

int insert_fix(NODE* new)// node* new refer to the last node inserted;
{
	if(new->p==&NIL)
		return 0;

	while(new->p->color=='r')
	{
		if(new->p->p->l->color=='r'&&new->p->p->r->color=='r')
		{
			new->p->p->color='r';
			new->p->p->l->color=new->p->p->r->color='b';
			new=new->p->p;
		}
		else if(new->p==new->p->p->l)
		{
			if(new==new->p->r){
				new=new->p;
				left_rotate(new);
			}
			new->p->color='b';
			new->p->p->color='r';
			new=new->p->p;
			right_rotate(new);
			break;
		}
		else
		{
			if(new==new->p->l)
			{
				new=new->p;
				right_rotate(new);
			}
			new->p->color='b';
			new->p->p->color='r';
			new=new->p->p;
			left_rotate(new);
			break;
		}
	}
}





int insert(NODE* root,int value){
	NODE* new=NULL;
	if(NULL==(new=(NODE*)malloc(sizeof(NODE))))
	return -1;

	new->color='r';
	new->value=value;
	new->l=&NIL;
	new->r=&NIL;
	new->p=&NIL;
	if (root==NULL){
		root=new;
		root->value=value;
		root->color='b';
		root->p->l=root;
		root_t=root;
		return 0;
	}

		
	while(new->p==&NIL)
	{
		if(root->value<value)
			if(root->r==&NIL){
				root->r=new;
				new->p=root;
			}
			else 	root=root->r;
			
		else
			if(root->l==&NIL){
				root->l=new;
				new->p=root;
			}		
			else	root=root->l;
			

	}
	insert_fix(new);
}


int ergodic(NODE* root)
{	
	if(root!=&NIL){

		ergodic(root->l);
		printf("%d",root->value);
		ergodic(root->r);
	}
	return 0;
}

int main(){
	int value;
	char a;
	while(1)
	if('i'==(a=getchar()))
	{ scanf("%d",&value);
		insert(root_t,value);
	}	
	else if('s'==a)
	{ scanf("%d",&value);
		if(NULL!=search(root_t,value))
			puts("in");
		else
			puts("not in");
	}
	else if('a'==a)
	{ 
		ergodic(root_t);
	}
}
