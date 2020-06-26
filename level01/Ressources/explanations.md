We find that `/etc/passwd` contains something for `flag01`: `flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash`  
We know that the second field (`42hDRfypTqqnw`) is the hashed password for `flag01`.

We will use [John the Ripper](https://tools.kali.org/password-attacks/john) to crack the password on a second Virtual Machine. We start by creating a file called `hashes.txt` containing `flag01:42hDRfypTqqnw`. Then we launch `sudo john hashes.txt` and get the following output:
```
Proceeding with wordlist:/usr/share/john/password.lst, rules:Wordlist
abcdefg          (flag01)
```

The password for `flag01` is `abcdefg`, and with it we get the token `f2av5il02puano7naaf6adaaf`.