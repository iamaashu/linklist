#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*p;

void InsAtBeg(int num)
{
    struct node *temp;
    temp=new node;
    temp->data=num;
    if(p==NULL)
    {
        temp->next=NULL;
        p=temp;
    }
    else
    {
        temp->next=p;
        p=temp;
    }
}

void InsAtEnd(int num)
{
    struct node *temp,*r;
    temp=new node;
    temp->data=num;
    r=p;
    if(p==NULL)
    {
        temp->next=NULL;
        p=temp;
    }
    else
    {
        while(r->next!=NULL)
        {
            r=r->next;
        }
        temp->next=NULL;
        r->next=temp;
    }
}
void InsAfterPos(int num,int pos)
{
    struct node *temp,*r;
    temp=new node;
    temp->data=num;
    r=p;
    if(p==NULL)
    {
        temp->next=NULL;
        p=temp;
    }
    else
    {

        while(r->data!=pos)
        {
            r=r->next;
        }
        temp->next=r->next;
        r->next=temp;
    }
}

void DelAtBeg()
{
    struct node *r;
    r=p;
    if(r==NULL)
    {
        cout<<"\nLinked list is empty.";
        return;
    }
    else
    {
        p=r->next;
        delete(r);
    }
}

void DelAtEnd()
{
    node *ptr,*prev;
    if(p==NULL)
    {
        cout<<"\nLinked list is empty.";
    }
    else if(p->next==NULL)
    {
        ptr=p;
        p=NULL;
        delete(ptr);
    }
    else
    {
        ptr=p;
        while(ptr->next!=NULL)
        {
            prev=ptr;
            ptr=ptr->next;
        }
        prev->next=NULL;
        delete(ptr);
    }
}
/*not working*/
void delatpos(int num)
{
    struct node *r1,*r2;
    r1=p;
    r2=p->next;
    if(r1==NULL)
    {
        cout<<"\nLinked list is empty.";
        return;
    }
    else if(r2->data==num)
    {
        r1->next=r2->next;
        delete(r2);
        return;
    }
    else
    {
        while(r2->next!=NULL)
        {
            if(r2->next!=NULL)
            {
                r1->next=r2->next;
                delete(r2);
                return;
            }
            else
            {
                r1=r2;
                r2=r2->next;
            }
        }
    }
}

void SearchEle(int num)
{
    struct node *r;
    int flag=0;
    r=p;
    if(r==NULL)
    {
        cout<<"\nLinked list is empty.";
        return;
    }
    else
    {
        while(r!=NULL)
        {
            if(r->data==num)
            {
                flag=1;
                break;
            }
            else
            {
                r=r->next;
            }
        }
    }
    if(flag==1)
    {
        cout<<"\nElement is available in Linked list .";
    }
    else
    {
        cout<<"\nElement is not available in Linked list .";
    }
}

void display()
{
    node *temp=p;
    if(p==NULL)
    {
        cout<<"\nLinklist is empty...";
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
    }
}
int main()
{
    int choice,num,pos;;
    while(1)
    {
        cout<<"\nMenu:";
        cout<<"\n 1. Insertion at beginning ";
        cout<<"\n 2. Insertion at End ";
        cout<<"\n 3. Insertion at given position ";
        cout<<"\n 4. Deletion at beginning";
        cout<<"\n 5. Deletion at End";
        cout<<"\n 6. Deletion at given position";
        cout<<"\n 7. Enter Number to search : ";
        cout<<"\n 8. Display";
        cout<<"\n Enter Choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter Number:";
            cin>>num;
            InsAtBeg(num);
            break;

        case 2:
            cout<<"Enter Number:";
            cin>>num;
            InsAtEnd(num);
            break;

        case 3:
            cout<<"Enter Number:";
            cin>>num;
            cout<<"Enter Position:";
            cin>>pos;
            InsAfterPos(num,pos);
            break;

        case 4:
            DelAtBeg();
            break;

        case 5:
            DelAtEnd();
            break;

        case 6:
            cout<<"Enter the value u want to delete:";
            cin>>num;
            delatpos(num);
            break;

        case 7:
            cout<<"\nEnter Number to search : ";
            cin>>num;
            SearchEle(num);
            break;


        case 8:
            display();
            break;
        }
    }
}
