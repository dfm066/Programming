#include <bits/stdc++.h>

using namespace std;

#define MAX 1e7

bool first_comp(const pair<long long,long long> a, const pair<long long,long long> b) {
    if (a.first > b.first)  return false;
    else if(a.first == b.first && a.second > b.second) return false;
    else return true;
}


bool second_comp(const pair<long long,long long> a, const pair<long long,long long> b) {
    if (a.second > b.second)    return false;
    else if (a.second == b.second && a.first > b.first) return false;
    return true;
}

int is_equal(const pair<long long,long long> &val, const vector<pair<long long,long long>> &container) {
    int st = 0;
    int en = container.size();
    int middle = 0;
    while (st <= en) {
        middle = (st+en) / 2;
        if (container[middle] == val)   return middle;
        else if(second_comp(val, container[middle]))    en = middle - 1;
        else    st = middle + 1;

    }
    return middle;
}

int is_greater_or_equal(const pair<long long,long long> val, const vector<pair<long long,long long>> &container, int lim) {
    int st = 0;
    int en = lim;
    int middle = 0;
    while (st <= en) {
        middle = (st+en) / 2;
        if (val.first == container[middle].second)  {
                while(container[middle].second == val.first && middle > 0)    middle--;
                break;
        }
        else if (val.first < container[middle].second)   en = middle -1;
        else    st = middle + 1;

    }
    if (val.first <= container[middle].second)    return middle;
    else    return middle+1;
}

template <class T>
void print_container(string header, T container) {
    cout << header << " : ";
    for(auto val:container) {
        cout << "[" << val.first << ", " << val.second << "] ";
    }
    cout << endl;
}

int solution(vector<int> &A) {
    int N = (int)A.size();
    int res = 0;
    vector<pair<long long,long long>> start_bound(N);

    for(long long pos = 0; pos < N; pos++) {
        start_bound[pos].first = pos - A[pos];
        start_bound[pos].second = pos + A[pos];
    }
    // Debugging purpose
    print_container("original vector", start_bound);

    vector<pair<long long,long long>>  end_bound(start_bound);
    make_heap(start_bound.begin(), start_bound.end(), first_comp);
    make_heap(end_bound.begin(), end_bound.end(), second_comp);

    // Debugging purpose
    print_container("start_bound before sort", start_bound);
    print_container("end_bound before sort", end_bound);

    sort_heap(start_bound.begin(), start_bound.end(), first_comp);
    sort_heap(end_bound.begin(), end_bound.end(), second_comp);

    // Debugging purpose
    print_container("start_bound after sort", start_bound);
    print_container("end_bound after sort", end_bound);

    for (auto val:start_bound){

        int en_lim = is_equal(val, end_bound);
        int st_lim = is_greater_or_equal(val, end_bound, en_lim);

        // Debugging purpose
        cout << en_lim << " " << st_lim << " "<< res << endl;

        assert(en_lim >= st_lim);
        res += en_lim-st_lim;
    }
    if (res > MAX)  res = -1;
    return res;
}


// Driver Program
int main(){
    int N;

    cin>>N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
            cin>>A[i];
    }
    cout << "Input : ";
    for(auto val : A){
        cout << " " << val;
    }
    cout << endl;
    cout << "Solution : " << solution(A) << endl;
    cout << MAX;
    return 0;
}
