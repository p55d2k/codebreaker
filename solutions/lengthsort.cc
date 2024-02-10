#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<string> v(n);

  // map for word to index to use if same length
  unordered_map<string, int> wordIndex;

  for (int i = 0; i < n; i++) {
    cin >> v[i];
    wordIndex[v[i]] = i;
  }

  sort(v.begin(), v.end(), [&wordIndex](const string& a, const string& b) {
    if (a.size() == b.size()) {
      return wordIndex[a] < wordIndex[b];
    }
    return a.size() > b.size();
  });

  for (const string& sortedStr : v) {
    cout << sortedStr << "\n";
  }

  return 0;
}
