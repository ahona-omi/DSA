//give a c++ algorithm to find all nodes less than some value x in a binary max heap(DFS)

#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS on the binary max heap
void dfsMaxHeap(vector<int>& heap, int currentIdx, int x) {
    // Base case: If the current index exceeds the heap size or the node value is greater than or equal to x, return
    if (currentIdx >= heap.size() || heap[currentIdx] >= x) {
        return;
    }

    // Print the node value as it is less than x
    cout << heap[currentIdx] << " ";

    // Recursively visit the left and right child nodes
    dfsMaxHeap(heap, 2 * currentIdx + 1, x);
    dfsMaxHeap(heap, 2 * currentIdx + 2, x);
}

// Function to find all nodes less than x in a binary max heap
void findNodesLessThanX(vector<int>& heap, int x) {
    cout << "Nodes less than " << x << ": ";
    dfsMaxHeap(heap, 0, x);
    cout << endl;
}

int main() {
    // Example usage
    vector<int> heap = {90, 85, 80, 70, 75, 65, 50, 45, 60};
    int x = 80;

    findNodesLessThanX(heap, x);

    return 0;
}
