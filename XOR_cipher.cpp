/*
 * #include <iostream>
using namespace std;
int main() {
int lnth,wdth;
cout << " Enter Width and length of trapezoid:  ";
cin >> wdth >> lnth;
int qq=wdth;
if (wdth/lnth >= 2){
    for (int i=0; lnth > i; i++){
        for (int q = i; q > 0; q--){
            cout<<" ";
        }
        for (int ii=qq; ii>0; ii --){
            cout <<"*";
        }
        qq -=2;
        cout << endl;
    }
}
else cout <<"Imposable trapezoid ";
    }
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    // Welcome message and options
    cout << "Welcome to XOR Cipher Program" << endl;
    cout << "You can enter any message to cipher it or any encrypted message to decrypt it" << endl;
    cout << "1-Cipher 2-Decipher 3-Exit" << endl;

    // Variable to store user's choice
    char choice;
    cin >> choice;
    cin.ignore(); // Consume the newline character

    // Cipher operation
    if (choice == '1') {
        string message;
        cout << "Enter plain text you want to cipher: ";
        getline(cin, message);

        string xorKey;
        cout << "Enter secret key you need to use: ";
        cin >> xorKey;

        string cipheredText;
        unsigned long length = message.length();
        int index = 0;

        cout << "Ciphered text: ";
        // Cipher each character in the message
        for (int i = 0; length > i; i++) {
            if (index == xorKey.length())
                index = 0;

            char encryptedChar = message[i] ^ xorKey[index];
            cipheredText += encryptedChar;
            index++;

            if (isprint(encryptedChar)) // Check if the character is printable
                cout << encryptedChar;
        }

        // Display ciphered text in hexadecimal form
        cout << endl << "Hexadecimal: ";
        for (int j = 0; j < length; j++) {
            cout << hex << setw(2) << setfill('0') << static_cast<int>(cipheredText[j]) << " ";
        }
    }

        // Decipher operation
    else if (choice == '2') {
        cout << "Please enter the message you want to decrypt in hexadecimal form: ";
        string encryptedMessage;
        getline(cin, encryptedMessage);

        // Remove non-hexadecimal characters from the message
        for (int i = 0; i < encryptedMessage.length(); ) {
            if (!isxdigit(encryptedMessage[i])) // Check if character is not a hexadecimal digit
                encryptedMessage.erase(i, 1); // Remove non-hexadecimal characters
            else
                i++; // Move to the next character
        }

        string xorKey;
        cout << "Enter secret key you want to use: ";
        cin >> xorKey;

        int keyIndex = 0;
        stringstream ss;

        cout << "Deciphered text: ";
        // Decipher each pair of hexadecimal characters
        for (int i = 0; i < encryptedMessage.length(); i += 2) {
            if (keyIndex == xorKey.length()) // Wrap around if xorKey is shorter than the message
                keyIndex = 0;

            string pair = encryptedMessage.substr(i, 2);
            int hexValue;
            ss.clear();
            ss << hex << pair;
            ss >> hexValue;

            // Decipher and print the character
            if (hexValue >= 0) {
                char character = static_cast<char>(hexValue);
                character = character ^ xorKey[keyIndex];
                cout << character;
            }
            keyIndex++;
        }
    }

        // Exit
    else if (choice == '3') {
        cout << "Thanks for using XOR cipher." << endl;
    }

    return 0;
}


