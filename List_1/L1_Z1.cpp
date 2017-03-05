#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;


long int **create_array(long int w, long int k)
{
	long int **array2 = new long int *[w];
	
	for (long int i = 0; i < w; i++)
		array2[i] = new long int[k];
	
	return(array2);
}


void fill_array(long int w, long int k, long int x, long int **array2)
{
	for(long int i = 0; i < w; i++)
		for(long int j = 0; j < k; j++)
			array2[i][j] = rand() % x;
}

void show_array(long int w, long int k, long int x, long int **array2)
{
	for(long int i = 0; i < w; i++)
	{
		cout << endl;
		for(long int j = 0; j < k; j++)
		{
			cout.width(5);
			cout << array2[i][j];
		}
	}
	cout << endl;
}

void delete_array(long int **array2, long int w)
{
	for (long int i = 0; i < w; i++)
		delete [] array2[i];
	delete [] array2;
	array2 = NULL;
}


void menu()
{
	char option;
	long int **array2;
	bool array_exist=false;
	bool fill_exist=false;
	bool x_exist=false;
	long int w,k,x;
	
	while(1) {
	cout << endl << "- - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "1. Ustal rozmiar tablicy" << endl;
	cout << "2. Ustal maksymalna wartosc x" << endl;
	cout << "3. Wypelnij tablice wartosciami od 0 do x" << endl;
	cout << "4. Wyswietl tablice" << endl;
	cout << "5. Usun tablice" << endl;
	cout << "0. Koniec (usuwa dynamiczna tablice)" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
	cout << "Wybor (0-5): ";
	cin >> option;
	cout << endl << endl;
	
	switch(option)
	{
		case '1':
			cout << "Podaj liczbe wierszy: ";
			cin >> w;
			cout << "Podaj liczbe kolumn:  ";
			cin >> k;
			if(w>0 && k>0){
				array2=create_array(w,k);
				array_exist=true;
			} else {
				cerr << "Podano nieprawidlowe wymiary tablicy" << endl;
			}
		break;
		
		case '2':
			cout << "Podaj wartosc x: ";
			cin >> x;
			if (x<=0) cerr << "Podano nieprawdilowa wartosc x, podaj wartosc >0" << endl;
			else x_exist=true;
		break;
		
		case '3':
			if (x_exist && array_exist) fill_array(w,k,x,array2);
			else {
			cerr << "Nie podano rozmiaru tablicy badz wartosci x" << endl;
			menu();
			}
			fill_exist=true;
		break;
		
		case '4':
			if (fill_exist) show_array(w,k,x,array2);
			else {
			cerr << "Nie wypelniono tablicy" << endl;
			menu();
			}
		break;
		
		case '5':
			if (array_exist) delete_array(array2,w);
			else {
			cerr << "Tablica nie istnieje" << endl;
			menu();
			}
			array_exist=false;
			fill_exist=false;
		break;
		
		case '0':
			if (array_exist) delete_array(array2,w);
			exit(0);
		break;
		
		default:
			cerr << "Brak takiej opcji w menu" << endl;
			menu();
		break;
		
	}
}
}

int main()
{
	menu();
	return 0;	
}
