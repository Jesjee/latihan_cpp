#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int evaluasiPostfix(const string& ekspresi) {
    stack<int> s;
    stringstream ss(ekspresi);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Jika token adalah angka, ubah ke integer dan push ke stack
            s.push(stoi(token));
        } else {
            // Operator: ambil dua elemen teratas dari stack
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            if (token == "+") s.push(a + b);
            else if (token == "-") s.push(a - b);
            else if (token == "*") s.push(a * b);
            else if (token == "/") s.push(a / b);
        }
    }

    return s.top();
}

int main() {
    string ekspresi1 = "2 3 +";
    string ekspresi2 = "5 3 * 8 +";

    cout << "Hasil dari \"" << ekspresi1 << "\" adalah: " << evaluasiPostfix(ekspresi1) << endl;
    cout << "Hasil dari \"" << ekspresi2 << "\" adalah: " << evaluasiPostfix(ekspresi2) << endl;

    return 0;
}
