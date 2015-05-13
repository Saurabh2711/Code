#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int lengthOfLongestSubstring(string s) {
  int n = s.size();
  int i = 0, j = 0;
  int maxLen = 0;
  bool exist[256] = { false };
  while (j < n) {
    if (exist[s[j]]) {
      maxLen = max(maxLen, j-i);
      while (s[i] != s[j]) {
        exist[s[i]] = false;
        i++;
      }
      i++;
      j++;
    } else {
      exist[s[j]] = true;
      j++;
    }
  }
  maxLen = max(maxLen, n-i);
  return maxLen;
}
main()
{
  int t;
  string str;
  while(t--)
  {
    cin>>str;
    cout<<lengthOfLongestSubstring(str)<<endl;
  }
  return 0;
}