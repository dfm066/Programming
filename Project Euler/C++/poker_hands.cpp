/*
Author : dfm066

Problem 54

In the card game poker, a hand consists of five cards and are ranked, from
lowest to highest, in the following way:

    High Card: Highest value card.
    One Pair: Two cards of the same value.
    Two Pairs: Two different pairs.
    Three of a Kind: Three cards of the same value.
    Straight: All cards are consecutive values.
    Flush: All cards of the same suit.
    Full House: Three of a kind and a pair.
    Four of a Kind: Four cards of the same value.
    Straight Flush: All cards are consecutive values of same suit.
    Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the highest
value wins; for example, a pair of eights beats a pair of fives (see example 1
below). But if two ranks tie, for example, both players have a pair of queens,
then highest cards in each hand are compared (see example 4 below); if the
highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:
Hand	 	Player 1	 	Player 2	 	    Winner
1	 	5H 5C 6S 7S KD   2C 3S 8S 8D TD        Player 2
        Pair of Fives    Pair of Eights

2	 	5D 8C 9S JS AC   2C 5C 7D 8S QH        Player 1
       Highest card Ace Highest card Queen

3	 	2D 9C AS AH AC  3D 6D 7D TD QD         Player 2
        Three Aces      Flush with Diamonds

4	 	4D 6S 9H QH QC  3D 6D 7H QD QS         Player 1
    Pair of Queens      Pair of Queens
    Highest card Nine   Highest card Seven

5	 	2H 2D 4C 4D 4S  3C 3D 3S 9S 9D         Player 1
        Full House        Full House
    With Three Fours    with Three Threes

The file, poker.txt, contains one-thousand random hands dealt to two players.
Each line of the file contains ten cards (separated by a single space): the
first five are Player 1's cards and the last five are Player 2's cards. You can
assume that all hands are valid (no invalid characters or repeated cards), each
player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?
*/

#include "utils.h"
using namespace std;

int rf = 0;
int sf = 0;
int fk = 0;
int fh = 0;
int f = 0;
int s = 0;
int tk = 0;
int tp = 0;
int pa = 0;

int rounds = 1;

int indexof(int ch) {
    if (ch >= '2' && ch <= '8')    return ch - '2';
    else {
        switch(ch) {
            case '9': return 7;
            case 'T': return 8;
            case 'J': return 9;
            case 'Q': return 10;
            case 'K': return 11;
            case 'A': return 12;
            case -1: return -1;
            default: assert(0);
        }
    }
}

int nextof(int ch) {
    if (ch >= '2' && ch <= '8')    return ch + 1;
    else {
        switch(ch) {
            case '9': return 'T';
            case 'T': return 'J';
            case 'J': return 'Q';
            case 'Q': return 'K';
            case 'K': return 'A';
            default: assert(0);
        }
    }
}

void count_cards(const string *cards, int *kind) {
    for (int card = 0; card < 5; card++) {
        kind[indexof(cards[card][0])]++;
    }
}

char is_royal_flush(const string*   cards) {
    char rf_seq[5] = {'A', 'J', 'K', 'Q', 'T'};
    char suit = cards[0][1];
    for (int card = 4; card >= 0; card--) {
        if (!(rf_seq[card] == cards[card][0] && suit == cards[card][1]))    return -1;
    }
    rf++;
    return indexof(cards[4][0]);
}

char is_flush(const string*   cards) {
    char suit = cards[0][1];
    for (int card = 1; card < 5; card++) {
        if (!(suit == cards[card][1]))    return -1;
    }
    f++;
    return indexof(cards[4][0]);
}

char is_striaght(const string*   cards) {
    for (int card = 1; card < 5; card++) {
        if (!(cards[card][0] == nextof(cards[card-1][0])))    return -1;
    }
    s++;
    return indexof(cards[4][0]);
}

