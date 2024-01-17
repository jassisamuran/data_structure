class Solution
{
    public:
    int lcs(string X, string Y, int m, int n)
    {
     
        int L[m + 1][n + 1];
     
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    L[i][j] = 0;
     
                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
     
                else
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
        return L[m][n];
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        return lcs(s1, s2, n, m);
    }
};
// time complexity o(n*n)
// space complexity o(n*n)