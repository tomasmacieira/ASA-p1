#include <iostream>
#include <vector>
using namespace std;

int main() {
    int plate_width, plate_height, num_of_pieces;

    cin >> plate_width >> plate_height;
    cin >> num_of_pieces;

    vector<vector<int>> pieces(num_of_pieces, vector<int>(3));
    vector<int> k(plate_height + 1, 0);
    vector<int> v(plate_width + 1, 0);

    for (int i = 0; i < num_of_pieces; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    for (int i = 1; i <= plate_height; i++) {
        int max_val = 0;
        int max_height = 0;
        int cur_val = 0;

        for (int w = 1; w <= plate_width; w++) {
            cur_val = 0;
            int max_val_i = 0;

            for (int j = 0; j < num_of_pieces; j++) {
                int piece_width = pieces[j][0];
                int piece_height = pieces[j][1];
                int piece_val = pieces[j][2];

                if (w - piece_width >= 0) {
                    if (v[w - piece_width] + piece_val > max_val_i && piece_height <= i) {
                        max_val_i = v[w - piece_width] + piece_val;
                        max_height = piece_height;
                    }
                } 
                if (piece_height <= w) {
                    if (piece_width <= i && v[w - piece_height] + piece_val > max_val_i) {
                        max_val_i = v[w - piece_height] + piece_val;
                        max_height = piece_width;
                    }
                }
            }
            v[w] = max_val_i;
            cur_val = v[w];
        }
        if (i - max_height >= 0 && k[i - max_height] + cur_val > max_val) {
                max_val = k[i - max_height] + cur_val;
            }
        fill(v.begin(), v.end(), 0);
        k[i] = max_val;
    }
    cout << k[plate_height] << endl;
    return 0;
}
