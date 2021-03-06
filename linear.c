#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohamed Eliskandrani");
MODULE_DESCRIPTION("Linear");
MODULE_VERSION("1");


int listing_tasks_init(void)
{
	struct task_struct *task;

	for_each_process(task) {
		printk(KERN_INFO "[pid: %d] pname: %s [state: %ld]\n", task->pid, task->comm, task->state);
	}
	return 0;
}

void listing_tasks_exit(void)
{
	printk(KERN_INFO "Removing module\n");
}

module_init(listing_tasks_init);
module_exit(listing_tasks_exit);

