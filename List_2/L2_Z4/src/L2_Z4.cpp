#include "libraries.hpp"

#include "Deque.hpp"

bool check_palindrome(Deque <char> deque)
{
	bool status;
	int len=deque.length();
	char tmp_front = deque.begin();
	char tmp_end = deque.end();

	if (len<=1) { deque.pop_front(); return true; }
	
	if(tmp_front==tmp_end){
		status=true; 
		deque.pop_front();
		deque.pop_back();
	} else status=false;
	
	return status && check_palindrome(deque);
}

int menu()
{
	char c;
	Deque <char> deque;
	

	cout << endl;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Program sprawdza palindrom w oparciu o Deque" << endl;
	
	cout << endl << "Podaj slowo: ";
	
	while(cin.get(c))
	{
		if(c<32 || c>126) break; // ASCII DEC, letter, digits and some signs
		deque.push_back(tolower(c)); //change Upper letters to lower and add to deque, it deals with digits
	}

	if(check_palindrome(deque)) 
		cout << endl << "Podane slowo jest palindromem" << endl;
	else {
		deque.remove_all();
		cout << endl << "Podano slowo nie jest palindromem" << endl;
	}
}
		

int main()
{	
	
	menu();
	return 0;
}
