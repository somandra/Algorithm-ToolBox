#include<bits/stdc++.h>

using namespace std;

int lcs2(vector<int> &a, vector<int> &b) {

  int n = a.size(),m = b.size();
  int d[n+1][m+1];
  // for (int i = 0; i <=n; i++) cout<<a[i]<<" ";
  // cout<<"\n";
  // for (int j = 0; j <=m; j++) cout<<b[j]<<" ";
  // cout<<"\n";
  for (int i = 0; i <=n; i++)
  {
    for (int j = 0; j <=m; j++)
    {
      if(i==0) d[i][j] = 0;
      else if(j==0) d[i][j] = 0;
      else if(a[i-1] == b[j-1]){
        //cout<<"Match"<<"\n";
        d[i][j] = d[i-1][j-1]+1;
      }
      else if(a[i-1]!=b[j-1]){
        //cout<<"No match"<<"\n";
        d[i][j] = max(d[i][j-1],d[i-1][j]);
      }
    }
    
  }
  // for (int i = 0; i <=n; i++)
  // {
  //   for (int j = 0; j <=m; j++)
  //   {
  //     cout<<d[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  
  return d[n][m];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
