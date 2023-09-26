#include <bits/stdc++.h>
using namespace std;

int minComputation(int size, int files[]){
	// Create a min heap
	priority_queue<int, vector<int>, greater<int> > pq;

	for (int i = 0; i < size; i++) {
		// Add sizes to priorityQueue
		pq.push(files[i]);
	}
	// Variable to count total Computation
	int count = 0;
	while (pq.size() > 1) {
		// pop two smallest size element from the min heap
		int first_smallest = pq.top();
		pq.pop();
		int second_smallest = pq.top();
		pq.pop();

		int temp = first_smallest + second_smallest;

		// Add the current computations with the previous one's
		count += temp;

		// Add new combined file size to priority queue or min heap
		pq.push(temp);
	}
	return count;
}

int main(){
	int n = 6;
	int files[] = { 2, 3, 4, 5, 6, 7 };
	cout << "Minimum Computations = "
		<< minComputation(n, files);

	return 0;
}
