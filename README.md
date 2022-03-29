# Energy Efficient Soc through acceleration for IoT applications
## Project Description:
In this project we are trying to design an SoC which can deploy a machine learning and do data encryption on the edge while meeting the constraints of the real time applications and without increasing the power usage. 
To do this, we needed to explore three parts:
### 1) Machine Learning Acceleration:
In this part, we were aiming to accelerate the machine leaning models thatr deployed on  embeded systems for IOT devices. We first started with profiling KWS model to  find that convolution took 95.95% of the total time. Therefore, we worked on designing an ML accelerator to speedup MAC operations wich is the main unit of convolution function. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator)
### 2) Security Acceleration:
In this part, we work on accelerating the Montgomery Reduction function used in the SSL protocol. More details could be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/Security%20Accelerator)
### 3) Accelerators integration with SoC:
After finalizing the design of the accelerators, we integrated them with the Chameleon SoC (an open source ibex based SoC) to test the system effeciency. More details could be found [here](https://github.com/NouranAbdelaziz/ML_and_Sec_Accelerated_Chameleon_SoC)
