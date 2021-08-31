#include <iostream>
#include <fstream>
using namespace std;

// Program takes 256 byte file as input and creates 128 byte file as output.

char convert(char num[]) {
   int len = 2;
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (num[i]>='0' && num[i]<='9') {
         temp += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temp += (num[i] - 55)*base;
         base = base*16;
      }
   }
   return static_cast<char>(temp);
}

char display(char s[]) {
    int len = 32;
    cout << "Size of file - " << len << " bytes" << endl;
    char temp[2];
    cout << "File name - ";
    for(int i=0; i<5; i++) {
        temp[0] = s[2*i];
        temp[1] = s[2*i + 1];
        cout << convert(s);
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.bin", "w", stdout);
    char f[256];
    for(int i=1; i<=128; i++) {
        char a[2];
        cin >> a[0] >> a[1];
        f[2*i - 2] = a[0];
        f[2*i - 1] = a[1];
        cout << convert(a);
    }

    for(int i=0; i<4; i++) {
        char temp[32];
        for(int j=0; j<64; j+=2) {
            temp[j] = f[8*i + j];
            temp[j+1] = f[8*i + j + 1];
        }
        display(temp);
    }
}