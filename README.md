# TermoRecorder
The arduino records measurements from the thermocouples. It can run 4 measurements simultaneously. The measurements are saved into SD card in a '.CSV' file. A desktop software based on python creates an ETL pipeline to generate a dashboard to analyzes



<img src="https://i.postimg.cc/4xnSqn5J/termo2.jpg" alt="TermoProject" width="500"/>

## COMPONENTS :gear: 

- 1x Arduino Mega 2560
- 1x SD card module 
- 1x Display LCD 16x2
- 1x Potentiometer 10kOhms
- 4x 300Ω Resistors 
- 4x Module Max6675 K
- 4x Push Buttons

## PINOUT
*UNDER CONSTRUTION*

## SETUP
*UNDER CONSTRUTION*


## HOW IT WORKS :chart_with_upwards_trend:

Every time that you click on push button the arduino starts to record a measurement. It can run 4 measurement simultaneously. The measurements are save into SD card in a `'.CSV'` file ([example file](https://raw.githubusercontent.com/LincolnG4/TermoRecorder/master/examples/DADOS3.CSV) or see more on `example` folder)  

## RUNNING DESKTOP SOFTWARE :computer:

### PREREQUISITES 
*UNDER CONSTRUTION* 

The desktop app is compose by 2 mainly codes:  

### 1. `create_measure.py` 

Drag all the `'.CSV'` generated by the arduino to the `create_measure.py` file.  
The `create_measure.py` will create a `'xlms'` file from the `'.CSV'` erasing all the NAN values and it creates a tab to each measurement.  
All blank rows in the `'xlms'` measurement file will be fill by interpolation during `plotter.py` running.

### 2. `plotter.py`

Drag all the `'xlms'` generated by step above. The command prompt will show up then write a name to your dashboard. 

<img src="https://i.postimg.cc/wTnYHSB8/Capturar.png" alt="TermoProject" width="1000"/>




