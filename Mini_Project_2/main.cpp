/*Young Liu
Miniproject 2
2/26/2015
c++*/
#include <fstream>
#include <string>
#include <boost/algorithm/string.hpp>

using namespace std;

string Arr[167964]; //made global to be used by these functions

int lengthChange[14] = {96, 1068, 4971, 13607, 28839, 
		51948, 80367, 105160, 125357, 140764, 152012, 159748, 164807};

bool divideConquer(string word1, string Arr[], int bound1, int bound2)
{
	//if bigger, then go right
	//if smaller, then go left
	int middle = (bound1+bound2) / 2;
	int difference = bound2-bound1;
	if (word1 == Arr[middle])
	{
		//returns true if found
		return true;
	}
	if (difference==1)
	{
		return false;
	}
	else if (word1 > Arr[middle])
	{
		//we got right
		return divideConquer(word1, Arr, middle, bound2);
	}
	else if (word1 < Arr[middle])
	{
		//we go left
		return divideConquer(word1, Arr, bound1, middle);
	}
	
	
}

//decrypt function from mini project 1
string decrypt(string text, string key)
{
	string output = "";;
	boost::algorithm::to_lower(text);
	boost::algorithm::to_lower(key);

	int j=0;
	int k;
	for (int i=0; i<text.length(); i++){//runs through the whole string
		char a = text.at(i);
		if (a >= 'a' && a <= 'z'){ //ensure we stay in the alphabet
			if (j==key.length()){
				j=0;//to wrap around the key if the text is longer
			}
			k = a - ((key.at(j)-97) % 26); //takes mod and subtracts it
			if(k<97){
				k = 122 - (96-k);//in case it goes under the a value
			}
			output += (char)k;
			j++;
		}		
	}

	return output;
}

void generateKey(int i, int keyLength, string array, string text, int wordLength)
{	
	if (i < keyLength)
	{
		for (int j=0; j<26; j++)
		{	
			//recursively call generate key to generate every possible key	
			generateKey(i+1, keyLength, array+(char)(j+97), text, wordLength);
		}
	}else
	{
		//here we call decrypt
		//to figure out what the sentence says
		string sentence = decrypt(text, array);

		//separate the first word
		string word = sentence.substr(0, wordLength);
		boost::to_upper(word);
		//convert everything to upper case

		bool ans = divideConquer(word, Arr, lengthChange[word.length()-3], lengthChange[word.length()-2]);

		if (ans)
		{
			//if return true, we print out the setence.
			std::cout << "sentence: " << sentence << std::endl;
		}
	}
}


int main()
{
	//allows user to enter the text
	string text;
	int wordLength, keyLength;;

	std::cout << "Please enter the ciphertext:" << std::endl;
	std::cin >> text;
	std::cout << "Please enter the key length:";
	std::cin >> keyLength;
	std::cout << "Please enter the word length:";
	std::cin >> wordLength;

	//The various ciphertexts, key lengths and length
	string ciphertext1 = "MSOKKJCOSXOEEKDTOSLGFWCMCHSUSGX";
	int keyLength1 = 2;
	int wordLength1 = 6;

	string ciphertext2 = "OOPCULNWFRCFQAQJGPNARMEYUODYOUNRGWORQEPVARCEPBBSCEQYEARAJUYGWWYACYWBPRNEJBMDTEAEYCCFJNENSGWAQRTSJTGXNRQRMDGFEEPHSJRGFCFMACCB";
	int keyLength2 = 3;
	int wordLength2 = 7;

	string ciphertext3 = "MTZHZEOQKASVBDOWMWMKMNYIIHVWPEXJA";
	int keyLength3 = 4;
	int wordLength3 = 10;

	string ciphertext4 = "HUETNMIXVTMQWZTQMMZUNZXNSSBLNSJVSJQDLKR";
	int keyLength4 = 5;
	int wordLength4 = 11;

	string ciphertext5 = "LDWMEKPOPSWNOAVBIDHIPCEWAETYRVOAUPSINOVDIEDHCDSELHCCPVHRPOHZUSERSFS";
	int keyLength5 = 6;
	int wordLength5 = 9;

	string ciphertext6 = "VVVLZWWPBWHZDKBTXLDCGOTGTGRWAQWZSDHEMXLBELUMO";
	int keyLength6 = 7;
	int wordLength6 = 13;
	

	std::ifstream is("dict.txt");

	string something;
	int i=0;

	//I ran through the dictionary storing length changes to be more efficient
	int lengthChange[14] = {96, 1068, 4971, 13607, 28839, 
		51948, 80367, 105160, 125357, 140764, 152012, 159748, 164807};

	//stores the entire dictionary into the array
	while (is >> something)
	{
		Arr[i] = something;
		i++;
	}

	string array="";

	clock_t startTime = clock(); //Start timer
 	double secondsPassed;

 	generateKey(0, keyLength, array, text, wordLength);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;

	/*generateKey(0, keyLength1, array, ciphertext1, wordLength1);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;
	generateKey(0, keyLength2, array, ciphertext2, wordLength2);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;
	generateKey(0, keyLength3, array, ciphertext3, wordLength3);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;
	generateKey(0, keyLength4, array, ciphertext4, wordLength4);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;
	generateKey(0, keyLength5, array, ciphertext5, wordLength5);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;
	generateKey(0, keyLength6, array, ciphertext6, wordLength6);
	 secondsPassed = (clock() - startTime) / (double) CLOCKS_PER_SEC;
	 std::cout << secondsPassed << " seconds have passed" << std::endl;*/

	//the comparison between the two words
	//so we start in the middle

	return 0;
}
