#include <bits/stdc++.h>
using namespace std;

class MinMaxHeap {
private:
    vector<int> heap;

    int getParentIndex(int index) {
        return (index - 1) / 2;
    }

    int getGrandParentIndex(int index) {
        return getParentIndex(getParentIndex(index));
    }

    bool isMinLevel(int index) {
        int level = 0;
        while (index > 0) {
            index = getParentIndex(index);
            level++;
        }
        return level % 2 == 0;
    }

    bool isMaxLevel(int index) {
        return !isMinLevel(index);
    }

    bool isMinNode(int index) {
        if (isMinLevel(index)) {
            return true;
        } else {
            int grandParentIndex = getGrandParentIndex(index);
            if (grandParentIndex >= 0 && heap[index] > heap[grandParentIndex]) {
                return true;
            }
        }
        return false;
    }

    bool isMaxNode(int index) {
        if (isMaxLevel(index)) {
            return true;
        } else {
            int grandParentIndex = getGrandParentIndex(index);
            if (grandParentIndex >= 0 && heap[index] < heap[grandParentIndex]) {
                return true;
            }
        }
        return false;
    }

    void trickleUp(int index) {
        if (index == 0) {
            return; // Root node
        }

        if (isMinNode(index) && heap[index] < heap[getParentIndex(index)]) {
            swap(heap[index], heap[getParentIndex(index)]);
            trickleUpMin(getParentIndex(index));
        } else if (isMaxNode(index) && heap[index] > heap[getParentIndex(index)]) {
            swap(heap[index], heap[getParentIndex(index)]);
            trickleUpMax(getParentIndex(index));
        }
    }

    void trickleUpMin(int index) {
        if (index == 0) {
            return; // Root node
        }

        int grandParentIndex = getGrandParentIndex(index);
        if (heap[index] > heap[grandParentIndex]) {
            swap(heap[index], heap[grandParentIndex]);
            trickleUpMin(grandParentIndex);
        }
    }

    void trickleUpMax(int index) {
        if (index == 0) {
            return; // Root node
        }

        int grandParentIndex = getGrandParentIndex(index);
        if (heap[index] < heap[grandParentIndex]) {
            swap(heap[index], heap[grandParentIndex]);
            trickleUpMax(grandParentIndex);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        trickleUp(heap.size() - 1);
    }

    void display() {
        for (int i = 0; i < heap.size(); i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinMaxHeap heap;

    // Insert elements into the min-max heap
    heap.insert(10);
    heap.insert(5);
    heap.insert(15);
    heap.insert(2);
    heap.insert(20);

    // Display the min-max heap
    cout << "Min-Max Heap: ";
    heap.display();

    return 0;
}
