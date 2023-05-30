#include <iostream>
#include <string>
using namespace std;

bool ExistInKeyMatrix (char km[5][5], char ch) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (km[i][j] == ch)
                return true;
        }
    }
    return false;
}

void PrintKeyMatric (char km[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (km[i][j] == 'i')
                cout << "i/j" << "\t";
            else
                cout << km[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void InitializeKeyMatric (char km[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            km[i][j] = '\0';
        }
    }
}

void KeyMatrixGeneration (char km[5][5], string key) {
    int row = -1;
    int col = -1;
    for (int i = 0; i < key.length(); i++) {
        if (!ExistInKeyMatrix(km, key[i])) {
            int r = ++row / 5;
            int c = ++col % 5;
            km[r][c] = key[i];
        }
    }

    for (int i = 0; i < 26; i++) {
        if (char(i + 'a') == 'j') continue;
        if (!ExistInKeyMatrix(km, char(i + 'a'))) {
            int r = ++row / 5;
            int c = ++col % 5;
            km[r][c] = char(i + 'a');
        }
    }
}

string PreProcessingP (string p) {
    for (int i = 0; i < p.length(); i = i + 2) {
        if (i + 1 < p.length()) {
            if (p[i] == p [i+1]) {
                p.insert(i+1, "x");
            }
        }
    }
    if (p.length() % 2)
        p.push_back('x');
    return p;
}

void FindRowAndCol (char km[5][5], char ch, int *r, int *c) {
    if (ch == 'j') ch = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (km[i][j] == ch) {
                *r = i;
                *c = j;
            }
        }
    }
}

string Encryption (char km[5][5], string p) {
    string pp = PreProcessingP(p); //pp -> processed plaintext
    string ct (pp.length(), '\0');
    for (int i = 0; i < pp.length(); i = i + 2) {
        int r1, c1, r2, c2;
        FindRowAndCol(km, pp[i], &r1, &c1);
        FindRowAndCol(km, pp[i+1], &r2, &c2);
        if (r1 == r2) {
            c1 = ++c1 % 5;
            c2 = ++c2 % 5;
            ct[i] = km[r1][c1];
            ct[i+1] = km[r2][c2];
        }
        else if (c1 == c2) {
            r1 = ++r1 % 5;
            r2 = ++r2 % 5;
            ct[i] = km[r1][c1];
            ct[i+1] = km[r2][c2];
        }
        else  {
            ct[i] = km[r1][c2];
            ct[i+1] = km[r2][c1];
        }
    }
    return ct;
}

int main()
{
    char KeyMatrix [5][5];
    InitializeKeyMatric(KeyMatrix);
    string key = "cryptography";
    KeyMatrixGeneration(KeyMatrix, key);
    PrintKeyMatric(KeyMatrix);
    string plaintext = "wearediscoveredsaveyourself";
    string ciphertext = Encryption(KeyMatrix, plaintext);
    cout << plaintext << endl;
    cout << ciphertext << endl;
    return 0;
}