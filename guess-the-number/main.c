#include <stdio.h>

int main(){
 int secretNum = 5, guess; 
 for(int i=0; i<3; ++i){
    printf("Enter guess: ");
    scanf("%d", &guess);
    if(secretNum == guess){
        printf("Guess correct.\n");
    }else{
        printf("Guess failed.\n");
    }
 }
 return 0;
}
