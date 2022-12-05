#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char tab[3][3] = { {' ', ' ', ' ' }, {' ', ' ', ' '}, {' ', ' ', ' '} };
unsigned short tour = 0;
int colors[4] = { 31, 34, 32, 33 };

void display() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (tab[i][j] != ' ') {
                cout << " \033[" << colors[tab[i][j] == 'o'] << "m" << tab[i][j] << " ";
            }
            else {
                cout << " \033[" << colors[2] << "m" << i * 3 + j + 1 << " ";
            }

            if (j != 2) {
                cout << "\033[" << colors[3] << "m|";
            }
        }

        if (i != 2) {
            cout << endl << "\033[" << colors[3] << "m---+---+---" << endl;
        }
    }
    cout << " \033[0m";

    cout << endl << endl << "Choose fild :D" << endl << endl;
}

void action(int field) {
    int x, y;
    y = (field - 1) % 3;
    x = (field - 1) / 3;

    if (x >= 3) {
        cout << endl << "Wrong value, please enter again :D" << endl;
    }
    else if (tab[x][y] == ' ') {
        tab[x][y] = "xo"[tour++ % 2];
        display();
    }
    else {
        cout << endl << "This field is already taken you stupid man!!!" << endl;
    }
}


int main()
{
    display();

    while (tour != 9) {
        string temp = " ";
        getline(cin, temp); // <-- https://www.algorytm.edu.pl/biblioteki/string/getline.html

        try {
            int field = stoi(temp);
            action(field);
        }
        catch (const exception&) {
            cout << endl << "Wrong value, please enter again :D" << endl;
        }
    }



    /* X |   | O
       ---+---+---
       X | O |
       ---+---+---
      | X | O |    */


}
