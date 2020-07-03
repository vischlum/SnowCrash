In `/home/user/level09` we see a binary and a file called `token`.  
When testing the binary, we notice that it requires an argument. Using `aaaa` as argument, it outputs `abcd`: the binary adds the value of the index to each character.  
`cat token` gives us jibberish. We try to use the binary on it, but we still get jibberish.  
We write a programm ([`turner.c`](turner.c)) that does the opposite (substracts the value of the index).  
We get a flag to connect to `flag09`.
