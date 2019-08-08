#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define Fastest ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define SIZE 1000005

char sieve[SIZE];
vector<int>prime;

void primeSieve()
{
	sieve[0] = 1;
	sieve[1] = 1;
	for(int i = 4; i <= 1000000; i+=2) sieve[i] = 1;
	int len = sqrt(1000000);
	for(int i = 3; i <= len; i+=2)
	{
		if(sieve[i] == 0)
		{
			for(int j = i*i; j <= 1000000; j += 2*i)
			{
				sieve[j] = 1;
			}
		}
	}
	prime.push_back(2);
	for(int i = 3; i <= 1000000; i+=2)
	{
		if(sieve[i] == 0) prime.push_back(i);
	}
}

void div(int n)
{
    int len = sqrt(n),total = n;
    for(int i = 0; i < prime.size() && prime[i] <= len; i++)
    {
		if(sieve[n] == 0) break;
		if(n%prime[i] == 0)
		{
			while(n%prime[i] == 0)
			{
				n /= prime[i];
			}
			len = sqrt(n);
			total /= prime[i];
			total *= prime[i]-1;
		}
	}
	if(n != 1)
	{
		total /= n;
		total *= n-1;
	}	
	cout << total << endl;
}

int main()
{
	Fastest
	
	primeSieve();
    
    int t, n;
    
    cin >> t;
    
    while(t--)
    {
		cin >> n;
		div(n);
	}	
	
	return 0;
}
