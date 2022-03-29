Details and code can be found in [this](https://github.com/NouranAbdelaziz/ML_and_Sec_Accelerated_Chameleon_SoC) repository
# Chameleon SoC (IBEX)
AHB-Lite based SoC for IBEX

## The Memory Map
<img src="./docs/soc_mem_map.png" size="50%">

## Peripherals
|Peripheral|Bus|Base Address|IRQ #|MPRJ I/O Pins|
|----------|---|------------|--------|-----|
|GPIO (14)|AHB|0x48000000|N/A|0-13|
|UART0|APB|0x40000000|16|20-21|
|UART1|APB|0x40100000|17|22-23|
|SPI0|APB|0x40200000|18|24-27|
|SPI1|APB|0x40300000|19|28-31|
|I2C0|APB|0x40400000|20|32-33|
|I2C1|APB|0x40500000|21|34-35|
|PWM0|APB|0x40600000|n/a|26|
|PWM1|APB|0x40700000|n/a|37|
|TMR0|APB|0x40800000|22|n/a|
|TMR1|APB|0x40900000|23|n/a|
|TMR2|APB|0x40A00000|24|n/a|
|TMR3|APB|0x40B00000|25|n/a|
|WDT0|APB|0x40C00000|26|n/a|
|WDT1|APB|0x40D00000|27|n/a|

## Modified Architecture
Two new accelerators is added to the SoC by connecting them to the AHB bus with a slave interface
![SoC drawio](https://user-images.githubusercontent.com/79912650/145666467-7f18b01b-ce7d-4491-b060-a33ef2cf1e9f.png)

## Accelerators connections explained 
### SoC hierarchy:
The Top level file of the verilog code hierarchy is soc_core.v which instantiates the ibex core which is the master of our system and the RAM (of size 3K x 32) along with the AHB bus system which connects both the peripherals (APB slaves) and the rest of the slaves connected on AHB bus.
![top drawio](https://user-images.githubusercontent.com/79912650/145666485-3dee383a-3ef0-4b38-a802-3c9a9b0a24d8.png)

### AHB Bus system:
The AHB bus system passes all the signals of the master (ibex core) to the five slaves and to the bus. The AHB bus selects which slave will use the bus now through checking on the base address of the HADDR signal and accordingly set the HREADY signal and HRDATA that will be sent back to the master and set the HSEL signals for ech slave which will be only 1 for the acting slave and 0 for the rest. 
![AHB drawio (1)](https://user-images.githubusercontent.com/79912650/145666491-8df523b5-0353-491c-817a-9ccfe970926a.png)

## Accelerators connections testing 
<img src="./docs/4.png" size="80%">

### FPGA Validation 

To validate our design, we integrated a read-only memory on which we load the program (hex file) on the SoC. 
![FW_diagram](https://user-images.githubusercontent.com/79912650/160588662-c92d0673-0491-405b-82da-f313a8a0a43b.png)



### Flash Writer and UART master integration 

The read-only memory is not very practical because once the program loaded, we can not reload another program. That is why we integrated UART master which will program Flash writer slave on the AHB bus and the Flash writer will communicate with the flash in order tp program it. Once the flash is programmed, the ibex core will be the master on the bus and will fetch instructions from the flash using the QSPI flash controller. 

![ROM_diagram](https://user-images.githubusercontent.com/79912650/160588689-e4018247-41f2-4fd4-9821-c43cf246ad9b.png)
