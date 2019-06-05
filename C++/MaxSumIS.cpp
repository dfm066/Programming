#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
typedef long long ll;

int main()
 {
	int T,N;
	cin >> T;
	while(T--) {
	    cin >> N;
	    map<ll, int> prev_num;
	    vector<ll> sum(N);
	    ll max_sum = ll(0);
	    int num = 0;
	    for (int i = 0; i < N; i++) {
            scanf("%d", &num);
            sum[i] = num;
            auto found = prev_num.find(sum[i]);
            if (found != prev_num.end()) {
                sum[i] += sum[found->second];
                prev_num[num] = i;
            } else {
                auto inserted = prev_num.insert({num, i});
                if(inserted.first != prev_num.begin())
                    sum[i] += sum[prev(inserted.first, 1)->second];
            }
            cout << i << " " << sum[i] << endl;
	    }
	    max_sum = *(max_element(sum.cbegin(), sum.cend()));
	    cout << max_sum << endl;
	}
	return 0;
}