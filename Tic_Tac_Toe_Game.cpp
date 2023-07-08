#include <iostream>
#include <cstdlib>
#include <ctime> //Using for Random number
#include <string> //Using for String conversion
#include <windows.h> //using for Windows compatibility colors
using namespace std;

 HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // line handle color object

char Board[3][3];
const char PLAYER_X = 'X';
const char COMPUTER = 'O';
const char PLAYER_Y = 'O';

string nameuser;
string secondnameuser;

// Function prototypes
void SetNameUser(string NU);
string GetNameUser();
void SetSecondnameUser(string NU2);
string GetSecondnameUser();
void DesignGame();
void PrintBoard();
void AskedUser();
void PlayerMove();
void ComputerMove();
char CheckWinner();
int CheckFreeSpaces();
void PrintWinner(char winner);
void StartGame();
void PlayerMove2();
void PrintWinner2(char winner);
void StartGame2();


int main()

{
     DesignGame();
     AskedUser();

     SetConsoleTextAttribute(h, 2);   // Green

    cout << "THE Designer and Maker this Game ALI SALMAN //IRAQ" << endl;


    return 0;
}





void DesignGame()
{
    SetConsoleTextAttribute(h, 2);   // Green
    char shape[3][3] = {
        {'X', 'O', 'X'},
        {'O', 'X', 'O'},
        {'O', 'X', 'X'}
    };

    system("cls");
     
    cout << "<><><>GAME<><><>" << endl;
    cout << " X    Vs   O    " << endl;
    SetConsoleTextAttribute(h,90);
    cout << " ___ ___ ___ " << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << shape[0][0] << " | " << shape[0][1] << " | " << shape[0][2] << " |" << endl;
    cout << "|___|___|___|" << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << shape[1][0] << " | " << shape[1][1] << " | " << shape[1][2] << " |" << endl;
    cout << "|___|___|___|" << endl;
    cout << "|   |   |   |" << endl;
    cout << "| " << shape[2][0] << " | " << shape[2][1] << " | " << shape[2][2] << " |" << endl;
    cout << "|___|___|___|" << endl;
    cout << "\n\n";
    SetConsoleTextAttribute(h, 2);   // Green

    cout << "Welcome to Our --> X_O_GAME <--\n" << endl;
}



void PrintBoard()
{ 
    SetConsoleTextAttribute(h, 1);   // Blue
    system("cls");
    cout << "\n\n <|>'Tic Tac Toe Game'<|> \n" << endl;

    cout << "   |   |   " << endl;
    cout << " " << Board[0][0] << " | " << Board[0][1] << " | " << Board[0][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Board[1][0] << " | " << Board[1][1] << " | " << Board[1][2] << endl;
    cout << "___|___|___" << endl;
    cout << "   |   |   " << endl;
    cout << " " << Board[2][0] << " | " << Board[2][1] << " | " << Board[2][2] << endl;
    cout << "   |   |   " << endl;
}

void AskedUser()
{
    string Answer;
     
      SetConsoleTextAttribute(h, 13);  // Light Magenta
     
    
    cout << "Hello Hero" << endl;
    
    cout << "\nDO YOU WANT TO PLAY Vs COMPUTER? \nIF say NO  Will play with your friend" << endl;
    cout << "ANSWER ->( Yes/No ): ";
    cin >> Answer;

    if (Answer == "Yes" || Answer == "yes" || Answer == "Y" || Answer == "y")
    {
        cout << "\nOKAY -> Enter Your Name: ";
        cin >> nameuser;
        SetNameUser(nameuser);
        cout << "Thanks! The game will now start.\n" << endl;
        cout << "PLAYER with X is: " << GetNameUser() << "\nPLAYER with O is: COMPUTER" << endl;

        StartGame();
    }
    else if (Answer == "No" || Answer == "no" || Answer == "N" || Answer == "n")
    {
        cout << "\nWOW! The game will be played with Two Heroes." << endl;

        cout << "Enter the name of the first hero: ";
        cin >> nameuser;

        cout << "Enter the name of the second hero: ";
        cin >> secondnameuser;

        SetNameUser(nameuser);
        SetSecondnameUser(secondnameuser);

        cout << "PLAYER with X is: " << GetNameUser() << "\nPLAYER with O is: " << GetSecondnameUser() << endl;
        cout << "Thanks! The game will now start.\n" << endl;

        StartGame2();
    }
    else
    {
        cout << "\nThank you for your time, future Hero!" << endl;
    }
}

void PlayerMove()
{
    int x;

    do
    {    SetConsoleTextAttribute(h, 12);  // Light Red
        cout << "Enter your move position (1-9): ";
        cin >> x;

        int i = (x - 1) / 3;
        int j = (x - 1) % 3;

        if (x < 1 || x > 9)
        {
            cout << "Invalid move! Try again." << endl;
        }
        else if (Board[i][j] != ' ')
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Invalid move! Cell already occupied. Try again." << endl;
        }
        else
        {
            Board[i][j] = PLAYER_X;
            break;
        }
    } while (true);
}

