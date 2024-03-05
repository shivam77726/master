#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

MODULE_AUTHOR("SHIVAM");
MODULE_DESCRIPTION("Hello Kernel");
MODULE_LICENSE("Dual MIT/GPL");
MODULE_VERSION("0.1");



static int __init helloworld_lkm_init(void)
{
	printk(KERN_INFO"Hello Kernel");
}

static void __exit helloworld_lkm_exit(void)
{
	printk(KERN_INFO"Bye Kernel");
}

module_init(helloworld_lkm_init);
module_exit(helloworld_lkm_exit);
