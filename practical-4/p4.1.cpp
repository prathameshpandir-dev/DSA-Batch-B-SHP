#include<iostream>
using namespace std;

class Node
{


public:
    int data;
    Node* link;

    Node(int data)
    {
        this->data=data;
        link=nullptr;
    }
};

class SLL
{
    Node* head;
public:

    SLL()
    {
        head=nullptr;
    }

void push_f(int x)
    {
        Node* temp=new Node(x);
        if(head==nullptr)
        {
            head=temp;
        }
        else
        {
            temp->link=head;
            head=temp;
        }
    }

void push_b(int x)
    {
        Node* temp = new Node(x);
        if(head==nullptr)
        {
            head=temp;

        }
        else if(head->link==nullptr)
        {
            head->link=temp;

        }
        else
        {
            Node* save=head;
            while(save->link!=nullptr)
            {
                save=save->link;
            }
            save->link=temp;
        }
    }
void insert_atpos(int pos,int x)
    {
       int c=0;
       Node* temp= new Node(x);
       Node* save=head;
       while(save!=nullptr)
       {
           c++;
           if((c+1)==pos)
           {
             Node* next=save->link;
             save->link=temp;
             temp->link=next;
           }
           save=save->link;
       }
       if(save==nullptr)
            cout<<"Invalid Position"<<endl;
    }

void delete_f()
{
    if(head==nullptr)
        cout<<"empty List"<<endl;
    else if(head->link==nullptr)
    {
         Node* temp=head;
         head=nullptr;
        delete temp;
    }
    else
    {
         Node* temp=head;
        head=head->link;
        temp->link==nullptr;
        delete temp;
    }
}

void delete_value(int val)
{
     if(head==nullptr)
        cout<<"empty List"<<endl;
    else if(head->link==nullptr)
    {
        if(head->data==val)
            {
            Node* temp=head;
            head=nullptr;
            delete temp;
            }
         else
         {
             cout<<"Not-found"<<endl;
         }
    }
    else
    {

         Node* temp=head;
         if(temp->data==val)
         {

            Node* temp=head;
            head=head->link;
            temp->link==nullptr;
            delete temp;
            return;
         }

         while(temp!=nullptr)
         {
             if(temp->link->data==val)
             {
                 Node* next=temp->link;
                 temp->link=next->link;
                 next->link=nullptr;
                 delete next;
                 break;

             }
             temp=temp->link;
         }
         if(temp==nullptr)
         {
             cout<<"Not-found"<<endl;
         }

    }

}
void print()
{
    Node* save=head;
    while(save!=nullptr)
    {
        cout<<save->data<<endl;
        save=save->link;
    }
}

void print_anypoint(int pos)
{
    int c=0;

        Node* save=head;
        while(save!=nullptr)
        {
            c++;
            if(c>=pos)
                cout<<save->data<<endl;
            save=save->link;
        }
        if(save==nullptr&&c<pos)
            cout<<"position not exist"<<endl;

}

    Node* getHead()
        {
            return head;
        }
};
void reverse_printing(Node* temp)
{
    if(temp==nullptr)
        return;
    reverse_printing(temp->link);
    cout<<temp->data<<endl;;

}
int main()
{
    SLL s;
    cout<<"-----Hospital Managment System------"<<endl;
     int choice;
    while(choice!=9)
    {
          int choice;
    cout<<"1-insert a patient from front\n2-insert a patient from back\n3-insert a patient at a position\n4-remove patient\n5-remove patient by id\n6-view the  remaining patient queue\n7-view remaing patient queue from a position\n8-Reverse printing\n9-exit\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
        {
            int id;
            cout<<"Enter patient id: ";
            cin>>id;
            s.push_f(id);
            cout<<"Patient inserted from front"<<endl;
            break;
        }
        case 2:
        {
            int id;
            cout<<"Enter patient id: ";
            cin>>id;
            s.push_b(id);
            cout<<"Patient inserted from back"<<endl;
            break;
        }
        case 3:
        {
            int pos,id;
            cout<<"Enter position: ";
            cin>>pos;
            cout<<"Enter patient id: ";
            cin>>id;
            s.insert_atpos(pos,id);
            break;
        }
        case 4:
        {
            s.delete_f();
            break;
        }
        case 5:
        {
            int id;
            cout<<"Enter patient id to remove: ";
            cin>>id;
            s.delete_value(id);
            break;
        }
        case 6:
        {
            cout<<"Remaining patient queue:"<<endl;
            s.print();
            break;
        }
        case 7:
        {
            int pos;
            cout<<"Enter position: ";
            cin>>pos;
            s.print_anypoint(pos);
            break;
        }
        case 8:
        {
            cout<<"Reverse patient queue:"<<endl;
            reverse_printing(s.getHead());
            break;
        }
        case 9:
        {
            cout<<"Exiting..."<<endl;
            return 0;
        }
        default:
        {
            cout<<"Invalid choice"<<endl;
        }
    }
    }
    return 0;
}
