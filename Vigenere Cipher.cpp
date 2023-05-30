Vigenere Cipher
=================================================================
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char vigenere_table[26][26] = {
'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A',
'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B',
'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C',
'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D',
'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E',
'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F',
'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
'U', 'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'V', 'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
'W', 'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
'X', 'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
'Y', 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y'
};

void Encrypt (string in, string &out, string k) {
    int i = 0;
    for (string :: iterator it = in.begin(); it != in.end(); it++) {
        if (*it != ' ') {
            int row = toupper(*it) - 'A';
            int column = toupper(k[i % k.length()]) - 'A';
            out += vigenere_table[row][column];
        }
        else {
            out += ' ';
        }

        i++;
    }

}

void Decrypt (string in, string &out, string k) {
    int i = 0;
    for (string :: iterator it = in.begin(); it != in.end(); it++) {
        if (*it != ' ') {
            int column = toupper(k[i % k.length()]) - 'A';
            int row;
            for (row = 0; row < 26; row++) {
                if (vigenere_table[row][column] == *it) break;
            }
            out += 'A' + row;
        }
        else {
            out += ' ';
        }
        i++;
    }
}

int main ()
{
    string input, output, key;
	cout << "Put key value (put alphabets/words): ";
    getline(cin,key);
    int choice = 0;

    while (choice != 3) {
        cout << endl << "Press 1: Encryption, 2: Decryption; 3: quit: " ;

        try {
            cin >> choice;
            cin.ignore();
            if (choice != 1 && choice != 2 && choice != 3) throw "Incorrect Choice";
        }
        catch (const char* chc) {
            cerr << "INCORRECT CHOICE !!!!" << endl;
            return 1;
        }
        if (choice == 1 || choice == 2) {
            try {
                cout << endl << "Enter cipertext (only alphabets) and press enter to continue: ";
                getline(cin, input);

                for (int i = 0; i < input.size(); i++) {
                    if ((!(input[i] >= 'a' && input[i] <= 'z')) && (!(input[i] >= 'A' && input[i] <= 'Z')) && (!(input[i] == ' ')))
                        throw "Incorrect string";
                }
            }
            catch (const char* str) {
                cerr << "YOUR STRING MAY HAVE DIGITS OR SPECIAL SYMBOLS !!!" << endl;
                cerr << "PLEASE PUT ONLY ALPHANBETS !!! " << endl;
                return 1;
            }

            if (choice == 1) {
                Encrypt(input, output, key);
                cout << endl << "Cipher text: " << output << endl;
            }
            else if (choice == 2) {
                input = output;
                output.clear();
                Decrypt(input, output, key);
                cout << endl << "Plain text: " << output << endl;
            }
        }

    }
    return 0;
}

Playfair Cipher
==================================================================
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

char matrix[5][5];
string key;

void setKey (string k) { key = k; }
string getKey () { return key; }

void InitializeMatric ()
{
    //  Initializing the playfair matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix[i][j] = 0;
        }
    }
}

string keyWithoutDuplicateAlphabet (string k)
{
    string str_wo_dup; //string without duplicate alphabets

    for (string::iterator it = k.begin(); it != k.end(); it++) {
        bool alphabet_exist = false;
        for (string::iterator it1 = str_wo_dup.begin(); it1 != str_wo_dup.end(); it1++) {
            if (*it1 == *it) {
                alphabet_exist = true;
            }
        }

        if (!alphabet_exist) {
            str_wo_dup.push_back(*it);
        }
    }

    return str_wo_dup;
}

void setMatrix ()
{
    string kwda = keyWithoutDuplicateAlphabet(getKey());  //  Getting the key with unique characters

    int i_val, j_val;

    int count = 0;
    //  Populating the Playfair matrix with the key and other letters
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (count == kwda.length()) break;
            else {
                matrix[i][j] = toupper(kwda[(5 * i) + j]);
                ++count;
            }
        }
        if (count == kwda.length()) break;
    }

    for (int i = 0; i < 26; i++) {
        char ch = 65 + i;
        bool alphabet_exist = false;

        for (string::iterator it = kwda.begin(); it != kwda.end(); it++) {
            if (ch == toupper(*it)) {
                alphabet_exist = true;
            }
        }

        if (ch == 'J') alphabet_exist = true; //since i and j both co-exist in the same cell, we'll only put i in the cell

        bool exit = false;
        if (!alphabet_exist) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (!isalpha(matrix[i][j])) {
                        matrix[i][j] = toupper(ch);
                        exit = true;
                    }
                    if (exit == true) break;
                }
                if (exit == true) break;
            }
        }
    }
}

