# R65 ISO Firmware

* This ISO Keymap was made by: [NieblaDev](https://github.com/NieblaDev)
* Based on the work of: [sdk66](https://github.com/sdk66), [irfanjmdn](https://github.com/irfanjmdn), [iamdanielv](https://github.com/iamdanielv)
* Hardware Supported: R65 (AKA RK839)
* Hardware Availability: [rk](http://www.rkgaming.com)

# How to compile this firmware

QMK MYSYS Console:

    qmk compile -kb rk/r65 -km iso
Then you flash using QMK Toolbox.

To reset the board into bootloader mode, do one of the following:

* Hold the Reset switch mounted on the bottom side of the PCB while connecting the USB cable
* Hold the Escape key while connecting the USB cable (also erases persistent settings)
* Fn+R_Shift+Esc will reset the board to bootloader mode if you have flashed the default QMK keymap

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

