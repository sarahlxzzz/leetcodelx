class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        // Reverse the string
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        // Combine s, a special separator, and rev
        string combined = s + "#" + rev;
        int m = combined.length();
        
        // KMP table (LPS array)
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
            lps[i] = j;
        }
        
        // The last value in the LPS array gives the length of the longest palindromic prefix
        int matchLen = lps.back();
        
        // Add the remaining part of the reversed string to the front
        string add = rev.substr(0, n - matchLen);
        return add + s;
    }
};