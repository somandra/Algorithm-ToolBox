#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using std::vector;

bool sortcol( const vector<double>& v1, 
               const vector<double>& v2 ) { 
 return v1[0] > v2[0]; 
} 

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int i = 0,j=0,k=0,n = weights.size();
  int index[n] = {0};
  vector<vector<double>> A(n);
  for (int j = 0; j < n; ++j)
  {
    A[j].push_back((double)values[j]/weights[j]);
    A[j].push_back(j);
    index[k++] = j;
  }
  sort(A.begin(), A.end(), sortcol);
  k=0;
  for (int j = 0; j < n; ++j)
  {
  	//cout<<A[j][0]<<" "<<A[j][1]<<"\n";
  	index[k] = A[j][1];
  	//cout<<index[k]<<"\n";
  	k++;
  }

  //j=0;
  k=0;
  while(i<n){
    if (capacity==0)
    {
      return value;
    }
    j=0;
    while(j<n & weights[index[j]]>0){
      int a = min(weights[index[j]], capacity);
      value += (double)a*A[j][0];
      weights[index[j]]= weights[index[j]]-a;
      capacity-=a;
      //cout<<a<<" "<<value<<" "<<weights[index[j]]<<" "<<capacity<<"\n";
	    if (capacity==0)
	    {
	      return value;
	    }
      j++; 
    }
     i++;
  }

  return value;
}
  


int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);
  cout << optimal_value << std::endl;
  return 0; 
}
