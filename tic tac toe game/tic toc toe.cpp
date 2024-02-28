#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
char board[9]={' ' , ' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' ,' ' };
void display_board()
{
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
	cout<<"\t"<<board[0]<<"\t|\t   "<<board[1]<<"\t\t|\t"<<board[2]<<endl;
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
	cout<<"\t"<<board[3]<<"\t|\t   "<<board[4]<<"\t\t|\t"<<board[5]<<endl;
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
	cout<<"-----------------------------------------------------------"<<endl;
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
	cout<<"\t"<<board[6]<<"\t|\t   "<<board[7]<<"\t\t|\t"<<board[8]<<endl;
	cout<<"\t"<<"\t|\t"<<"\t"<<"\t|\t"<<endl;
}
int count_board(char ch)
{
	int total=0;
	for(int i=0;i<9;i++)
	{
		if(board[i]==ch)
		{
			total++;
		}
	}
	return total;
}
void get_x()
{
	while(true)
	{
		int choice;
		cout<<"Select your position (from 1-9)"<<endl;
		cin>>choice;
		choice--;
		if(choice<0||choice>8)
		{
			cout<<"Please select position from 1 to 9"<<endl;
			break;
		}
		else if(board[choice]!=' ')
		{
			cout<<"Please select an empty position.."<<endl;
			break;
		}
		else
		{
			board[choice]='x';
			break;
		}
	}
}
void get_o()
{
	while(true)
	{
		int choice;
		cout<<"Select your position (from 1-9)..."<<endl;
		cin>>choice;
		choice--;
		if(choice<0||choice>8)
		{
			cout<<"Please select your choice from 1 to 9"<<endl;
			break;
		}
		else if(board[choice]!=' ')
		{
			cout<<"Please select an empty position.."<<endl;
			break;
		}
		else
		{
			board[choice]='o';
			break;
		}
	}
}
void get_computer_choice()
{
	srand(time(0));
	int choice;
	do
	{
		choice=rand()%9+1;
	}while(board[choice]!=' ');
	board[choice]='o';
}
char check_winner()
{
	if(board[0]==board[1]&&board[1]==board[2]&&board[0]!=' ')
	{
		return board[0];
	}
	if(board[3]==board[4]&&board[4]==board[5]&&board[3]!=' ')
	{
		return board[3];
	}
	if(board[6]==board[7]&&board[7]==board[8]&&board[6]!=' ')
	{
		return board[6];
	}
	if(board[0]==board[3]&&board[3]==board[6]&&board[0]!=' ')
	{
		return board[0];
	}
	if(board[1]==board[4]&&board[4]==board[7]&&board[1]!=' ')
	{
		return board[1];
	}
	if(board[2]==board[5]&&board[5]==board[8]&&board[2]!=' ')
	{
		return board[2];
	}
	if(board[0]==board[4]&&board[4]==board[8]&&board[0]!=' ')
	{
		return board[0];
	}
	if(board[2]==board[4]&&board[4]==board[6]&&board[0]!=' ')
	{
		return board[2];
	}
	if(count_board('x')+count_board('o')<9)
	{
		return 'c';
	}
	else
	{
		return 'd';
	}
}
void com_vs_player()
{
	string player_name;
	cout<<"Enter the Player Name:";
	cin>>player_name;
	while(true)
	{
		display_board();
		if(count_board('x')==count_board('o'))
		{
			cout<<player_name<<"'s turn"<<endl;
			get_x();
		}
		else
		{
			cout<<"Computer's turn"<<endl;
			get_computer_choice();
		}
		char winner=check_winner();
		if(winner=='x')
		{
			display_board();
			cout<<"Congratulations........!!!"<<endl;
			cout<<player_name<<" won the game"<<endl;
		 	break;
		}
		else if(winner=='o')
		{
			display_board();
			cout<<"Computer won the game.."<<endl;
			break;
		}
		else if(winner=='d')
		{
			cout<<"Game is Draw.."<<endl;
			break;
		}
	}
}
void player_vs_player()
{
	string x_player_name,o_player_name;
	cout<<"enter x_player_name:";
	cin>>x_player_name;
	cout<<"enter o_player_name:";
	cin>>o_player_name;
	while(true)
	{
		
		display_board();
		if(count_board('x')==count_board('o'))
		{
			cout<<x_player_name<<"'s turn"<<endl;
			get_x();
		}
		else 
		{
			cout<<o_player_name<<"'s turn"<<endl;
			get_o();
		}
		char winner=check_winner();
		if(winner=='x')
		{
			display_board();
			cout<<"Congratulations....."<<endl;
			cout<<x_player_name<<" won the game..."<<endl;
			break;
		}
		else if(winner=='o')
		{
			display_board();
			cout<<"Congratulations....."<<endl;
			cout<<o_player_name<<"won the game"<<endl;
			break;
		}
		else if(winner=='d')
		{
			cout<<"Game is Draw"<<endl;
			break;
		}
	}
}
int main()
{
	cout<<"-----------------Welcome----------------"<<endl;
	cout<<"---------------Tic tac toe ---------------"<<endl;
	int c;
	do
	{
		cout<<"enter your choice"<<endl;
		cout<<"\n1.computer vs player\n2.player vs player\n3.Quit the game\n";
		cin>>c;
		switch(c)
		{
			case 1:
				com_vs_player();
				break;
			case 2:
				player_vs_player();
				break;
			case 3:
				cout<<"Thank you for playing the game!!!"<<endl;
				break;
			default:
				cout<<"Enter correct option..."<<endl;
				break;
		}
	}while(c!=3);
}
