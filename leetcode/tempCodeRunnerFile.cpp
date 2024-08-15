int validSubarraySize(vector<int> &nums, int threshold) {
  long long N = nums.size();
  stack<pair<long long, long long>> s; // value, index
  long long i = 0;
  while (i < N) {
    if (s.empty() || s.top().first < nums[i]) {
      s.push({nums[i], i});
      i++;
    } else {
      pair<int, int> cur = s.top();
      s.pop();
      long long width;
      if (s.empty()) {
        width = i;
      } else {
        width = i - 1 - s.top().second;
      }
      if (width * s.top().first > threshold) {
        return width;
      }
    }
  }
  while (!s.empty()) {
    pair<int, int> cur = s.top();
    s.pop();
    long long width;
    if (s.empty()) {
      width = i;
    } else {
      width = i - 1 - s.top().second;
    }
    if (width * s.top().first > threshold) {
      return width;
    }
  }
  return -1;
}