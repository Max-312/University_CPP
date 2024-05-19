#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int getMaxVolume(int a, int b, int c, const vector<int>& heights) {
    int maxVolume = 0;

    for (int startColumn = 0; startColumn < heights.size(); ++startColumn) {
        for (int endColumn = startColumn + 1; endColumn < heights.size(); ++endColumn) {
            if (endColumn - startColumn <= a && min(heights[startColumn], heights[endColumn]) <= c)
            {
                int length = endColumn - startColumn;
                int height = min(heights[startColumn], heights[endColumn]);
                int volume = b * length * height;
                if (volume > maxVolume) {
                    maxVolume = volume;
                }
            }
        }
    }

    return maxVolume;
}