pair<bool, pair<char, char>> is_striaght_flush(const string*   cards) {
    pair<char, char>    p = make_pair(is_flush(cards), is_striaght(cards));
    if (p.first != -1 && p.second != -1) {
        sf++;
        return make_pair(true, p);
    }
    else return make_pair(false, p);
}

char is_four_of_kind(const string*   cards, const int* kind) {
    
    for (int i = 0; i < 13; i++) if(kind[i] == 4) {
        fk++;
        return i;
    }
    return -1;
}

char is_three_of_kind(const string*   cards, const int* kind) {
    for (int i = 0; i < 13; i++) if(kind[i] == 3) {
        tk++;
        return i;
    }
    return -1;
}

pair<bool, pair<char, char>> is_two_pair(const string*   cards, const int* kind) {
    int i = 12;
    pair<char, char> p = make_pair(-1, -1);
    for (; i >= 0; i--) if(kind[i] == 2)    break;
    if (i >= 0) {
        pa++;
        p.first = i;
    }
    for (--i; i >= 0; i--) if(kind[i] == 2)    break;
    if (i >= 0) p.second = i;
    if (p.first != -1 && p.second != -1) {
        tp++;
        return make_pair(true, p);
    }
    return make_pair(false, p);
}

pair<bool, pair<char, char>> is_full_house(const string*   cards, const int* kind) {
    int i = 0;
    pair<char, char> p = make_pair(-1, -1);
    char thrice = is_three_of_kind(cards, kind);
    if (thrice == -1)   return make_pair(false, p);
    p.first = thrice;
    if (thrice == cards[0][0] && cards[3][0] == cards[4][0])    p.second = cards[3][0]; 
    else if (thrice == cards[4][0] && cards[0][0] == cards[1][0])    p.second = cards[0][0];
    else return make_pair(false, p);
    fh++;
    return make_pair(true, p);
}

int is_higher_card(const string *p1, const string *p2) {
    for (int card = 4; card >= 0; card--){
        if (indexof(p1[card][0]) < indexof(p2[card][0]))    return 2;
        else if (indexof(p1[card][0]) > indexof(p2[card][0]))   return 1;
    }
    return 0;
}

void print_cards(const string *p1, const string *p2, const char *msg) {
    cout << msg;
    cout << "Player 1: ";
    for (int card = 0; card < 5; card++) {
      cout << p1[card] << " ";
    }
    cout << " Player 2: ";
    for (int card = 0; card < 5; card++) {
      cout << p2[card] << " ";
    }
    cout << endl;
}
void sort_cards(string *cards){
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            if (indexof(cards[i][0]) > indexof(cards[j][0]))  swap(cards[i], cards[j]);
        }
    }
}

