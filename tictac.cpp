#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

//Global Varaibles
char array[3][3] = {{'1', '2','3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int rows,choice;
int columns;
char turn='X';
bool tie= false;


void To_DisplayBoard()
{
	
	cout<<"\t\t   |    |   \n";
	cout<<"\t\t "<<array[0][0]<<" |  "<<array[0][1]<<" |  "<<array[0][2]<<"   \n";
	cout<<"\t\t___|____|___\n";
	cout<<"\t\t   |    |   \n";
	cout<<"\t\t "<<array[1][0]<<" |  "<<array[1][1]<<" |  "<<array[1][2]<<"   \n";
	cout<<"\t\t___|____|___\n";
	cout<<"\t\t   |    |   \n";
	cout<<"\t\t "<<array[2][0]<<" |  "<<array[2][1]<<" |  "<<array[2][2]<<"   \n";
	cout<<"\t\t   |    |   \n";
}

void  function(){
/* here we are checking if there is any unused space which is left in the structure to fill
 so what we are doing is if the value of token is x that means player 1 turn is there and at a
 particular place there is not "x" and not "0" as well so player 1's value will be assigned there and after that players 2 turn is there so
 we have assigned the value 0 to the token that is player 2's value*/
 
 
// we create a variable digit so that we can take a value from the user
	int digit;
	if(turn == 'X')
	{
		cout<<"\nPlayer 1 [X] turn : ";	
	}
	
	else if(turn == '0')
	{
		cout<<"\nPlayer 2 [O] turn : ";
		
	}
	cin>>digit;
	//Taking input from user
	//updating the board according to choice and reassigning the turn Start
	

	
	switch(digit){
        case 1: rows=0; columns=0; break;
        case 2: rows=0; columns=1; break;
        case 3: rows=0; columns=2; break;
        case 4: rows=1; columns=0; break;
        case 5: rows=1; columns=1; break;
        case 6: rows=1; columns=2; break;
        case 7: rows=2; columns=0; break;
        case 8: rows=2; columns=1; break;
        case 9: rows=2; columns=2; break;
        default:
            cout<<"Invalid Move";       
	}
	
	if(turn == 'X' && array[rows][columns] != 'X' && array[rows][columns] != '0')
	{
		array[rows][columns] = 'X';
		turn = '0';
	}
	
	else if(turn == '0' && array[rows][columns] != 'X' && array[rows][columns] != '0')
	{
		array[rows][columns] = '0';
		turn = 'X';
	}
 	else {
		cout<<"No empty space is found !!"<<endl;
		function();
	}
	
  To_DisplayBoard();
}

bool The_Game()
{
	
	for(int i=0;i<3;i++)
	{	
		//checking horizontally and vertically
		if (array[i][0] == array[i][1] && array[i][0] == array[i][2] || array[0][i] == array[1][i] && array[0][i] == array[2][i])
		{
			return false;
		}
	}
	//checking diagonally
	if(array[0][0] == array[1][1] && array[0][0] == array[2][2] || array[0][2] == array[1][1] && array[0][2] == array[2][0])
	{
			return false;
	}
	
	//checking the game is in continue mode or not
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if (array[i][j] != 'X' && array[i][j] != '0')
			{  
				return true;
			}
		}
	}
	// checking the if game already tie or not
	tie= true;
	return false;
}

//Main 
int main()
{
	cout<<"\t\t\tTIC ------ TAC ------ GAME\t\t\t"<<endl;
	cout<<"\n\t\t\t\tFor Two Players\n\t\t\t"<<endl;
	
	
	
	To_DisplayBoard(); //Display the initial board once

    while (The_Game())
    {
        function();
        The_Game();
    }
    
	if(turn == 'X' && tie == false)
	{
		cout<<"\n\n Congratulation! Player with 'O' has won the game"<<endl;
	}
	else if(turn == '0' && tie == false)
	{
		cout<<"\n\n Congratulation! Player with 'X' has won the game"<<endl;
	}
	else
	{
		cout<<"It's a draw!"<<endl;
	}
	
}




