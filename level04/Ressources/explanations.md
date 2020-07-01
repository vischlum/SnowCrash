Once logged on as `level04`, we find a perl script in the home. It is also present in `/var/www/level04` and the `apache2` server is configured to serve it on the 4747 port.  
The script waits for a parameter with the name `x`. So we craft a `GET` request in the browser: `<IP>:4747?x=something`  
It will print `something`, we want to execute `getflag` so we put backquotes around the command: ``<IP>:4747?x=`getflag` ``  
This gets us the flag for `level05` because the script is run as `flag04`.
