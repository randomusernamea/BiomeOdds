#include <iostream>
#include <vector>
 
using namespace std;
typedef vector<vector<double>> Matrix;
 
Matrix multiplyMatrix(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                result[i][j] += A[i][k] * B[k][j];
    return result;
}
 
Matrix matrixExponentiation(Matrix base, long long exp) {
    int n = base.size();
    Matrix result(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i)
        result[i][i] = 1.0;
 
    while (exp > 0) {
        if (exp % 2 == 1)
            result = multiplyMatrix(result, base);
        base = multiplyMatrix(base, base);
        exp /= 2;
    }
    return result;
}
 
int main() {
    const int N = 33;
    Matrix P = {
    // Slum
    {0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Construction site
    {0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,  0.0},
    // Laboratory
    {0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Metropolis
    {1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Power
    {0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Factory
    {0.0,    0.0,    0.125,  0.0,    0.0,    0.0,    0.0,    0.0,    0.875,  0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Dojo
    {0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    5.0/6.0,    0.0,    0.0,    0.0,    0.0,    1.0/6.0, 0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Meadow
    {0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.75,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.25,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Plains
    {0.0,    0.0,    0.0,    1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Grass Fields
    {0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Jungle
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Forest
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Tall Grass
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Temple
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/6.0,    0.0,    5.0/6.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Ruins
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Desert
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Swamp
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Graveyard
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Fairy
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/6.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    5.0/6.0,    0.0,    0.0,    0.0,    0.0},
    // Space
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Abyss
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    4.0/27.0,    0.0,    0.0,    19.0/27.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   4.0/27.0,    0.0,    0.0},
    // Lake
    {0.0,   1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,      1.0/3.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,   0.0},
    // Cave
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Badlands
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0, 0.0,    0.5},
    // Snow Forest
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.5,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,     0.0},
    // Beach
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.125,    0.0,    0.0,    0.875,    0.0,    0.0,     0.0},
    // Island
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0},
    // Seabed
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.875,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.125,     0.0},
    // Ice Cave
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,     0.0},
    // Sea
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Waste
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0},
    // Volcano
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.875,    0.0,    0.0,    0.125,    0.0,    0.0,    0.0,    0.0},
    // Mount
    {0.0,   0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    0.0,    1.0/6.0,    5.0/6.0,    0.0}
};
 
    long long turns = 1000000000; // 1 billion
 
    // Where you start, useful if you want a small number of turns for w/e reason.
    vector<double> initial_state(N, 0.0);
    initial_state[8] = 1.0; 
 
    Matrix P_exp = matrixExponentiation(P, turns);
 
    vector<double> final_state(N, 0.0);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            final_state[i] += initial_state[j] * P_exp[j][i];
    vector<string> locations = {"Slum","Construction Site",	"Laboratory",	"Metropolis",	"Power Plant",	"Factory",	"Dojo",	"Meadow",	"Plains",	 "Grass Fields", "Jungle",	 "Forest",	 "Tall Grass",	 "Temple",	  "Ancient Ruins",	  "Desert",  "Swamp",   "Graveyard",	  "Fairy Cave",	  "Space",	  "Abyss",	  "Lake",	  "Cave",	  "Badlands",	  "Snowy Forest",   "Beach",	  "Island",  "Seabed",    "Ice Cave",	  "Sea",     "Wastelands",   "Volcano",    "Mountain"};
    double auxS = 0;
    for (int i = 0; i < N; ++i){
        auxS += final_state[i];
        cout << "Probability of being at " << locations[i] << " after " << turns << " turns: " << 100*final_state[i] << "%" << endl;
    }
    cout << auxS;
    return 0;
}
