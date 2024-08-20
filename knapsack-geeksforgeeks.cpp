#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int s, int w[], int v[], int n)
    {
        int dp[n + 1][s + 1];

        // Initialize the DP table
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= s; j++)
            {
                if (w[i - 1] <= j)
                {
                    dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // Return the maximum value that can be obtained
        return dp[n][s];
    }
};

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    int v[n], w[n];
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }

    int s;
    cout << "Enter the capacity of the knapsack: ";
    cin >> s;

    Solution sol;
    int result = sol.knapSack(s, w, v, n);
    cout << "Maximum value that can be obtained: " << result << endl;

    return 0;
}
