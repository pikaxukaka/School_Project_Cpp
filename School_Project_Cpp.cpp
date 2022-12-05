#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

char **tab;
unsigned short tour = 0;
int colors[4] = { 31, 34, 32, 33 };
int tabsize = 3;

void display() {
    for (int i = 0; i < tabsize; i++) {
        for (int j = 0; j < tabsize; j++) {
            
            if (tab[i][j] != ' ') {
                cout << " \033[" << colors[tab[i][j] == 'o'] << "m" << tab[i][j] << " ";
            }
            else {
                cout << "\033[" << colors[2] << "m";
                unsigned short number = i * tabsize + j + 1;

                if (number / 100 == 0) {
                    cout << " ";
                }

                cout << number;

                if (number / 10 == 0) {
                    cout << " ";
                }
                

            }

            if (j < tabsize - 1) {
                cout << "\033[" << colors[3] << "m|";
            }
        }

        if (i < tabsize - 1) {
            cout << endl << "\033[" << colors[3] << "m";
            for (int k = 0; k < tabsize - 1; k++) {
                cout << "---+";     
            }
            cout << "---" << endl;
        }
    }
    cout << " \033[0m";

    cout << endl << endl << "Choose fild :D" << endl << endl;
}

void action(int field) {
    int x, y;
    y = (field - 1) % tabsize;
    x = (field - 1) / tabsize;

    if (x >= tabsize) {
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
    string temp = " ";

    cout << "Choose size of the board --> ( 3 - 20 )" << endl;

    do {
        getline(cin, temp);
        
        try {
            tabsize = stoi(temp);
        }
        catch (const exception&) {
            cout << endl << "Wrong value, please enter again :D" << endl;
        }

    } while (tabsize < 3 || tabsize > 20);

    tab = new char* [tabsize];
    
    for (int i = 0; i < tabsize; i++) {
        tab[i] = new char[tabsize];
        for (int j = 0; j < tabsize; j++) {
            tab[i][j] = ' ';
        }
    }

    display();

    while (tour != tabsize * tabsize) {
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
