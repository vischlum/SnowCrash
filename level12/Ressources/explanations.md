In `/home/user/level12` we find a a perl script ([`level12.pl`](level12.pl)):
- It accepts a GET request on port 4646 with two params (`x` and `y`).
- Two regex are applied to `x`:
	- transform every lowercase into uppercase
	- delete everything after the first space character. In Perl regex, `s` is the [substitution operator](https://perldoc.perl.org/5.14.2//functions/s.html), but no replacement string is defined.
- Like in `flag04`, the backquotes (\`) mean the string `egrep "^$xx" /tmp/xd 2>&1` will be interpreted as a system command (and the expression will return the result of this command)

We must find a way to inject our own `getflag` command while avoiding the regex.  
Because of the space removal, we will make the `egrep` command execute a script:
- We put our script in `/tmp/EXPLOIT` (in all caps, because Linux is case sensitive).
- `chmod 777 /tmp/EXPLOIT` to make sure that every user can launch it.
- We open a browser to make our request: ``<IP>:4646/?x=`/*/EXPLOIT` ``(we use \` to make it executable and `*` to avoid the regex uppercasing everything)
- We get the flag with `cat /tmp/flag`