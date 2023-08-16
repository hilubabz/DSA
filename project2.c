#include<stdio.h>
#include<conio.h>
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
Node *start=NULL;

Node *getnode()
{
    return((Node *)malloc(sizeof(Node)));
} 


void display(Node *start)
{
    Node *temp;
    temp=start;
    if(temp==NULL){
    	printf("No data in directory!\n");
    	getch();
    	return;
	}
    while(temp!=NULL)
    {
        printf("%s ",temp->firstname);
        printf("%s ",temp->lastname);
        printf("%d\n",temp->number);
        temp=temp->next;
    }
    getch();
}
void insert()
{
    Node *temp,*nn;
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

Node create()
{
    Node *temp,*nn;
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
    Node *temp;
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
    getch();
    break;
	}
    temp=temp->next;
}
printf("Data not found");
getch();
}
void del()
{
    Node *pretemp,*temp;
	char f[20],l[20];
    printf("Enter full name :");
    scanf("%s%s",&f,&l);
    temp=start;
	pretemp=start;
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
            getch();
            return;
        }
       
        pretemp=temp;
        temp=temp->next;
    }
    printf("Data not found!");
    getch();
}

void swap(char a[20], char b[20]) {
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void sort()
{
    struct node* temp, * pretemp;
    char p[20];
    temp = start;
  
    while (temp != NULL)
    {
    	pretemp = temp->next;
    	while(pretemp!=NULL){
		
        if (strcmp(temp->firstname, pretemp->firstname) > 0) {
            swap(temp->firstname, pretemp->firstname);
            swap(temp->lastname, pretemp->lastname);
            
        }
        else if (strcmp(temp->firstname, pretemp->firstname) == 0) {
            if (strcmp(temp->lastname, pretemp->lastname) > 0) {
                swap(temp->lastname, pretemp->lastname);
                
            }
        }

        
        pretemp = pretemp->next;
    }
    temp=temp->next;
    }
    getch();
}


int main()
{
    int ch;
    int op;
    do {
         system("CLS");
		printf("-------Welcome--------\n ");
        printf("1.Create\n2.Insert\n3.Display\n4.Delete\n5.Search\n6.Sort\n7.Exit\n");
       
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
            case 6:
            	sort();
            case 7:
            	printf("Exiting");
        }
    
           
        } while (ch!=7);
return 0;
}
