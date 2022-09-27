#include <iostream>
using namespace std;
//class for node
class node{
    public:
      int data;
      node *next;
      node()
      {
          data=0;
          next=NULL;
      }
      node(int data)
      {
          this->data=data; 
          this->next=NULL;
      }
};
//class for linked list
class linkedlist
{
    node *head; 
    public:
       int length;
       linkedlist(){length=0;head=NULL;}
       void insert_begin(int data);
       void insert_end(int data);
       void insert_ind(int data,int pos);
       void delete_begin();
       void delete_end();
       void delete_ind(int ind);
       void search(int data);
       void max();
       void min();
       void traverse();
};
//insert_begin
void linkedlist::insert_begin(int data)
{
    node *newnode=new node(data);
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    length++;
}
//insert_end
void linkedlist::insert_end(int data)
{
    node *newnode=new node(data),*temp=head;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
    length++;
}
//insert_ind insert at index
void linkedlist::insert_ind(int data,int ind)
{
    node *newnode=new node(data),*temp=head;
    if(ind==0)
    {
        insert_begin(data);
    }
    else
    {
        for(int i=0;i<ind-1;i++)
        {
          temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    length++;
}
//delete_begin
void linkedlist::delete_begin()
{
    node *temp=head;
    if(head==NULL)
    {
     cout<<"Empty List"<<endl;
    }
    else
    {
        head=head->next;
        temp->next=NULL;
    }
    length--;
}
//delete_end
void linkedlist::delete_end()
{
    node *temp=head,*temp1;
    if(head==NULL)
    {
     cout<<"Empty List"<<endl;
    }
    else if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while(temp->next!=NULL)
        {
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
    }
    length--;
}
//delete_ind 
void linkedlist::delete_ind(int ind)
{
    node *temp=head;
    if(ind==0)
    {
        delete_begin();
    }
    else
    {
        for(int i=0;i<ind-1;i++)
        {
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
    length--;
}
//max element
void linkedlist::max()
{
    int max=head->data;
    node *temp=head->next;
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    while(temp!=NULL)
    {
        if(temp->data > max){max=temp->data;}
        temp=temp->next;
    }
    cout<<"max element:"<<max<<endl;
}
//min element
void linkedlist::min()
{
    int min=head->data;
    node *temp=head->next;
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    while(temp!=NULL)
    {
        if(temp->data < min){min=temp->data;}
        temp=temp->next;
    }
    cout<<"min element:"<<min<<endl;
}
//search
void linkedlist::search(int data)
{
    node *temp=head;
    int ind=0;
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"Key found at"<<ind;
        }
        ind++;
        temp=temp->next;
    }
    cout<<endl;
}
//traverse
void linkedlist::traverse()
{
    node *temp=head;
    if(head==NULL)
    {
        cout<<"Empty List";
    }
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    int ch,data,ind;
    linkedlist sll;
    cout<<"/*--------------------------------Single Linked List------------------------------------*/"<<endl;
    while(true)
    {
        cout<<"*********************************************"<<endl;
        cout<<"Enter Your Choice"<<endl;
        cout<<"1.insert_begin"<<endl;
        cout<<"2.insert_end"<<endl;
        cout<<"3.insert_ind"<<endl;
        cout<<"4.delete_begin"<<endl;
        cout<<"5.delete_end"<<endl;
        cout<<"6.delete_ind"<<endl;
        cout<<"7.search"<<endl;
        cout<<"8.max element"<<endl;
        cout<<"9.min element"<<endl;
        cout<<"10.traverse"<<endl;
        cout<<"----------------------------"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:cout<<"Enter data"<<endl;
                   cin>>data;
                   sll.insert_begin(data);
                   break;
            case 2:cout<<"Enter data"<<endl;
                   cin>>data;
                   sll.insert_end(data);
                   break;
            case 3:cout<<"Enter data & index"<<endl;
                   cin>>data>>ind;
                   sll.insert_ind(data,ind);
                   break;
            case 4:sll.delete_begin();
                   break;
            case 5:sll.delete_end();
                   break;
            case 6:cout<<"Enter index"<<endl;
                   cin>>ind;
                   sll.delete_ind(ind);
                   break;
            case 7:cout<<"Enter key to search"<<endl;
                   cin>>data;
                   sll.search(data);
                   break;
            case 8:sll.max();
                   break;
            case 9:sll.min();
                   break;
            case 10:sll.traverse();
                   break;
            default:exit(0);
        }
    }
}