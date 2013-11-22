//Matthew Sanchez
//Project 1
//This project mimics the game Mastermind.

//Libraries
#include <iostream> 
#include <cstdlib> //For RNG function.
#include <ctime> //For time function.

//No Global Constants

//Function Prottypes here
void displayInstructions();
void getInput (char guess[]);
char colorconversion (int);
int numCorrect (char guess[], char correct[]);
int rightColor (char guess[], char correct[]);

//Execution begins here
using namespace std;
int main(int argc, char *argv[]) {
 	//Declare Variables
 	int randNum1, randNum2, randNum3, randNum4; //Variable to convert input to integer
 	char correct[4], guess[4]; //Variable for numbers/colors generated
 	char again; //Input by user to play again
    int numguess=0; //Number of user guesses
 
 	do{
 	displayInstructions(); //Function call to display instructions and begin program.
	 
 	srand(time(0)); //RNG function to generate the correct sequence
 	randNum1=rand()%5+1; //Range the random numbers 1-5
 	randNum2=rand()%5+1;
 	randNum3=rand()%5+1;
 	randNum4=rand()%5+1;
 
 	//Get the Correct Sequence
 	correct[0]= colorconversion(randNum1);
 	correct[1]= colorconversion(randNum2);
 	correct[2]= colorconversion(randNum3);
 	correct[3]= colorconversion(randNum4);
  
 	cout<<correct[0]<<correct[1]<<correct[2]<<correct[3]<<endl; 
 	do{ 
 	getInput(guess); //Function call to output for user to start guessing
       
 	//Determine how many are correct
 	cout<<"Total right and in correct position= "<<numCorrect(guess, correct)<<endl;
        
 	//Determine how many are the right color but in wrong position
 	cout<<"Total colors right but in wrong place= "<<rightColor(guess, correct)<<endl;
        
    //Break out if user wins
        if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && 		guess[3]==correct[3]) {
            numguess=7;
        }
        numguess++; //Counter for user guesses
 	} while (numguess<7); //Limit user guesses to 7
        
        //Determine if user wins
 	if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && 	guess[3]==correct[3]) {
 	 cout<<"Congratulations you win!";
 	} else {
            //If user loses output correct sequence
  	cout<<"Sorry try again. Correct sequence was "<<correct[0]<<" "<<correct[1]<<
  	" "<<correct[2]<<" "<<correct[3]<<" "<<endl;
	 }
        
        //Prompt user to play again
        cout<<"Do you want to play again? (Y/N)?"<<endl;
        cin>>again;
        } while (again=='Y' || again=='y');
 
        //Exit Stage Right
 	return 0;
}
void displayInstructions () {
 cout<<"++++++++Mastermind++++++"<<endl;
 cout<<"I will generate 4 random stones that can each be"
 <<" 1 of 5 colors allowing duplicates."<<endl;
 cout<<"You will get 7 guesses at the color of each and I will tell you after"  <<" each guess the number of colors that are are correct and in the"  <<" right position"
 <<" and also the number of colors that are correct but misplaced."<<endl;
 cout<<"Enter the first letter of each color to guess. You will get 7 guesses."<<endl; cout<<"You have 5 colors to pick from: Green Yellow Red Blue Purple"<<endl;
 cout<<"A sample guess would look like B Y B G"<<endl;
}
void getInput (char guess[]) {
 cout<<"Fire away!"<<endl; //Output for guesses
 cin>>guess[0]>>guess[1]>>guess[2]>>guess[3]; //Input guesses
for (int count= 0; count<4; count++){ //Convert to uppercase
	if (guess[count]>91)
	guess[count]= guess[count]-32;
	}
} 
char colorconversion (int passNum) {
 switch (passNum) {
  case 1: 
    return 'G'; //Color is green
  break;
  case 2: 
    return 'Y'; //Color is yellow
  break;
  case 3: 
    return 'R'; //Color is red
  break;
  case 4: 
    return 'B'; //Color is blue
  break;
  case 5: 
    return 'P'; //Color is purple
  break;
 } 
}
int numCorrect (char guess[], char correct[]){
 int totRight=0;
  if (guess[0]==correct[0]) //Determine if 1st color guess is right
   totRight++;       //If true add 1 to counter
  if (guess[1]==correct[1]) //Determine if 2nd color guess is right
   totRight++;       //If true add 1 to counter
  if (guess[2]==correct[2]) //Determine if 3rd color guess is right
   totRight++;       //If true add 1 to counter
  if (guess[3]==correct[3]) //Determine if 4th color guess is right
   totRight++;       //If true add 1 to counter
 return totRight;                  //Return the number right
}
int rightColor (char guess[], char correct[]){
   //Determine if correct color is in a different place
	//If correct add 1 to counter
	int rightColor=0;
    if (guess[0]==correct[1]){ 
        rightColor++;
	
    }
    else if (guess[0]==correct[2]){
        rightColor++;
	
    }
    else if (guess[0]==correct[3]){
        rightColor++;

    }
    if (guess[1]==correct[0]){
        rightColor++;

    }
    else if (guess[1]==correct[2]){
        rightColor++;

    }
    else if (guess[1]==correct[3]){
        rightColor++;

    }
    if (guess[2]==correct[0]){
        rightColor++;

    }
    else if (guess[2]==correct[1]){
        rightColor++;

    }
    else if (guess[2]==correct[3]){
        rightColor++;

    }
    if (guess[3]==correct[0]){
        rightColor++;

    }
    else if (guess[3]==correct[1]){
        rightColor++;

    }
    else if (guess[3]==correct[2]){
        rightColor++;
    }
    return rightColor;
}