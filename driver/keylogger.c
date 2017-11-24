#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <asm/io.h>

/*
   This function services keyboard interrupts.
 */
irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs) {
	static unsigned char scancode;

	/*
	   Read keyboard status
	 */
	scancode = inb(0x60);

	if ((scancode == 0x01) || (scancode == 0x81)) {
		printk ("\nYou pressed Esc !\n");
	}

	return (irq_handler_t) IRQ_HANDLED;
}

/*
   Initialize the module − register the IRQ handler
 */
int init_module() {
	/*
	   Request IRQ 1, the keyboard IRQ, to go to our irq_handler IRQF_SHARED means we're willing to have other handlers on this IRQ.
	 */
	printk(KERN_ALERT "Hello, world\n");
	return request_irq (1, (irq_handler_t) irq_handler, IRQF_SHARED, "test_keyboard_irq_handler", (void *)(irq_handler));
}

MODULE_LICENSE("Dual BSD/GPL");
