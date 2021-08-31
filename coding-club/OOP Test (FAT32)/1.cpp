#include <iostream>
#include <fstream>
using namespace std;

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
}