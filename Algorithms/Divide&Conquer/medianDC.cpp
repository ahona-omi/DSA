#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& arr, int left, int right) {
    // Choose a random pivot and move it to the rightmost position
    int randomIndex = left + rand() % (right - left + 1);
    swap(arr[randomIndex], arr[right]);

    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[right]);
    return i + 1;
}

int randomizedSelect(vector<int>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left];
    }

    int pivotIndex = partition(arr, left, right);
    int pivotRank = pivotIndex - left + 1;

    if (k == pivotRank) {
        return arr[pivotIndex];
    } else if (k < pivotRank) {
        return randomizedSelect(arr, left, pivotIndex - 1, k);
    } else {
        return randomizedSelect(arr, pivotIndex + 1, right, k - pivotRank);
    }
}

int findMedian(vector<int>& arr) {
    int n = arr.size();
    int k = (n + 1) / 2; // Median is the (n/2 + 1)th smallest element

    return randomizedSelect(arr, 0, n - 1, k);
}

int main() {
    srand(time(nullptr));
    
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int median = findMedian(arr);

    cout << "The median is: " << median << endl;

    return 0;
}
