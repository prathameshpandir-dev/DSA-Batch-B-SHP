#include<iostream>
#include<algorithm>
using namespace std;

int binarry(auto ab[],auto t,int n)
{
    int s=0,e=n-1;

    while(s<=e)
    {
        int m=(s+e)/2;

        if(t==ab[m])
            return m;
        else if(t>ab[m])
        {
            s=m+1;

        }
        else if(t<ab[m])
        {
            e=m-1;
        }

    }
return -1;
}


int main()
{
    int no;
    cout<<"Enter no of elements"<<endl;
    cin>>no;
    int arr[no];
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }
   sort(arr,arr+no);
   int target;
   cout<<"Enter the target :";
   cin>>target;
   cout<<endl;


    int p=binarry(arr,target,no) ;

    if(p<0)
        cout<<"element not found !!!!"<<endl;
    else
        cout<<"The position of element in the array : "<<p<<endl;

}
