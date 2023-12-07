#include <iostream>
#include <vector>
using namespace std;

int plate_height, plate_width, num_of_pieces;
vector<vector<int>>k;
vector<vector<int>>pieces;

void parse_instance() {

    int x, y, v;
    cin >> plate_height >> plate_width;
    cin >> num_of_pieces;

    k.resize(plate_height + 1, vector<int>(plate_width + 1, 0));
    pieces.resize(plate_height + 1, vector<int>(plate_width + 1, 0));

    for (int i = 0; i < num_of_pieces; i++) {
        cin >> x >> y >> v;
        if (x <= plate_height && y <= plate_width)
            pieces[x][y] = v;
        if (y <= plate_height && x <= plate_width)
            pieces[y][x] = v;
    }
}

int compute() {
    for (int i = 1; i <= plate_height; i++) {
        for (int j = 1; j <= plate_width; j++) {
            k[i][j] = pieces[i][j];
            if (j <= plate_height && i <= plate_width && pieces[j][i] > k[i][j]){
                k[i][j] = pieces[j][i];
            }
            for (int a = 1; a <= i; a++) {
                k[i][j] = max(k[i][j], k[a][j] + k[i - a][j]);
            }
            for (int b = 1; b <= j; b++) {
                k[i][j] = max(k[i][j], k[i][b] + k[i][j - b]);
            }
        }
    }
    return k[plate_height][plate_width];
}

int main() {
    parse_instance();
    int output = compute();
    cout << output << endl;
    return 0;
}