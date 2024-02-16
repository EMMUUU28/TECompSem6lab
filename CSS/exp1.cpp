#include <bits/stdc++.h>
using namespace std;
class Affine {
public:
    string encrypt(string plain, int k1, int k2) {
        string p = toUpper(plain);
        int l = plain.length();
        string s;
        for (int i = 0; i < l; i++) {
            char c = p[i];
            int ch = c - 'A';
            int ci = (ch * k1) + k2;
            int mod = ci % 26;
            char cip = mod + 'A';
            s += cip;
        }
        return s;
    }

    string decrypt(string cipher, int k1, int k2) {
        string p = toUpper(cipher);
        int l = cipher.length();
        string s;
        for (int i = 0; i < l; i++) {
            char c = p[i];
            int ch = c - 'A';
            int k = inverse(k1);
            int ci = (ch - k2) * k;
            if (ci < 0) {
                int cnew = (ci % 26) + 26;
                char cip = cnew + 'A';
                s += cip;
            } else {
                int mod = ci % 26;
                char cip = mod + 'A';
                s += cip;
            }
        }
        return s;
    }

    int inverse(int base) {
        int in = 0;
        for (int i = 0; i < 26; i++) {
            if ((base * i) % 26 == 1) {
                in = i;
            }
        }
        return in;
    }

private:
    string toUpper(string str) {
        for (char &c : str) {
            c = toupper(c);
        }
        return str;
    }
};

int main() {
    Affine a;
    while (true) {
        cout << "Select an Option: 1. Encrypt 2. Decrypt\n";
        int n;
        cin >> n;
        switch (n) {
            case 1: {
                cout << "\nEnter PlainText: ";
                string plain;
                cin >> plain;
                cout << "\nEnter Key 1: ";
                int k1;
                cin >> k1;
                cout << "\nEnter Key 2: ";
                int k2;
                cin >> k2;
                string cipher = a.encrypt(plain, k1, k2);
                cout << "\nEncrypted Text is " << cipher << endl;
                break;
            }
            case 2: {
                cout << "\nEnter Cipher: ";
                string cipher;
                cin >> cipher;
                cout << "\nEnter Key 1: ";
                int k1;
                cin >> k1;
                cout << "\nEnter Key 2: ";
                int k2;
                cin >> k2;
                string plain = a.decrypt(cipher, k1, k2);
                cout << "\nDecrypted Text is " << plain << endl;
                break;
            }
            default:
                cout << "\nEnter correct choice\n";
        }
    }
    return 0;
}
