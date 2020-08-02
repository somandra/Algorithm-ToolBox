#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {

    return ((long long)numbers[0])*numbers[1];
}

int main() {
    long long n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    sort(numbers.begin(),numbers.end(), greater<int>());
    long long result = MaxPairwiseProduct(numbers);
    std::cout << result << "\n";
    return 0;
}

