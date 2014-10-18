#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,x, A[101][101], B[101][101], maxSubRectz, subRectz, subRecto;

int main() {
  while (1){

scanf("%d %d", &n,&m);
if (n == 0 && m == 0) return 0;

  
for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    scanf("%d", &x);

    if (x==0){A[i][j]=1; B[i][j]=0;}
   else{A[i][j]=0; B[i][j]=1;}
  


    if (i > 0) A[i][j] += A[i - 1][j] ; B[i][j] += B[i-1][j];
   




    if (j > 0) A[i][j] += A[i][j-1] ; B[i][j] += B[i][j-1];
     



   
    if (i > 0 && j > 0) A[i][j] = A[i][j] - A[i-1][j-1] ; B[i][j] = B[i][j] - B[i-1][j-1];
     

 }


  maxSubRectz = 0;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
    for (int k = i; k < n; k++) for (int l = j; l < m; l++) {
      subRectz = A[k][l]; subRecto = B[k][l];     
      if (i > 0) {subRectz -= A[i - 1][l]; subRecto -= B[i - 1][l];}                               
      if (j > 0) {subRectz -= A[k][j - 1]; subRecto -= B[k][j-1];}                              
      if (i > 0 && j > 0) {subRectz += A[i - 1][j - 1]; subRecto += B[i - 1][j - 1]; }          

      if (subRecto == 0){ maxSubRectz = max(maxSubRectz, subRectz);} }


  printf("%d\n", maxSubRectz); 

  }
  return 0;

}

