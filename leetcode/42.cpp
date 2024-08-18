class Solution {
public:
  int trap(vector<int> &height) {
    if (height.empty())
      return 0;

    int tmp_height = height[0];
    int ans = 0;
    int second_high = 0;
    int second_high_idx = 0;
    int i = 1;

    while (i < height.size()) {
      if (height[i] < tmp_height) {
        while (i < height.size()) {
          ans += tmp_height - height[i];
          i++;
          if (i < height.size() && height[i] >= tmp_height) {
            break;
          }
        }
      }
      if (i < height.size()) {
        tmp_height = height[i];
      }
      i++;
    }

    int monotone_inc = height[height.size() - 1];
    int sub = tmp_height - monotone_inc;

    if (height.size() >= 2) {
      for (int i = height.size() - 2; i >= 0 && height[i] < tmp_height; i--) {
        if (height[i] > monotone_inc) {
          monotone_inc = height[i];
        }
        sub += tmp_height - monotone_inc;
      }
    }

    return ans - sub;
  }
};
