import smtplib #libreria per email


print("""
     spedisce eMail utilizzando Gmail!
    Server: smtp.gmail.com
    Porta: 587
    Si richiedono: Username, Password, Destinatario, Oggetto e Contenuto
    """) #print 

user_mittente = input("Inserisci l'Username --> ")
password = input("Inserisci la Password --> ")
destinatario = input("A chi stiamo spedendo questa Mail? ")
oggetto = "Subject: " + input("Inserisci l'oggetto della Mail, quindi premi invio: ")
contenuto = "\n\n" + input("Ora puoi inserire il contenuto Mail: ") #\n\n fa si che il contenuto venga separato dall'oggetto
messaggio = oggetto + contenuto #vreazione del messaggio
print("Sto effettuando la connessione col Server...") #print di avviso 
email = smtplib.SMTP("smtp.gmail.com",587)  #contatto server gmail
email.ehlo() 
email.starttls() #avvio  TLS
email.login(user_mittente,password) #effettuo il login
print("Sto inviando...")
email.sendmail(user_mittente,destinatario,messaggio)  #invio del messaggio 
email.quit() #disconessione
print("Messaggio Inviato!") #conferma del invio 
