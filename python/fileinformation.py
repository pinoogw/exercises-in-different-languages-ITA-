import hashlib

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
