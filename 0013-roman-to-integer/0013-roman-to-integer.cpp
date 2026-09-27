class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        for (int i =0; i<s.length(); i++){
            int x;
            if (s[i]=='I') x = 1;
            else if (s[i]== 'V')x = 5;
            else if (s[i]== 'X')x = 10;
            else if (s[i]== 'L')x = 50;
            else if (s[i]== 'C')x = 100;
            else if (s[i]== 'D')x = 500;
            else x = 1000;

            if (i + 1<s.length()){
                int y;
                if (s[i+1]== 'I')y = 1;
                else if (s[i+1]== 'V')y = 5;
                else if (s[i+1]== 'X')y = 10;
                else if (s[i+1]== 'L')y = 50;
                else if (s[i+1]== 'C')y = 100;
                else if (s[i+1]== 'D')y = 500;
                else y = 1000;

                if (x<y)
                ans -= x;
                else
                ans += x;
            }
            else
            {
            ans += x;
        }
    }
    return ans;
    }
};