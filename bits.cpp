#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
    int p,n,k;

    std::ios::sync_with_stdio(false);  
    int indice, n_prob, k_prob;
    int max_n = 0, max_k = 0;
    cin >> p;

    vector<pair<int, int> > date_intrare;
    date_intrare.reserve(p+1);

    for(int i = 1 ;i <= p; i++)
    {
        cin >> indice >> n_prob >> k_prob;
        if(max_n < n_prob)
        {
            max_n = n_prob;
        }
        if(max_k < k_prob)
        {
            max_k = k_prob;
        }
        date_intrare[indice] = make_pair(n_prob, k_prob);
    }
    vector<vector<vector<int> > > dp(max_n+1, vector<vector<int> >(max_k+1, vector<int>(2,0)));

    //caz baza rec 0
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    //cazul de baza + rec 1
    for(int i = 2; i <= max_n; i++)
    {
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][0][0];
    }

    //recurenta
    for(int i = 2 ;i <= max_n ; i++)
    {
        for(int l = 1; l <= max_k; l++)
        {
            dp[i][l][0] = dp[i-1][l][0] + dp[i-1][l][1];
            dp[i][l][1] = dp[i-1][l-1][1] + dp[i-1][l][0];
        }
    }

    for(int i = 1; i <= p; i++)
    {
        cout << i << " " << (dp[date_intrare[i].first][date_intrare[i].second][0] + dp[date_intrare[i].first][date_intrare[i].second][1]) << endl;
    }
    return 0;
}
