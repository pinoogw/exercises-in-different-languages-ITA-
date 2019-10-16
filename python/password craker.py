import os
from urllib.request import urlopen, hashlib
import random
import time
def cracker():
    picasso = str(input("sha 256 "))
    with open('password.txt') as f:
        for line in f:
            line = line.strip()
            print(f'{hashlib.sha256(line.encode()).hexdigest()} --> {line}')
            if hashlib.sha256(line.encode()).hexdigest() == picasso:
                print('password trovata --> ' + line)
                break
           

def database_ampliatore():
    x=0
    while x<10000000000:
         s = "01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZqwertyuiopasdfghjklzxcvbnm@#"
         passlen = 16
         p =  "".join(random.sample(s,passlen ))
         x=x+1
         with open('password.txt') as file:
             contents = file.read()
             search_word = p
             if search_word in contents:
                 print ('parola trovata non aggiungo nulla')
             else:
                 testate = open('password.txt', 'a')
                 testate.write(p + '\n')
                 print("parola aggiunta")

def scelta_personale():
    aggiunta=input("aggiungi parola personale ")
    with open('password.txt') as file:
        contents = file.read()
        search_word = aggiunta
        if search_word in contents:
            print ('parola trovata gia inserita')
        else:
            testate = open('password.txt', 'a')
            testate.write(aggiunta + '\n')
            print("parola aggiunta")

def menu():
    print("\n1 crack")
    print("2 aggiungi")
    print("3 aggiungi(personale) ")

def main():
    menu()
    scelta=int(input("segli"))
    if scelta == 1: cracker()
    elif scelta == 2: database_ampliatore()
    elif scelta == 3: scelta_personale()
    else:
        print("comando sconosciuto ")
         
main()
