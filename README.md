# MEN2AS-SoC
## Project Description:
  The main Target of the product is contributing to the hardware development flow for the IoT devices. The product is an open source single core System on chip, based on the open source Chameleon SoC with 32-bit RISC-V (Ibex core) augmented with specialized blocks for compute-intensive data processing and encryption functions, supporting software codesign through [NNOM](https://github.com/majianjia/nnom) and [wolfSSL](https://github.com/wolfssl) libraries. 

## features:
  * Clock Frequency : 33 MHz for 130 NM technology
  * Gates number : 64177
  * Machine Learning Accelerator
  * Security Accelerator

## Dependencies:


## Architecture:




## Accelerators:
###  Machine Learning Accelerator:
In this part, we were aiming to accelerate the machine leaning models thatr deployed on  embeded systems for IOT devices. We first started with profiling KWS model to  find that local_convlove function took 95.95% of the total time. Therefore, we worked on designing an ML accelerator to speedup MAC operations wich is the main unit of convolution function. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator)

We also migrated the lookup tables of Activation functions Tanh and sigmoid from software to hardware in order to reduce on-chip memory.
More details could be found [here]
### Security Accelerator:
In this part, we work on accelerating the Montgomery Reduction function used in the SSL protocol. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/Security%20Accelerator)

## Accelerators integration with SoC:
After finalizing the design of the accelerators, we integrated them with the Chameleon SoC (an open source ibex based SoC) to test the system effeciency. More details could be found [here](https://github.com/NouranAbdelaziz/ML_and_Sec_Accelerated_Chameleon_SoC)

## Hardening SoC
We then moved to harden our design using [OpenLane] and we were able to have gds of our design. 
More details could be found [here]

