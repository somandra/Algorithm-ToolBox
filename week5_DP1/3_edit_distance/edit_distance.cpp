#include<bits/stdc++.h>
using namespace std;

using std::string;

int edit_distance(const string &str1, const string &str2) {
  int n = str1.length(),m = str2.length();
  int d[n+1][m+1];

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= m; j++)
    {
      if(i==0) d[i][j] = j;
      else if(j==0) d[i][j] = i;
      else if (str1[i-1] == str2[j-1])
      {
        d[i][j] = d[i-1][j-1];
      }
      else{
        int insertion = d[i][j-1]+1;
        int deletion = d[i-1][j]+1;
        int mismatch = d[i-1][j-1]+1;
        d[i][j] = min(min(insertion,deletion),mismatch);
      }
      
    }
    
  }
  
    // for (int i = 0; i <= n; i++){
    //   for (int j = 0; j <= m; j++){
    //     cout<<d[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
  return d[n][m];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
