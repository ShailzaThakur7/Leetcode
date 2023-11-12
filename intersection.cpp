#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
	vector<int> result;
	int i=0,j=0;
	n=arr1.size();
	m=arr2.size();
	while(i<n&&j<m){
		if(arr1[i]<arr2[j]){
			i++;
		}
		else if(arr1[i]>arr2[j]){
			j++;
		}
		else{
			result.push_back(arr2[j]);
			i++;
			j++;
		}
	}
	return result;
}