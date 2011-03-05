#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>
#include <linux/uinput.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

void simulate_key(int fd,int kval)
{
    struct input_event event;
    event.type = EV_KEY;
    event.value = 1;
    event.code = kval;
    
    gettimeofday(&event.time,0);
    write(fd,&event,sizeof(event)) ;
    
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd, &event, sizeof(event));
    
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_KEY;
    event.code = kval;
    event.value = 0;
    write(fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd, &event, sizeof(event));
    
}

void simulate_mouse(int fd)
{
    struct input_event event;
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_REL;
    event.code = REL_X;
    event.value = 10;
    write(fd, &event, sizeof(event));
    
    event.type = EV_REL;
    event.code = REL_Y;
    event.value = 10;
    write(fd, &event, sizeof(event));
    
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(fd, &event, sizeof(event));
}

int main()
{
    int fd_kbd; 
    int fd_mouse; 
    fd_kbd = open("/dev/input/event3",O_RDWR);
    if(fd_kbd<=0){
        printf("error open keyboard:\n");
        return -1;
	
    }
    
//    fd_mouse = open("/dev/input/event5",O_RDWR); 
//    if(fd_mouse<=0){
//        printf("error open mouse\n");
//	return -2;
//    }
    
    int i = 0;
    for(i=0; i< 10; i++)
    {
        simulate_key(fd_kbd, KEY_A + i);
//        simulate_mouse(fd_mouse);
        sleep(1);
    }
    
    close(fd_kbd);
}
