#include<iostream>
using namespace std;
#include<unordered_map>
typedef long long ll;

void factor(unordered_map<ll, ll>& factors, ll number)
{
	ll n = number;
	while (n % 2 == 0)
	{
		factors[2]++;
		n /= 2;
	}

	for (ll i = 3; i * i < n; i += 2)
	{
		while (n % i == 0)
		{
			factors[i]++;
			n /= i;
		}
	}

	if (n > 2)
	{
		factors[n]++;
	}

}

int main()
{
	ll n = 0;
	cin >> n;
	unordered_map<ll, ll> factors;

	while (n--)
	{
		factors.clear();
		ll number, k;
		cin >> number >> k;
		factor(factors, number);

		ll num = 1;
		for (auto& e : factors)
		{
			if (e.second >= k)
			{
				num *= (ll)(pow(e.first, e.second));
			}
		}

		cout << num << endl;
	}


	return 0;
}