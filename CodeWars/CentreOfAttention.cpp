#include <bits/stdc++.h>
using namespace std;
struct Image {
    unsigned *pixels;
    unsigned width, height;
    Image(unsigned *pixels, unsigned width, unsigned height) : pixels(pixels), width(width), height(height) {}
    std::vector<unsigned> central_pixels(unsigned colour) const {
        std::vector<int> row, col, res;
        for (int i = 0; i < width * height; i++) {
            row.push_back(0);
            col.push_back(0);
        }
        for (int i = 0; i < height; i++) {
            int start, end;
            for (int j = 0; j < width; j++) {
                if (pixels[i * width + j] == colour) {
                    start = i * width + j;
                    while (j < width && pixels[i * width + j] == colour)
                        j++;
                    end = i * width + j;
                    int l = 0;
                    for (int k = 1; k <= (end - start) / 2 + 1; k++) {
                        row[start + l] = k;
                        l++;
                    }
                    if ((end - start) % 2) {
                        row[start + l] = (end - start) / 2 + 1;
                        l++;
                    }
                    for (int k = (end - start) / 2; k >= 1; k--) {
                        row[start + l] = k;
                        l++;
                    }
                }
            }
        }
        for (int i = 0; i < width; i++) {
            int start, end;
            for (int j = 0; j < height; j++) {
                if (pixels[i + height * j] == colour) {
                    start = i + height * j;
                    while (j < height && pixels[i + height * j] == colour)
                        j++;
                    end = i + height * j;
                    int l = 0;
                    for (int k = 1; k <= ((end - start) / width) / 2 + 1; k++) {
                        col[start + l * width] = k;
                        l++;
                    }
                    if (((end - start) / width) % 2) {
                        col[start + l * width] = ((end - start) / width) / 2 + 1;
                        l++;
                    }
                    for (int k = ((end - start) / width) / 2; k >= 1; k--) {
                        col[start + l * width] = k;
                        l++;
                    }
                }
            }
        }

        for (int i = 0; i < width * height; i++)
            res.push_back(row[i] > col[i] ? col[i] : row[i]);
        int max = 0;
        for (int i = 0; i < width * height; i++)
            if (res[i] > max) max = res[i];

        std::vector<unsigned> result;
        for (int i = 0; i < width * height; i++)
            if (res[i] == max)
                result.push_back(i);
        return result;
    }
};