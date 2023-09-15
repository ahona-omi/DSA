/*the Nuts and Bolts Matching problem 
using randomized QuickSort*/

#include <bits/stdc++.h>
using namespace std;

// Compare function to compare a nut with a bolt
int compare(int nut, int bolt)
{
    if (nut < bolt)
        return -1;
    else if (nut > bolt)
        return 1;
    else
        return 0;
}

// Partition function for QuickSort
int partition(int arr[], int low, int high, int pivot)
{
    int i = low;
    int temp1, temp2;

    // Find the index of the pivot
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot) == -1) {
            temp1 = arr[i];
            arr[i] = arr[j];
            arr[j] = temp1;
            i++;
        } else if (compare(arr[j], pivot) == 0) {
            temp1 = arr[j];
        }
    }

    // Move the matching bolt to its position
    temp2 = arr[i];
    arr[i] = arr[high];
    arr[high] = temp2;

    // Return the partition index
    return i;
}

// Randomized QuickSort to match nuts and bolts
void matchNutsAndBolts(int nuts[], int bolts[], int low, int high)
{
    if (low < high) {
        // Choose a random bolt as pivot
        int pivot = bolts[low + rand() % (high - low + 1)];

        // Partition the nuts using the bolt as pivot
        int partitionIndex = partition(nuts, low, high, pivot);

        // Partition the bolts using the nut at partitionIndex as pivot
        partition(bolts, low, high, nuts[partitionIndex]);

        // Recursively match the remaining nuts and bolts
        matchNutsAndBolts(nuts, bolts, low, partitionIndex - 1);
        matchNutsAndBolts(nuts, bolts, partitionIndex + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int nuts[] = {5, 3, 8, 2, 7};
    int bolts[] = {2, 7, 5, 8, 3};
    int n = sizeof(nuts) / sizeof(nuts[0]);

    // Randomize the order of nuts and bolts
    for (int i = 0; i < n; i++) {
        int j = rand() % (i + 1);
        swap(nuts[i], nuts[j]);
        swap(bolts[i], bolts[j]);
    }

    // Match the nuts and bolts
    matchNutsAndBolts(nuts, bolts, 0, n - 1);

    // Print the matched nuts and bolts
    cout << "Matched nuts and bolts: " << endl;
    printArray(nuts, n);
    printArray(bolts, n);

    return 0;
}
