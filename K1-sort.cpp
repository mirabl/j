/*
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sort(vector<int>& A) {
	int n = int(A.size());
	for (int i = 0; i < n - 1; ++i) {
		int min_i = i;
		for (int j = i + 1; j < n; ++j) {
			if (A[j] < A[min_i]) {
				min_i = j;
			}
		}
		swap(A[i], A[min_i]);
	}
}

void insertion_sort(vector<int>& A) {
	int n = int(A.size());
	for (int i = 1; i < n; i++) {
		// insert A[i] in A[0]...A[i-1]
		int j = 0;
		while (j < i && A[j] < A[i]) {
			j++;
		}
		int tmp = A[i];
		// insert A[i] at position j and shift A[j]...A[i - 1] to A[j + 1]...A[i]
		for (int k = i; k > j; k--) {
			A[k] = A[k - 1];
		}
		A[j] = tmp;
	}
}



/* BEGIN */

/*
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(vector<int>& A) {
}

void insertion_sort(vector<int>& A) {
}
*/


void print_vector(const vector<int>& v) {
        for (int i = 0; i < (int)v.size(); ++i) {
                cout << v[i] << " ";
        }
}

bool is_sorted(vector<int>& A) {
	for (int i = 0; i < int(A.size()) - 1; i++) {
		if (A[i] > A[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));

	int n = 15;
	vector<int> A;
	for (int i = 0; i < n; ++i) {
		A.push_back(i + 1);
	}

	random_shuffle(A.begin(), A.end());
	print_vector(A);
	cout << "   (*)" << endl;
	
	random_shuffle(A.begin(), A.end());
	selection_sort(A);
	print_vector(A);
	cout << " " << (is_sorted(A) ? "OK" : "NOK") << endl;
	cout << endl;

	random_shuffle(A.begin(), A.end());
	insertion_sort(A);
	print_vector(A);
	cout << " " << (is_sorted(A) ? "OK" : "NOK") << endl;
	cout << endl;


	cout << "-----------" << endl;
}

/* END */




/*


void bubble_sort(vector<int>& A) {
	int n = int(A.size());
	for (int i = n - 1; i > 0; i--) {
		// Put the max of A[0]...A[i] in A[i]
		for (int j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				swap(A[j], A[j + 1]);
			}
		}
	}
}

void merge_sort_rec(vector<int>& A, int lo, int hi, vector<int>& B) {
	if (lo >= hi) {
		return;
	}
	int mid = lo + (hi - lo) / 2;
	merge_sort_rec(A, lo, mid, B);
	merge_sort_rec(A, mid + 1, hi, B);
	int i = lo;
	int j = mid + 1;
	int k = lo;
	while (i < mid + 1 || j < hi + 1) {
		if (j == hi + 1 || (i < mid + 1 && A[i] < A[j])) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	for (k = lo; k < hi + 1; k++) {
		A[k] = B[k];
	}
}

void merge_sort(vector<int>& A) {
	int n = int(A.size());
	vector<int> B(n);
	merge_sort_rec(A, 0, n - 1, B);
}

void quick_sort_rec(vector<int>& A, int lo, int hi) {
	if (lo >= hi) {
		return;
	}
	int pivot = A[hi];
	int i = lo;
	for (int j = lo; j < hi; j++) {
		if (A[j] <= pivot) {
			swap(A[i], A[j]);
			i++;
		}
	}
	swap(A[i], A[hi]);

	quick_sort_rec(A, lo, i - 1);
	quick_sort_rec(A, i + 1, hi);
}

void quick_sort(vector<int>& A) {
	// assume random order.
	quick_sort_rec(A, 0, int(A.size()) - 1);
}

*/

/*

	random_shuffle(A.begin(), A.end());
	merge_sort(A);
	print_vector(A);
	cout << " " << (is_sorted(A) ? "OK" : "NOK") << endl;
	cout << endl;

	random_shuffle(A.begin(), A.end());
	quick_sort(A);
	print_vector(A);
	cout << " " << (is_sorted(A) ? "OK" : "NOK") << endl;
	cout << endl;
*/

/*
void selection_sort(vector<int>& A) {
	int n = A.size();
	for (int i = n - 1; i > 0; i--) {
		int k = 0;
		for (int j = 0; j <= i; j++) {
			if (A[j] > A[k]) {
				k = j;
			}
		}
		swap(A[i], A[k]);
	}
}

void insertion_sort(vector<int>& A) {
	int n = A.size();
	// insert A[i] in sorted A[0]..A[i - 1]
	for (int i = 1; i < n; i++) {
		int k = 0;
		while (A[i] > A[k]) {
			k++;
		}
		// insert before A[k]
		int tmp = A[i];
		for (int j = i; j > k; j--) {
			A[j] = A[j - 1];
		}
		A[k] = tmp;
	}
}

void selection_sort(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n - 1; i++) {
		int k = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}
		swap(A[i], A[k]);
	}
}

void insertion_sort(vector<int>& A) {
	int n = A.size();
	// insert A[i] in A[0]..A[i-1]
	for (int i = 0; i < n; i++) {
		int j = 0;
		while (A[i] > A[j]) {
			j++;
		}
		int next = A[i];
		while (j <= i) {
			swap(A[j], next);
			j++;
		}
	}
}


*/
	

	/*
void selection_sort(vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n - 1; i++) {
		int j_min = i;
		for (int j = i + 1; j < n; j++) {
			if (A[j] < A[j_min]) {
				j_min = j;
			}
		}
		swap(A[i], A[j_min]);
	}
}

void insertion_sort(vector<int>& A) {
	int n = A.size();
	for (int i = 1; i < n; i++) {
		int j = 0;
		while (A[j] < A[i] && j < i) {
			j++;
		}
		int tmp = A[i];
		for (int k = i; k > j; k--) {
			A[k] = A[k - 1];
		}
		A[j] = tmp;
	}
}

*/