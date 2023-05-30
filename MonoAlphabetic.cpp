
MonoAlphabetic
==================================================================
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

typedef vector <char> CharVec;
CharVec Plain;
CharVec Cipher;

void PutCharInVec ()
{
    cout << "Plain: " << endl;
    for(int i = 0; i < 26; i++) {
        Plain.push_back(i+97);  // Assigning the plain characters in Vector
    }

    for(int i = 0; i < 26; i++) {
        cout << Plain[i] << "\t" ;
    }
    cout << endl;
    // Assigning the random characters in Vector to use as key
    cout << "Cipher: " << endl;

    int num;
    for(int i = 0; i < 26; i++) {
    //  Generating unique random numbers as keys
        bool exist = true;
        while (exist) {
            exist = false;
            num = rand() % 26;
            for (vector <char> :: iterator it = Cipher.begin(); it != Cipher.end(); it++) {
                if ((*it) == num + 65) {
                    exist = true;
                    break;
                }
            }
        }
        if (!exist)
            Cipher.push_back(num + 65);
    }

    for(int i = 0; i < 26; i++) {
        cout << Cipher[i] << "\t" ;
    }
    cout << endl;

}

char Monoalphabetic (char c)
{
     // Encryption
     if (c != toupper(c)) {
        for (int i = 0; i < 26; i++) {
            if (Plain[i] == c) {
                return Cipher[i];
            }
        }
     }
    // Decryption
     else {
        for (int i = 0; i < 26; i++) {
            if (Cipher[i] == c) {
                return Plain[i];
            }
        }
     }
     return 0;
}

int main ()
{
    string input, output;

    PutCharInVec();
    int choice = 0;

    while (choice != 2) {
        cout << endl << "Press 1: Encryption/Decryption; Press 2: quit: " ;

        try {
            cin >> choice;
            cin.ignore();
            if (choice != 1 && choice != 2) throw "Incorrect Choice";
        }
        catch (const char* chc) {
            cerr << "INCORRECT CHOICE !!!!" << endl;
            return 1;
        }
        if (choice == 1) {
            try {
                cout << endl << "NOTE: Put LOWER CASE letters for encryption and" << endl;
                cout << "UPPER CASE letters for decryption" << endl;
                cout << endl << "Enter cipertext (only alphabets) and press enter to continue: ";
                getline(cin, input);

                for (int i = 0; i < input.size(); i++) {
                    if ((!(input[i] >= 'a' && input[i] <= 'z')) && (!(input[i] >= 'A' && input[i] <= 'Z'))) throw "Incorrect string";
                }
            }
            catch (const char* str) {
                cerr << "YOUR STRING MAY HAVE DIGITS OR SPECIAL SYMBOLS !!!" << endl;
                cerr << "PLEASE PUT ONLY ALPHANBETS !!! " << endl;
                return 1;
            }

            for(unsigned int x = 0; x < input.length(); x++) {
                output += Monoalphabetic(input[x]);
            }

            cout << output << endl;
            output.clear();
        }

    }
    return 0;
}
