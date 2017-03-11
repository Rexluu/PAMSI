#include <iostream>
#include <cctype>

using namespace std; 

unsigned int count=0;
string *pal_array = new string[count];

string lower_string(string word)
{
	for (int i=0; i < word.length(); i++) 
		word[i]=tolower(word[i]);
	
	return word;
}

void show_array()
{
	for (unsigned int i = 0; i < count; i++)
		cout << i << ": " << pal_array[i] << endl;
}

void copy_array(string *from_array, string *to_array, unsigned int first, unsigned int last, int move)
{
	for (unsigned int i = first; i < last; i++)
		to_array[i+move] = from_array[i];
}


void expand_array(unsigned int new_size)
{
	string *temp_pal_array = new string[new_size];

	copy_array(pal_array,temp_pal_array,0,count-1,0); // only added empty place so count-1;

	delete [] pal_array;
	pal_array = temp_pal_array;			
}

void rmv_copies() // remove copies of palindromes and reduce size of dynamic array
{
	for (unsigned int j = 0; j < count; j++)
		for (unsigned int i = j+1; i < count; i++)
			if (lower_string(pal_array[j])==lower_string(pal_array[i])){
				string *temp_pal_array = new string[count-1];
				copy_array(pal_array,temp_pal_array,0,i,0);
				copy_array(pal_array,temp_pal_array,i+1,count,-1);
				count --;
				delete [] pal_array;
				pal_array = temp_pal_array;
				rmv_copies();
			}
}

void add_to_array(string word)
{
	count++;
	expand_array(count);
	pal_array[count-1]=word;
}

bool check_palindrome(string word)
{
	bool status;
	unsigned int len=word.length();
	if (len<=1) return true;
	
	
	if(word[0]==word[len-1]){
		status=true; 
		word.erase(len-1,len-1);
		word.erase(0,1); 
	} else status=false;
	
	return status && check_palindrome(word);
}

void swap(char &a, char &b)
{
	char tmp = a;
	a = b;
	b = tmp;
}

void perm(string word, unsigned int iter, unsigned int n)
{
	if (iter == n){
		string temp_word = lower_string(word);
		if (check_palindrome(temp_word))
			add_to_array(word);
		//cout << ++count <<": "<< word << endl; // test to see all permutations
	} else {

		for (unsigned int i = iter; i <= n; i++){
			swap(word[iter],word[i]);
			perm(word,iter+1,n);
		}
	}		
}

int main()
{
	string word;
	cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	cout << "Program do generowania wszystkich mozliwych permutacji," << endl;
	cout << "wypisuje wszystkie utworzone w ten sposob palindromy" << endl << endl;
	cout << "Podaj slowo: ";
	cin >> word;
	cout << endl;
	
	perm(word,0,word.length()-1);
	
	if (count != 0 ){
		rmv_copies();
		show_array();
		cout << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
	} else cout << "Brak palindromow" << endl << endl;

	delete [] pal_array;
	
	return 0;
}
