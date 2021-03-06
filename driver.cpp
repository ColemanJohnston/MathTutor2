//Name: Coleman Johnston, Sandra Flores, NicoleBernadette Hipolito, and Ali Fenton 
//Date: 16 October 2015
//Description: A program to give a user math questions 
//             and tell the user if they got the right answer or not.
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

// ********************************************************
char menu();
//Summary: will have the (+ , - , * , / , Q) so you can pick which problem you want to do.
//Precondition: user picks char (‘a’ for + , ‘s’ for  - , ‘m’ for * , ‘d’ for / , ‘q’ for Q) for the problem they want
//Postcondition: it will return the character from the user

// ********************************************************
int addition();
//Summary: adds two random ints between the range of 1 to 12.
//Precondition: It will have you do the problem 5 times and makes sure you are doing it right
//Postcondition: it will return the number of times the user answered correctly.

// ********************************************************
int multiplication();
//Summary: Multiplies two random ints between the range of 1 to 12.
//Precondition: It will ask the user 5 multiplication problems.
//Postcondition: It will return the number of times the user answered correctly.

// ********************************************************
int subtraction();
//Summary: subtracts two random integers between 1-12
//Precondition: It will ask the user 5 subtraction questions 
//Postcondition: it will return the number of times the user answered correctly

// ********************************************************
int division();
//Summary: Divides two random ints between the range of 1 to 12.
//Precondition: It will ask the user 5 division problems. 
//Postcondition: It will return the number of times the user answered correctly.

// ********************************************************
 void compliment();
 //Summary: gives the user a random compliment.
//Precondition: the user got a correct answer.
//Postcondition: A random compliment is printed to the screen.

// ********************************************************
void encourage();
// Summary: gives the user a random encouragement.
// Precondition: the user got an incorrect answer.
// Postcondition: a random encouragement is printed to the screen. 

// ********************************************************
int check( int answer, int correct );
//Summary: checks for the right and wrong answers
//Precondition: it will check if the user’s answer is correct
//Postcondition: it will return 1 for a right for a correct answer and call compliment() and it will //return 0 for a wrong answer and call encourage. 
// **********************************************************


int main()
{
    srand(time(0));

    char userChoice;
    int score = 0;//user's over all score of right answers
    
    do//do until user quits by entering Q.
    {
        cout << "Your current score is: " << score << endl;
        userChoice = menu();//call the menu to get a choice from the user(lower case)
        switch(userChoice)
        {
            case 'a':
            score += addition();
            break;
            case 's':
            score += subtraction();
            break;
            case 'd':
            score += division();
            break;
            case 'm':
            score += multiplication();
            break;
            default://if the user enters 'Q' into the menu say goodbye
            cout << "Good work! your final score was: " << score << endl;
            cout << "Goodbye!" << endl;
        }
    }while(userChoice != 'q');//if the user decides to quit end the loop. 
    
    return 0;
}

char menu(){
        char ans;
    
     cout << "\n"
          << "Welcome to Math Tutor\n"
          << "       A. Addtion\n"
          << "       S. Subtraction\n"
          << "       M. Multiplication\n"
          << "       D. Division\n"
          << "       Q. Quit\n"
          << "\n"
          << "Enter what you want to practice." << endl;
          cin >> ans;
          ans = tolower(ans);
             
          while (ans != 'a' && ans != 's' && ans != 'm' && ans != 'd'&& ans != 'q')
          {
            cout << "\n"
                 << "Invalid input. Please choose A, S, M, D, or Q: ";
            cin >> ans;
            ans = tolower(ans);
          }
    return ans;
}

int addition(){
    int answer;
    int score = 0;
    
    for(int i = 5; i > 0; i--){
        int numberA = rand() % 12 + 1;
        int numberB = rand() % 12 + 1;
        
        cout << numberA << " + " << numberB << endl;
        cin >> answer;
        
        int correct = numberA + numberB;
        score += check(correct, answer);
    }
    
    cout << "You answered " << score << " questions correcly.\n";
    return score;
}

int multiplication()
{
    int answer;
    int score = 0;
    for(int i = 0; i < 5; i++)
    {
        int num1 = (rand() % 12) + 1;
        int num2 = (rand() % 12) + 1;
        cout << num1 << " * " << num2 << endl;
        cin >> answer;
        int correct = num1*num2;    
        score  += check(correct, answer);
    }
    cout << "You answered " << score << " questions correcly.\n";

    return score;
}

int subtraction()
{
    int answer;
    int score = 0;
    
    for(int i = 5; i > 0; i--)
    {
        int numberA = rand() % 12 + 1;
        int numberB = rand() % 12 + 1;
        
        cout << numberA << " - " << numberB << endl;
        cin >> answer;
        
        int correct = numberA - numberB;
        score += check(correct, answer);
    }
    
    cout << "You answered " << score << " questions correcly.\n";

    return score;
}

int division()
{
    int answer, num1,num2;
    int score = 0;
    for(int i = 0; i < 5; i++)
    {
        num1 = (rand() % 12) + 1;
        num2 = (rand() % 12) + 1;
        while(num1 % num2 != 0)
        {
            num1 = (rand() % 12) + 1;
            num2 = (rand() % 12) + 1;
        }
        cout << num1 << " / " << num2 << endl;
        cin >> answer;
        int correct = num1/num2;    
        score  += check(correct, answer);
    }
    cout << "You answered " << score << " questions correcly.\n";

    return score;
}

void compliment()
{
    int num1 = (rand() % 4) + 1;
    switch(num1)
    {
        case 1:
        cout << "Good job for working hard! (๑•̀ㅂ•́)و\n";
        break;
        case 2:
        cout << "You're doing great! (๑˃ᴗ˂)و\n";
        break;
        case 3:
        cout << "I'm very proud of you! ٩(ˊᗜˋ*)و \n";
        break;
        case 4:
        cout << "You're showing great potential! (•̀ᴗ•́)و ̑̑\n";
        break;
    }    
}

void encourage()
{
    int num1 = (rand() % 4) + 1;
    switch(num1)
    {
        case 1:
        cout << "Incorrect.\nDon't worry, if you keep working hard you'll get it!\n";
        break;
        case 2:
        cout << "Sorry, wrong answer.\nKeep trying and you'll get better.\n";
        break;
        case 3:
        cout << "Good try.\nDon't stop now, you've almost got it!\n";
        break;
        case 4:
        cout << "Not quite.\nKeep working! You can do it!\n";
        break;
    }
    return;    
}

int check(int answer, int correct)
{
    int score = 0;
    
    if(answer == correct)
    {
        score += 1;
        compliment();
    }
    else 
    {
        score = score;
        encourage();
    }
    
    return score;
}
