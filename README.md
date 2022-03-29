# Energy Efficient Soc through acceleration for IoT applications
## Project Description:
The main Target of the product is contributing to the hardware development flow for the IoT devices. The product is an open source single core System on chip, based on the open source Chameleon SoC with 32-bit RISC-V (Ibex core) augmented with specialized blocks for compute-intensive data processing and encryption functions, supporting software codesign through NNOM and wolfSSL libraries. 
To do this, we needed to explore three parts:
### 1) Machine Learning Acceleration:
In this part, we were aiming to accelerate the machine leaning models thatr deployed on  embeded systems for IOT devices. We first started with profiling KWS model to  find that convolution took 95.95% of the total time. Therefore, we worked on designing an ML accelerator to speedup MAC operations wich is the main unit of convolution function. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator)
### 2) Security Acceleration:
In this part, we work on accelerating the Montgomery Reduction function used in the SSL protocol. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/Security%20Accelerator)
### 3) Accelerators integration with SoC:
After finalizing the design of the accelerators, we integrated them with the Chameleon SoC (an open source ibex based SoC) to test the system effeciency. More details could be found [here](https://github.com/NouranAbdelaziz/ML_and_Sec_Accelerated_Chameleon_SoC)
