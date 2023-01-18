# DJuke

![DJuke](https://i.imgur.com/GCfQ7mGh.jpeg)

A custom controller for the music game DJMax. Successor of [DJam](https://github.com/qmk/qmk_firmware/tree/master/keyboards/deng/djam) that adopts [optical switches](https://www.keychron.com/products/low-profile-keychron-optical-switch-set-87-pcs).

* Keyboard Maintainer: [Leo Deng](https://github.com/myst729)
* Hardware Supported: DJuke controller with STM32F401
* Hardware Availability: Private Groupbuy

Make example for this keyboard (after setting up your build environment):

    make deng/djuke:default

Flashing example for this keyboard:

    make deng/djuke:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the top left 2U key (0,0 in the matrix) and plug in the keyboard
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
