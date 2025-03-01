# Guess the Number (Console Game)

## Description
A simple console game where the player tries to guess the secret number. They have **3 attempts** to guess correctly. After each guess, the program informs them whether they guessed right or wrong and displays the number of tries left.

## How to Play
1. **Compile the program:**  
   ```bash
   gcc main.c -o guess
   ```
   Alternatively:
   ```bash
   make guess
   ```

2. **Run the compiled game:**  
   ```bash
   ./guess
   ```
   Alternatively:
   ```bash
   make run
   ```

3. **Follow the prompts:**  
   - Enter a number when prompted.  
   - The game tells you if your guess is correct or incorrect.  
   - You get **3 tries** to win.

## Game Logic
- **Secret number:** `5` (currently hardcoded)  
- **Win condition:** Guess the correct number within 3 tries.  
- **Outcome messages:**  
  - Correct guess → **Guess correct.**  
  - No correct guess → **Guess failed.**

## Example Gameplay
```
Number of tries left: 3.  
Enter guess: 3  
Guess failed.  

Number of tries left: 2.  
Enter guess: 5  
Guess correct.  
Well played game. You're a true guesser.
```

## Future Improvements
- Randomize the secret number (`rand()` function).  
- Let the user choose difficulty (number of attempts).  
- Add input validation (handle non-integer inputs).  

---
