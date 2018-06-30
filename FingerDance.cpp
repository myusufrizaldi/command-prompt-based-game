#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

using namespace std;

int score = 0;
int stroke = 0;
float acc = 0;
int menu = 0;
int difficulty = 0;
int infinity = 0;
int maxKeystroke = 50;

void clear();
char generate();
void selectMenu();
void selectDifficulty();
void selectMode();
void line();
void header();
void stats();
void credits();

int main() {
	while (menu == 0) {
		int arrSize = 13;
		char arr[arrSize];
		char current;	
	
		//showing main menu
		clear();
		header();
		line();
		credits();
		line();
		selectMenu();
		if(menu == 1){
			return 0;
		}
	
		//showing difficulty selections
		header();
		line();
		selectDifficulty();
		
		//showing mode selections
		header();
		line();
		selectMode();
	
		//first initiate the queue
		for (int i=0; i<arrSize; i++){
			arr[i] = generate();
		}
	
	
		//main game
		while ((infinity == 0 && stroke <= maxKeystroke) || infinity == 1) {
			do {		
				clear();
				header();
				line();
				credits();
				stats();
				
				//print the queue
				cout<<"  ";		
				for (int i=0; i<arrSize; i++){
					if(i != arrSize-1){
						cout<<arr[i]<<"  ";
					}else{
						cout<<"("<<arr[i]<<")";
					}
				}
				
				//get char from keyboard & get stats
				current = getch();
				current = toupper(current);		
				if(current == arr[arrSize-1]){
					score++;	
				}
				stroke++;
				acc = (  float(score)/float(stroke)  )*100;
			
			} while (current != arr[arrSize-1]);
			
			//moving the queue from left to right
			for(int i=arrSize-1; i>0; i--){
				arr[i] = arr[i-1];
			}
			arr[0] = generate();
		}
		
		//game finished, stopping the game
		cout<<"\n\nFinished!!";
		Sleep(2000);
		cout<<" Press any key to main menu...";
		char decoy = getch();
	}
}

char generate() {
	//generating random char for the queue
	int diff;
	char key[] = {'A', 'S', 'D', 'J', 'K', 'L', 'G', 'H', 'I', 'C', 'E', 'F', 'M', 'N', 'O', 'P', 'Q', 'R', 'B', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	switch (difficulty) {
		case 0:
			diff = 3;
			break;
		case 1:
			diff = 6;
			break;
		case 2:
			diff = 26;
			break;
	}
	
	return key[rand() % (diff)];
}

void clear() {
	//just clear the screen
	system("CLS");
}

void selectMenu() {
	//main menu
	int tempMenu = -1;
	do {
		cout<<"Select menu :"<<endl;
		cout<<"1. Play"<<endl;
		cout<<"2. Close"<<endl;
		cout<<"Your answer : ";
		cin>>tempMenu;
		menu = tempMenu - 1;
		
		if(tempMenu < 1 || tempMenu > 3){
			cout<<"Your answer is not valid. Please try again...";
		}else{
			if(tempMenu != 2){
				cout<<"Do not waste your time OK?!";
			}else{
				cout<<"Thank you, now closing...";
			}
		}
		
		Sleep(2000);
		clear();
	} while (tempMenu < 1 || tempMenu > 3);
}

void selectDifficulty() {
	//difficulty selection
	int tempDifficulty = -1;
	do {
		cout<<"Select difficulty :"<<endl;
		cout<<"1. Easy"<<endl;
		cout<<"2. Medium"<<endl;
		cout<<"3. Hard"<<endl;
		cout<<"Your answer : ";
		cin>>tempDifficulty;
		difficulty = tempDifficulty - 1;
		
		if(tempDifficulty < 1 || tempDifficulty > 3){
			cout<<"Your answer is not valid. Please try again...";
		}else{
			cout<<"I hope you enjoy this game...";
		}
		
		Sleep(2000);
		clear();
	} while (tempDifficulty < 1 || tempDifficulty > 3);
}

void selectMode() {
	//mode selection
	int tempMode = -1;
	infinity = 0;
	do {
		cout<<"Select mode : "<<endl;
		cout<<"1. 50 Keystroke"<<endl;
		cout<<"2. 100 Keystroke"<<endl;
		cout<<"3. 200 Keystroke"<<endl;
		cout<<"4. 800 Keystroke"<<endl;
		cout<<"5. Infinity Keystroke"<<endl;
		cout<<"Your answer : ";
		cin>>tempMode;
		
		if(tempMode < 1 || tempMode > 5){
			cout<<"Your answer is not valid. Please try again...";
		}else{
			cout<<"Nice answer...";
			switch(tempMode){
				case 1:
					maxKeystroke = 50;
					break;
				case 2:
					maxKeystroke = 100;
					break;
				case 3:
					maxKeystroke = 200;
					break;
				case 4:
					maxKeystroke = 800;
					break;
				case 5:
					infinity = 1;
					maxKeystroke = -1;
					break;
			}
		}
		
		Sleep(2000);
		clear();
	} while (tempMode < 1 || tempMode > 5);
}

void line() {
	//just printing a line of equals
	cout<<"==========================================="<<endl;
}

void header() {
	//printing the game's name
	cout<<"...@@@@..@..@@....@...@@@@..@@@@@..@@@@@..."<<endl;
	cout<<"...@.....@..@.@...@..@......@......@...@..."<<endl;
	cout<<"...@@@@..@..@..@..@..@..@@..@@@....@@@....."<<endl;
	cout<<"...@.....@..@...@.@..@...@..@......@..@...."<<endl;
	cout<<"...@.....@..@....@@..@@@@@..@@@@@..@...@..."<<endl;
	cout<<"..........................................."<<endl;
	cout<<"....@@@......@....@@....@...@@@@..@@@@@...."<<endl;
	cout<<"....@..@....@.@...@.@...@..@......@........"<<endl;
	cout<<"....@...@..@@@@@..@..@..@..@......@@@......"<<endl;
	cout<<"....@..@...@...@..@...@.@..@......@........"<<endl;
	cout<<"....@@@....@...@..@....@@...@@@@..@@@@@...."<<endl;
}

void stats() {
	//show the statistics
	line();
	cout<<"Score    : "<<score<<endl;
	cout<<"Stroke   : "<<stroke<<endl;
	cout<<"Accuracy : "<<acc<<" %"<<endl;
	line();
	cout<<"\n\n";
}

void credits() {
	//just a credit to my github
	cout<<"GitHub : @myusufrizaldi ~~ FingerDance 2018"<<endl;
}
