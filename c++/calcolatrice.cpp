#include <windows.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <unistd.h>
#include <cstdio>
#include <math.h>
#include <bits/stdc++.h> 
using namespace std; 
// Funzione per reversare la stringa
void reverseStr(string& str) 
{ 
    int n = str.length(); 
    for (int i = 0; i < n / 2; i++) 
        swap(str[i], str[n - i - 1]); 
} 
int main ()
{
double num1;
int aliquota;
double radice;
radice=0;
double num2;
char risposta; 
double num3;
int risultato;
char risposta1;
int scelta;
int numero;
double media;	
int i=0;	
double somma=0;
char c;
double importo;
double iva;
const int PERC=22;
const int PERC1=4;
const int PERC2=10;
//menu di scelta
puts ("\n1 addizione");
puts ("\n2 sottrazione");
puts ("\n3 moltiplicazione");
puts ("\n4 divisione");
puts ("\n5 iva");
puts ("\n6 media");
puts ("\n7 elevamento");
puts ("\n8 radice");
puts ("\n9 test palindromo");
puts ("\n0 chiusura veloce");
//inizializazzione del loop con richieta di uscire
do
{
cin>>scelta;
switch (scelta) {
case 1: //addizione
do
{
puts ("primo numero");
cin>>num1;
puts ("secondo numero");
cin>>num2;
risultato = num1 + num2;
cout<<"\nrisultato = " << risultato;
cout<<endl<<endl;
puts("continuare?");
cin>>risposta;
}
while (risposta == 's');
system ("\npause");
break;
case 2: //sottrazione
do
{
puts ("primo numero");
cin>>num1;
puts ("secondo numero");
cin>>num2;
risultato = num1 - num2;
cout<<"\nrisultato = " << risultato;
cout<<endl<<endl;
puts("continuare?");
cin>>risposta;
}
while (risposta == 's');
system ("\npause");
break;
case 3: //moltiplicazione
	do
	{
	
	puts ("primo numero");
cin>>num1;
puts ("secondo numero");
cin>>num2;
risultato = num1 * num2;
cout<<"\nrisultato = " << risultato;
cout<<endl<<endl;
puts("continuare?");
cin>>risposta;
}
while (risposta == 's');
system ("\npause");
break;
case 4: //divisione
do
{
puts ("primo numero");
cin>>num1;
puts ("secondo numero");
cin>>num2;
try //ecezzione nel dividere per zero
{
	if (num2 == 0)
	{
		throw 100;
	}

risultato = num1/num2;
cout<<"\nrisultato = " << risultato;
}
catch (int codice)
{

	cout<<"secondo la regola non si puo dividere per zero";
}
cout<<endl<<endl;
puts("continuare?");
cin>>risposta;
}
while (risposta == 's');
system ("\npause");
break;
case 5: //iva
do
{
puts("scegliere la aliquota iva");
puts("1-4%");
puts("2-10%");
puts("3-22%");
cin>>aliquota;
if (aliquota == 1) //iva 4%
{
puts ("importo");
cin>>importo;
iva= importo*PERC1/100;
importo += iva;
cout<<"\nimporto con iva ="<<importo;
cout<<endl<<endl;
}
if (aliquota == 2) //iva 10%
{
	puts ("importo");
cin>>importo;
iva= importo*PERC2/100;
importo += iva;
cout<<"\nimporto con iva ="<<importo;
cout<<endl<<endl;
}
if (aliquota == 3) //iva 22%
{
puts ("importo");
cin>>importo;
iva= importo*PERC/100;
importo += iva;
cout<<"\nimporto con iva ="<<importo;
cout<<endl<<endl;
}
puts("continuare?");
cin>>risposta;
}
while (risposta == 's');
system ("\npause");
break;
case 0:
puts ("arresto emergenza");
system ("pause");
return 3;
case 6: //media
do
	{
		cout << "\ninserisci il numero utente: ";
		cin >> numero;
		somma += numero;
		i++;
		cout << "\nvuoi continuare  (s/n)    " ;
		cin >> risposta;
	}
	while (risposta == 's') ;
	media = somma / i;
	cout << "\n\n media = " << media;
	cout << "\nquesta è la tua media  ";
	cout << endl << endl;
	system ("pause");
	break;
	case 7: //potenza
	do 
	{
	puts ("potenza");
	cin>>num1;
	risultato = num1*num1;
	cout<<"\nrisultao" << risultato;
	cout<<endl<<endl;
	puts("continuare?");
	cin>>risposta;
    }
    while (risposta == 's');
	system ("\npause");
	break;
	case 8: //radice quadrata
	do
	{
	puts("inserisci il numero");
	cin>>num1;
	radice=sqrt(num1);
	cout<<"\nrisultato" <<radice;
	cout<<endl<<endl;
	puts("continuare");
	cin>>risposta;
    }
    while (risposta == 's');
	system ("pause");
	break;
	case 9: //palindroma
	{
string str;
do 
{
puts("inserisci il numero/parola");
cin>>str; //leggi la stringa
reverseStr(str);  //richiama la funzione reverse
cout << str;    //scrivi a schermo la stringa 
if (str == string(str.rbegin(), str.rend())) { //se la stringa è palindroma 
cout << "\tis a palindrome"; //scrivi a schermo che è palindroma 
}
puts("\ncontinuare");
cin >> risposta;
}
while (risposta == 's');
}	
default: puts ("errore"); break;
}
puts("rincominciare?"); //rifare la scelta 
cin>>risposta1;
system ("cls");
puts ("1 addizione");
puts ("\n2 sottrazione");
puts ("\n3 moltiplicazione");
puts ("\n4 divisione");
puts ("\n5 iva");
puts ("\n6 media");
puts ("\n7 elevamento");
puts ("\n8 radice");
puts("\n9 test palindromo");
puts ("\n0 chiusura veloce");
}
while (risposta1 == 's');
return 0;
}
