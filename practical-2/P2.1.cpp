#include<iostream>
using namespace std;

int searchingg( string a[],string t,int n,int i=0)
{
    for(i=0;i<n;i++)
    {
        if(t==a[i])
        {
            return i;
        }

    }

return -1;
}
int main()
{
    int n;
    cout<<"Enter the no of cars avaliable in parking"<<endl;
    cin>>n;
    string ab[n],s;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Vehicle No"<<i+1<<":";
        cin>>ab[i];
        cin.ignore();
        cout<<endl;
    }
    cout<<"ENter the car to find :";
    cin>>s;
    cin.ignore();
    int no;
    cout<<"ENter the position at which the atchman stops"<<endl;
    cin>>no;



        int p=searchingg(ab,s,no);
        if(p==(-1))
        {
           cout<<"\n The car is at "<<searchingg(ab,s,n,no)<<"Position"<<endl;
        }
        else
            cout<<"\n The car is at "<<p<<"Position"<<endl;



}
