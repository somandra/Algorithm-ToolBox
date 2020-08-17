#include <bits/stdc++.h> 
using namespace std; 


bool subsetSum(vector<int> &A, int n, int a, int b, int c)
{
	// return true if subset is found
	if (a == 0 && b == 0 && c == 0)
		return true;

	// base case: no items left
	if (n < 0)
		return false;

	// Case 1. current item becomes part of first subset
	bool A1 = false;
	if (a - A[n] >= 0)
		A1 = subsetSum(A, n - 1, a - A[n], b, c);

	// Case 2. current item becomes part of second subset
	bool B = false;
	if (!A1 && (b - A[n] >= 0))
		B = subsetSum(A, n - 1, a, b - A[n], c);

	// Case 3. current item becomes part of third subset
	bool C = false;
	if ((!A1 && !B) && (c - A[n] >= 0))
		C = subsetSum(A, n - 1, a, b, c - A[n]);

	// return true if we get solution
	return A1 || B || C;
}

int partition3(vector<int> &A) {
  int n = A.size();
  if(n<3) return 0;
  int s = accumulate(A.begin(), A.end(), 0);  
  return !(s%3) && subsetSum(A,n-1,s/3,s/3,s/3);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
  }
  std::cout << partition3(A) << '\n';
}
