#include <stdio.h>

int main(){
 int secretNum = 5, guess, win = 0; // 0 -> false; 
 for(int i=0; i<3; ++i){
    printf("Number of tries left: %d.\n", 3-i);
    printf("Enter guess: ");
    scanf("%d", &guess);
    if(secretNum == guess){
        printf("Guess correct.\n");
        win = 1; // 1 -> true; basically non-zero natural numbers = true;
        break;
    }else{
        printf("Guess failed.\n");
        win = 0;
    }
 }
 if(win){
    printf("Well played game. You\'re a true guesser.\n");
 }else{
    printf("Too bad you lost, better luck next time.\n");
 }
 return 0;
}