int get_winner(const string* p1, const string* p2) {
    string p1_sorted[5], p2_sorted[5];
    for (int card = 0; card < 5; card++) {
      p1_sorted[card]  = p1[card];
    }
    for (int card = 0; card < 5; card++) {
      p2_sorted[card]  = p2[card];
    }
    // print_cards(p1, p2, "Before sorting ");
    sort_cards(p1_sorted);
    sort_cards(p2_sorted);
    print_cards(p1_sorted, p2_sorted, "\nAfter sorting ");

    int p1_kind[13] = {0};
    int p2_kind[13] = {0};
    char rf_1, fk_1;
    char rf_2, fk_2;
    pair<bool, pair<char, char>>    sf_1, fh_1, tp_1;
    pair<bool, pair<char, char>>    sf_2, fh_2, tp_2;
    
    count_cards(p1_sorted, p1_kind);
    count_cards(p2_sorted, p2_kind);

    // Check for royal flush
    cout << "RF";
    rf_1 = is_royal_flush(p1_sorted);
    rf_2 = is_royal_flush(p2_sorted);
    if (rf_1 == rf_2 && rf_1 != -1)   return 0;
    else if (rf_1 > rf_2)        return 1;
    else if (rf_1 < rf_2)        return 2;
    cout << " x";

    // Check for straight flush
    cout << " SF";
    sf_1 = is_striaght_flush(p1_sorted);
    sf_2 = is_striaght_flush(p2_sorted);
    if (sf_1.first && sf_2.first) {
        if (sf_1.second.second > sf_2.second.second) return 1;
        else if (sf_1.second.second < sf_2.second.second) return 2;
        return 0;
    } else if (sf_1.first)  return 1;
    else if (sf_2.first)    return 2;
    cout << " x";

    // Check for four of kind
    cout << " FK";
    fk_1 = is_four_of_kind(p1_sorted, p1_kind);
    fk_2 = is_four_of_kind(p2_sorted, p2_kind);
    if (fk_1 > fk_2)    return 1;
    else if (fk_1 < fk_2)    return 2;
    cout << " x";
    
    // Check for full house
    cout << " FH";
    fh_1 = is_full_house(p1_sorted, p1_kind);
    fh_2 = is_full_house(p2_sorted, p2_kind);
    if (fh_1.first && fh_2.first) {
        if (fh_1.second.first > fh_2.second.first)  return 1;
        else if (fh_1.second.first < fh_2.second.first) return 2;
        else assert(0);
    } else if (fh_1.first)  return 1;
    else if (fh_2.first)    return 2;
    cout << " x";
    
    // Check for flush
    cout << " F";
    if (sf_1.second.first > sf_2.second.first)  return 1;
    else if (sf_1.second.first < sf_2.second.first) return 2;
    cout << " x";

    // Check for straight
    cout << " S";
    if (sf_1.second.second > sf_2.second.second)  return 1;
    else if (sf_1.second.second < sf_2.second.second) return 2;
    cout << " x";

    // Check for three of a kind
    cout << " TK";
    if (fh_1.second.first > fh_2.second.first)  return 1;
    else if (fh_1.second.first < fh_2.second.first) return 2;
    cout << " x";


    // Check for two pairs
    tp_1 = is_two_pair(p1_sorted, p1_kind);
    tp_2 = is_two_pair(p2_sorted, p2_kind);
    if (tp_1.first && !tp_2.first) {
        cout << " PP";
        return 1;
    }
    if (!tp_1.first && tp_2.first) {
        cout << " PP";
        return 2;
    }
    if (tp_1.second.first > tp_2.second.first)  {
        cout << " x P";
        return 1;
    }
    else if (tp_1.second.first < tp_2.second.first) {
        cout << " x P";
        return 2;
    } else if (tp_1.second.second > tp_2.second.second) return 1;
    else if (tp_1.second.second < tp_2.second.second) return 2;
    else {
        cout << " x";
        return is_higher_card(p1_sorted, p2_sorted);
    }
}

int main() {
  string player_one[5];
  string player_two[5];
  int players[3] = {0, 0, 0};

  auto st = GET_HRTIME();
  while (true) {

    for (int card = 0; card < 5; card++) {
      cin >> player_one[card];
    }
    for (int card = 0; card < 5; card++) {
      cin >> player_two[card];
    }
    if (cin.eof())  break;
    int winner = get_winner(player_one, player_two);
    players[winner]++;
    assert(players[0] + players[1] + players[2] == rounds);
    printf("\nRound %d : P1 Wins = %d P2 Wins = %d Draws = %d\n", rounds, players[1], players[2],
         players[0]);
    rounds++;
  }
  auto en = GET_HRTIME();
  pa -= tp;
  printf("Royal Flush: %d Straight Flush: %d Four of a Kind: %d Full House: %d"
         " Flush: %d Straight: %d Three of a Kind: %d Two Pairs: %d One Pair: %d\n",rf, sf, fk, fh, f, s, tk, tp, pa);
  time_diff exec_t = en - st;
  cout << "Time to execute : " << ms(exec_t).count() << "ms\t"
       << us(exec_t).count() << "us\t" << ns(exec_t).count() << "ns\n"
       << endl;
  return 0;
}