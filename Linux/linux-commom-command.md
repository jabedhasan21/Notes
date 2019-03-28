### [Bash Guide](https://github.com/Idnan/bash-guide)

### See which ports are open
netstat -ntlp | grep LISTEN

### kill a process on a port on ubuntu
sudo kill \`sudo lsof -t -i:9001\`

or

`sudo kill $(sudo lsof -t -i:9001)`

### To see the no. of CPU’s
lscpu

### Nginx Log
tail -f /var/log/nginx/* /var/log/php*

### OS Info
+ hostnamectl
+ cat /etc/centos-release
+ cat /etc/redhat-release

### Kernel Versions
`uname -a`

## xvda1 is 100% full, What is it? how to fix?

+ To check all volume: `df -h`

+ To check specific directory: `du -h`

+ To see the full size of all folders and identify the bigger ones: `sudo su - cd /; du -hs *`

+  To find all files greater than 10 MB (10 MB is a big enough file size, you can choose +1M for 1MB similarly): `sudo find / -type f -size +10M -exec ls -lh {} \;`

# Unix
+ Show service file path: `systemctl show cron.service | grep Path`
+ Specific users can also create cron jobs. User-specific cron jobs are located in `/var/spool/cron/username`.
+ [ubuntu-crontab](https://www.rosehosting.com/blog/ubuntu-crontab/)

# Networking
+ Get IPS IP: `curl ifconfig.pro`

### linux-commands
![1](linux-commands.png)