void showMatrix()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] != 'I') cout << matrix[i][j] << "\t";
            else cout << "I/J" << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int findRow (char ch)
{
    // Finding the specific row for a character
    if (ch == 'j') ch = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == toupper(ch)) { return i; }
        }
    }
    return -1;  // If not found
}

int findCol (char ch)
{
    // Finding the specific row for a character
    if (ch == 'j') ch = 'i';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == toupper(ch)) { return j; }
        }
    }
    return -1;  // If not found
}


string encrypt (string str)
{
    string output;

    // replace (by x) the repeating plaintext letters that are in the same pair
    for (int i = 1; i < str.length(); i = i + 2) {
        if (str[i-1] == str[i]) {
            string temp1, temp2;

            for (int j = 0; j < i; j++) {
                temp1.push_back(str[j]);
            }

            for (int j = i; j < str.length(); j++) {
                temp2.push_back(str[j]);
            }

            str.clear();
            str = temp1 + 'x' + temp2;
        }
    }

    for (int i = 0; i < str.length(); i = i + 2) {

        // for the letter pair falls in the same row
        if (findRow(str[i]) == findRow(str[i+1])) {
            output.push_back(matrix[findRow(str[i])][(findCol(str[i]) + 1) % 5]);
            output.push_back(matrix[findRow(str[i + 1])][(findCol(str[i + 1]) + 1) % 5]);
        }

        // for the letter pair falls in the same coloumn
        else if (findCol(str[i]) == findCol(str[i+1])) {
            output.push_back(matrix[(findRow(str[i]) + 1) % 5][findCol(str[i])]);
            output.push_back(matrix[(findRow(str[i + 1]) + 1) % 5][findCol(str[i + 1])]);
        }

        //for other cases
        else {
            output.push_back(matrix[findRow(str[i])][findCol(str[i + 1])]);
            output.push_back(matrix[findRow(str[i + 1])][findCol(str[i])]);
        }
    }


    if ((str.length() % 2) != 0) {
        output[output.length() - 1] = toupper(str[str.length() - 1]);
    }

    return output;
}

string decrypt (string str)
{
    string output;

    for (int i = 0; i < str.length(); i = i + 2) {

        // for the letter pair falls in the same row
        if (findRow(str[i]) == findRow(str[i+1])) {
            int y;
            if ((findCol(str[i]) - 1) >= 0) y = (findCol(str[i]) - 1);
            else y = 4;

            output.push_back(matrix[findRow(str[i])][y]);

            if ((findCol(str[i + 1]) - 1) >= 0) y = (findCol(str[i + 1]) - 1);
            else y = 4;

            output.push_back(matrix[findRow(str[i + 1])][y]);
        }

        // for the letter pair falls in the same coloumn
        else if (findCol(str[i]) == findCol(str[i+1])) {
            int x;
            if ((findRow(str[i]) - 1) >= 0) x = (findRow(str[i]) - 1);
            else x = 4;

            output.push_back(matrix[x][findCol(str[i])]);

            if ((findRow(str[i + 1]) - 1) >= 0) x = (findRow(str[i + 1]) - 1);
            else x = 4;

            output.push_back(matrix[x][findCol(str[i + 1])]);
        }

        //for other cases
        else {
            output.push_back(matrix[findRow(str[i])][findCol(str[i + 1])]);
            output.push_back(matrix[findRow(str[i + 1])][findCol(str[i])]);
        }
    }

    // remove x from the string
    for (int i = 0; i < output.length(); i++) {
        if (output[i] == 'X') {
            output.erase(output.begin() + i);
        }
    }

    return output;
}

int main () {
    string key, input;

    //  Input the key to generate Playfair matrix
    cout << "Put key value (put alphabets/words): " << endl;
    getline(cin,key);
    cout << key << endl;

    //  Generating the Playfair matrix
    setKey(key);
    setMatrix();
    showMatrix();

    cout << "Press 1: Encrypt | 2: Decrypt | 3: Quit" << endl;
    int choice;
    cin >> choice;

    while (choice != 3) {
            //  Input the data to encrypt or decrypt
        cout << "Put your text: ";
        fflush(stdin);
        getline(cin,input);

        if (choice == 1) cout << encrypt(input) << endl;
        else cout << decrypt(input) << endl;

        cout << "Press 1: Encrypt | 2: Decrypt | 3: Quit" << endl;
        cin >> choice;
    }
    return 0;
}