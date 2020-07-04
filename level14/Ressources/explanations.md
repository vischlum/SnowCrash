We cannot find anything related to `level14`, neither a file (in the home directory or elsewhere on the system) nor a process...  
All that's left is to exploit `getflag` itself.

We run it with `gdb`:
- We prefer using the intel syntax for ASM (`set disassembly-flavor intel`)
- We set a breakpoint at `main` to explore the ASM code (`b main`)
- We find the call to `ptrace` which will be triggered by gdb (`b *0x0804898e`)
- We change `eax` to avoid it (`set $eax=0`)
- We jump to the call to `getuid` (`b *0x08048c01`)
- We find in `/etc/passwd` that flag14 uid is 3004. So we modify the register containing the return value of `getuid` (`set $eax=3004`)
- We continue running the program (`c`)
- We get the flag!