void ComputerMove()
{
    srand(time(NULL));
    int x;

    if (CheckFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 9 + 1;

            int i = (x - 1) / 3;
            int j = (x - 1) % 3;

            if (Board[i][j] == ' ')
            {
                Board[i][j] = COMPUTER;
                break;
            }
        } while (true);
    }
    else
    {
        PrintWinner('T');
    }
}

int CheckFreeSpaces()
{
    int freeSpaces = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (Board[i][j] == ' ')
            {
                freeSpaces++;
            }
        }
    }

    return freeSpaces;
}

char CheckWinner()
{
    for (int i = 0; i < 3; i++)
    {
        if (Board[i][0] == Board[i][1] && Board[i][1] == Board[i][2])
        {
            return Board[i][0];
        }

        if (Board[0][i] == Board[1][i] && Board[1][i] == Board[2][i])
        {
            return Board[0][i];
        }
    }

    if (Board[0][0] == Board[1][1] && Board[1][1] == Board[2][2])
    {
        return Board[0][0];
    }

    if (Board[2][0] == Board[1][1] && Board[1][1] == Board[0][2])
    {
        return Board[2][0];
    }

    if (CheckFreeSpaces() == 0)
    {
        return 'T'; // Tie
    }

    return ' ';
}

void PrintWinner(char winner)
{
  
    if (winner == PLAYER_X)
    {
         SetConsoleTextAttribute(h, 5);  // Light Red
        cout << "Congratulations! " << GetNameUser() << " > You win!" << endl;
       
    } 
    else if (winner == COMPUTER)
    {   
        SetConsoleTextAttribute(h, 12);  // Light Red
        cout << "Oops! You lose!" << endl;
        
    }

    else if (winner == 'T')
    {
        
         SetConsoleTextAttribute(h, 8);  // Light Red
        cout << "It's a tie!" << endl;
        
    }
}

void StartGame()
{
    cout << "YOU (X) Vs COMPUTER (O)\n" << endl;
    char winner;
    char response;
    int  counter_score_p=0;
    int counter_score_c =0;


    do
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Board[i][j] = ' ';
            }
        }

        winner = ' ';
        response = ' ';

        while (winner == ' ')
        {
            PrintBoard();

            PlayerMove();
            winner = CheckWinner();
            if (winner != ' ')
            {
                
                break;
            }
            

            ComputerMove();
            winner = CheckWinner();
            if (winner != ' ')
            {
              
                break;
            }
        }

        PrintBoard();
        PrintWinner(winner);
         SetConsoleTextAttribute(h, 12);  // Light Red
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> response;
        response = toupper(response);
    } while (response == 'Y');
    
     SetConsoleTextAttribute(h, 90);  // Light Red
    cout << "Thanks for playing!\n" << endl;
    cout << "<><><>GAME IS OVER<><><>" << endl;
}

void PlayerMove2()
{
    int x;

    do
    {    SetConsoleTextAttribute(h, 12);  // Light Red
        cout << "Enter your move position (1-9): ";
        cin >> x;

        int i = (x - 1) / 3;
        int j = (x - 1) % 3;

        if (x < 1 || x > 9)
        {

            cout << "Invalid move! Try again." << endl;
        }
        else if (Board[i][j] != ' ')
        {
            SetConsoleTextAttribute(h, 4);

            cout << "Invalid move! Cell already occupied. Try again." << endl;
        }
        else
        {
            Board[i][j] = PLAYER_Y;
            break;
        }
    } while (true);
}

void PrintWinner2(char winner)
{    SetConsoleTextAttribute(h, 1000);  
    if (winner == PLAYER_X)
    {
        cout << "Congratulations! " << GetNameUser() << " > You win!" << endl;
        cout << "Oops! " << GetSecondnameUser() << " You lose!" << endl;
    }
    else if (winner == PLAYER_Y)
    {
        cout << "Congratulations! " << GetSecondnameUser() << " > You win!" << endl;
        cout << "Oops! " << GetNameUser() << " You lose!" << endl;
    }
    else if (winner == 'T')
    {
        cout << "It's a tie!" << endl;
    }
}

void StartGame2()
{
    char winner;
    char response;

    do
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                Board[i][j] = ' ';
            }
        }

        winner = ' ';
        response = ' ';

        while (winner == ' ')
        {
            PrintBoard();

            PlayerMove();
            winner = CheckWinner();
            if (winner != ' ')
            {
                break;
            }

            PlayerMove2();
            winner = CheckWinner();
            if (winner != ' ')
            {
                break;
            }
        }

        PrintBoard();
        PrintWinner2(winner);
        
         SetConsoleTextAttribute(h, 90);  
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> response;
        response = toupper(response);
    } while (response == 'Y');
     
      SetConsoleTextAttribute(h, 50);  
    cout << "Thanks for playing!\n" << endl;
    cout << "<><><>GAME IS OVER<><><>" << endl;
}

void SetNameUser(string NU)
{
    nameuser = NU;
}

string GetNameUser()
{
    return nameuser;
}

void SetSecondnameUser(string NU2)
{
    secondnameuser = NU2;
}

string GetSecondnameUser()
{
    return secondnameuser;
}


