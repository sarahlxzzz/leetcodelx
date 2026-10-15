class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        
        for (char c: num){
            while(res.length()>0 && res.back()> c && k>0){
                res.pop_back();
                k--;
            }
            if (res.length() > 0 || c != '0') {
                res.push_back(c);
            }
        }
        while (k > 0 && res.length() > 0) {
            res.pop_back();
            k--;
        }
     return res == "" ? "0" : res;
    }
};