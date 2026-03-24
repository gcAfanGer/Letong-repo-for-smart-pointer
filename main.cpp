#include <iostream>
#include <memory>
#include <fstream>
#include <string>
using namespace std;

int getEnter() {
    char dummy;
    while (cin >> dummy) {
        getchar();
        if (dummy == 'n') {
            return 0;
        }
        if (dummy == 'Q') {
            return 1;
        }
    }
    return 0;
}

int main() {
    ifstream Fil;
    Fil.open("present.txt");
    if (!Fil.is_open()) {
        cout << "Could not open file" << endl;
    }

    string str;
    while (getline(Fil, str)) {
        cout << str << endl;
        if (getEnter()==1) {
            cout << "skipping the text file";
            Fil.close();
            break;
        }
    }



}
