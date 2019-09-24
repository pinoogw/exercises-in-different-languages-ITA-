#include<stdio.h>
#include<conio.h>
#include<windows.h>
bool CeckFile(char file[])
{
FILE *o;
if((o=fopen(file,"rw"))==NULL){return false;}
return true;
}

int main()
{
if(CeckFile("password.txt"))//sostituiscimio_mio_file.txt col percorso del file da testare
{printf("\n\n Il file esiste !\n");}
else{printf("\n\n Il file non esiste !\n");}
getch();
}
