# Number Guessing Game (C++)

A simple console **Hot/Cold** number guessing game written in C++.  
You guess a number between 1–100; the program tells you if you’re *Boiling hot, Hot, Warm, Cool, Cold* and whether you’re getting **Hotter** or **Colder** compared to your previous guess.

## Features
- Input range checks (1–100) and invalid-input handling
- Warmer/Colder feedback based on distance to the secret number
- Simple, beginner-friendly structure

## Build & Run
### Using g++
```bash
g++ -std=c++17 practice.cpp -o practice
./practice
