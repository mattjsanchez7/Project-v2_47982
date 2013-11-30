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
void getInput (char [], int &);
char colorconversion (int);
int numCorrect (char [], char []);
int greenCountC (char []);
int yellowCountC (char []);
int redCountC (char []);
int blueCountC (char []);
int purpleCountC (char []);
int greenCount (char []);
int yellowCount (char []);
int redCount (char []);
int blueCount (char []);
int purpleCount (char []);
int compareG(int &, int &);
int compareY(int &, int &);
int compareR(int &, int &);
int compareB(int &, int &);
int compareP(int &, int &);


//Execution begins here
using namespace std;
int main(int argc, char *argv[]) {
 	//Declare Variables
 	int randNum1, randNum2, randNum3, randNum4; //Variable to convert input to integer
 	char correct[4], guess[4]; //Variable for numbers/colors generated
 	char again; //Input by user to play again
    int numguess=0, guessleft=10; //Number of user guesses
	int numGc, numYc, numRc, numBc, numPc; 
	int numG, numY, numR, numB, numP; 
	int keepG, keepY, keepB, keepR, keepP, keepsum;
	int wrongS, totright;

 
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
  
 	//cout<<correct[0]<<correct[1]<<correct[2]<<correct[3]<<endl; 
 	do{ 
 	getInput(guess, guessleft); //Function call to output for user to start guessing
	totright=numCorrect(guess, correct);
    cout<<"Total right and in correct position= "<<totright<<endl;
 	
	//Count the code colors
 
	numGc=greenCountC (correct);
		
	numYc=yellowCountC (correct);
		
	numRc=redCountC (correct);
	
	numBc=blueCountC (correct);
		
	numPc=purpleCountC (correct);
		
	
	//Count the guess colors
	numG=greenCount (guess);
	
		
	numY=yellowCount (guess);
		
		
	numR=redCount (guess);
	
		
	numB=blueCount (guess);
	

		
	numP=purpleCount (guess);
	
	
	keepG=compareG(numGc, numG);
	//cout<<"keepG "<<keepG<<endl;
	
	keepY=compareY(numYc, numY);
	//cout<<"keepY "<<keepY<<endl;
		
	keepR=compareR(numRc, numR);
	//cout<<"keepR "<<keepR<<endl;
			
	keepB=compareB(numBc, numB);
	//cout<<"keepB "<<keepB<<endl;
				
	keepP=compareP(numPc, numP);
	//cout<<"keepP "<<keepP<<endl;
	
	keepsum=keepG+keepY+keepR+keepB+keepP;
	
	wrongS=keepsum-totright;

	cout<<"Right color wrong position= "<<wrongS<<endl;
	
	
	


        
    //Break out if user wins
        if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && 		guess[3]==correct[3]) {
            numguess=10;
        }
        numguess++; //Counter for user guesses
 	} while (numguess<10); //Limit user guesses to 7
        
        //Determine if user wins
 	if (guess[0]==correct[0] && guess[1]==correct[1] && guess[2]==correct[2] && 	guess[3]==correct[3]) {
 	 cout<<"Congratulations you win!";
 	} else {
            //If user loses output correct sequence
  	cout<<"Sorry try again. Correct sequence was "<<correct[0]<<" "<<correct[1]<<
  	" "<<correct[2]<<" "<<correct[3]<<" "<<endl;
	 }
        
        //Prompt user to play again
        cout<<" Do you want to play again? (Y/N)?"<<endl;
        cin>>again;
		 if (again=='Y' || again=='y'){
		numguess=0;
		guessleft=10;
		}
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
void getInput (char guess[], int &guessleft) {
cout<<"Fire away!"<<endl; //Output for guesses
 cin>>guess[0]>>guess[1]>>guess[2]>>guess[3]; //Input guesses
	guessleft--;
cout<<"Guesses left "<<guessleft<<endl;
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

int greenCountC(char correct[]){
	int green=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='G'){
	green++;
	}
	return green;
	
}
int yellowCountC (char correct[]){
	int yellow=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='Y'){
		yellow++;
	}
	return yellow;
}
int redCountC (char correct[]){
	int red=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='R'){
	red++;
	}
	return red;
	
}
int blueCountC (char correct[]){
	int blue=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='B'){
	blue++;
	}
	return blue;
}
int purpleCountC (char correct[]){
	int purple=0;  
	for(int i=0; i<4; i++)
	if (correct[i]=='P'){
	purple++;
	}
	return purple;
}
int greenCount (char guess[]){
	int green=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='G'){
	green++;
	}
	return green;
}
int yellowCount (char guess[]){
	int yellow=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='Y'){
		yellow++;
	}
	return yellow;
}
int redCount (char guess[]){
	int red=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='R'){
	red++;
	}
	return red;
}
int blueCount (char guess[]){
	int blue=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='B'){
	blue++;
	}
	return blue;
}
int purpleCount (char guess[]){
	int purple=0;  
	for(int i=0; i<4; i++)
	if (guess[i]=='P'){
	purple++;
	}
	return purple;
}
int compareG(int &numGc, int &numG){
		if(numGc<=numG)
		return numGc;
		else return numG;
}
int compareY(int &numYc, int &numY){
		if(numYc<=numY)
				return numYc;
				else return numY;

}
int compareR(int &numRc, int &numR){
		if(numRc<=numR)
				return numRc;
				else return numR;

}
int compareB(int &numBc, int &numB){
		if(numBc<=numB)
				return numBc;
				else return numB;
}
int compareP(int &numPc, int &numP){
		if(numPc<=numP)
				return numPc;
				else return numP;
}