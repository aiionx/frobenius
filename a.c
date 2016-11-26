#include<stdio.h>
#include<string.h>


int gcd(int a, int b) {
   return (b == 0) ? a : gcd(b, a % b);
}

void frobenius1(int a, int b){
  printf("%d\n", a * b - a - b);
}


// Unknown algorithm
void frobenius2(int a, int b, int c, int d){
  bool f[10001],ff[1010001];
  int i,j,numsLength,max,t,count,flag;
  numsLength = 4;
  int nums[numsLength];
  memset(f,0,sizeof(f));
  memset(ff,0,sizeof(ff));

  nums[0] = a; f[a] = 1;
  nums[1] = b; f[b] = 1;
  nums[2] = c; f[c] = 1;
  nums[3] = d; f[d] = 1;

  ff[0]=1;
  count=1;
  max=0;
  for(i=0; i < 1000000;i++){
    flag=0;
    for(j = 0; j < numsLength; j++){
      if( i-nums[j] >= 0 && ff[i-nums[j]] == 1) {
        ff[i]=1;
        count++;
        flag=1;
        break;
      }
    }
    if(flag == 0) {
      max=i;
    }
  }
  t=0;
  for(i=1000000; i < 1010000; i++){
    flag=0;
    for(j=1; j <= numsLength; j++){
      if(i-nums[j]>=0 && ff[i-nums[j]]) {
        flag=1;
        ff[i]=1;
        break;
      }
    }
    if(flag==0){
      t=1;
      break;
    }
  }
  if(t){
    printf("Cant find answer");
  }else{
    printf("%d\n",max);
  }
}

// Sebastian Böcker & Zsuzsanna Lipták
void frobenius3(int w, int x, int y, int z){
  int i,j,d,r,n,q,p,max,numsLength;
  int nums[numsLength];
  numsLength = 4;
  nums[0] = w;
  nums[1] = x;
  nums[2] = y;
  nums[3] = z;
  int ns[nums[0]];
  memset(ns,-1,sizeof(ns));
  ns[0] = 0;
  for (int i = 1; i < numsLength; i++) {
      d = gcd(nums[0], nums[i]);
      for (r = 0; r < d; r++) {
          n = -1;
          if (r == 0){
            n = 0;
          } else {
              int q = r;
              while (q < nums[0]) {
                  if (ns[q] != -1 && (ns[q] < n || n == -1))
                      n = ns[q];
                  q += d;
              }
          }
          if (n != -1)
              for (j = 0; j < nums[0] / d; j++) {
                  n += nums[i];
                  int p = n % nums[0];
                  if (ns[p] != -1 && (ns[p] < n || n == -1))
                      n = ns[p];
                  ns[p] = n;
              }
      }
  }
  max = 0;
  for (i = 0; i < nums[0]; i++){
    if (ns[i] == -1 || ns[i] > max){
      max = ns[i];
    }
  }
  if (max == -1){
    printf("Cant find answer");
  } else {
    printf("%d\n", max - nums[0]);
  }

}



int main(){
  frobenius1(4, 7);
  frobenius2(4, 6, 9, 20);
  frobenius3(4, 6, 9, 20);
}
