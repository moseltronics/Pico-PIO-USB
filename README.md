# Pico-PIO-USB
--- modified version ---

First of all thanks to sekigon-gonnoc and Ha Thach for their great work on this library.
The original description is below.

What i tried to change was:
- RX only running on one state machine instead of 2
- having only one TX program instead of 4

How it could be achieved:
- fequency for RX was increased to 120 MHz (was 96)
- synchronizing was reduced
- inverting output and changing jump adrresses for TX in dependence of the requirements
- surrounding files had to be adapted

Experiences:
- couldn't find any disadvantages
- worked with 4 root ports (and one regular device port) as a midi interface
- a simple device example did work, too
- swapping data pins did work

How to try it out:
- if Pico-Pio-Usb is installed, just overwrite the existing files in tinyusb/hw/mcu/raspberry_pi/Pico-PIO-USB/src
- or copy everything into a subdirectory of your project with adding the following to the projects CMakeLists.txt:
- (for example:)
-     add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib/Pico-PIO-USB)
- (and later on)
-     add "pico-pio-usb" to "target_link_libraries(${target_proj}"

--- original description ---

USB host/device implementation using PIO of raspberry pi pico (RP2040).

You can add additional USB port to RP2040.

## Demo

https://user-images.githubusercontent.com/43873124/146642806-bdf34af6-4342-4a95-bfca-229cdc4bdca2.mp4

## Project status

|Planned Features|Status|
|-|-|
|FS Host|✔|
|LS Host|✔|
|Hub support|✔|
|Multi port|✔|
|FS Device|✔|

## Examples

- [capture_hid_report.c](examples/capture_hid_report/capture_hid_report.c) is a USB host sample program which print HID reports received from device. Open serial port and connect devices to pico. Default D+/D- is gp0/gp1. Call `pio_usb_add_port()` to use additional ports.
- [usb_device.c](examples/usb_device/usb_device.c) is a HID USB FS device sample which moves mouse cursor every 0.5s. External 1.5kohm pull-up register is necessary to D+ pin (Default is gp0).
- [host_hid_to_device_cdc.c](examples/host_hid_to_device_cdc/host_hid_to_device_cdc.c) is similar to **capture_hid_report.c** which print mouse/keyboard report from host port to device port's cdc. TinyUSB is used to manage both device (native usb) and host (pio usb) stack.

```bash
cd examples
mkdir build
cd build
cmake ..
make
# Copy UF2 file in capture_hid_report/ or usbdevice/ to RPiPico
```

Another sample program for split keyboard with QMK

[https://github.com/sekigon-gonnoc/qmk_firmware/tree/rp2040/keyboards/pico_pico_usb](https://github.com/sekigon-gonnoc/qmk_firmware/tree/rp2040/keyboards/pico_pico_usb)

## Resource Usage

- Two PIO
  - One PIO is for USB transmitter using 22 instruction and one state machine
  - Another PIO is for USB receiver using 31 instruction and two state machine
- Two GPIO for D+/D- (Series 22ohm resitors are better)
- 15KB ROM and RAM
- (For Host) One 1ms repeating timer
- (For Device) One PIO IRQ for receiver
