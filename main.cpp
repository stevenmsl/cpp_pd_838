#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol833;

/*
Input: ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
*/

tuple<string, string>
testFixture1()
{
  return make_tuple(".L.R...LR..L..", "LL.RR.LLRRLL..");
}

/*
Input: "RR.L"
Output: "RR.L"
Explanation: The first domino expends no
additional force on the second domino.
*/

tuple<string, string>
testFixture2()
{
  return make_tuple("RR.L", "RR.L");
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.push(get<0>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see " << get<1>(f) << endl;
  Solution sol;
  cout << sol.push(get<0>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}