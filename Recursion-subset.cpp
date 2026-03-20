// Subset/ Powerset problem using recursion.

/*
  TIME COMPLEXITY: O(2^n)
  SPACE COMPLEXITY: O(n)
*/

/*
EXPLANATION:
  num -> input array
  index -> point out current index
  subset -> store subset of num array
  ans -> store power set i.e all possible subset of num.

  APPROACH (Pass by Value)
*/

//   SOLUTION: 
#include <bits/stdc++.h>
using namespace std;

void powerSet( vector<int> num, int index, vector<int> subset, vector< vector <int> >& ans)
{
  //BASE CASE
  if ( index >= num.size() )
  {
    // We Reach to the Leaf Node
    ans.push_back( subset);
    return;
  }

  
  //EXCLUDE
  powerSet( num, index+1, subset, ans);

  //INCLUDE
  int currentElement = num [index];
  subset.push_back( currentElement );
  // GO TO NEXT ELEMENT
  powerSet( num, index+1, subset, ans);

}

vector<vector <int>> subsetProblem( vector <int> num)
  {
    vector<int> subset;
    vector< vector<int> > ans;
    int index=0;

    powerSet( num, index, subset, ans);

    return ans;
  
  }

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = subsetProblem(nums);

    for (auto subset : ans) {
        cout << "[ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}

/*
PROS:-
1. Simple to write and understand: No need to worry about removing elements
2. No side-effects (safe): Each recursive call has its own copy
3. Less chance of logical bugs: No risk of forgetting backtracking

CONS:-
1. Extra copying overhead: Every recursive call copies the subset
2. Higher time complexity in practice: O(n * 2^n)
3. Extra memory usage: Many copies of subset created
4. Not preferred in interviews: Interviewers expect backtracking understanding
*/
