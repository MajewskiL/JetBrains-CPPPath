#include <iostream>
#include <random>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    random_device rd;   // Seed with a real random value, if available
    mt19937 gen(rd());  // Standard mersenne_twister_engine seeded with rd()

    std::string ans;
    std::string winner;
    std::unordered_map<int, std::string> c; 
    c[0] = "Rock"; 
    c[1] = "Paper"; 
    c[2] = "Scissors"; 
    while (true) {
        std::cout << "Welcome to the Rock, Paper, Scissors Game!\n" << std::endl;
        std::cout << "Please enter your name, number of repetitions,\nand your chosen steps" << std::endl;
        std::cout << "1 - Rock," << std::endl;
        std::cout << "2 - Paper," << std::endl;
        std::cout << "3 - Scissors\n" << std::endl;

        std::string user;
        int rounds = 0;
        std::cin >> user;
        std::cin >> rounds;
        std::cout << "> " << user << " ";
        std::cout << rounds << " ";

        std::string user_hands[rounds];
        std::string comp_hands[rounds];
        for (int i = 0; i < rounds; i++) {
            int random_choice = gen() % 3;
            comp_hands[i] = c[random_choice];
            std::cin >> user_hands[i];
            std::cout << user_hands[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "\nGame Start!" << std::endl;
        int user_score = 0;
        int comp_score = 0;
        
        for (int i = 0; i < rounds; i++) {
            
            ans = user_hands[i];
            if (user_hands[i] == "1" || user_hands[i] == "rock") ans = c[0];
            if (user_hands[i] == "2" || user_hands[i] == "paper") ans = c[1];
            if (user_hands[i] == "3" || user_hands[i] == "scissors") ans = c[2];
            
            std::cout << "Round " << i + 1 << ": Computer chose " << comp_hands[i] << ", " << user << " chose " << ans << ". Winner: ";

            for(char &ch : ans){
            ch = std::tolower(ch); 
            }
            for(char &ch : comp_hands[i]){
            ch = std::tolower(ch);
            }
            std::string comp = comp_hands[i];

            if ((ans == "rock" && comp == "paper") || (ans == "paper" && comp == "rock") ) {

                winner = (ans == "paper") ? user : "Computer";
            } else if ((ans == "scissors" && comp == "paper") || (ans == "paper" && comp == "scissors") ) {

                winner = (ans == "scissors") ? user : "Computer";

            } else if ((ans == "scissors" && comp == "rock") || (ans == "rock" && comp == "scissors") ) {

                winner = (ans == "rock") ? user : "Computer";
            } else if (ans == comp) {
                winner = "draw";
            } else {
                std::cout << "Invalid move. Please enter Rock, Paper, or Scissors";
                winner = "";
            }
            std::cout << winner << "." <<  std::endl;
            if (winner == user) {user_score++;}
            else if (winner == "Computer") {comp_score++;}
        }

        std::cout << "\nGame Over!" << std::endl;   
        std::printf("Total Score - %s: %d, Computer: %d\n", user.c_str(), user_score, comp_score);
        
        std::cout << "Would you like to play again? (yes/no)." << std::endl;
        std::string next_round;
        std::cin >> next_round;
        if (next_round == "no") {return 0;}
    } 
    return 0;
}   
