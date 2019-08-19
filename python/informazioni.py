import socket
import requests
import uuid
import platform
ip = requests.get("https://api.myip.com")
print ("il tuo ip pubblico ==> " + ip.text)
hostname = socket.gethostname()    
IPAddr = socket.gethostbyname(hostname)    
print("il nome del tuo pc ===> " + hostname)    
print("l'indirizzo ip del tuo computer ===> " + IPAddr) 
print ("l'indirizzo mac è : ", end="") 
print (':'.join(['{:02x}'.format((uuid.getnode() >> ele) & 0xff) 
for ele in range(0,8*6,8)][::-1]))
print("il tuo sistema operativo è ===> " + platform.platform())
print("il tuo processore è ===> " + platform.processor())
