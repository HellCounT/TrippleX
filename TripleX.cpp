#include <iostream>
#include <ctime>

void PrintIntro(int Difficulty)
{
    //Introduction
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room\nEnter the correct code to continue...\n\n";
}   

bool PlayGame(int Difficulty)
{
    PrintIntro(Difficulty);

    //Declare numbers  
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;

    //Output sum and prod
    std::cout << "+ There are three numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to: " << CodeProd << std::endl;

    //Store player guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProd = GuessA * GuessB * GuessC;

    //Comparison
    if (GuessSum == CodeSum && GuessProd == CodeProd)
    {
        std::cout << "\nYou've got the file! Great! Keep going to the next level!";
        return true;
    }
    else
    {
        std::cout << "\nYou've entered the wrong code. Please try again."; 
        return false;
    }
}

int main()
{
    srand(time(NULL)); //Create new random sequence based on time of day
    int LevelDifficulty = 1;
    int const MaxDifficulty = 4;

    while(LevelDifficulty <= MaxDifficulty) //Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty; //increase the level difficulty
        }
    }

    std::cout << "\nGreat you've got them all. Now it's time to escape!";
    return 0;
}