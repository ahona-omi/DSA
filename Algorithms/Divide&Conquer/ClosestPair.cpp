#include <bits/stdc++.h>
using namespace std;

class Point { 
	public:
	int x, y; 
}; 

int compareX(const void* a, const void* b) { 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->x - p2->x); 
} 

int compareY(const void* a, const void* b) { 
	Point *p1 = (Point *)a, *p2 = (Point *)b; 
	return (p1->y - p2->y); 
} 

float dist(Point p1, Point p2){ 
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
				(p1.y - p2.y)*(p1.y - p2.y) 
			); 
} 

float bruteForce(Point P[], int n) { 
	float min = FLT_MAX; 
	for (int i = 0; i < n; ++i) 
		for (int j = i+1; j < n; ++j) 
			if (dist(P[i], P[j]) < min) 
				min = dist(P[i], P[j]); 
	return min; 
} 

float min(float x, float y) 		{return (x < y)? x : y; } 

/* A utility function to find the 
distance between the closest points of 
strip of given size. All points in 
strip[] are sorted according to 
y coordinate. They all have an upper
bound on minimum distance as d. 
Note that this method seems to be 
a O(n^2) method, but it's a O(n) 
method as the inner loop runs at most 6 times */

float stripClosest(Point strip[], int size, float d) { 
	float min = d;

	qsort(strip, size, sizeof(Point), compareY); 

	for (int i = 0; i < size; ++i) 
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
			if (dist(strip[i],strip[j]) < min) 
				min = dist(strip[i], strip[j]); 

	return min; 
} 

float closestUtil(Point P[], int n) { 
	if (n <= 3) 	return bruteForce(P, n); 

	int mid = n/2; 
	Point midPoint = P[mid]; 

	float dl = closestUtil(P, mid); 
	float dr = closestUtil(P + mid, n - mid); 

	float d = min(dl, dr); 

	Point strip[n]; 
	int j = 0; 
	for (int i = 0; i < n; i++) 
		if (abs(P[i].x - midPoint.x) < d) 
			strip[j] = P[i], j++; 

	return min(d, stripClosest(strip, j, d) ); 
} 

float closest(Point P[], int n) { 
	qsort(P, n, sizeof(Point), compareX); 

	return closestUtil(P, n); 
}

void printPoint(Point P[], int n) {
	cout << "The smallest distance is " << closest(P, n) << endl;

    float minDistance = closest(P, n);
    cout << "The closest pair of points..." << endl;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dist(P[i], P[j]) == minDistance) {
                cout << "Point 1: (" << P[i].x << ", " << P[i].y << ")" << endl;
                cout << "Point 2: (" << P[j].x << ", " << P[j].y <<")" << endl;
            }
        }
    }
}
int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);

	printPoint(P,n);
    return 0;
}

/*
Time complexity of above algorithm be T(n). Let us assume that we use a O(nLogn) sorting algorithm. The above algorithm divides all points in two sets and recursively calls for two sets. After dividing, it finds the strip in O(n) time, sorts the strip in O(nLogn) time and finally finds the closest points in strip in O(n) time. So T(n) can expressed as follows 
T(n) = 2T(n/2) + O(n) + O(nLogn) + O(n) 
T(n) = 2T(n/2) + O(nLogn) 
T(n) = T(n x Logn x Logn)

Auxiliary Space: O(log n)
*/