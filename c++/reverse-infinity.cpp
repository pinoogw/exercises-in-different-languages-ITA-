#include <bits/stdc++.h> 
#include <stdio.h> 
#include <string.h> 
#include <iostream>
#define ever (;;)
using namespace std; 
  
// Funzione per reversare la stringa
void reverseStr(string& str) 
{ 
    int n = str.length(); 
  
    
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
  
int main() 
{ 

string str;
for ever //loop
{

cin>>str; //leggi la stringa
   reverseStr(str);  //richiama la funzione reverse
    cout << str;    //scrivi a schermo la stringa 
    if (str == string(str.rbegin(), str.rend())) { //se la stringa è palindroma 
    cout << "\tis a palindrome"; //scrivi a schermo che è palindroma 
}
}
    return 0; 
} 


