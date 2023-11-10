#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Find the k-th smallest element using QuickSelect
int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low == high)    return arr[low];

    int pivotIndex = partition(arr, low, high);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelect(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelect(arr, pivotIndex + 1, high, k);
    }
}

// Main function to find the median (or k-th smallest element)
int findMedian(vector<int>& arr, int k) {
    if (k < 0 || k >= arr.size()) {
        throw runtime_error("Invalid value of k");
    }

    return quickSelect(arr, 0, arr.size() - 1, k);
}

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

    int n=6;
    // cout << "Enter the number of elements: ";
    // cin >> n;

    // cout << "Enter the elements: ";
    // for (int i = 0; i < n; i++) {
    //     int num;
    //     cin >> num;
    //     arr.push_back(num);
    // }

    int k=0;
    // cout << "Enter the value of k (k-th smallest element): ";
    // cin >> k;

    int median = findMedian(arr, k);

    cout << "The " << k << "-th smallest element is: " << median << std::endl;

    return 0;
}