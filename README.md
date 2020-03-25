# stm32f3_disco_tflite_magic_wand
This is a port of the tensorflow lite microcontrollers magic wand example for the STM32F3-discovery.
https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro/examples/magic_wand

I used STM32CubeMX: https://www.st.com/en/development-tools/stm32cubemx.html to generate the code imported the project to STM32CubeIDE. Since the accelerometer code for the STM32F3-discovery is not included for STM32CubeMX I had to add that manually.  

The initial code didn't work so well so I have re-trained the network with new data that I captured while performing the gestures on the F3-disco.

To run, I hold the device with the "ST-Link" USB cable in my right hand. When I want to perform a gesture I click the blue user button. While the gesture is cast, leds are blinking. When the leds stop blinking the capture buffer is filled and the inference is run. If an Wing gesture was captured blue led are lit, if a Ring gesture was captured green leds are lit, if a Slope gesture was captured orange led are lit, otherwise red leds are lit.

For more details I wrote a blog post for this project:

https://martaafry.github.io/2020/03/25/Magic.html



