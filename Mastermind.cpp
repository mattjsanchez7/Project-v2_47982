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
void getInput (char [], char [], int &, char [][4], int, int [], int [], int);
char colorconversion (int);
int numCorrect (char [], char []);
int wrongSpot (char [], char [], int);




//Execution begins here
using namespace std;
int main(int argc, char *argv[]) {
 	//Declare Variables
 	int randNum1, randNum2, randNum3, randNum4; //Variable to convert input to integer
 	char correct[4], guess[4]; //Variable for numbers/colors generated
 	char again; //Input by user to play again
    int numguess=0, guessleft=10; //Number of user guesses

	int keepG, keepY, keepB, keepR, keepP, keepsum; //Keep the smaller of the two and sum them
	int wrongS=0, totright=0; //Variable to display the users right guesses and right colors but in wrong spot
	char history[10][4];
	int counter=0, hCorrect[10], hWrongS[10];
 
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
 	

	//Get input and display results

	getInput(guess, correct, guessleft, history, counter, hCorrect, hWrongS, totright); 
	
	
    
	
	//Break out if user wins
        if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && guess[3]==correct[3]) {
            numguess=10;
        }
        numguess++; //Counter for user guesses
		counter++;
 	} while (numguess<10); //Limit user guesses to 10
        
        //Determine if user wins
 	if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && guess[3]==correct[3]) {
 	 cout<<"Congratulations you win!";
 	} else {
        
        //If user loses output correct sequence
  	cout<<"Sorry try again. Correct sequence was "<<correct[0]<<" "<<correct[1]<<
  	" "<<correct[2]<<" "<<correct[3]<<" "<<endl;
	 }
        
        //Prompt user to play again
        cout<<" Do you want to play again? (Y/N)?"<<endl;
        cin>>again;
		      
        //If user wants to play again reset the guesses counter to zero
        if (again=='Y' || again=='y'){
        numguess=0;
		guessleft=10;
		}
        } while (again=='Y' || again=='y');
        //Exit Stage Right
 	return 0;
}

//Function to display instructions
void displayInstructions () {
 cout<<"++++++++Mastermind++++++"<<endl;
 cout<<"I will generate 4 random stones that can each be"
 <<" 1 of 5 colors allowing duplicates."<<endl;
 cout<<"You will get 10 guesses at the color of each and I will tell you after"  <<" each guess the number of colors that are are correct and in the"  <<" right position"
 <<" and also the number of colors that are correct but misplaced."<<endl;
 cout<<"Enter the first letter of each color to guess."<<endl; cout<<"You have 5 colors to pick from: Green Yellow Red Blue Purple"<<endl;
 cout<<"A sample guess would look like B Y B G"<<endl;
}


//Function to get users guesses
void getInput (char guess[], char correct[], int &guessleft, char history[][4], int counter, int hCorrect [], int hWrongS[], int totright) {
	
cout<<"Fire away!"<<endl; //Output for guesses
 
	
		for(int i =0;i<4;i++){
			cin >> guess[i];
			if (guess[i]>91)
				guess[i]= guess[i]-32;			
				history[counter][i]=guess[i];

		
		
		}
			
			hCorrect[counter]=numCorrect(guess, correct);
					hWrongS[counter]=wrongSpot(guess, correct, hCorrect[counter]);
			
			for (int i=0; i<counter+1; i++){
					cout<<"History "<<i+1 << " ";
					for(int j =0;j<4;j++){
						cout << history[i][j];

					
					
					}
						
							 							cout<<" Correct= "<<hCorrect[i]<<" Wrong spot= "<<hWrongS[i];

							cout<<endl;
							

			}
			
			
	
	//cout<<"History= "<<history[0]<<endl;
	guessleft--;
	cout<<endl;
	cout<<"Guesses left "<<guessleft<<endl;
	cout<<endl;
	if (guessleft==3)
	cout<<"Warning 3 more tries!!!"<<endl;
	if(guessleft==2)
	cout<<"Warning two tries left"<<endl;
	if(guessleft==1)
	cout<<"Last chance, choose wisely!"<<endl;

}

//Convert random number to a character representing a color
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

//Function to determine how many colors were correct and in the right spot.
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

//Count the greens in the correct code
int wrongSpot(char correct[], char guess[],int totright){
	int greenC=0; 
	int sum=0, keepG, keepY, keepR, keepB, keepP;
	for(int i=0; i<4; i++)
	if (correct[i]=='G'){
	greenC++;
	}
	int green=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='G'){
	green++;
	}
	if (greenC<=green)
	keepG=greenC;
	else keepG=green;
	

	int yellowC=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='Y'){
		yellowC++;
	}
	int yellow=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='Y'){
		yellow++;
	}
	if (yellowC<=yellow)
	keepY= yellowC;
	else keepY= yellow;
	

	int redC=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='R'){
	redC++;
	}
	int red=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='R'){
	red++;
	}
	if (redC<=red)
	keepR= redC;
	else keepR= red;
	

	int blueC=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='B'){
	blueC++;
	}
	int blue=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='B'){
	blue++;
	}
	if (blueC<=blue)
	keepB= blueC;
	else keepB= blue;

	int purpleC=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='P'){
	purpleC++;
	}
	int purple=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='P'){
	purple++;
	}
	if (purpleC<=purple)
	keepP= purpleC;
	else keepP= purple;
	sum=keepG+keepY+keepR+keepB+keepP;
	return sum-totright;
}
