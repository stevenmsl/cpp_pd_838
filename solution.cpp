#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <unordered_map>
#include <stack>
#include <string>
using namespace sol833;
using namespace std;

/*takeaways
  - use two pointers approach
  - 3 cases you need to handle them differently
    - ...L.... -> LLLL....
      - everything on L's left will be marked as 'L'
    - ...R.... -> ...RRRRR
      - the opposite as the fist case
    - ...R....L...
      - half of the periods between (R,L) interval
        will be marked as 'R' and the other half 'L'
        - even number of periods between the interval
          ...RRRLLL...
        - odd number of periods between the interval
          ...RRR.LLL...

*/
string Solution::push(string s)
{
  const int N = s.size();
  /* the index of previous occurrence
     of L and R
  */
  auto lastL = -1, lastR = -1;
  for (auto i = 0; i <= N; i++)
  {
    if (i == N || s[i] == 'R')
    {
      /* two cases
         - found two consecutive R's, mark everything
           between lastR and i as 'R'
         - there is no 'L' from the last 'R'
           to the end of string
           - you need to check when i = N, so we
             have chance to run this scenario
      */
      if (lastR > lastL)
        while (++lastR < i)
          s[lastR] = 'R';

      /* record the last index of R */
      lastR = i;
    }
    else if (s[i] == 'L')
    {
      /*
        - have not found 'R' so far;
        - mark everything on my left
          as 'L'
      */
      if (lastR == -1)
        while (++lastL < i)
          s[lastL] = 'L';
      /* we found a (R,L) interval
         - we found R last time and
           L this time
      */
      else if (lastR > lastL)
      {
        auto l = lastR + 1;
        auto r = i - 1;
        while (l < r)
          s[l] = 'R', s[r] = 'L', l++, r--;
      }
      /* update the last index of L */
      lastL = i;
    }
  }

  return s;
}