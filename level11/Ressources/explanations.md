We see a lua script that creates a server on port 5151:
- It waits for the connection of a client then asks for a password.
- This string is sent to a function `hash` :
    - It uses the function [`io.popen`](https://www.lua.org/manual/5.1/manual.html#pdf-io.popen) (equivalent to `system()` in C) to launch `echo <string> | sha1sum`

With `ps -faux`, we notice a process `lua /home/user/level11/level11.lua` launched by the user `flag11`, this script is therefore already running.

Like we did for the `flag07`, we will give it the argument `;getflag > /tmp/flag` to get the script to launch `getflag` for us:
- We use `nc` to connect to the server: `nc localhost 5151`
- We give it the password: `;getflag > /tmp/flag`
- finally `cat /tmp/flag` gives us the token `fa6v5ateaw21peobuub8ipe6s`, to log on as user `level12`.