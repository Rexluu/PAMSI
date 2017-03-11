#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void menu();

void free_array(long int *array, bool read_file) // czyszczenie, free usuwa calosc i przy ponowniej reallokacji przy free program sie wysypie
{
	if (read_file)
	{
	
		long int *temp_array;
	
		temp_array = (long int*) realloc (array, 1 * sizeof(long int));
	
		if(temp_array==NULL)
		{
			cerr << "Cos poszlo nie tak, sprawdz ilosc wolnej pamieci ram" << endl;
			free(array);
			menu();
		}
		else
		{
			array = temp_array;
		}
	}
}

void array_realloc(long int *array, long int iterator)
{
	long int *temp_array;
	
	temp_array = (long int*) realloc (array, iterator * sizeof(long int));
	
	if(temp_array==NULL)
	{
		cerr << "Cos poszlo nie tak, sprawdz ilosc wolnej pamieci ram" << endl;
		free(array);
		menu();
	}
	else
	{
		array = temp_array;
	}
}

void add_item(long int *array,long int iterator,long int number)
{
	array_realloc(array,iterator);
	array[iterator-1]=number; // start from 0
}

bool read_txt_array(long int *array, string name, long int &iterator)
{
	long int number;
	iterator = 0; // start from zero
	
	ifstream file(name.c_str(), ifstream::in);
	
	if (file.is_open())
	{
		while(file >> number) {
			iterator++;
			add_item(array,iterator,number);
		}
		file.close();
		return true;
	} else {
		cerr << "Cos poszlo nie tak, sprawdz czy plik istnieje lub nie jest uzywany przez inny program" << endl;
		return false;
	}
}

bool read_bin_array(long int *array, string name, long int &iterator)
{
	long int number;
	iterator = 0; // start from zero
	
	ifstream file(name.c_str(), ifstream::in | ifstream::binary);
	
	if (file.is_open())
	{
		while((file.read((char *) & number, sizeof number))) {
			iterator++;
			add_item(array,iterator,number);
		}
		file.close();
		return true;
	} else {
		cerr << "Cos poszlo nie tak, sprawdz czy plik istnieje lub nie jest uzywany przez inny program" << endl;
		return false;
	}
}

void write_txt_array(long int *array, string name, long int iterator)
{
	ofstream file (name.c_str(), ofstream::out | ofstream::app);
	
	if (file.is_open())
	{
		for(long int i = 0; i < iterator; i++) file << array[i] << " ";
		file.close();
	} else cerr << "Cos poszlo nie tak, sprawdz czy plik nie jest uzywany przez inny program" << endl;
}

void write_bin_array(long int *array, string name, long int iterator)
{
	ofstream file (name.c_str(), ofstream::out | ofstream::app | ofstream::binary);
	
	if (file.is_open())
	{
		for(long int i = 0; i < iterator; i++) file.write((const char *) &array[i], sizeof array[i]);
		file.close();
	} else cerr << "Cos poszlo nie tak, sprawdz czy plik nie jest uzywany przez inny program" << endl;
}

void menu()
{
	char option;
	long int *array;
	bool read_file=false;
	string name;
	long int iterator;
	
	while(1) {
	
	cout << endl << "- - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "1. Wczytaj tablice z pliku tekstowego" << endl;
	cout << "2. Wczytaj tablice z pliku binarnego" << endl;
	cout << "3. Zapisz tablice do pliku tektowego" << endl;
	cout << "4. Zapisz tablice do pliku binarnego" << endl;
	cout << "0. Wyjdz z programu" << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - -" << endl << endl;
	cout << "Wybor (0-4): ";
	cin >> option;
	cout << endl;
	
	switch(option)
	{
		case '1':
			cout << "Podaj nazwe pliku: ";
			cin >> name;
			free_array(array, read_file);
			read_file=read_txt_array(array,name,iterator);
		break;
		
		case '2':	
			cout << "Podaj nazwe pliku: ";
			cin >> name;
			free_array(array, read_file);
			read_file=read_bin_array(array,name,iterator);
		break;
		
		case '3':
			if (read_file)
			{
			cout << "Podaj nazwe pliku: ";
			cin >> name;
			write_txt_array(array,name,iterator);
			} else cerr << "Nie mozna wykonac tej operacji, nie wczytano tablicy" << endl;
		break;
		
		case '4':
			if (read_file)
			{
			cout << "Podaj nazwe pliku: ";
			cin >> name;
			write_bin_array(array,name,iterator);
			} else cerr << "Nie mozna wykonac tej operacji, nie wczytano tablicy" << endl;
		break;
		
		case '0':
			free(array);
			exit(0);
		break;
			
		default:
			cout << "Brak takiej opcji w menu" << endl;
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
