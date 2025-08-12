#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

// Classifies distance into words
std::string heatWord(int d) {
    if (d == 0)        return "Bingo!";
    if (d <= 3)        return "Boiling hot";
    if (d <= 10)       return "Hot";
    if (d <= 20)       return "Warm";
    if (d <= 30)       return "Cool";
    return "Cold";
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    const int secret = std::rand() % 100 + 1;  // 1..100

    std::cout << "I'm thinking of a number between 1 and 100.\n";
    std::cout << "Type your guess. I'll say Hot/Cold and whether you're getting Hotter or Colder.\n\n";

    int tries = 0;
    int prevDiff = -1;            // previous |guess - secret| (unknown yet)
    while (true) {
        std::cout << "Enter your guess: ";
        int guess;
        if (!(std::cin >> guess)) {                      // input validation
            std::cout << "Invalid input. Please enter a number.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (guess < 1 || guess > 100) {                  // keep within range
            std::cout << "Please guess between 1 and 100.\n";
            continue;
        }

        ++tries;
        int diff = std::abs(guess - secret);

        // Proximity feedback
        std::cout << heatWord(diff);

        if (diff == 0) {
            std::cout << " You got it in " << tries << " tries!\n";
            break;
        }

        // Direction (higher/lower) + hotter/colder trend
        std::cout << " — " << (guess < secret ? "Too low" : "Too high");

        if (prevDiff != -1) {
            if (diff < prevDiff)      std::cout << " (Hotter)";
            else if (diff > prevDiff) std::cout << " (Colder)";
            else                      std::cout << " (Same heat)";
        }
        std::cout << ". Try again.\n";

        prevDiff = diff;
    }
    return 0;
}
