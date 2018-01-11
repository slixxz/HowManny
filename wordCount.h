//Title Lab 5 WordData class and implementations 
//Author: David Smith
//Description: 

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

class WordData
{
public:
  WordData ();
  WordData (const WordData & OtherWord);
  ~WordData ();
  void SetWord (const string & InWord);
  string GetWord () const;
  void WriteData (ostream & outs) const;
  bool operator < (const WordData & OtherWord) const;
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
private:
  string word; // C++ string to hold the word
  int vowels; // vowel counter
  int digits;// digti counter
  int consonants; // consonant counter
  int specialchars; // special character counter.
};

// Function implementations will be placed after this line.

bool isvowel (char aletter);


WordData :: WordData ()
{
  vowels=0;
  consonants=0;
  digits=0;
  specialchars=0;
}

WordData :: WordData (const WordData & OtherWord)
{
  word=OtherWord.word;
  vowels=OtherWord.vowels;
  consonants=OtherWord.consonants;
  digits=OtherWord.digits;
  specialchars=OtherWord.specialchars;
}

WordData::~WordData ()
{

}

bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
 
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase == 'O' || upcase == 'U')
    {
      return true;
    }
  return false;
}


void WordData::SetWord ( const string & InWord)
{
  word=InWord;


  for (int i = 0; i < InWord.length(); i++)
    {

      if (isalpha(word[i]))
	{

	  if (isvowel (word[i]))
	    vowels++;

	  else
	    consonants++;
	}

      else
	{

	  if(isdigit(word[i]))
	    digits++;

	  else
	    specialchars++;
	}
    }
}

string WordData::GetWord () const
{
  return word;
}





void WordData::WriteData (ostream & outs) const
{
  outs << setw(12) << left << word;
  outs << setw(8) << right << vowels;
  outs << setw(8) << right << consonants;
  outs << setw(8) << right << digits;
  outs << setw(8) << right << specialchars;
}



int WordData::GetNumVowels () const
{
  return vowels;
}
int WordData::GetNumConsonants () const
{
  return consonants;
}
int WordData::GetNumDigits () const
{
  return digits;
}
int WordData::GetNumSpecialChars () const
{
  return specialchars;
}

bool WordData::operator < (const WordData & OtherWord) const
{
  if (word.length() < OtherWord.word.length())
    {
      return true;
    }
  else if (word.length() > OtherWord.word.length())
    {
      return false;
    }
  else if(word.length() == OtherWord.word.length())
    {
      if(word < OtherWord.word)
	{
	  return true;
	}

      else
	{
	  return false;
	}
    }
}

#endif
