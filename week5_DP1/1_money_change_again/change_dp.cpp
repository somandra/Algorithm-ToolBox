#include <bits/stdc++.h>
using namespace std;

int get_change(int m) {
	int coins[] = {1,3,4};
	int MinNumCoins[m];
	MinNumCoins[0] = 0;
	for (size_t i = 1; i <=m ; i++)
	{
			MinNumCoins[i] = 100000;
			int num_coins=0;
			for (size_t j = 0; j < 3; j++)
			{
				if(i>=coins[j]){
					num_coins = MinNumCoins[i-coins[j]]+1;
				}
				if(num_coins<MinNumCoins[i]){
					MinNumCoins[i] = num_coins;
				} 
			
			}
		
	}
	// for (size_t i = 0; i < m; i++)
	// {
	// 	cout<<MinNumCoins[i]<<" ";
	// }
	
	return MinNumCoins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
