// Subset/ Powerset problem using recursion.

/*
BACKTRACKING APPROACH (Optimal)
*/

//SOLUTION:-

#include <bits/stdc++.h>
using namespace std;

void powerSet(vector<int> num, int index, vector<int>& subset, vector< vector<int>>& ans)
{
  //BASE CASE
  if( index >= num.size())
  {
    ans.push_back(subset);
    return;
  }

  //INCLUDE
  subset.push_back( num[index]);
  powerSet( num, index+1, subset, ans);

  //BACKTRACT
  subset.pop_back();

  //EXCLUDE
   powerSet( num, index+1, subset, ans);
}

vector< vector<int>> subsetProblem( vector<int> num)
{
  vector< vector<int>> ans;
  vector<int> subset;

  powerSet( num, 0, subset, ans);
  
  return ans;
}

int main()
{
  // INPUT SET
  vector<int> num = {1, 2, 3};

  //CALLING
  vector< vector<int>> result;
  result = subsetProblem(num);

  //OUTPUT
  cout << "All Subsets:" << endl << "{" << endl;
  
  for(const auto& subset : result)
    {
        cout << "[ ";
        for(int num : subset)
        {
            cout << num << " ";
        }
        cout << "]," << endl;
    }
 cout <<  endl << "}";
}

/*
Pros:-
1. Efficient (no copying): Only one subset is modified
2. Better performance: O(2^n)
3. Space optimized: O(n) recursion stack only
4. Interview standard solution 

Cons;-
1. Slightly harder to understand initially
2. Bug-prone if you forget to backtrack
3. Missing pop_back() = wrong answers
*/
