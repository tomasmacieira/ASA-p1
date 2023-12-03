// ASA2023 P1 - Tomás Macieira & Guilherme Henriques

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int plate_width, plate_height, num_of_pieces;

    cin >> plate_height >> plate_width;
    cin >> num_of_pieces;

    vector<vector<int>> pieces(num_of_pieces, vector<int>(3));
    vector<vector<int>> k(plate_height + 1, vector<int>(plate_width + 1, 0));

    for (int i = 0; i < num_of_pieces; i++) {
        cin >> pieces[i][0] >> pieces[i][1] >> pieces[i][2];
    }

    int contador = 0;

    for (int i = 1; i <= plate_height; i++) {
        for (int j = 1; j <= plate_width; j++) {
            for (int a = 1; a <= i; a++) {
                k[i][j] = max(k[i][j], k[a][j] + k[i - a][j]);
                //printf("\nH-> i: %d, j: %d, a: %d, k[i][j]: %d\n", i, j, a, k[i][j]);
                contador++;
            }
            for (int b = 1; b <= j; b++) {
                k[i][j] = max(k[i][j], k[i][b] + k[i][j - b]);
                //printf("\nV-> i: %d, j: %d, b: %d, k[i][j]: %d\n", i, j, b, k[i][j]);
                contador++;
            }
            for (const vector<int>& piece : pieces) {
                if (piece[0] <= i && piece[1] <= j) {
                    k[i][j] = max(k[i][j], k[i - piece[0]][j - piece[1]] + piece[2]);
                    //printf("\nPN-> i: %d, j: %d, k[i][j]: %d\n", i, j, k[i][j]);
                    contador++;
                }
                if (piece[1] <= i && piece[0] <= j) { // Rotação da peça
                    k[i][j] = max(k[i][j], k[i - piece[1]][j - piece[0]] + piece[2]);
                    //printf("\nPR-> i: %d, j: %d, k[i][j]: %d\n", i, j, k[i][j]);
                    contador++;
                }
            }
        }
    }
    cout << "---------------" << endl;
    for (int w = 0; w <= plate_width; w++) {
        for (int i = 0; i <= plate_height; i++) {
            cout << k[i][w] << " ";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    cout << k[plate_height][plate_width] << endl;
    cout << contador << endl;
    return 0;
}





