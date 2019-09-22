from gtts import gTTS
import subprocess
import os.path

text = input("")
tts = gTTS(text=text, lang='it')
tts.save("pino.mp3")
print("tutto fatto, file salvato!")




