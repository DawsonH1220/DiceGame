#include <iostream>
#include <cstdlib>
#include <ctime>
int main(){
    std::cout << "WELCOME TO THE DICE GAME!" << std::endl;
    const int target{100};
    int player{};
    int turn{};
    int roll{};
    int min{1};
    int max{6};
    int score0{};
    int score1{};
    int current0{};
    int current1{};
    char move{};
    srand(time(nullptr));
        do{
            do{
                if(turn == 0){
                    std::cout << "PLAYER 1 TURN" << std::endl;
                }
                    std::cout << "Roll or keep(R/K): ";
                    std::cin >> move;
                if(move == 'r' || move == 'R'){
                    roll = 0;
                    roll = rand() % max + min;
                    if(roll != 1){
                        std::cout << "You rolled a " << roll << std::endl;
                        current0 += roll;
                        turn++;
                        std::cout << "You now have " << current0 << " points." << std::endl;
                        std::cout << "keep for a total of " << current0 + score0 << std::endl;
                    }else{
                        std::cout << "You rolled a 1" << std::endl;
                        std::cout << "You lost " << current0 << " points, should have kept." <<std::endl;
                        std::cout << "Total score: " << score0 << std::endl;
                        current0 = 0;
                        player = 1;
                        turn = 0;
                    }
                }
                    if(move == 'k' || move == 'K'){
                        score0 += current0;
                        turn = 0;
                        std::cout << "You kept " << current0 << " points, your total score is " << score0 << std::endl;
                        player = 1;
                        current0 = 0;
                }
        }while(player == 0);
        do{
            if(turn == 0){
                std::cout << "PLAYER 2 TURN" << std::endl;
            }
                std::cout << "Roll or keep(R/K): ";
                std::cin >> move;
            if(move == 'r' || move == 'R'){
                roll = 0;
                roll = rand() % max + min;
                if(roll != 1){
                    std::cout << "You rolled a " << roll << std::endl;
                    current1 += roll;
                    turn++;
                    std::cout << "You now have " << current1 << " points." << std::endl;
                    std::cout << "Keep for a total of " << current1 + score1 << " points." << std::endl;
                }else{
                    std::cout << "You rolled a 1" << std::endl;
                    std::cout << "You lost " << current1 << " points, should have kept." <<std::endl;
                    std::cout << "Total score: " << score1 << std::endl;
                    current1 = 0;
                    player = 0;
                    turn = 0;
                }
            }
                if(move == 'k' || move == 'K'){
                    score1 += current1;
                    turn = 0;
                    std::cout << "You kept " << current1 << " points, your total score is " << score1 << std::endl;
                    player = 0;
                    current1 = 0;
                }
        }while(player == 1);
        }while(score0 < target && score1 < target);
        if(score0 >= target){
            std::cout << "Player 1 wins!" << std::endl;
        }
        if(score1 >= target){
            std::cout << "Player 2 wins!" << std::endl;
        }
    
    return 0;
}