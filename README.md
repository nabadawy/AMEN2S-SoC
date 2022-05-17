# MEN2AS-SoC
## Project Description:
  The main Target of the product is contributing to the hardware development flow for the IoT devices. The product is an open source single core System on chip, based on the open source Chameleon SoC with 32-bit RISC-V (Ibex core) augmented with specialized blocks for compute-intensive data processing and encryption functions, supporting software codesign through [NNOM](https://github.com/majianjia/nnom) and [wolfSSL](https://github.com/wolfssl) libraries. 

## features:
  * Clock Frequency : 33 MHz for 130 NM technology
  * Gates number : 64177
  * Machine Learning Accelerator
  * Security Accelerator

## Dependencies:
* Our product depends on the RISC-V GNU Compiler Toolchain to compile the C code into a Hex file which can then be executed with the SoC. 
* There is no special dependency for NNOM since it uses local pure C backend implementation. It only needs to enable  libc ,malloc(), free(), and memset().Otherwise, you can use the equivalent memory method in your system
* The RSA & SHA-3 will depend on the wolfSSL library that has a lightweight implementation of SSL suitable for embedded devices.

## Assumptions:
### Machine learning models are built on Keras and supported by NNOM
There is an assumption that Machine Learning models are trained using Keras and compatible with NNOM library to be converted to c models and deployed on the soc
### Security Protocols assumptions 
The implementation of the RSA and SHA-3 accelerators assumes the use of SSL protocol and the wolfSSL library specifically. 
### assume single core 
There is an assumption that the applications which will run on the SoC will not require using more than one core to meet their required deadlines and a single core will be sufficient to do so. 
### low weigh application 
Just like any edge device, due to the memory constraints and the requirement of low power consumptions, the application which will run on top of the SoC must not be a heavy weight one. 

## Architecture:
The final SoC Architecture is showing the integration between the [Chameleon SoC](https://github.com/shalan/Chameleon_SoC) and our extra hardware components (ML (Convolution Accelerator) Unit, Data Security Unit and the two activation functions (Tanh and Sigmoid)

(https://github.com/nabadawy/MEN2AS-SoC/blob/main/Architecture/ThesisI-Page-1.drawio.png)



## Accelerators:
###  Machine Learning Accelerator:
In this part, we were aiming to accelerate the machine leaning models thatr deployed on  embeded systems for IOT devices. We first started with profiling KWS model on [NNOM](https://github.com/majianjia/nnom/tree/master/examples/keyword_spotting) paltform to  find that `local_convlove` function took 95.95% of the total execution time. Therefore, we worked on designing an ML accelerator to speedup MAC operations wich is the main unit of convolution function. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator)

We also migrated the lookup tables of Activation functions Tanh and sigmoid from software to hardware in order to reduce on-chip memory.
More details could be found [here](https://github.com/ashrakatkh/Activation-Lookup-Tables)

### Security Accelerator:
In this part, we work on accelerating the Montgomery Reduction function used in the SSL protocol. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/Security%20Accelerator)

## Accelerators integration with SoC:
After finalizing the design of the accelerators, we integrated them with the Chameleon SoC (an open source ibex based SoC) to test the system effeciency. More details could be found [here](https://github.com/NouranAbdelaziz/ML_and_Sec_Accelerated_Chameleon_SoC)

## Hardening SoC
We then moved to harden our design using [OpenLane] and we were able to have gds of our design. 
More details could be found [here]

