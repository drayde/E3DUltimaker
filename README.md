# Firmware for Ultimaker 2 with E3D v6 Hotend and Titan Extruder

This firmware is for a Ultimaker 2 with the E3D Upgrade Kit installed, which includes a E3D v6 hotend and a Titan extruder.

The firmware is a fork of the original Ultimaker firmware:
https://github.com/Ultimaker/Ultimaker2Marlin

The original README ist included as README_orig in this repro.

Changes have been made to the source code by E3D to work with the changed setup.
The orginal E3D fork is no longer online, but should match the *e3d-latest* branch in this repro.

## Links

Old wiki page on e3d-online.com: https://wiki.e3d-online.com/E3D-v6_on_Ultimaker_2
([local copy as pdf](https://github.com/drayde/E3DUltimaker/blob/drayde/E3D-v6%20on%20Ultimaker%202%20-%20E3D-Online.pdf))

Conversion video guide by Thomas Sanladerer: https://youtu.be/aLLci32tHA4

3D printed parts on thingiverse: https://www.thingiverse.com/thing:1934309

## Firmware changes by E3D

Firmware changes as documented on https://wiki.e3d-online.com/E3D-v6_on_Ultimaker_2

Changes in the "configuration.h" file:

    // increase the maximum temperature for the E3D V6 HotEnd
    #define HEATER_0_MAXTEMP 400


    // PID values for Ultimaker2 with E3D HotEnd
    #define  DEFAULT_Kp 36.59
    #define  DEFAULT_Ki 3.65
    #define  DEFAULT_Kd 91.72


    // travel extents have reduced slightly for E3D HotEnd
    #define X_MAX_POS 215 // For E3D HotEnd
    #define Y_MAX_POS 210 // For E3D HotEnd
    #define INVERT_E0_DIR true   // for direct drive extruder v9 set to true, for geared extruder set to false


    // default steps per unit for Ultimaker2 and E3D Extruder
    #define DEFAULT_AXIS_STEPS_PER_UNIT   {80.0,80.0,200,837}   // 837 to be changed to 418.5 for if a 200 steps/mm motor is used
    #define DEFAULT_MAX_FEEDRATE          {300, 300, 40, 20}    // (mm/sec)
    #define DEFAULT_MAX_ACCELERATION      {9000,9000,100,3000}  // X, Y, Z, E maximum start speed for accelerated moves. 
                                                                // E default values are good for skeinforge 40+, for older 
                                                                // versions raise them a lot.

The Bowden retraction settings should be changed if the filament change function is to work properly after the upgrade. These settings are found in the "UltiLCD2_menu_material.h" file. Here are the variables that need to be changed and their new value:

    #define FILAMENT_REVERSAL_LENGTH      (FILAMANT_BOWDEN_LENGTH + 150)
    #define FILAMENT_REVERSAL_SPEED       75
    #define FILAMENT_INSERT_FAST_SPEED    75   // Speed during the forward length

**Note:** These changes were done on an old version of the Ultimaker 2 firmware (from 29th January 2016).

The later Ultimaker 2 firmware (after v14.09) has a temperature safety feature built in, which has been notoriously sensitive. It seems like it is overly sensitive and an E3D HotEnd doesn't conform to its expected heat up and cool down cycles. The result is a common "ERROR - STOPPED Heater error" on the display panel and a failed print. The part cooling fans can often trigger this error as the air blown to cool the print can also end up cooling the heater block due to certain print geometry. Although the silicone sock provided in the kit should reduce this, it is still a recurring issue.

If you repeatedly encounter this issue, check the position of your part cooling fan ducts. They should be as low as possible without touching the bed when the nozzle does. Also, adding a siliconw sock can greatly reduce this error. Otherwise, the following lines in the "configuration.h" file control the parameters of this "safety feature".

    #define MAX_HEATING_TEMPERATURE_INCREASE 0.1 //[E3D] original value 10
    #define MAX_HEATING_CHECK_MILLIS (90000) //[E3D] original value(30 * 1000)

If you want to disable this feature like it was back in v14.09 then you can comment out the following lines in the "temperature.cpp" file at your own risk:

    // Commented out for UM2 because too sensitive for E3D HotEnd           
    //            disable_heater();
    //            Stop(STOP_REASON_HEATER_ERROR);

## My firmware changes 

none yet :-)
