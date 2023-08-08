#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    char firstname[20];
    char lastname[20];
    int number;
    struct node *next;
};
typedef struct node Node;
struct node *start=NULL;

struct node *getnode()
{
    return((struct node *)malloc(sizeof(struct node)));
} 


void display(struct node *start)
{
    struct node *temp;
    temp=start;
    if(temp==NULL){
    	printf("No data in directory!\n");
    	return;
	}
    while(temp!=NULL)
    {
        printf("%s ",temp->firstname);
        printf("%s ",temp->lastname);
        printf("%d\n",temp->number);
        temp=temp->next;
    }
}
/*void sort()
{
    struct node *temp,*pretemp;
    char *p;
    temp=start;
    pretemp=start->next;
    while(pretemp!=NULL)
    {
    if(strcmp(temp->lastname,pretemp->lastname)>0)
    {
        if(temp->lastname==pretemp->lastname)
        {
            if(strcmp(temp->firstname,pretemp->firstname)>0)
            {
                p=temp->firstname;
                temp->firstname=pretemp->firstname;
                pretemp->firstname=p;   
            }
        }
        else
        {
                p=temp->lastname;
                temp->lastname=pretemp->firstname;
                pretemp->firstname=p;
        }
    }
    }
}
*/
void insert()
{
    struct node *temp,*nn;
    nn=getnode();
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        
    }
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    temp->next=nn;
    nn->next=NULL;
    display(start);
}

struct node *create()
{
    struct node *temp,*nn;
    if(start!=NULL)
        insert();
    else
    {
    nn=getnode();
    start=nn;
    temp=start;
    printf("Enter First name:\n");
    scanf("%s",&nn->firstname);
    printf("Enter Last name:\n");
    scanf("%s",&nn->lastname);
    printf("Enter number:\n");
    scanf("%d",&nn->number);
    nn->next=NULL;
    display(start);
    }
}
void search()
{
    struct node *temp;
    char f[20],l[20];
    if(temp==NULL){
    	printf("No data in directory!\n");
    	return;
	}
    temp=start;
    printf("Enter name to be searched:\n");
    scanf("%s",&f);
    scanf("%s",&l);
while(temp!=NULL){
       
   if(strcmp(temp->firstname,f)==0 && strcmp(temp->lastname,l)==0){
   
    printf("%s ",temp->firstname);
    printf("%s ",temp->lastname);
    printf("%d\n",temp->number);
    break;
	}
    temp=temp->next;
}
printf("Data not found");
}
void del()
{
    Node *pretemp,*temp;
	char f[20],l[20];
    printf("Enter full name :");
    scanf("%s%s",&f),&l;
    temp=start;
	pretemp=temp;
    while(temp!=NULL)
    {
        if(strcmp(temp->firstname,f)==0 && strcmp(temp->lastname,l)==0)
        {
            printf("The data: ");
			printf("%s ",temp->firstname);
            printf("%s ",temp->lastname);
            printf("%d ",temp->number);
            printf("is deleted\n");
            pretemp->next=temp->next;
            free(temp);
            return;
        }
       
        pretemp=temp;
        temp=temp->next;
    }
    printf("Data not found!");
}

int main()
{
    int op,ch;
    do{
         system("CLS");
		printf("-------Welcome--------\n ");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n6.Sort\n");
       
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: create();
            break;
            case 2: insert();
            break;
            case 3: display(start);
            break;
            case 4: del();
            break;
            case 5:search();
            break;
            /*case 6:sort();
            break;*/
        }
        printf("Do you want to quit ? 1 for no / 0 for yes:");
        scanf("%d",&op);
    }while(op!=0);
return 0;
}
