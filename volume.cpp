
using namespace std;

int getMaxVolume(int a, int b, int c, const std::vector<int>& heights) {
    int n = heights.size();
    int max_volume = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int height = std::min(heights[i], heights[j]);
            int length = j - i;
            int volume = b * length * height;
            max_volume = std::max(max_volume, volume);
        }
    }

    return max_volume;
}