#include <bits/stdc++.h> 
using namespace std; 

using std::vector;

pair<int, long long> findEntryWithLargestValue( 
    map<int, long long> sampleMap) 
{ 

    pair<int, long long> entryWithMaxValue 
        = make_pair(0, 0); 
 
    map<int, long long>::iterator currentEntry; 
    for (currentEntry = sampleMap.begin(); 
         currentEntry != sampleMap.end(); 
         ++currentEntry) { 
  
        if (currentEntry->second 
            > entryWithMaxValue.second) { 
  
            entryWithMaxValue 
                = make_pair( 
                    currentEntry->first, 
                    currentEntry->second); 
        } 
    } 
  
    return entryWithMaxValue; 
} 

int solution(vector<int> &a, int left, int right){
  map<int, long long> result;

  for (int i = 0; i < right; ++i)
  {
    if(result.count(a[i])){
      result[a[i]]++;
    }
    else{
      result[a[i]] = 1;
    }
  }
  // map<int, long long>::iterator itr;
  // for (itr = result.begin(); itr != result.end(); ++itr) { 
  //       cout << '\t' << itr->first 
  //            << '\t' << itr->second << '\n'; 
  // }
  pair<int, long long> entryWithMaxValue 
        = findEntryWithLargestValue(result);
  if(entryWithMaxValue.second>right/2){
    //cout<<entryWithMaxValue.second<<"\n";
    return 1;
  } 
  else{
    return -1;
  }

}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  sort(a.begin(), a.end());
  //std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  std::cout << (solution(a, 0, a.size()) != -1) << '\n';
}
