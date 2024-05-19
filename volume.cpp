#include "volume.h"


int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxVolume = 0;

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int height = std::min(arr[left], arr[right]);

        int width = right - left;

        int volume = b * width * height;

        if (volume > maxVolume) {
            maxVolume = volume;
        }

        if (arr[left] < arr[right]) {
            left++;
        }
        else {
            right--;
        }
    }

    return maxVolume;
}
