#include <linux/delay.h>
#include <linux/err.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

int wlan_power_ctrl(unsigned char isPowerON)
{
	printk("WEI: wlan_power_ctrl\n");
	return 0;
}

EXPORT_SYMBLE(wlan_power_ctrl);
