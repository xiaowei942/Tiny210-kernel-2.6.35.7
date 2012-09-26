#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>

#define DEVICE_NAME "/dev/pwm"

#define PWM_IOCTL_SET_FREQ		1
#define PWM_IOCTL_STOP			0


int main(int argc,char **argv)
{
	int err = -1;
	int fd = -1;
	int freq = 0;
	int tmp;
	int cmd = 0;
	char buf[32];

	fd = open(DEVICE_NAME,O_RDWR);
	if(fd == -1)
	{
		printf("Failed to open %s.\n",DEVICE_NAME);
		return -1;
	}

	printf("Open device: %s success.\n",DEVICE_NAME);

	while(1) {
		printf("Please input freq:");
		gets(buf);
		tmp = atoi(buf);	
		switch (tmp)
		{
			case 1:
				freq = 1000;
				cmd = PWM_IOCTL_SET_FREQ;
				err = ioctl(fd,cmd,&freq);		
				break;
			case 0:
				cmd = PWM_IOCTL_STOP;
				err = ioctl(fd,cmd,&freq);		
				break;
			case 2:
				cmd = PWM_IOCTL_STOP;
				err = ioctl(fd,cmd,&freq);		
				return -1;
			default:
				freq = tmp;
				err = ioctl(fd,cmd,&freq);		
				break;
		}
	}
	return 0;
}

