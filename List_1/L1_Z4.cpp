#include <iostream>
#include <cctype>

using namespace std; 

bool check_palindrom(string word)
{
	bool status;
	int len=word.length();
	if (len<=1) return true;
	
	
	if(word[0]==word[len-1]){
		status=true; 
		word.erase(len-1,len-1);
		word.erase(0,1); 
	} 
	else status=false;
	
	return status && check_palindrom(word);
}

int main()
{
	string word;
	cin >> word;
	
	string temp_word=word;
	for (unsigned int i = 0; i < temp_word.length(); i++) temp_word[i]=tolower(temp_word[i]);
	
	check_palindrom(temp_word) ? cout << "Slowo: " << word << " jest palindromem" : cout << "Slowo: " << word << " nie jest palindromem";
	
	return 0;
}
