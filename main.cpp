#include <iostream>
#include <string>
using namespace std;
void board(char v[]) {
	system("clear");
	cout << "\n";
	for(int i = 0; i < 9; i++) {
		cout << " " << v[i];
		if(i == 2 || i == 5)
			cout << "\n-- + - + --\n";
		else if(i == 8)
			cout << "\n";
		else
			cout << " |";
	}
	cout << "\n";
}
int input() {
	int x;
	cin >> x;
	return (x-1);
}
bool game(char v[], int* p) {
	bool g = false;
	if((v[0] == v[4] && v[4] == v[8]) || (v[2] == v[4] && v[4] == v[6]) || (v[0] == v[1] && v[1] == v[2]) || (v[3] == v[4] && v[4] == v[5]) || (v[6] == v[7] && v[7] == v[8]) || (v[0] == v[3] && v[3] == v[6]) || (v[1] == v[4] && v[4] == v[7]) || (v[2] == v[5] && v[5] == v[8]))
		g = true;
	if(g == false) {
		int j = 0;
		for(int i = 0; i < 9; i++) {
			if(v[i] == 'X' || v[i] == 'O')
				j++;
		}
		if(j == 9) {
			g = true;
			*p = 0;
		}
	}
	return g;
}
string pname(int p, string* p1, string* p2) {
	if(p == 1)
		return *p1;
	else if(p == 2)
		return *p2;
	else
		return "It's a tie. Everybody";
}
int main() {
	char v[9];
	bool g;
	for(int i = 0; i < 9; i++)
		v[i] = (char)(i+49);
	int p = 1, x;
	system("clear");
	string p1, p2;
	cout << "Enter name of player 1: ";
	getline(cin, p1);
	cout << "Enter name of player 2: ";
	getline(cin, p2);
	do {
		play:
			board(v);
			cout << pname(p, &p1, &p2) << "\'s turn: ";
			x = input();
			if(x > 8 || x < 0 || v[x] == 'X' || v[x] == 'O')
				goto play;
			else {
				if(p == 1) {
					v[x] = 'X';
					p = 2;
				} else {
					v[x] = 'O';
					p = 1;
				}
			}
			g = game(v, &p);
	} while(!g);
	for(int i = 0; i < 9; i++) {
		if(v[i] != 'X' && v[i] != 'O')
			v[i] = ' ';
	}
	board(v);
	cout << pname(p, &p2, &p1) << " wins!\n";
	system("exit");
	return 0;
}