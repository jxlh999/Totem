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

/* Globals */
static int uinp_fd = -1;
struct uinput_user_dev uinp; // uInput device structure
struct input_event event; // Input device structure

/* Setup the uinput device */
int setup_uinput_device()
{
    // Temporary variable
    int i=0;
    // Open the input device
    uinp_fd = open("/dev/uinput", O_WRONLY | O_NDELAY);
    if (uinp_fd == -1)
    {
	printf("Unable to open /dev/uinput\n");
	return -1;
    }
    memset(&uinp,0,sizeof(uinp)); // Intialize the uInput device to NULL
    strncpy(uinp.name, "my uinput device", UINPUT_MAX_NAME_SIZE);
    uinp.id.version = 4;
    uinp.id.bustype = BUS_USB;
    
    // Setup the uinput device
    ioctl(uinp_fd, UI_SET_EVBIT, EV_KEY);
    ioctl(uinp_fd, UI_SET_EVBIT, EV_REL);
    ioctl(uinp_fd, UI_SET_RELBIT, REL_X);
    ioctl(uinp_fd, UI_SET_RELBIT, REL_Y);
    for (i=0; i < 256; i++) {
        ioctl(uinp_fd, UI_SET_KEYBIT, i);
    }
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MOUSE);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_TOUCH);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MOUSE);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_LEFT);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_MIDDLE);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_RIGHT);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_FORWARD);
    ioctl(uinp_fd, UI_SET_KEYBIT, BTN_BACK);
    /* Create input device into input sub-system */
    write(uinp_fd, &uinp, sizeof(uinp));
    if (ioctl(uinp_fd, UI_DEV_CREATE))
    {
        printf("Unable to create UINPUT device.\n");
	return -1;
    }
    return 1;
}

void send_click_events()
{
    // Move pointer to (0,0) location
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_REL;
    event.code = REL_X;
    event.value = 100;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_REL;
    event.code = REL_Y;
    event.value = 100;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
    // Report BUTTON CLICK - PRESS event
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_KEY;
    event.code = BTN_LEFT;
    event.value = 1;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
    // Report BUTTON CLICK - RELEASE event
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_KEY;
    event.code = BTN_LEFT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
}

void send_button()
{
    // printf("sending keycode: %s \n", k);
    // Report BUTTON CLICK - PRESS event
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_KEY;
    event.code = KEY_M;
    event.value = 1;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
    // Report BUTTON CLICK - RELEASE event
    memset(&event, 0, sizeof(event));
    gettimeofday(&event.time, NULL);
    event.type = EV_KEY;
    event.code = KEY_M;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
    event.type = EV_SYN;
    event.code = SYN_REPORT;
    event.value = 0;
    write(uinp_fd, &event, sizeof(event));
}

/* This function will open the uInput device. Please make
sure that you have inserted the uinput.ko into kernel. */
int main() {

    // Return an error if device not found.
    if (setup_uinput_device() < 0)
    {
        printf("Unable to find uinput device\n");
        return -1;
    }

    //uinput actions here ...
    int i = 0;
    for (; i < 10; ++i)
    {
        send_button();
	sleep(1);
    }
    //send_click_events(); // Send mouse event
    
    /* Destroy the input device */
    ioctl(uinp_fd, UI_DEV_DESTROY);
    
    /* Close the UINPUT device */
    close(uinp_fd);
}
