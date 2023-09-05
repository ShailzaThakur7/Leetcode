#include <iostream>
using namespace std;
int find(int arr[],int m){
    int ans=0;
    for (int i = 0; i < m; i++)
    {
        /* code */
        ans=ans^arr[i];
    }
    return ans;
    


}
int main()
{
    int m;
    cin>>m;
    int arr[2*m+1];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    find(arr,m);

return 0;
}