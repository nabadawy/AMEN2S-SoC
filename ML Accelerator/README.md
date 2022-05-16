# One 8-bit MAC unit accelerator
The building block of our project is the MAC unit where this module takes 8-bit to multiply them and output the result. This module takes: valid bit, 8-bits A, 8-bits B and outputs 8-bits out. The importance of the valid bit is to check weather the mac unit will work or output zero incase we do not want this mack to function. We are using one unit to save area and minimise the delay. In order to do that we made divided the input which is 32-bits in every load from the memory, into 4 8-bits passed to the MAC unit. [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator/MAC_unit)

## Architecture:
![MAC unit architecture](MAC_unit/mac.png)


## Area and Speed Analysis
#gates: 742		area(um2): 6377.37			delay(ps): 3877.12

![Untitled Diagram2 drawio](https://user-images.githubusercontent.com/62911896/145671523-54b7a095-4796-4dd6-9708-4ad5f72ef02c.png)

## Power Analysis
Our aim is to increase the speed of the accelerator without increasing the power consumption. That is why we migrated the convolution function to hte hardware instead of the software to increase the speed with less power usage. The power consumption is the power of the software plus the power ot the hardware.

# Four 8-bit MAC unit accelerator

## Motivation:
In one cycle, we load 32-bits which then will be divided into 4 8-bits. Each 8-bits will be bassed to the MAC unit to be multiplied then the output of the four mac units will be accumilated to the old sum. The input of the Module is: 4-bits valid, 32-bits sum, 32-bits A, 32-bits B.
The code will be found [here](https://github.com/nabadawy/Energy-Efficient-Soc-through-acceleration-for-IoT-applications/tree/main/ML%20Accelerator/four_mac)


## Architecture :
![Four MAC units](four_mac/4mac.png)



## Area and Speed Analysis:

#gates: 2593		area(um2):23068.38		delay(ps):4859.73

<img width="453" alt="Area_speed_4" src="https://user-images.githubusercontent.com/72893623/145666760-da3464cb-7c72-4080-b6e1-323b80c391d3.png">



## Cycles Analysis:

<img width="254" alt="acceleratedconvolution" src="https://user-images.githubusercontent.com/72893623/145666993-4fea5f16-af98-4ed6-94c4-514182638be5.png">

<img width="258" alt="unaccelerated convolution" src="https://user-images.githubusercontent.com/72893623/145666994-cd952a3a-ce99-471f-9763-57491110971d.png">

<img width="257" alt="speedup" src="https://user-images.githubusercontent.com/72893623/145666998-52a9609b-7a57-4476-87f9-259fdea20e82.png">


# Paralle MAC  Accelerator

## Motivation:
  Giving area of four_MAC accelerator is very small (0.0231 mm^2) (2593 cells). We then thought of designing A parallel mac accelerator to make use of parallelism operations in convolution and reduce memory Access by reusing input data. Each filter in convolution is convolved with input data pixels to produce one feature output map. Thus our idea is to produce a four_MAC path for each filter and thus the operations will run in parallel and the input data will be reused instead of reading it again.
 
The number of filters in the popular convloution architecture such vggNet and Alexnet in all layers are multiple of 4. Thus we decided that our accelerator will be a four_path parallel accelerator.

## Design
 The accelerator is developed of four parallel four_Mac accelerator.

## Architecture :
![parallel2](https://user-images.githubusercontent.com/72893623/160555495-499b85f0-4443-4633-8e84-9c70d626984b.png)


## Analysis :

<img width="734" alt="p1" src="https://user-images.githubusercontent.com/72893623/160562108-035b8384-775c-4e94-bdbb-bed7c5e32967.png">


<img width="909" alt="p2" src="https://user-images.githubusercontent.com/72893623/160562204-1ad7a759-8b8f-4ca8-b0af-356e6e54e903.png">

## Testing on SoC :

After connecting Accelerator on SOC, we test the accelerator with a covloution function its input pixels are of size 5*5 and 3 input channels, the size of filters is 3x3 and we test once with two filters and another time with four filters. In the two filters case, we were able  to achieve an acceleration of 34.8% with parallel accelerator compared to 20.8% with four_Mac acceleraltor. For the four filters case, we were able to achieve an acceleration of 51.4% with parallel accelerator compared to 15.4% with four_Mac accelerrator.


## Results


### Using 2 filters
<img width="825" alt="r1" src="https://user-images.githubusercontent.com/72893623/160566241-c5b21a75-ad07-4fa3-ac11-465328a68200.png">



### Using 4 filters
<img width="842" alt="r2" src="https://user-images.githubusercontent.com/72893623/160566266-5a5e801a-794f-494c-8e06-9b1a9bd45fb1.png">





