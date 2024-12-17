#include <bits/stdc++.h>
using namespace std;
vector<int> sieve_of_eratosthenisis(int n)
{
    // time complexity: O(n*log(log(n)))
    vector<bool> isprime(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (isprime[i])
            primes.push_back(i);
    return primes;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Primes till " << n << " are ";
    for (int p : sieve_of_eratosthenisis(n))
        cout << p << " ";
    cout << endl;
    return 0;
}
