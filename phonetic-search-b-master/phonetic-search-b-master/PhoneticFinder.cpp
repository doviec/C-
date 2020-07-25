
#include <iostream>
#include "PhoneticFinder.hpp"
#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <functional>




vector<string> split (string sentence, string split) 
{
    size_t pos_start = 0, pos_end, splitBy_len = split.length();
    string token;
    vector<string> res;

    while ((pos_end = sentence.find (split, pos_start)) != string::npos) 
    {
        token = sentence.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + splitBy_len;
        res.push_back (token);
    }

    res.push_back (sentence.substr (pos_start));
    return res;
}

string phonetic::find(string txt, string word)
{
    if (word.empty() || txt.empty() || word.size() < 1 || txt.size()  < 1)
    {
       cout << "wrong input";
       throw  std::exception(); //throw exception 
    }
    transform(word.begin(), word.end(),word.begin(), :: tolower);  //change word to lower key
    int indexWord, indexCurrent;
    string splitBy = " ";
    string tempCurrent;
    vector textSplit = split(txt,splitBy); //splits the text to words
    bool check = false;
    bool checkChar = false;
    for (auto current : textSplit) 
    {
        tempCurrent = current;
        transform(tempCurrent.begin(), tempCurrent.end(),tempCurrent.begin(), :: tolower);
        if (tempCurrent.size() == word.size())  // check if words length is equal
        {
           indexWord = 0;
           indexCurrent = 0;
           for (int i = 0; i < word.size(); i++) // go over both words to check if equal
           {
               if (tempCurrent.at(indexCurrent) == word.at(indexWord))  // checks if letters are equal
               {

                  indexWord ++;
                  indexCurrent ++; 
               } 
               else  // if not, check if the the replacment letter is equal
               {
                   char charCurrent = tempCurrent.at(indexCurrent);
                   char charWord = word.at(indexWord);
                   checkChar = checkEqual(charCurrent, charWord); 
                   if (checkChar == false)
                   {
                      i = word.size();  //will stop the for
                   }
                   else
                   {
                       indexWord ++;
                       indexCurrent ++; 
                   }
               }
           }
           if (current.size() == indexWord)
           {
               check = true;
               cout << "The word in the text is : " + current + '\n';
               return current;
               
           }
           
           
           
        }       
    }
    cout << "The word " + word + " is not in the text '\n'";
    throw  std::exception();
   }

bool checkEqual(char currentC, char wordC)
{
    switch (wordC){
      // v || w
        case 'v':
                if (currentC == 'w')
                {
                    return true;
                }
                else return false;
       case 'w':
                if (currentC == 'v')
                {
                    return true;
                }
                else return false; 
    // b || f || p
        case 'b':
                if (currentC == 'f' || currentC == 'p')
                {
                    return true;
                }
                else return false;  
        case 'f':
                if (currentC == 'b' || currentC == 'p')
                {
                    return true;
                }
                else return false;                                   
        case 'p':
                if (currentC == 'f' || currentC == 'b')
                {
                    return true;
                }
                else return false;  
        // j || g
        case 'j':
                if (currentC == 'g')
                {
                    return true;
                }
                else return false;          
        case 'g':
                if (currentC == 'j')
                {
                    return true;
                }
                else return false;  
        // c || k || q
        case 'c':
                if (currentC == 'k' || currentC == 'q')
                {
                    return true;
                }
                else return false;  
        case 'k':
                if (currentC == 'c' || currentC == 'q')
                {
                    return true;
                }
                else return false;                                   
        case 'q':
                if (currentC == 'c' || currentC == 'k')
                {
                    return true;
                }
                else return false; 
        // s || z
        case 's':
                if (currentC == 'z')
                {
                    return true;
                }
                else return false;          
        case 'z':
                if (currentC == 's')
                {
                    return true;
                }
                else return false;         
       
          // d || t
        case 'd':
                if (currentC == 't')
                {
                    return true;
                }
                else return false;          
        case 't':
                if (currentC == 'd')
                {
                    return true;
                }
                else return false;   
         // o || u
        case 'o':
                if (currentC == 'u')
                {
                    return true;
                }
                else return false;          
        case 'u':
                if (currentC == 'o')
                {
                    return true;
                }
                else return false;                 
        // i || y
        case 'i':
                if (currentC == 'y')
                {
                    return true;
                }
                else return false;          
        case 'y':
                if (currentC == 'i')
                {
                   ////////////////////////////  cout << "i ";
                    return true;
                }
                else return false;  
        default:
          return false;
    }   
}


