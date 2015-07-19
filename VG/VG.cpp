#include <fstream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "VG.h"

using namespace std;

void Insertion(VG * & games, int & count)
{





	VG * temp = new VG[count + 1];


	for (int i = 0; i < count; i++)


		temp[i] = games[i];


	games = temp;


	cout << "Enter a new Game: " << endl;


	cin >> games[count++];







}
int Lookup(VG * games, int count)
{





	long gameGID;


	cout << "Enter GID: ";


	cin >> gameGID;


	cin.ignore();


	for (int i = 0; i < count; i++)


	{


		if (gameGID == games[i].getgid())


		{


			cout << "Found" << endl;


			cout << games[i] << endl;


			return (i);


		}


	}


	cout << "not found" << endl;


	return (-1);







}
void Removal(VG * & games, int & count)
{





	if (count == 0) return;


	int mark4removal = Lookup(games, count);


	if (mark4removal != (-1))


	{


		VG * temp = new VG[count - 1];


		for (int i = 0, j = 0; i < count; i++)


		{


			if (i == mark4removal) i++;


			temp[j++] = games[i];


		}


		games = temp;


		count--;


	}







}
void ShowAll(VG * games, int count)
{





	for (int i = 0; i < count; i++)


		cout << games[i] << endl;







}
void AlphabeticOrder(VG * games, int count)
{





	if (count == 0) return;










	for (int k = 0; k < count - 1; k++)


	{


		int m = k;


		for (int i = k + 1; i < count; i++)


			if (games[i].getname() < games[m].getname())


				m = i;


		swap(games[k], games[m]);


	}


	ShowAll(games, count);







}
void AscendingOrder(VG * games, int count)







{





	if (count == 0) return;










	for (int k = 1; k > count; k--)


	{


		for (int i = k; i < 0; i++)


			if (games[i].getprice() < games[i + 1].getprice())


				swap(games[i], games[i + 1]);


			else


				break;


	}


	ShowAll(games, count);







}
void RangeQuery(VG * games, int count)







{





	double highestPrice, lowestPrice;


	cout << "Enter the highest price: ";


	cin >> highestPrice;


	cout << "Enter the lowest price: ";


	cin >> lowestPrice;


	for (int i = 0; i < count; i++)


	{


		if (lowestPrice <= games[i].getprice() &&


			highestPrice >= games[i].getprice())


		{


			cout << games[i] << endl;


		}


	}








}
void ExactMatch(VG * games, int count)







{





	string gameSystem;


	cout << "Enter a console: ";


	cin >> gameSystem;


	for (int i = 0; i < count; i++)


	{


		if (gameSystem == games[i].getsystem())


		{


			cout << "Found" << endl;


			cout << games[i] << endl;


		}


	}


	cout << "not found" << endl;







}
void OpenAll(VG * & games, int & count)
{





	ifstream fin("VG.txt");


	if (!fin)


	{


		cout << "Unable to open file. ";


		return;


	}


	int size;


	fin >> size;


	VG * temp = new VG[count + size];


	for (int i = 0; i < count; i++)


		temp[i] = games[i];


	games = temp;


	for (int i = 0; i < size; i++)


		fin >> games[count++];


	fin.close();







}
void SaveAll(VG * games, int count)
{





	ofstream fout("VG.txt");


	if (!fout)


	{


		cout << "Unable to open file. ";


		return;


	}


	fout << count << endl;


	for (int i = 0; i < count; i++)


		fout << games[i] << endl;


	fout.close();







}
void main()
{





	VG * games = nullptr;


	int count = 0;


	int option;


	cout << fixed << setprecision(2) << showpoint;


	do	{


		system("cls");


		cout << "-------------------------------------" << endl;


		cout << " Main Menu Video Games" << endl;


		cout << "-------------------------------------" << endl;


		cout << " Press (1) to add a new Video game" << endl;


		cout << " Press (2) to remove a Video game" << endl;


		cout << " Press (3) to search by GID" << endl;


		cout << " Press (4) to show in alphabetic order" << endl;


		cout << " Press (5) to show in Ascending order" << endl;


		cout << " Press (6) to range query by price" << endl;


		cout << " Press (7) to exact match by System" << endl;


		cout << " Press (8) to restore all VideoGames" << endl;


		cout << " Press (9) to store all VideoGames" << endl;


		cout << " Press (0) to exit the program" << endl;


		cout << "-------------------------------------" << endl;


		cout << "Enter option: ";


		cin >> option;


		cin.ignore();


		switch (option)


		{


		case 0: exit(0);


		case 1: Insertion(games, count); break;


		case 2: Removal(games, count); break;


		case 3: Lookup(games, count); break;


		case 4: AlphabeticOrder(games, count); break;


		case 5: AscendingOrder(games, count); break;


		case 6: RangeQuery(games, count); break;


		case 7: ExactMatch(games, count); break;


		case 8: OpenAll(games, count); break;


		case 9: SaveAll(games, count); break;


		default: cout << "Invalid option." << endl;


		}


		system("pause");


	} while (true);







}

