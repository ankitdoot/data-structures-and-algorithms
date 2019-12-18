#include<stdio.h>
#include<stdlib.h>
void deletel(void);
void append(void);
int listLength(void);
void display(void);
void find(int x);
struct listNode{
int data;
struct listNode *next;
        };
struct listNode*root;        
int main()
{
int b,x;

for(int i=0;i<10;i++)
{
append();
}
 b=listLength();
 printf("TOTAL NO. OF ELEMENTS IN LINKED LIST:%d \n",b);
display();
printf(" ENter value to find\n");
scanf("%d",&x);
find(x);
deletel();
printf("After deletion \n");
display();
return 0;
}
/*struct listNode *ptr =(struct listNode*)malloc(sizeof(struct listNode));
ptr->23;
next->NULL*/
  
int listLength(void)
{
int count =0;
struct listNode *current;
current=root;
while (current!=NULL)
{
count++;
current=current->next;
   }
return count;
   }

void append(void)
{   
struct listNode *temp;
temp=(struct listNode*)malloc(sizeof(struct listNode*));
printf("Enter value to instert\n");
scanf("%d",&temp->data);
temp->next= NULL;
if(root==NULL)
{
root=temp;
}
else
{
struct listNode*p;
p=root;
while(p->next != NULL )
{
p=p->next;
}
p->next=temp;
} 
}
void display(void)
{
struct listNode *current;
current=(struct listNode*)malloc(sizeof(struct listNode*));
current=root;
if(current==NULL)
{
printf("NO data here\n");
}
while (current!=NULL)
{
printf("%d\n",current->data);
current=current->next;
   }
   }
void find(int x)
{int flag=0;
struct listNode *temp=(struct listNode*)malloc(sizeof(struct listNode*));
temp=root;
while(temp!=NULL)
{
if(temp->data==x)
   {
flag++;
break;}
temp=temp->next;
}

     if(flag==0)
{printf("notFound\n");
}
else
{printf("found\n");
}
}
void deletel(void)
{
int loc;
struct listNode*temp=(struct listNode*)malloc(sizeof(struct listNode*));
printf("Enter location here\n");
scanf("%d",&loc);
if(loc>listLength())
{
printf("Enter valid location\n");
}
else if(loc==1)
{
temp=root;
root=temp->next;
temp->next=NULL;
}
    else 
{
struct listNode*p=root,*q;
int i=1; 
while(i<loc-1)
{
p=p->next;
   i++;
}
q=p->next;
p->next=q->next;
q->next=NULL;
free(q);

} 
}





