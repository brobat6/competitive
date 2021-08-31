#include <stdio.h>
int main() {
    int a[3][3],b[3][3];
    for(int j=0;j<3;j++) {
        for(int k=0;k<3;k++) {
            scanf("%d",&a[j][k]);
        }
    }
    for(int j=0;j<3;j++) {
        for(int k=0;k<3;k++) {
            scanf("%d",&b[j][k]);
        }
    }
    int c[3][3];
    for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            c[i][j] = 0;
            for (int k=0;k<3;k++) {
                c[i][j] += (a[i][k]*b[k][j]);
            }
        }
    }
    for (int i=0;i<3;i++) {
        printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
    }
    return 0;
}