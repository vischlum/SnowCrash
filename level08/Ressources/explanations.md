In `/home/user/level08`, we find a file named `token` and an executable. The latter takes an argument, and refuses to read file with `token` in their name.  
This is confirmed by a disassembly with `gdb`: it is protected by `strstr`.  

We need to find a way to spoof the name.  
We create a symbolic link in `/tmp`: `ln -s  /home/user/level08/token /tmp/spoof` (be careful to use an absolute path).  
Launcing `./level08 /tmp/spoof` gives a token we use to connect to user `flag08`.
