#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
int main(){	
	ifstream in("in.txt");
	string line;
	vector<vector<int>> mat;
	vector<int> row;
	vector<string> num;
	while(!in.eof()){
		getline(in,line);
		tokenize(line,num);
		for(auto i:num)
			row.push_back(stoi(i));
		
		mat.push_back(row);
		num.clear();
		row.clear();
	}
	for(auto r:mat){
		for(auto c:r){
			cout<< c << " ";
		}
		cout<< endl;
	}
	return 0;
}
