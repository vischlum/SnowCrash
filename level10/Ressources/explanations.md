We find an executable and a token that we cannot open. The usage of the program tells us it sends a file to a host if we have access to it.  
Launching the binary, we see it tries to connect to `127.0.0.1:6969`.

We check the program with `nm`, and working from the hint in the usage we look how to exploit the [`access`](https://linux.die.net/man/2/access) function.  
We see that there is a delay between the call to `access` (to check if the binary has the necessary rights to read the sent file) and the call to [`open`](https://linux.die.net/man/3/open) (to actually read the file). This means we should be able to engineer a race condition, more precisely a [TOCTOU](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use) (*Time-of-check-to-time-of-use*).

We aim to create a file that we have access to. It will be accepted by the program but before it is sent, we change it to a symbolic link to the token.  
To do this, we create two scripts: [`linking.sh`](linking.sh) and [`running.sh`](running.sh).  

Using `netcat`, we listen on port 6969 and send a file: `nc -lk 6969 > listener`   (-l localhost , k keep listening).  
We find the token to `su flag10` with `cat listener.`
