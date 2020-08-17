#include<bits/stdc++.h>
using std::vector;
using namespace std;

vector<int> compute_sequence(int n, vector<int> ops){
  vector<int> sequence;
  while (n>0)
  {
    sequence.push_back(n);
    if(n%2 != 0 && n%3 != 0){
      n = n-1;
    }
    else if(n%2 == 0 && n%3 == 0){
      n=n/3;
    }
    else if(n%2 == 0){
      if(ops[n-1]<ops[n/2]){
        n=n-1;
      }
      else{
        n=n/2;
      }
    }
    else if(n%3 == 0){
      if(ops[n-1]<ops[n/3]){
        n=n-1;
      }
      else{
        n=n/3;
      }
    }
  }
  reverse(sequence.begin(),sequence.end());
  return sequence;
  
} 

vector<int> min_ops(int n){
  vector<int> result(n+1);
  for (int i = 1; i < n+1; i++)
  {
    result[i] = 0;
  }
  
  for (int i = 2; i <= n; i++)
  {
    int min1 = i-1;
    int min2 = INT32_MAX;
    int min3 = INT32_MAX;
    if (i%2 == 0){
      min2 = result[i/2];
    }
    if(i%3 == 0){
      min3 = result[i/3];
    }
    result[i] = min(min(min1,min2),min3)+1;
  }
  return result;
  
}

vector<int> optimal_sequence(int n) {
  vector<int> ops(n);
  if(n==1){
    ops[0] = 1;
    return ops;
  }
  ops = min_ops(n);
  return compute_sequence(n,ops);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
