#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>

class Player {
    public:
        int score, credits, bust;
        void set_values(int, int, int);
};

void Player::set_values(int x, int y, int z){
    score = x;
    credits = y;
    bust = z;
}

int turnscore = 0;

int card(char c)
{
    if (c == 'A')
    {
        if (turnscore <= 10)
        {
            return 11;
        }
        if (turnscore > 10)
        {
            return 1;
        }
    }
    if (c == '2')
    {
        return 2;
    }
    if (c == '3')
    {
        return 3;
    }
    if (c == '4')
    {
        return 4;
    }
    if (c == '5')
    {
        return 5;
    }
    if (c == '6')
    {
        return 6;
    }
    if (c == '7')
    {
        return 7;
    }
    if (c == '8')
    {
        return 8;
    }
    if (c == '9')
    {
        return 9;
    }
    if (c == 'X')
    {
        return 10;
    }
    if (c == 'J')
    {
        return 10;
    }
    if (c == 'Q')
    {
        return 10;
    }
    if (c == 'K')
    {
        return 10;
    }

}




int main()
{
    srand(time(NULL));
    int turn = 0;
    char cards[13] = {'A','2','3','4','5','6','7','8','9','X','J','Q','K'};
    int bust[4] = {0};
    int score[4] = {0};
    int win[4] = {0};
    int running = 0;

    int activePlayer = 0;

    Player player1;
    Player player2;
    Player player3;
    Player user;
    player1.set_values(0,200,0);
    player2.set_values(0,200,0);
    player3.set_values(0,200,0);
    user.set_values(0,200,0);
    
    int draw = 0;
    char Ccard;
    int selection;

    int tester = 0;
    int pos = 4;
    int winNum = 0;
    int testerS;

    

    while (running == 0)
    {
        if (turn == 0)
        {
            turnscore = 0;
            player1.score = 0;
            tester = 0;
            winNum = 0;
            for (int i = 0; i < 4; i++)
            {
                bust[i] = 0;
                score[i] = 0;
                win[i] = 0;
            }
            //CPU_1
            //will always hit once and then hold
            //first card
            draw = (rand() %13);
            Ccard = cards[draw];
            player1.score += card(Ccard);
            turnscore += card(Ccard);
            
            //print hand
            std::cout << "CPU 1: ";
            std::cout << Ccard;
            //second card
            draw = (rand() %13);
            Ccard = cards[draw];
            player1.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << " _ ";
            //third card
            draw = (rand() %13);
            Ccard = cards[draw];
            turnscore += card(Ccard);
            player1.score += card(Ccard);
            std::cout << Ccard << std::endl;
            score[0] = player1.score;
            turn = 1;
        }

        if (turn == 1)
        {
            turnscore = 0;
            player2.score = 0;
            //player 2
            //will only hit when the score is below 15
            draw = (rand() %13);
            Ccard = cards[draw];
            player2.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << "CPU 2: ";
            std::cout << Ccard;
            draw = (rand() %13);
            Ccard = cards[draw];
            player2.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << " _ ";
            while (player2.score <= 15)
            {
                draw = (rand() %13);
                Ccard = cards[draw];
                turnscore += card(Ccard);
                player2.score += card(Ccard);
                std::cout << Ccard;
            }
            std::cout << std::endl;
            score[1] = player2.score;
            turn = 2;
        }

        if (turn == 2)
        {
            turnscore = 0;
            player3.score = 0;
            //player 3
            //high risk taker: hits when its below 17
            draw = (rand() %13);
            Ccard = cards[draw];
            player3.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << "CPU 3: ";
            std::cout << Ccard;
            draw = (rand() %13);
            Ccard = cards[draw];
            player3.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << " _ ";
            while (player3.score <= 17)
            {
                draw = (rand() %13);
                Ccard = cards[draw];
                turnscore += card(Ccard);
                player3.score += card(Ccard);
                std::cout << Ccard;
            }
            std::cout << std::endl;
            score[2] = player3.score;
            turn = 3;

        }
        if (turn == 3)
        {
            turnscore = 0;
            user.score = 0;
            int active = 1;
            std::cout << "User Turn: " << std::endl;

            draw = (rand() %13);
            Ccard = cards[draw];
            user.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << Ccard;

            draw = (rand() %13);
            Ccard = cards[draw];
            user.score += card(Ccard);
            turnscore += card(Ccard);
            
            std::cout << Ccard << std::endl;

            while (active == 1)
            {
                std::cout << "Hit(1) or Hold(2)?";
                std::cin >> selection;
                if (selection == 1)
                {
                    draw = (rand() %13);
                    Ccard = cards[draw];
                    turnscore += card(Ccard);
                    user.score += card(Ccard);
                    std::cout << Ccard << std::endl;
                }
                else
                {
                    active = 0;
                    
                }

            }
            score[3] = user.score;
            turn = 4;
        }

        if (turn == 4)
        {
            //ante here
            player1.credits -= 10;
            player2.credits -= 10;
            player3.credits -= 10;
            user.credits -=10;
            //printing hands:
            std::cout << "Player 1 Total: ";
            std::cout << player1.score << std::endl;
            if (player1.score > 21)
            {
                std::cout << "BUST" << std::endl;
                bust[0] = 1;
            }

            std::cout << "Player 2 Total: ";
            std::cout << player2.score << std::endl;
            if (player2.score > 21)
            {
                std::cout << "BUST" << std::endl;
                bust[1] = 1;
            }

            std::cout << "Player 3 Total: ";
            std::cout << player3.score << std::endl;
            if (player3.score > 21)
            {
                std::cout << "BUST" << std::endl;
                bust[2] = 1;
            }

            std::cout << "User Total: ";
            std::cout << user.score << std::endl;
            if (user.score > 21)
            {
                std::cout << "BUST" << std::endl;
                bust[3] = 1;
            }

            for (int i = 0; i < 4; i++)
            {
                //make sure they havent busted
                if (bust[i] == 0)
                {
                    if (score[i] > tester)
                    {
                        tester = score[i];
                        pos = i;
                    }

                }
            }

            for (int i = 0; i < 4; i++)
            {
                if (score[i] == tester)
                {
                    win[i] = 1;
                }
            }

            for (int i = 0; i < 4; i++)
            {
                if (win[i] == 1)
                {
                    winNum++;
                }
            }

            
            if (winNum <= 1)
            {
                if (pos == 0)
                {
                    std::cout << "Player 1 Wins" << std::endl;
                    player1.credits += 40;
                }
                if (pos == 1)
                {
                    std::cout << "Player 2 Wins" << std::endl;
                    player2.credits += 40;
                }
                if (pos == 2)
                {
                    std::cout << "Player 3 Wins" << std::endl;
                    player3.credits += 40;
                }
                if (pos == 3)
                {
                    std::cout << "User Wins!" << std::endl;
                    user.credits += 40;

                }
                if (pos == 4)
                {
                    std::cout << "Dealer Wins" << std::endl;

                }
            }
            
            else
            {
                if (win[0] == 1)
                {
                    std::cout << "Player 1 ";
                    player1.credits += 40;
                }
                if (win[1] == 1)
                {
                    std::cout << "& Player 2 ";
                    player2.credits += 40;
                }
                if (win[2] == 1)
                {
                    std::cout << "& Player 3 ";
                    player3.credits += 40;
                }
                if (win[3] == 1)
                {
                    std::cout << "& User ";
                    user.credits += 40;
                }
                std::cout << "Win!" << std::endl;
            }

            std::cout << "Player 1 Credits: ";
            std::cout << player1.credits << std::endl;

            std::cout << "Player 2 Credits: ";
            std::cout << player2.credits << std::endl;

            std::cout << "Player 3 Credits: ";
            std::cout << player3.credits << std::endl;

            std::cout << "User Credits: ";
            std::cout << user.credits << std::endl;

            std::cout << "Play again? Yes(1) No(2)" << std::endl;
            std::cin >> selection;

            if (selection == 1)
            {
                turn = 0;
            }
            else
            {
                running = 1;
            }



        }
        


    }

    
}
