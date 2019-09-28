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
using namespace std;
int main ()
{
double num1;
int Giorgi;
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
int n;
puts ("1 addizione");
puts ("\n2 sottrazione");
puts ("\n3 moltiplicazione");
puts ("\n4 divisione");
puts ("\n5 iva");
puts ("\n6 media");
puts ("\n7 elevamento");
puts ("\n8 radice");
puts ("\n0 chiusura veloce");
do
{
cin>>scelta;
switch (scelta) {
case 1:
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
case 2:
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
case 3:
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
case 4:
do
{
puts ("primo numero");
cin>>num1;
puts ("secondo numero");
cin>>num2;
try 
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
case 5:
do
{
puts("scegliere la aliquota iva");
puts("1-4%");
puts("2-10%");
puts("3-22%");
cin>>aliquota;
if (aliquota == 1)
{
puts ("importo");
cin>>importo;
iva= importo*PERC1/100;
importo += iva;
cout<<"\nimporto con iva ="<<importo;
cout<<endl<<endl;
}
if (aliquota == 2)
{
	puts ("importo");
cin>>importo;
iva= importo*PERC2/100;
importo += iva;
cout<<"\nimporto con iva ="<<importo;
cout<<endl<<endl;
}
if (aliquota == 3)
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
case 6:
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
	case 7:
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
	case 8:
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
	
		
default: puts ("errore"); break;
}
puts("rincominciare?");
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
puts ("\n0 chiusura veloce");
}
while (risposta1 == 's');
return 0;
}
