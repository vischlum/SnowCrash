In `home/user/level13` we find an executable that asks to be run with a `uid` 4242 (the error message is `UID 2013 started us but we we expect 4242`).  
Using `nm` we find that it uses `getuid`.  

To investigate further, we use `gdb`:
- Launch gdb with the binary (`gdb level13`)
- Define a breakpoint on the main function (`break main`) then run the binary (`r`)
- We look up the memory state with `x/201 main` and notice a `cmp` comparison instruction: `0x804859a <main+14>:	cmp    $0x1092,%eax`
- Let's define a new breakpoint (`break *main+14`, because this is where the comparison happens) and continue the execution of the binary (`c`)
- Right after the call to `getuid`, we see that the comparison takes place between `0x1092` (4242 in hexadecimal) and the register `eax`. `print $eax` allows us to check that it contains the value `2013`
- We will change the content of this register with `set $eax = 4242`, and continue the execution (`c`)

All of this gets us a token, that we can use to log on as `level14`.