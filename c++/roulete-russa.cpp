#include <iostream>
#include <time.h>
#include <cstdio>
#include <windows.h>
#include <cstdlib>
#include <string>
using namespace std;
int main () {
int a;
int x;
cout<<"\nbenvenuto nella famosa roulette russa premi invio per giocare";
for (;;)
{
	for (char i=1; i<=255; i++)
	{
		if(GetAsyncKeyState(i) != NULL)
		{
			a=i;
		  	if (a==13)
			{
				
				srand(time(0));
				x=(rand() %10)+1;
				switch(x)
				{
				case 1:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 2:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 3:
				MessageBox(NULL,"vita","Caption",MB_OK);
				case 4:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 5:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 6:
				MessageBox(NULL,"morte","Caption",MB_OK);
				MessageBox(NULL,"hai perso","Caption",MB_OK);
				return 1;
				break;	
				case 7:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 8:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 9:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				case 10:
				MessageBox(NULL,"vita","Caption",MB_OK);
				break;
				
				}
			}
	
		}
	}
}
cin.get();
cin.get();
}
