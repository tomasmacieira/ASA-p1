// ASA2023 P1 - Tomás Macieira & Guilherme Henriques

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int plate_width, plate_height, num_of_pieces;

    cin >> plate_width >> plate_height;
    cin >> num_of_pieces;

    vector<vector<int>> pieces(num_of_pieces, vector<int>(3));
    vector<vector<int>> k(plate_height + 1, vector<int>(plate_width + 1, 0));

    for (int i = 0; i < num_of_pieces; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    for (int i = 1; i <= plate_height; i++) {
        for (int w = 1; w <= plate_width; w++) {
            int max_val = 0;

            for (int j = 0; j < num_of_pieces; j++) {
                int piece_width = pieces[j][0];
                int piece_height = pieces[j][1];
                int piece_val = pieces[j][2];

                if (w - piece_width >= 0 && i - piece_height >= 0) {
                    if (k[i][w - piece_width] + k[i - piece_height][w] - k[i - piece_height][w - piece_width] + piece_val > max_val) {
                        max_val = k[i][w - piece_width] + k[i - piece_height][w] - k[i - piece_height][w - piece_width] + piece_val;
                    }
                }

                if (w - piece_height >= 0 && i - piece_width >= 0) {
                    if (k[i][w - piece_height] + k[i - piece_width][w] - k[i - piece_width][w - piece_height] + piece_val > max_val) {
                        max_val = k[i][w - piece_height] + k[i - piece_width][w] - k[i - piece_width][w - piece_height] + piece_val;
                    }
                }
            }
            k[i][w] = max_val;
        }
    }
    cout << k[plate_height][plate_width] << endl;
    return 0;
}
