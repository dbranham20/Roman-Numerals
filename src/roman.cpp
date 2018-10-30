//----------------------------------------------------------------------------------
//
//	Program by Daniel Branham - 9/13/18
//		A program that accepts Roman Numeral character strings and returns
//		whether or not the string is a valid Roman Numeral between 1-100
//----------------------------------------------------------------------------------
#include<iostream>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	string states[14][6] = {
	//State, inputI, inputV, inputX, inputL, inputC
	{"S","I","V","X","L","C"}, //Start state
	{"I","II","IV","IX","D","D"}, //I state   
	{"V","I","D","D","D","D"}, //V state
	{"X","I","V","XX","XL","XC"}, //X state
	{"L","I","V","X","D","D"}, //L state
	{"C","I","V","X","D","D"}, //C state
	{"II","III","D","D","D","D"}, //II state
	{"III","D","D","D","D","D"}, //III state
	{"XX","I","V","XXX","D","D"}, //XX state
	{"XXX","I","V","D","D","D"}, //XXX state
	{"IX","D","D","D","D","D"}, //IX state
	{"IV","D","D","D","D","D"}, //IV state
	{"XC","I","V","D","D","D"}, //XC state
	{"XL","I","V","X","D","D"}, //XL state
	};
	//D signifies dead state

	if(argc < 2)
		cout << "Not enough command line arguments!" << endl;

	else
	{ 
		string roman = argv[1], charCmpr, nxtState; //get input
		bool flag = true;
		int stateIndex = 0;
		
		transform (roman.begin(), roman.end(), roman.begin(), ::toupper); //all uppercase
        cout << endl << "Given string: " + roman << endl;

		for(int y = 0; y < roman.length(); y++)
		{
			string charCmpr(1, roman.at(y)); //first char...second char...third char...etc
		
			if(flag) //as long as we haven't reached a dead state
			{
				if(charCmpr == "I") //is the current char any of the inputs
					nxtState = states[stateIndex][1];
				
				else if(charCmpr == "V")
					nxtState = states[stateIndex][2];
				
				else if(charCmpr == "X")
					nxtState = states[stateIndex][3];
				
				else if(charCmpr == "L")
					nxtState = states[stateIndex][4];
				
				else if(charCmpr == "C")
					nxtState = states[stateIndex][5];

				else //if not, flag for dead state
					flag = false;

				if(nxtState == "D") //reached a dead state -> flag
					flag = false;

				else if(flag) //if no dead state, 
				{
					for(int x = 0; x < 14; x++) //look for next state in array 
					{
						if(states[x][0] == nxtState)
						{	
							stateIndex = x; //array index found
							flag = true;
						}	
					}
				}
			}
		}

		//done looping through input
		if(!flag)
			cout << "Input is rejected." << endl << endl;
		else if(flag)
			cout << "Input is accepted." << endl << endl;
	}
return 0;
}

