#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> getArrangementForRotation(int N){
    std::vector<int> arrangement(N, 0);
    std::queue<int> rotation_q;
    
    // Initialize queue with cards 1..N
    for (int i = 1; i <= N; i++) rotation_q.push(i);

    // Perform rotations on queue to extract position
    // of each card in a deck.
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            rotation_q.push(rotation_q.front());
            rotation_q.pop();
        }
        // Set card at its correct position in deck 
        arrangement[rotation_q.front()-1] = i;
        rotation_q.pop();
    }
    return arrangement;
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int N;
        std::cin >> N;
        std::vector<int> arrangement = getArrangementForRotation(N);
        for (const auto &card : arrangement) std::cout << card << " ";
        std::cout << std::endl;
    }
}