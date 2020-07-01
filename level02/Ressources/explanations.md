We find a file called `level02.pcap`; `pcap` files are usually recordings of network transmissions so we open it with [`wireshark`](https://tools.kali.org/information-gathering/wireshark).  
We follow the TCP stream (right click > follow > TCP stream). We find a password: `Password: ft_wandr...NDRel.L0L`  
We use the hexdump data display to find the value of the periods (`7f`), which is ASCII for the [delete character](https://en.wikipedia.org/wiki/Delete_character). So the password is `ft_waNDReL0L`.  
We use it to `su flag02`. Once logged as flag02, we can launch `getflag`.