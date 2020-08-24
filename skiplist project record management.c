#include <string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#define levels 5

struct Node
{
    char data[50];
    struct Node *next[levels];
}  *start=NULL;

struct Node *middle=NULL;

struct newNode
{
    char new_data[50];
    struct newNode *next[1];
};

//inserting
void insert_index(int val)
{
    struct Node *temp, *ptr;
    temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data[1]=NULL;
    temp->data[0]= val;
    temp->next[0]= NULL;
    temp->next[1]= NULL;
    temp->next[2]= NULL;
    temp->next[3]= NULL;

    if(start==NULL)
        start=temp;
    else
    {
        ptr=start;
        while(ptr->next[0]!= NULL)
            ptr=ptr->next[0];
        ptr->next[0]=temp;
    }
}

int count=0;
//traversing
void traverse_list_level_0()
{
    struct Node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {
            //printf(" %c ->",ptr->data[0]);
            ptr=ptr->next[0];
            count++;
        }
    }
}

void skip_list_links_level_1()
{
    struct Node *ptr, *prev;
    ptr=start, prev=start;

    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            prev->next[1]=ptr;
            ptr->next[1]=NULL;
            prev=ptr;
            ptr=ptr->next[0];
        }
    }
}

void traverse_list_level_1()
{
    struct Node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {   printf(" %c ->",ptr->data[0]);
            ptr=ptr->next[1];
        }
    }
}

void skip_list_links_level_2()
{
    int n=count, c=0;

    int n1= 1;
    int n2= n/8;
    int n3= n/4;
    int n4= 3*n/8;
    int n5= n/2;
    int n6= 5*n/8;
    int n7= 3*n/4;
    int n8= 7*n/8;
    int n9= n;

    struct Node *ptr, *prev;
    ptr=start, prev=start;

    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            c++;

            if(c==n2 || c==n3 || c==n4 || c==n5 || c==n6 || c==n7 || c==n8 || c==n9 )
            {
                prev->next[2]=ptr;
                ptr->next[2]=NULL;
                prev=ptr;
            }
            ptr=ptr->next[0];
        }
    }
}

void traverse_list_level_2()
{
    struct Node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {   printf(" %c ->",ptr->data[0]);
            ptr=ptr->next[2];
        }
    }
}

void skip_list_links_level_3()
{
    int n=count, c=0;

    int n1=1;
    int n2=n/4;
    int n3=n/2;
    int n4=3*n/4;
    int n5=n;

    struct Node *ptr, *prev;
    ptr=start, prev=start;

    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            c++;

            if(c==n2 || c==n3 || c==n4 || c==n5 )
            {
                prev->next[3]=ptr;
                ptr->next[3]=NULL;
                prev=ptr;
            }
            ptr=ptr->next[0];
        }
    }
}

void traverse_list_level_3()
{
    struct Node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {   printf(" %c ->",ptr->data[0]);
            ptr=ptr->next[3];
        }
    }
}

void skip_list_links_level_4()
{
    int n=count, c=0;

    int n1=1;
    int n2=n/2;
    int n3=n;

    struct Node *ptr, *prev;
    ptr=start, prev=start;

    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        while(ptr!=NULL)
        {
            c++;

            if(c==n2 || c==n3 )
            {
                prev->next[4]=ptr;
                ptr->next[4]=NULL;
                prev=ptr;
            }
            ptr=ptr->next[0];
        }
    }
}

void traverse_list_level_4()
{
    struct Node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        while(ptr!=NULL)
        {   printf(" %c ->",ptr->data[0]);
            ptr=ptr->next[4];
        }
    }
}


void searching_index_display(int value)
{
    struct Node *ptr, *prev;
    prev=start, ptr=start;
    int curr_level=4, flag=0, no_of_iterations=0;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
        while(ptr!=NULL)
        {
            if(ptr->data[0] < value && curr_level==4)
            {
                prev=ptr;
                ptr=ptr->next[4];
            }
            if(ptr->data[0] == value && curr_level==4)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==4)
            {
                curr_level=3;
                ptr=prev;
            }


            if(ptr->data[0] < value && curr_level==3)
            {
                prev=ptr;
                ptr=ptr->next[3];
            }
            if(ptr->data[0] == value && curr_level==3)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==3)
            {
                curr_level=2;
                ptr=prev;
            }


            if(ptr->data[0] < value && curr_level==2)
            {
                prev=ptr;
                ptr=ptr->next[2];
            }
            if(ptr->data[0] == value && curr_level==2)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==2)
            {
                curr_level=1;
                ptr=prev;
            }


            if(ptr->data[0] < value && curr_level==1)
            {
                prev=ptr;
                ptr=ptr->next[1];
            }
            if(ptr->data[0] == value && curr_level==1)
            {
                prev=ptr;
                flag=1;
                break;
            }
            no_of_iterations++;
        }

    middle=prev;
    printf("\n no of iterations to find index %c :  %d\n",value,no_of_iterations);
    ptr=ptr->next[1];
    while(prev!=ptr)
    {
        printf(" %s-> ", prev->data);
        prev=prev->next[0];
    }
}

