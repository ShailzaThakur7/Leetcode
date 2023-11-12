#include <iostream>
using namespace std;

int search(int n,int arr[],int key){
    int start=0;
    int i=0;
    int end=n-1;
    int mid=(start+end)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>=mid){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;        

    }
    return -1;

}
int main()
{
    int n,key;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>key;
    int index=search(n,arr,key);
    cout<<index<<endl;

    
return 0;
}