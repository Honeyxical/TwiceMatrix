#include <iostream>
#include <ctime>
using namespace std;

int getRandom();

int main() {
    srand (time(NULL));

    int n = 0;
    int m = 0;
    int min = 0;
        int minI = 0;
        int minJ = 0;
    int max = 0;
        int maxI = 0;
        int maxJ = 0;
    int temp = 0;
        int tempI = 0;
        int tempJ = 0;

    cout << "Write row m: ";
    cin >> m;
    cout << "Write column n:";
    cin >> n;

    int mass[m][n];
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            mass[i][j] = getRandom();
            cout << "\t" <<mass[i][j] << " ";
        }
        cout << endl;
    }

    min = mass[1][1];
    max = mass[0][0];

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            if(mass[i][j] > max){
                max = mass[i][j];
                maxI = i;
                maxJ = j;
            } else if(mass[i][j] < min){
                min = mass[i][j];
                minI = i;
                minJ = j;
            }
        }
    }

    cout << "Max: " << max << " position: i = " << maxI << " j = " << maxJ
         << "\nMin: " << min << " position: i = " << minI << " j = " << minJ << endl;

    mass[minI][minJ] = max;
    mass[maxI][maxJ] = min;

    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++) {
            cout << "\t" <<mass[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int getRandom(){
    return rand() % 100;
}