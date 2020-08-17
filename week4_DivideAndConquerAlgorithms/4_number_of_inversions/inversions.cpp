#include <iostream>
#include <vector>

using namespace std;

long long _mergeSort(vector<int> a, int temp[], int left, int right); 
long long merge(vector<int> a, int temp[], int left, int mid, int right); 
  


long long mergeSort(vector<int> &a, int a_size) 
{ 
    int* temp = (int*)malloc(sizeof(int) * a_size); 
    return _mergeSort(a, temp, 0, a_size - 1); 
} 
  

long long _mergeSort(vector<int> a, int temp[], int left, int right) 
{ 
    int mid, inv_count = 0; 
    if (right > left) { 

        mid = (right + left) / 2; 
  

        inv_count += _mergeSort(a, temp, left, mid); 
        inv_count += _mergeSort(a, temp, mid + 1, right); 
 
        inv_count += merge(a, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  

long long merge(vector<int> a, int temp[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int inv_count = 0; 
  
    i = left; 
    j = mid; 
    k = left; 
    while ((i <= mid - 1) && (j <= right)) { 
        if (a[i] <= a[j]) { 
            temp[k++] = a[i++]; 
        } 
        else { 
            temp[k++] = a[j++]; 
  
            
            inv_count = inv_count + (mid - i); 
        } 
    } 
  
   
    while (i <= mid - 1) 
        temp[k++] = a[i++]; 
  

    while (j <= right) 
        temp[k++] = a[j++]; 
  

    for (i = left; i <= right; i++) 
        a[i] = temp[i]; 
  
    return inv_count; 
} 


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  //vector<int> b(a.size());
  //std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  std::cout<<mergeSort(a,a.size())<<"\n";
}
