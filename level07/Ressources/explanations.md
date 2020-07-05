For `level07` we find a binary (with the uid of `flag07`). When run it outputs `level07`.  
Using [`nm`](https://en.wikipedia.org/wiki/Nm_(Unix)) we can deduct it calls `getenv` and `system`. With `gdb`, we find that it creates a string with `asprintf` and then calls `system` ([`radare2`](https://radare.org/n/radare2.html) can also be used for this).  
Looking at an hexdump we can see it calls the env variable `LOGNAME` and puts in in the following formated string `"./bin/echo %s"` 

We have to put the payload in `$LOGNAME`: ``export LOGNAME=`getflag` `` gives us an error.  
We use `;` to terminate the first command call and do a second one: `export LOGNAME=';getflag'`.  
Launching `./level07` gives us the flag.
