#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& v, int x){
	int lft = 0;
	int rgt = v.size()-1;
	while (lft<=rgt) {
		int mid=(lft+rgt)/2;
		if(v[mid]==x) 		return mid;
		else if(v[mid]<x)	lft=mid+1;
		else 				rgt=mid-1;
	}
	return -1;
}
//O(log n)
int binarySearchRecurrence(vector<int>& v,int strt,int end, int x){
	if (strt <= end) {
        int mid = strt + (end - strt) / 2;

        if (v[mid] == x)    return mid;
        else if (v[mid] < x)
            return binarySearchRecurrence(v, mid + 1, end, x);
        else
            return binarySearchRecurrence(v, strt, mid - 1, x);
    }
	return -1;
}

int main(){
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 69;

    int result1 = binarySearch(arr, target);
    int result2 = binarySearchRecurrence(arr,0,arr.size(), target);

    if (result2 != -1)
        cout << "Target " << target << " found at index " << result2 << endl;
    else
        cout << "Target " << target << " not found in the array" << endl;

	return 0;
}
