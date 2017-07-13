#include <iostream>
using namespace std;
int main(){
        int N;
        cin >> N;
        long result = 0;
		
		// 81 numbers which don't have a square (or are a power) in that range:
		result += 81 * 99;
		
		// four numbers, 5, 6, 7, 10 have a square but no third power:
		result += 4 * (99 + 50);
		
		int c = 0;		// third powers
		int d = 0;		// fourth powers
		int e = 0;		// fifth powers
		int f = 0;		// sixth powers
        int g = 0;      // 7th powers
		for ( int index = 2; index <= N; index++ )
		{
			int temp = index * 3;
			if ( (temp > N) &&
				 ((temp > 2*N) || (temp % 2) != 0) )
				c++;

			temp = index * 4;
			if ( (temp > 2*N) &&
				 ((temp > 3*N) || (temp % 3) != 0) )
				d++;

			temp = index * 5;
			if ( (temp > N) &&
				 ((temp > 2*N) || (temp % 2) != 0) &&
				 ((temp > 3*N) || (temp % 3) != 0) &&
				 ((temp > 4*N) || (temp % 4) != 0) )
				e++;

			temp = index * 6;
			if ( (temp > N) &&
				 ((temp > 2*N) || (temp % 2) != 0) &&
				 ((temp > 3*N) || (temp % 3) != 0) &&
				 ((temp > 4*N) || (temp % 4) != 0) &&
				 ((temp > 5*N) || (temp % 5) != 0) )
				f++;
            temp = index * 7;
			if ( (temp > N) &&
				 ((temp > 2*N) || (temp % 2) != 0) &&
				 ((temp > 3*N) || (temp % 3) != 0) &&
				 ((temp > 4*N) || (temp % 4) != 0) &&
                 ((temp > 5*N) || (temp % 5) != 0) &&
				 ((temp > 6*N) || (temp % 6) != 0) )
				g++;
		}
        int exp_map[64];
        exp_map[1] = N-1;
        exp_map[2] = N - N/2;
        for(int e2 = 2; e2 <= N; ++e2){
            for(int e1 = 3; e1 <= max_e1; ++e1){
                int curr_e = e2 * e1;
                if(curr_e > N){
                    int counter = 1;
                    for(int m = 2; m < e1; ++m){
                        if(curr_e > m * N || curr_e % m != 0) ++counter;
                    }
                    if(counter == e1)   ++exp_map[e1];
                }
            }
        }
		
		// 3:
		result += 99 + 50 + c + d;
		
		// 2:
		result += 99 + 50 + c + d + e + f;
		cout << c << " " << d << " " << e << " " << f << " " << g << endl; 
		cout << result << endl;
}