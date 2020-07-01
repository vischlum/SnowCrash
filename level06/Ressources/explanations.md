We find two files in `/home/user/leve06`: a binary and a php script.  The binary executes the php script. We cannot change anything.  
The php file accepts arguments on `argv`. The binary runs as `flag06`. We must exploit it to run `getflag`.  

`level06.php` uses [`preg_replace`](https://www.php.net/manual/en/function.preg-replace.php) on the content of the file situated on `argv[1]`, with the [`e flag`](https://www.php.net/manual/en/reference.pcre.pattern.modifiers.php) (meaning that the string will be evaluated, after normal substitution of backreferences in the replacement string). 
```PHP
$a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);
```

We craft a payload that will be selected by the regex and then evaluated by the `y` function: ``[x ${`getflag`}]``.  
We put it in a file in `/tmp` and call the binary with it as an argument. The flag is in the php error.
