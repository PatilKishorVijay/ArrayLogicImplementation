#include<iostream>
//#include<string>

using namespace std;


void convertToUpper(char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
		arr[i] = arr[i] - 32;
}

void convertToLower(char *arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
		arr[i] = arr[i] + 32;
}

void countVowelAndWords(char *arr)
{
	
	int vcount, ccount,words;
	vcount = ccount = words=0;
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == ' ')
			words++;
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u'
			|| arr[i] == 'A' || arr[i] == 'E' || arr[i] == 'I' || arr[i] == 'O' || arr[i] == 'U')
			vcount++;
		else if ((arr[i] >=65 && arr[i]<=90) || (arr[i]>=97 && arr[i]<=122))
			ccount++;
	}

	cout << " vowels count " << vcount  << " & consonant count "
		<< ccount << endl << " word count " << words + 1 << endl;

	
}

int checkStringValidity(char *arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (!((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122) ||
			(arr[i]>=48 && arr[i]<=57)))
			return 0;
	}
	return 1;
}

void reverseString(char *arr)
{
	int i, j;
	for (j = 0; arr[j] != '\0'; j++);
	j = j - 1;

	for (int i = 0; i < j; i++, j--)
	{
		char ch;
		ch = arr[i];
		arr[i] = arr[j];
		arr[j] = ch;
	}
}

int checkPal(char* arr)
{
	int i, j;
	for (j = 0; arr[j] != '\0'; j++);
	j = j - 1;

	for (int i = 0; i < j; i++, j--)
		if (arr[i] != arr[j])
			return 0;

	return 1;
}

void countOccurance(char *arr)
{


	int count[26] = { 0 };

	for (int i = 0; arr[i] != '\0'; i++)
	{
		count[(int)arr[i] - 97]++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (count[i] > 1)
		{
			cout << (char)(i + 97) << " repeated " << count[i] << " times " << endl;
		}
	}
}

int getLength(char *arr)
{
	int i;
	for (i = 0; arr[i] != '\0'; i++);
	return i;
}

int checkAnagram(char* a1, char *a2)
{
	int L1 = getLength(a1);
	int L2 = getLength(a2);
	if (L1 != L2)
		return 0;
	else
	{
		int arr[128] = { 0 };
		for (int i = 0; a1[i] != '\0'; i++)
		{
			arr[(int)a1[i]]++;
		}
		for (int i = 0; a2[i] != '\0'; i++)
		{
			arr[(int)a2[i]]++;
		}
		for (int i = 0; i < 128; i++)
		{
			if (arr[i] == 1)
				return 0;
		}
		return 1;

	}
}
int main()
{
	// create a char variable
	char c = 'a';
	cout << c << "ascii value is -  " << (int)c << endl;

	//string i.e array of characters
	char nm[10] = { 'o','j','a','s' };
	cout << "size of name array of char or STRING is "<<sizeof(nm) / sizeof(char) << endl;
	int i = 0;
	for (; nm[i] != '\0'; i++);
	cout << "length of array of character is " << i << endl;


	//string
	char name[] = "veritas";

	cout << "Program for upper to lower and lower to upper case " << endl;
	//lower to upper case
	// A-Z = 65 - 90
	// a-z = 97 - 122
	// diff = 32
	//  +32  upper to lower
	//  -32  lower to upper

	cout << name << endl;
	convertToUpper(name);
	cout << name << endl;
	convertToLower(name);
	cout << name << endl;
	cout << "***********************" << endl << endl;
	//counting numbewr of words and vowels

	cout << "program for counting numbewr of words and vowels ---" << endl;
	char A[] = "How Are You";

	cout << A << endl;
	countVowelAndWords(A);
	cout << "***********************" << endl << endl;

	//validating a string
	cout << "program for string validation" << endl;
	char arr[15];
	cin.getline(arr,15);
	cout << arr << endl;

	if (!checkStringValidity(arr))
		cout << "password must contain a-z ,A-Z , 0-9" << endl;
	cout << "***********************" << endl << endl;

	//reversing a string
	cout << "string revers" << endl;
	char rev[12];
	cout << "enter a strgin for reversing" << endl;
	cin.getline(rev,12);
	cout << rev << endl;
	reverseString(rev);
	cout << rev << endl;

	//compare and palindrome
	char pal[10];
	cout << "enter strng for palindrome check" << endl;
	cin >> pal;
	if (checkPal(pal))
		cout << "palindrome" << endl;
	else
		cout << "not palindrome" << endl;

	//count alphabet occurance
	char occurance[16];
	cout << "enter string for char occurance count" << endl;
	cin >> occurance;
	countOccurance(occurance);
	cout << "***********************" << endl << endl;

	//Anagram - if 2 strings are formed using same set of characters
	char a1[15];
	char a2[15];
	cout << "enter strings for anagram checking" << endl;
	cin >> a1;
	cin >> a2;
	if (checkAnagram(a1, a2))
		cout << "strings are anagram" << endl;
	else
		cout << "not anagram" << endl;
}