We cannot find anything related to `level14`, neither a file (in the home directory or elsewhere on the system) nor a process...  
All that's left is to exploit `getflag` itself.

We run it with `gdb`:
- We prefer using the intel syntax for ASM (`set disassembly-flavor intel`)
- We set a breakpoint at `main` to explore the ASM code (`b main`)
- We find the call to `ptrace` which will be triggered by gdb (`b *0x0804898e`)
- We change eax to 0  because it will contain the return value of ptrace that check if gdb is used (it will return -1) to avoid it (`set $eax=0`)
- We set a breakpoint after the call  of `getuid` (`b *0x08048b0a`) where they compare it to different value, we guess we need to find the value for the user flag14 
- We find in `/etc/passwd` that flag14 uid is 3014. So we modify the register containing the return value of `getuid` (`set $eax=3014`) at the breakpoint we stoped before
- We continue running the program (`c`)
- We get the flag!
