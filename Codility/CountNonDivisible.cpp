#include "../Library/C++/utils.h"
using namespace std;

vector<int> solution(vector<int> &A) {
    const int max = 100000;
    int sz = A.size();
    int f_map[max+1] = {0};
    int ft_map[max+1] = {0};
    int curr_max = max;
    vector<int> ans(sz);
    
    for(auto i : A) f_map[i]++;
    while(f_map[curr_max] == 0) curr_max--;
    
    ft_map[1] = f_map[1];
    for (int it = 2; it <= curr_max; it++) {
        ft_map[it] += f_map[1];
        ft_map[it] += f_map[it];
    }
    
    int ulim = floor(sqrt(curr_max));
    for (int it = 2; it <= ulim; it++) {
        int llim = curr_max / it;
        for (int f = it+1; f <= llim; f++) {
            ft_map[it*f] += f_map[it];
            ft_map[it*f] += f_map[f];
        }
        ft_map[it*it] += f_map[it];
    }
    
    for (int it = 0; it < sz; it++) {
        ans[it] = sz - ft_map[A[it]];
    }
   
    return ans;
}