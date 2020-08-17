#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cout;


void printArray(std::vector<int> &a){
  for (int i = 0; i < a.size(); ++i)
  {
    cout<<a[i]<<" ";
  }
  cout<<"\n";
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  for (int i = l; i <=r; ++i)
  {
    std::cout<<a[i]<<" ";
  }
  std::cout<<"\n";
  return j;
}

/* This function partitions a[] in three parts 
   a) a[l..i] contains all elements smaller than pivot 
   b) a[i+1..j-1] contains all occurrences of pivot 
   c) a[j..r] contains all elements greater than pivot */
void partition3(vector<int> &a, int l, int r, int &i, int &j) 
{ 
    i = l-1, j = r; 
    int p = l-1, q = r; 
    int v = a[r];
    //printArray(a); 
  
    while (true) 
    { 
        // From left, find the first element greater than 
        // or equal to v. This loop will definitely terminate 
        // as v is last element
        while (a[++i] < v); 
  
        // From right, find the first element smaller than or 
        // equal to v 
        while (v < a[--j]) 
            if (j == l) 
                break; 
  
        // If i and j cross, then we are done 
        if (i >= j) break; 
  
        // Swap, so that smaller goes on left greater goes on right 
        swap(a[i], a[j]); 
        //printArray(a);
        // Move all same left occurrence of pivot to beginning of 
        // array and keep count using p 
        if (a[i] == v) 
        { 
            p++; 
            swap(a[p], a[i]);
            //printArray(a); 
        } 
  
        // Move all same right occurrence of pivot to end of array 
        // and keep count using q 
        if (a[j] == v) 
        { 
            q--; 
            swap(a[j], a[q]);
            //printArray(a); 
        }
    } 
  
    // Move pivot element to its correct index 
    swap(a[i], a[r]); 
  
    // Move all left same occurrences from beginning 
    // to adjacent to arr[i] 
    j = i-1; 
    for (int k = l; k < p; k++, j--){
      swap(a[k], a[j]); 
      //printArray(a);
    } 
  
    // Move all right same occurrences from end 
    // to adjacent to arr[i] 
    i = i+1; 
    for (int k = r-1; k > q; k--, i++){
      swap(a[i], a[k]);
      //printArray(a);
    }
    //printArray(a);
 
} 


void partition3_modified(vector<int> &a, int l, int r, int &i, int &j){
	int x = a[l];
	i = l+1;
	j = l;
	for (int k = l+1; k <= r  ; ++k)
	{
		if(a[k]<=x){
			j++;
			swap(a[k],a[j]);
			if(a[j]<x){
				swap(a[i],a[j]);
				i++;
			}
		}
		//printArray(a);
	}
	swap(a[l],a[i-1]);
}



void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
  int i,j;
  partition3_modified(a, l, r, i, j);

  randomized_quick_sort(a, l, i-1);
  randomized_quick_sort(a, j+1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
