#include <stdio.h>

int main(){
 int num = 5, guess; 
 printf("Enter guess: ");
 scanf("%d", &guess);
 if(num == guess){
  printf("Guess correct.");
 }else{
  printf("Guess failed.");
 }
 return 0;
}
