#include<iostream>
using namespace std;

void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

void bubblsort(int a[],int n)
{
    for(int i=0;i<(n-1);i++)
    {
        for(int j=0;j<(n-1);j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
        printarray(a,n);
}

void selectionsort (int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int sindex=i;

            for(int j=i+1;j<n;j++)
            {
                if(a[j]<a[sindex])
                    sindex=j;
            }
            swap(a[i],a[sindex]);
    }
    printarray(a,n);
}
void insertionsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
                j--;

        }
        a[j+1]=temp;
    }
    printarray(a,n);
}

int main()
{
    int no;
    cout<<"ENTER the no of elements for sorting"<<endl;
    cin>>no;


    int arr[no];
    for(int i=0;i<no;i++)
    {
        cin>>arr[i];
    }
    int n=sizeof(arr)/sizeof(arr[0]);
    int c;


    while(c!=4)

    {
        cout<<"\n 1-Selection sort \n 2- bubble sort \n 3-insertion sort \n 4-exit "<<endl;
    cin>>c;
        switch(c)
        {
            case 1: selectionsort(arr,n);
                        break;

            case 2: bubblsort(arr,n);
                        break;

            case 3: insertionsort(arr,n);
                        break;
            case 4 : cout<<"Exiting.....";

            default: cout<<"Invalid Entry"<<endl;
        }

    }




    return 0;
}
