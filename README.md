# CRC32

🔧 Project: USB Serial Data Transmission for STM32G0B1
This project implements a USB CDC (Communications Device Class) interface on an STM32G0B1 microcontroller, designed for transmitting data between the microcontroller and a host PC via virtual COM port (USB). It is built upon STM32CubeMX-generated code and uses the STM32 USB Device Library.

Note:
If you intend to reuse this project or integrate it into your own application, you must modify the function CDC_Transmit_FS() located in USB_Device/App/usbd_cdc_if.c.
This function handles the actual transmission of data over USB, and should be adapted to your application's data format, timing, or buffering logic.
