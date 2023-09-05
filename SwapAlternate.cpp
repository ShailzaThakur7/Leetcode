#include <iostream>

using namespace std;

// void swap(int a,int b){
//     int temp;
//     temp=a;
//     a=b;
//     b=temp;
// }
void SwapArr(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }

}
void printarr(int arr[],int n){
    cout<<"After Swapping"<<endl;
     for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Before Swapping"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    SwapArr(arr,n);
    printarr(arr,n);  


return 0;
}