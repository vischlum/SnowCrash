# SnowCrash
*First security-oriented projet of the 42 cursus.*

This projects consists of an iso to create a Linux virtual machine containing 14 levels corresponding to a different challenges.  
The solutions in this repository were found by [Xavier-Emmanuel Moreau](https://github.com/xemxav) and [Vincent Schlumberger](https://github.com/vischlum).

We first connect using the couple ```level00:level00```. To go on the next level, the user flagXX (XX corresponding to the level we are on) need to execute the command ```getflag``` that will give us a password for the following level. The goal is to find a way to connect to this account or to have a program with this user credential to launch ```getflag``` for us.

#### This README presents the key take away of each different level:
- **level00:** mastering the 'find' command and caesar code
- **level01:** using [John the Ripper](https://tools.kali.org/password-attacks/john) to crack `/etc/password`
- **level02:** decoding a .pcap file with [Wireshark](https://www.wireshark.org/)
- **level03:** taking advantage of a SUID program calling a system command and redirecting it call to our own binary by spoofing the `PATH`
- **level04:** exploiting a perl script by crafting a GET request
- **level05:** using a cronjob to launch our exploit
- **level06:** exploiting the php vulnerability of `preg_replace()` in php with the `e` options because it will execute our payload
- **level07:** exploiting the `getenv()` (or equivalent function) by changing an environment variable as payload
- **level08:** using a symbolic link to spoof a filename
- **level09:** decoding a message by substracting to its ASCII value the value of its index in the message
- **level10:** setting up a race condition to exploit the `access()` function
- **level11:** exploiting the `io.popen()` function in a lua script, giving a command instead of a password
- **level12:** exploiting regex in a perl script
- **level13:** using gdb to trick a binary by changing the return value of a function during execution
- **level14:** using gdb to exploit the `getflag` command changing the return calue of the `getuid()` function