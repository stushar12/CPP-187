#include<bits/stdc++.h> 
using namespace std; 

bool isPossible(int arr[], int n, int students, int mid) 
{ 
	int studentsRequired = 1; 
	int pages = 0; 

	for (int i = 0; i < n; i++) 
	{ 
		if (arr[i] > mid) 
			return false; 

		if (pages + arr[i] > mid) 
		{ 
			studentsRequired++; 	
			pages = arr[i]; 

			if (studentsRequired > students) 
				return false; 
		}  
		else
			pages += arr[i]; 
	} 
	return true; 
} 

int findPages(int arr[], int n, int students) 
{ 
	long long sum = 0; 

	if (n < students) 
		return -1; 

	for (int i = 0; i < n; i++) 
		sum += arr[i]; 


	int lowerbound = 0, upperbound = sum; 
	int result = 0; 

	while (lowerbound <= upperbound) 
	{ 
		int mid = (lowerbound + upperbound) / 2; 
		if (isPossible(arr, n, students, mid)) 
		{ 
			result = mid; 
			upperbound = mid - 1; 
		} 
		else
			lowerbound = mid + 1; 
	} 
	return result; 
} 

int main() 
{ 
	//Number of pages in books 
	int arr[] = {12, 34, 67, 90}; 
	int n = sizeof arr / sizeof arr[0]; 
	int students = 2; 

	cout << "Minimum number of pages = "<< findPages(arr, n, students) << endl; 
}
