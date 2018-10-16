#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

const int   ALIGN = 4096;

typedef struct Point {
    int     pt;
    int     val;

    Point(int p, int v) : pt(p), val(v) {};
} Point;

ostream& operator<<(ostream& out, const Point& p) {
        out << "Point: " << p.pt;
        out << "\tVal : " << p.val;
        return out;
}

void print_pts(const vector<Point> &v, const string&& header) { 
    cout << header;
    for (const auto& p: v) {
        cout << p << endl;
    }
}

void print_queries(const vector<vector<int>> &queries, const string&& header) {
    cout << header;
    for (const auto& q: queries) {
        cout << "st : " << q[0] << " en : " << q[1] << " val : " << q[2] << endl;
    }
}
bool querysort(const vector<int> &q1, const vector<int> &q2) {
    if (q2[0] > q1[0])  return true;
    else if(q2[0] == q1[0] && q2[1] > q1[1])    return true;
    return false;
}

// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<Point>  start_pts, end_pts;
    long        curr_sum, curr_diff, curr_st, curr_en;
    int         tot_st, tot_en;
    int         N = queries.size();
    
    sort(begin(queries), end(queries), querysort);
    print_queries(queries, "After sorting queries : \n");

    curr_sum = curr_diff = curr_st = curr_en = 0;
    tot_st = tot_en = 0;
    start_pts.reserve(ALIGN);
    end_pts.reserve(ALIGN);

    curr_st = queries[0][0];
    curr_en = queries[0][1];
    curr_sum += queries[0][2];
    start_pts.push_back({curr_st, curr_sum});
    end_pts.push_back({curr_en, curr_diff});
    curr_diff += queries[0][2];

    for (int i = 1; i < N; i++) {
        curr_st = queries[i][0];
        curr_en = queries[i][1];
        curr_sum += queries[i][2];
        if (curr_st > end_pts[tot_en].pt) {
            start_pts.push_back({curr_st, curr_sum});
            ++tot_st;
        } else if (curr_st < end_pts[tot_en].pt){
            start_pts[tot_st].pt = curr_st;
            start_pts[tot_st].val = curr_sum;
        } else {
            start_pts.push_back({curr_st, curr_sum});
            ++tot_st;
            curr_diff = queries[i][2];
            end_pts.push_back({curr_en, curr_diff});
            tot_en++;
        }
        if (curr_en > end_pts[tot_en].pt) {
            curr_diff = queries[i][2];
            end_pts.push_back({curr_en, curr_diff});
            tot_en++;
        } else {
            curr_diff += queries[i][2];
            end_pts[tot_en].val = curr_diff;
        }
    }
    print_pts(start_pts, "Start points : \n");
    print_pts(end_pts, "End points : \n");

    return curr_sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
