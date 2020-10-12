#include <stdlib.h>
#include <stdio.h>
#include <libusb-1.0/libusb.h>
#include <usb.h>

int cmd();
struct libusb_device_handle *device_handle;

int main() {
    libusb_init(NULL);
    device_handle = libusb_open_device_with_vid_pid(NULL, 0x05AC, 0x1281);
    if (libusb_control_transfer(device_handle, 0x40, 0, 0, 0, "reboot", (strlen("reboot") + 1), 1000)) {
        printf("[*] Successfully sent command.\r\n");
        return 0;
    } else {
        printf("[*] Error with sending the Command");
        return 0;
    }
    return 1;
}
