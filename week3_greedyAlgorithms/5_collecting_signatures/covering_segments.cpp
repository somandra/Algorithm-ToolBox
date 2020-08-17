#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using namespace std;

struct Segment {
  int start, end;
};

bool cmp(Segment& v1,Segment& v2){
	return v1.end < v2.end; 
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  sort(segments.begin(), segments.end(),cmp);
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    // points.push_back(segments[i].start);
    // points.push_back(segments[i].end);
  	//cout<<segments[i].start<<" "<<segments[i].end<<"\n";
  	int j=0;
  	for (j = i+1; j < segments.size(); ++j)
  	{
  		if (segments[j].start<= segments[i].end)
  		{
  			//cout<<i<<" "<<j<<"\n";
  			continue;
  		}
  		else{
  			break;
  		}
  	}
  	points.push_back(segments[i].end);
  	i = j-1;

  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
