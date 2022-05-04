nasm -f win64 adjuststack.asm -o adjuststack.o
nasm -f win64 chkstk_ms.asm -o chkstk_ms.o
x86_64-w64-mingw32-gcc decoderstub.c -Wall -m64 -ffunction-sections -fno-asynchronous-unwind-tables -nostdlib -fno-ident -O2 -c -o decoderstub.o -Wl,-Tlinker.ld,--no-seh 
x86_64-w64-mingw32-ld -s adjuststack.o chkstk_ms.o decoderstub.o -o decoderstub.exe
for i in $(objdump -d decoderstub.exe |grep "^ " | cut -f2); do echo -e -n "\x$i"; done > decoderstub.bin
