#include <iostream>
#include <string>
using namespace std;

int main()
{
    string sentence, word = "", longestWord = "";
    
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    for(int i = 0; i <= sentence.length(); i++)
    {
        if(i == sentence.length() || sentence[i] == ' ')
        {
            if(word.length() > longestWord.length())
            {
                longestWord = word;
            }
            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }

    cout << "Longest word: " << longestWord << endl;
    cout << "Length: " << longestWord.length() << endl;

    return 0;
}