class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        string ans = "";
        int freq[] = {0,0,0,0,0,0,0,0,0,0, /* this one is for optimization*/0};
        for (const auto& d : digits) freq[d]++;
        // set freq 10 to 1 for optimization
        freq[10] = 1;
        int extra = (freq[1] + 2*freq[2] + 4*freq[4] + 5*freq[5] + 7*freq[7] + 8*freq[8])%3;
        // Remove the digits
        // if extra is 1 => 
        // 1. remove minimun out of present 1 or 4 or 7
        // 2. remove minimun out of present 2,2 or 2,5 or 5,5 or 5,8 or 8,8
        // if extra is 2 => 
        // 1. remove minimun out of present 2 or 5 or 8
        // 2. remove minimun out of present 1,1 or 1,4 or 4,4 or 4,7 or 7,7
        // create 8 configs to try for reduction
        // NOTE: here 10 is dummy digit incase single digit reduction is possible
        int reduceOne[] = {1,10,4,10,7,10,2,2,2,5,5,5,5,8,8,8};
        int reduceTwo[] = {2,10,5,10,8,10,1,1,1,4,4,4,4,7,7,7};
        if (extra) {           
            bool fixed = false;
            int *reduce = extra == 1 ? reduceOne : reduceTwo;
            for(int config = 0; config < 8; config++) {
                int first = reduce[config*2];
                int second = reduce[config*2+1];
                if ((first != second && freq[first] > 0 && freq[second] > 0) ||
                    (first == second && freq[first] > 1)
                   ) {
                    fixed = true;
                    freq[first]--;
                    freq[second]--;
                    break;
                }
            }
            if (!fixed) return "";
        }
        // Build the ans from frequency map of digits
        for (int i = 9; i >= 0; --i) {
            for (int j = freq[i]; j > 0; --j) ans.push_back('0'+i);
        }
        // Handle all 0's
        if (!ans.empty() && ans[0] == '0') {
            return "0";
        }
        return ans;
    }
};