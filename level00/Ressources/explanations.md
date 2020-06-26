We connect to the VM with `ssh level00@192.168.56.4 -p 4242` (password = `level00`), and notice that it's almost impossible to do anything.

We look for a file that our user or flag00 can manipulate: `find / -user flag00 2>/dev/null`  
This gives us `/user/sbin/john`
```
$> cat /user/sbin/john
cdiiddwpgswtgt
```

It's not possible to `su flag00` with this. But the presentation video for the project mentioned [dcode.fr](https://www.dcode.fr/chiffre-cesar). Using a [Caesar cipher](https://en.wikipedia.org/wiki/Caesar_cipher) with a shift of 15, we get `nottoohardhere`.  
It's the password for the user `flag00`, and with it we get the token `x24ti5gi3x0ol2eh4esiuxias`.
