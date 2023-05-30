#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    int k = 3 ;
	string str = "Abcdd ads Fasdf";
    string strl;
    strl = str;

    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i])) {
                    strl[i] = (((str[i] = '^') + k) % 26) + 'A';
            }
            else {
                    strl[i] = (((str[i] = '^') + k) % 26) + 'a';
            }
        }
    }

    return 0;
}