void insert_new_data(char new_project_0[])
{
    struct newNode *temp = (struct newNode *)malloc(sizeof(struct newNode));
    temp->next[0]=NULL;
    strcpy(temp->new_data,new_project_0);

    char str0=new_project_0[0];
    int str1=str0;
    int value=str1;

    if(value > 90)
        value-=32;

    struct Node *ptr, *prev;
    prev=start, ptr=start;
    int curr_level=4, flag=0, no_of_iterations=0;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
        while(ptr!=NULL)
        {
            if(ptr->data[0] < value && curr_level==4)
            {
                prev=ptr;
                ptr=ptr->next[4];
            }
            if(ptr->data[0] == value && curr_level==4)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==4)
            {
                curr_level=3;
                ptr=prev;
            }

            if(ptr->data[0] < value && curr_level==3)
            {
                prev=ptr;
                ptr=ptr->next[3];
            }
            if(ptr->data[0] == value && curr_level==3)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==3)
            {
                curr_level=2;
                ptr=prev;
            }

            if(ptr->data[0] < value && curr_level==2)
            {
                prev=ptr;
                ptr=ptr->next[2];
            }
            if(ptr->data[0] == value && curr_level==2)
            {
                prev=ptr;
                flag=1;
                break;
            }
            if(ptr->data[0] > value  && curr_level==2)
            {
                curr_level=1;
                ptr=prev;
            }

            if(ptr->data[0] < value && curr_level==1)
            {
                prev=ptr;
                ptr=ptr->next[1];
            }
            if(ptr->data[0] == value && curr_level==1)
            {
                prev=ptr;
                flag=1;
                break;
            }
            no_of_iterations++;
        }
    middle=prev;
    temp->next[0]= middle->next[0];
    middle->next[0]= temp;
}

void display_all_projects()
{
    struct Node *ptr, *a, *b;
    a = b = ptr = start;
    if(ptr==NULL)
        printf("\nlist is empty\n");
    else
    {
        printf("\n");
        int len;

        a=start;
        b=a->next[1];
        while(b!=NULL)
        {
            ptr=a;

            while(ptr!=b)
            {
                len=strlen(ptr->data);
                if(len<=2)
                    printf(" %c ->",ptr->data[0]);
                else
                    printf(" %s ->",ptr->data);
                ptr=ptr->next[0];
            }
            printf("\n");
            a=b;
            b=b->next[1];
        }
    }
}

void saved_projects()
{
    char new_project_1[50]="Blood Donation";
    insert_new_data(new_project_1);

    char new_project_2[50]="Duplichecker";
    insert_new_data(new_project_2);

    char new_project_3[50]="Library Management System";
    insert_new_data(new_project_3);

    char new_project_4[50]="Bank Management System";
    insert_new_data(new_project_4);

    char new_project_5[50]="Contact Management System";
    insert_new_data(new_project_5);

    char new_project_6[50]="Customer Billing System";
    insert_new_data(new_project_6);

    char new_project_7[50]="Employee Record System";
    insert_new_data(new_project_7);

    char new_project_8[50]="Hospital Management System";
    insert_new_data(new_project_8);

    char new_project_9[50]="Phonebook Application";
    insert_new_data(new_project_9);

    char new_project_10[50]="Bus Reservation System";
    insert_new_data(new_project_10);

    char new_project_11[50]="Railway Reservation System";
    insert_new_data(new_project_11);

    char new_project_12[50]="Student Database Management System";
    insert_new_data(new_project_12);

    char new_project_13[50]="Student Report Card System";
    insert_new_data(new_project_13);

    char new_project_14[50]="Airlines Reservation System";
    insert_new_data(new_project_14);

    char new_project_15[50]="ATM Banking System";
    insert_new_data(new_project_15);

    char new_project_16[50]="Movie Ticket Booking System";
    insert_new_data(new_project_16);

    char new_project_17[50]="Pharmacy Management System";
    insert_new_data(new_project_17);

    char new_project_18[50]="Train Reservation System";
    insert_new_data(new_project_18);

    char new_project_19[50]="Hospital Management System";
    insert_new_data(new_project_19);

    char new_project_20[50]="Restaurant billing System";
    insert_new_data(new_project_20);

    char new_project_21[50]="Kaun Banega Crorepati";
    insert_new_data(new_project_21);

}


int main()
{
    int i=1;

    // create skip list
    for(i=65; i<=90; i++)
        insert_index(i);

    traverse_list_level_0();

    skip_list_links_level_1();
    skip_list_links_level_2();
    skip_list_links_level_3();
    skip_list_links_level_4();

    saved_projects();

    char new_project_0[50];
    char value0;
    int value1;

    int choice;
    do{
        printf("\n------------------------------------------------------\n");
        printf("\n PROJECT RECORD AND DUPLICHECK SYSTEM ");
        printf("\n\n ( BASED ON SKIP LIST DATA STRUCTURE ) ");
        printf("\n\n\n **Choices** \n 0.exit \n 1.show levels \n 2.show saved projects all \n 3.show saved projects of particular index \n 4.enter new project \n 5.search project \n\n ");
        printf(" enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice)
        {
            case 0:
                break;

            case 1:
                printf("\n\nlevel 4 :  ");
                traverse_list_level_4();

                printf("\n\nlevel 3 :  ");
                traverse_list_level_3();

                printf("\n\nlevel 2 :  ");
                traverse_list_level_2();

                printf("\n\nlevel 1 :  ");
                traverse_list_level_1();
                break;

            case 2:
                display_all_projects();
                break;

            case 3:
                printf("\n\n enter index to be searched: ");
                scanf("%c",&value0);
                value1=value0;
                if(value1 > 90)
                    value1 -= 32;
                searching_index_display(value1);
                break;

            case 4:
                printf("\n\nenter new project name: ");
                gets(new_project_0);
                insert_new_data(new_project_0);
                printf("\n -> new project inserted successfully");
                break;

            case 5:
                break;
        }
        printf("\n");
        printf("\n------------------------------------------------------\n");
        printf("\n\n\n");

        printf(" 'press enter to continue' ");
        getchar();
        getchar();
        system("cls");

    }while(choice<6 && choice>0 && choice!=0);

    return 0;
}

