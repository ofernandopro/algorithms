#include <iostream>
#include <string>
#include <algorithm> // sort, erase, funções de max e min
#include <functional> // greater
#include <vector>
#include <utility> // pair
#include <iterator>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#define f first
#define s second

#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

using namespace std;

bool validMountainArray(vector<int>& arr) {

  if (arr.size() < 3) {
    return false;
  }

  int INF = 0x3f3f3f3f;
  int max = -INF;
  int maxIndex;

  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] > max) {
      max = arr[i];
      maxIndex = i;
    }
  }

  if (maxIndex == 0 || maxIndex == arr.size()-1) {
    return false;
  }

  int cont = true;
  for (int i = 1; i <= maxIndex; i++) {
    if (arr[i] <= arr[i-1]) {
      cont = false;
    }
  }

  if (cont == false) {
    return false;
  }

  int cont2 = true;
  for (int i = maxIndex+1; i < arr.size(); i++) {
    if (arr[i] >= arr[i-1]) {
      cont2 = false;
    }
  }

  if (cont && cont2) {
    return true;
  } else {
    return false;
  }

}

int main() { _

  vector<int> nums;
  nums.push_back(5);
  nums.push_back(5);
  nums.push_back(3);

  if (validMountainArray(nums)) {
    cout << "v" << endl;
  } else {
    cout << "f" << endl;
  }

  return 0;
}