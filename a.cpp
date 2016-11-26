#include<stdio.h>
#include<string.h>

void frobenius1(int a, int b){
  printf("%d\n", a * b - a - b);
}


// Unknown algorithm
void frobenius2(int a, int b, int c, int d){
  bool f[10001],ff[1010001];
  int i,j,aryLength,max,t,count,flag;
  aryLength = 4;
  int ary[aryLength];
  memset(f,0,sizeof(f));
  memset(ff,0,sizeof(ff));

  ary[0] = a; f[a] = 1;
  ary[1] = b; f[b] = 1;
  ary[2] = c; f[c] = 1;
  ary[3] = d; f[d] = 1;

  ff[0]=1;
  count=1;
  max=0;
  for(i=0; i < 1000000;i++){
    flag=0;
    for(j = 0; j < aryLength; j++){
      if( i-ary[j] >= 0 && ff[i-ary[j]] == 1) {
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
    for(j=1; j <= aryLength; j++){
      if(i-ary[j]>=0 && ff[i-ary[j]]) {
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
void frobenius3(int* a){

}



int main(){
  frobenius1(4, 7);
  frobenius2(4, 6, 9, 20);
}
