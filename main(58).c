#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strings.h>
void swap(int i,int j,int k, int* mas1,int* mas2 ){
    int tmp = mas1[k];
    mas1[k] = mas1[j];
    mas1[j] = mas1[i];
    mas1[i] = tmp;
    mas2[mas1[i]] = i;
    mas2[mas1[j]] = j;
    mas2[mas1[k]] = k;
return;
}


int main() {
int n,i,j,k,z,flag,sdvig;
scanf("%d",&n);
int *mas=malloc(n*sizeof(int));
int *mas1=malloc(n*sizeof(int));
int *mas2=malloc(n*sizeof(int));
for(i=0;i<n;i++){
    scanf("%d",&mas[i]);
    mas[i]-=1;
    mas1[i]=i;
    mas2[i]=i;}
 for (i = 0; i < n - 2; i++) {
        if (mas1[i] != mas[i]) {
            int j = mas2[mas[i]];
            if (j != n - 1) {
                swap(n - 1, j, i,mas1,mas2);
            } else {
                swap(n - 2, j, i,mas1,mas2);
            }
        }
    }
    if(mas1[n - 1] != mas[n - 1]){
        printf("Odd");
    }
    else{printf("Even");}
    return 0;
}