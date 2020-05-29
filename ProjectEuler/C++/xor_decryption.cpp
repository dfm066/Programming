/*
Author : dfm066

Problem 59

Each character on a computer is assigned a unique code and the preferred
standard is ASCII (American Standard Code for Information Interchange).For
example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107. A modern
encryption method is to take a text file, convert the bytes to ASCII, then XOR
each byte with a given value, taken from a secret key. The advantage with the
XOR function is that using the same encryption key on the cipher text, restores
the plain text; for example, 65 XOR 42 = 107, then 107 XOR 42 = 65. For
unbreakable encryption, the key is the same length as the plain text message,
and the key is made up of random bytes. The user would keep the encrypted
message and the encryption key in different locations, and without both
"halves", it is impossible to decrypt the message. Unfortunately, this method is
impractical for most users, so the modified method is to use a password as a
key. If the password is shorter than the message, which is likely, the key is
repeated cyclically throughout the message. The balance for this method is using
a sufficiently long password key for security, but short enough to be memorable.
Your task has been made easy, as the encryption key consists of three lower case
characters. Using cipher.txt (right click and 'Save Link/Target As...'), a file
containing the encrypted ASCII codes, and the knowledge that the plain text must
contain common English words, decrypt the message and find the sum of the ASCII
values in the original text.

*/

#include "utils.h"
using namespace std;

bool analyse(const string &msg) {
    char cmap[256] = {0};
    int sz = msg.size();
    int e_lim = sz * 0.10;
    int a_lim = sz * 0.04;
    int o_lim = sz * 0.04;
    for(auto c : msg){
        cmap[c]++;
    }
    if ((cmap['e'] + cmap['E']) > e_lim &&
        (cmap['a'] + cmap['A']) > a_lim &&
        (cmap['o'] + cmap['O']) > o_lim)   return true;

    return false;
    
}

int
main(int argc, char const* argv[])
{
  string line;
  vector<string> chars;
  cin >> line;

  tokenize(line, chars, ",");
  int char_cnt = chars.size();
  int it = 0;
  char key[3];
  bool possible;
  int ans = 0;
  cout << char_cnt << endl;
  string plain("0", char_cnt+1);
  for (int i = 'a'; i <= 'z'; i++) {
    for (int j = 'a'; j <= 'z'; j++) {
      for (int k = 'a'; k <= 'z'; k++) {
        key[0] = i;
        key[1] = j;
        key[2] = k;
        ans = 0;
        for (int it = 0; it < char_cnt; it++) {
          plain[it] = char(stoi(chars[it]) ^ key[it % 3]);
        }
        plain[char_cnt] = '\0';
        possible = analyse(plain);
        ans = 0;
        if (possible) {
            for (auto ch : plain)   ans += int(ch);
            cout << key[0] << key[1] << key[2] << " : " << ans << " - " << plain << endl;
        }
      }
    }
  }
  return 0;
}
