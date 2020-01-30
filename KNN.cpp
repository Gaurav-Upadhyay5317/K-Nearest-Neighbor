
#include <bits/stdc++.h> 
using namespace std; 

struct Point 
{ 
	int val;	 // Group of point 
	double x, y;	 // Co-ordinate of point 
	double distance; // Distance from test point 
}; 

bool comparison(Point a, Point b) 
{ 
	return (a.distance < b.distance); 
} 

int classifyAPoint(Point arr[], int n, int k, Point p) 
{ 
 
	for (int i = 0; i < n; i++) 
		arr[i].distance = 
			sqrt((arr[i].x - p.x) * (arr[i].x - p.x) + 
				(arr[i].y - p.y) * (arr[i].y - p.y)); 


	sort(arr, arr+n, comparison); 

	int freq1 = 0;	 // Frequency of group 0 
	int freq2 = 0;	 // Frequency of group 1 
	for (int i = 0; i < k; i++) 
	{ 
		if (arr[i].val == 0) 
			freq1++; 
		else if (arr[i].val == 1) 
			freq2++; 
	} 

	return (freq1 > freq2 ? 0 : 1); 
} 

 
int main() 
{ 
	int n = 17; // Number of data points 
	Point arr[n]; 

	arr[0].x = 2; 
	arr[0].y = 4; 
	arr[0].val = 0; 

	arr[1].x = 4; 
	arr[1].y = 2; 
	arr[1].val = 0; 

	arr[2].x = 6; 
	arr[2].y = 2; 
	arr[2].val = 1; 

	arr[3].x = 4; 
	arr[3].y = 4; 
	arr[3].val = 1; 

	arr[4].x = 6; 
	arr[4].y = 4; 
	arr[4].val = 0; 

	arr[5].x = 4; 
	arr[5].y = 6; 
	arr[5].val = 0; 


	/*Testing Point*/
	Point p; 
	p.x = 6; 
	p.y = 6; 

	// Parameter to decide group of the testing point 
	int k = 3; 
	printf ("The value classified to unknown point"
			" is %d.\n", classifyAPoint(arr, n, k, p)); 
	return 0; 
} 
