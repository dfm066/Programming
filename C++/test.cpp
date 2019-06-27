#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define fors for (int i = 0; i < s.length(); i++)
class base
{
public:
  int val;
  base()
  {
    cout << "Created base obj" << endl;
    val = 7;
  }
  virtual void test() { cout << "Test of Base with val : " << val << endl; }
  virtual ~base() {
        cout << "Deleted base obj " << endl;
  }
};

class parent_one : public base
{
public:
  parent_one() { cout << "Created parent_one obj " << endl; }
  virtual void test()
  {
    cout << "Test of parent_one with val : " << val << endl;
  }
  virtual ~parent_one() {
        cout << "Deleted parent_one obj " << endl;
  }
};

class parent_two : public base
{
public:
  parent_two() { cout << "Created parent_two obj " << endl;}
  virtual void test()
  {
    cout << "Test of parent_two with val : " << val << endl;
    val = 9;
  }
  virtual ~parent_two() {
        cout << "Deleted parent_two obj " << endl;
  }
};

class child
  : public parent_one
  , public parent_two
{
public:
    child() {
        cout << "Created child obj "<< endl;
    }
    ~child() {
        cout << "Deleted child obj " << endl;
    }
};
using ll = long long;

ll ackerman_test(ll m, ll n) {
  if (m == 0) return n + 1;
  if (m > 0 && n == 0) return ackerman_test(m-1, 1);
  return ackerman_test(m-1, ackerman_test(m, n-1));
}

int
main()
{
    {
        child c1;
        cout << "In main" << endl;
        c1.parent_two::test();
        c1.parent_one::test();
    }
  long long m, n;
  cout << "Enter ackerman function parameters : ";
  cin >> m >> n;
  long long test = ackerman_test(m,n);
  cout << "Ackerman test : " << test << endl;
  return 0;
}
