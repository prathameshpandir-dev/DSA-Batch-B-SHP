#include<iostream>
#include<set>
using namespace std;

int main() {
    int arr[100];
    int n;
    cin>>n;
    set<int> s;
    int i, j;
    int count;
     cout<<"enter the element:";
    for (i=0;i<n;i++){
      cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i])
    }

    for(auto a : s) {
        count=0;
        for(int i=0;i<n;i++)
        {
            if(a==arr[i])
        {
            count++;
        }
        }
        
        

        if(count>= 1) {
            cout << arr[i] << " duplicated " << count+1 << " times" << endl;
        }
    }

    return 0;
}
