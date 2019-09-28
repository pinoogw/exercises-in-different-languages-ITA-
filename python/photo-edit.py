from PIL import ImageFont
from PIL import Image
from PIL import ImageDraw
import tkinter
from tkinter import messagebox
import os
import cv2
import os.path
from pathlib import Path
import hashlib
import tkinter, tkinter.messagebox

print("menu")
print("1-edit" "\n2-informazioni")
scelta=input()
if scelta == "1":
    print("nome immagine")
    img_file = input()
    name = img_file
    #punto su cui scrivere
    x_y = (182, 66)#modificare a seconda della posizione
    #colore rgb
    color_rgb = (0,0,255)#modificare a seconda del colore desiderato
    #testo da scrivere
    print("testo")
    text = input()
    if len(text)>=45:
          print("attnezione stai scrivendo troppi caratteri possibilità di errore")
    def write(text):#funzione per scrivere sull'immagine
        try:
            img = Image.open(img_file)                      #apro l'immagine
            draw = ImageDraw.Draw(img)                      #imposto la scrittura
            draw.text(x_y ,text ,color_rgb)  #imposto il testo (text) sull'immagine
            draw = ImageDraw.Draw(img)#scrivo l'immagine
            print("formato desiderato png o jpg")
            sceltaVformato=input()
            if sceltaVformato=="png":
                print("nome immagine modificata")
                img.save(input()+".png")#salvo l'immagine
                root = tkinter.Tk()
                root.withdraw()
                tkinter.messagebox.showinfo("png", "successo")
                root.destroy()
            if sceltaVformato=="jpg":
                print("nome immagine modificata")
                root = tkinter.Tk()
                root.withdraw()
                tkinter.messagebox.showinfo("jpg", "successo")
                root.destroy()
                img.save(input()+".jpg")#salvo l'immagine
            else:
                print("formato non disponibole")
        except IOError:
             print("errore file non esistente")
    write(text) #eseguo la funzione

else:
    def calcolatore(filename):
        sha1 = hashlib.sha1()
        md5 = hashlib.md5()
        with open(filename, "rb") as thefile:
             buf = thefile.read()
             md5.update(buf)
             sha1.update(buf)
        print("md5 " +md5.hexdigest())
        print("sha1 " + sha1.hexdigest())
    print("nome file")
    calcolatore(input()) 

    
