#include <bits/stdc++.h>
using namespace std;

void Swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void merge2Heaps(int merged[], int a[], int b[], int N, int M){
    // Copy elements of both heaps into the merged array
    for (int i = 0; i < N; i++){
        merged[i] = a[i];
    }
    for (int i = 0; i < M; i++){
        merged[N + i] = b[i];
    }

    // Perform heapify operation on the merged array to maintain the Min Heap property
    for (int i = (N + M) / 2 - 1; i >= 0; i--){
        int current = i;
        while (true){
            int leftChild = 2 * current + 1;
            int rightChild = 2 * current + 2;
            int smallest = current;

            if (leftChild < N + M && merged[leftChild] < merged[smallest]){
                smallest = leftChild;
            }
            if (rightChild < N + M && merged[rightChild] < merged[smallest]){
                smallest = rightChild;
            }

            if (smallest != current){
                Swap(&merged[current], &merged[smallest]);
                current = smallest;
            }
            else    break;
        }
    }
}
void print(int arr[], int n){
    cout << "Binary Heap: ";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insert(int arr[], int &size, int key){
    int childIn = size;
    arr[childIn] = key;
    while (childIn > 0){
        int parentIn = (childIn - 1) / 2;
        if (arr[childIn] < arr[parentIn]){
            Swap(&arr[childIn], &arr[parentIn]);
            childIn = parentIn;
        }
        else    break;
    }
    size++;
}

void heapify(int arr[], int n, int i){
    if (i >= n || i < 0)    return;
    int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest])
        smallest = l;
    if (r < n && arr[r] < arr[smallest])
        smallest = r;
    if (smallest != i){
        Swap(&arr[i], &arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void heapSort(int arr[], int n){
    // Build Min Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Delete
    for (int i = n - 1; i > 0; i--){
        Swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
int extractMin(int arr[], int &size){
    if (size <= 0){
        cout << "Heap is empty." << endl;
        return -1; // Return a sentinel value to indicate an empty heap.
    }

    int minVal = arr[0];
    arr[0] = arr[size - 1];
    size--;

    // Heapify to maintain the Min Heap property.
    int i = 0;
    while (true){
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < size && arr[leftChild] < arr[smallest])
            smallest = leftChild;
        if (rightChild < size && arr[rightChild] < arr[smallest])
            smallest = rightChild;

        if (smallest != i){
            Swap(&arr[i], &arr[smallest]);
            i = smallest;
        }
        else    break;
    }
    return minVal;
}

int getMin(int arr[], int size){
    if (size <= 0){
        cout << "Heap is empty." << endl;
        return -1; // Return a sentinel value to indicate an empty heap.
    }
    return arr[0];
}

void decreaseKey(int arr[], int size, int index, int newValue){
    if (index < 0 || index >= size){
        cout << "Invalid index." << endl;
        return;
    }
    if (newValue >= arr[index]){
        cout << "New value is not smaller than the current value." << endl;
        return;
    }

    arr[index] = newValue;
    while (index > 0){
        int parentIndex = (index - 1) / 2;
        if (arr[index] < arr[parentIndex]){
            Swap(&arr[index], &arr[parentIndex]);
            index = parentIndex;
        }
        else    break;
    }
}

int main(){
    int n = 5, m = 3, l, mrg[n + m], x = 0, y;
    int a[n] = {10, 20, 15, 30, 40};
    int b[m] = {12, 7, 9};

    for (int i = 0; i < n; i++)
        insert(a, x, a[i]);

    insert(a, n, 69);
    print(a, n);

    int minVal = extractMin(a, n);
    cout << "Extracted Min Value: " << minVal << endl;
    print(a, n);

    int minValue = getMin(a, n);
    cout << "Minimum Value in the Heap: " << minValue << endl;

    decreaseKey(a, n, 3, 5);
    print(a, n);

    heapSort(a, n);
    print(a, n);

    merge2Heaps(mrg, a, b, n, m);
    print(mrg, n + m);

    return 0;
}
