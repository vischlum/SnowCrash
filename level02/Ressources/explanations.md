We find a file called level02.pcap

pcap file are usually recording of network transmission so we open it with wireshark.

We follow the TCP stream (right clik > follow > TCP stream)

we find a password : Password: ft_wandr...NDRel.L0L

we use the the hexdump data display to find the value of the periods, it's 7f, wichh in ASCII is 'delete'

then the password would be ft_waNDReL0L

we use it for :

su flag02

we are connected to flag02 so we can launch getflag