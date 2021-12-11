# One 8-bit MAC unit accelerator

## Architecture:



## Area and Speed Analysis


## power Analysis


# Four 8-bit MAC unit accelerator


## Motivation:
Since,area of MAC unit is very small (0.00235 mm^2) (264 gate cells) and the speed of one unit is 2.2ns less than 0.25% of clk cycle period, and to avoid the over head of using another clk, we propose that ML accelerator can consists of 4 8-bit MAC units.


## Architecture :
![Untitled Diagram2 drawio](https://user-images.githubusercontent.com/72893623/145666681-c4b636fd-2805-4e9d-9af7-9a038ea49d84.png)



## Area and Speed Analysis:

#gates: 2593		area(um2):23068.38		delay(ps):4859.73

<img width="453" alt="Area_speed_4" src="https://user-images.githubusercontent.com/72893623/145666760-da3464cb-7c72-4080-b6e1-323b80c391d3.png">



## Cycles Analysis:

<img width="254" alt="acceleratedconvolution" src="https://user-images.githubusercontent.com/72893623/145666993-4fea5f16-af98-4ed6-94c4-514182638be5.png">

<img width="258" alt="unaccelerated convolution" src="https://user-images.githubusercontent.com/72893623/145666994-cd952a3a-ce99-471f-9763-57491110971d.png">

<img width="257" alt="speedup" src="https://user-images.githubusercontent.com/72893623/145666998-52a9609b-7a57-4476-87f9-259fdea20e82.png">


# Paralle MAC paths Accelerator

## Motivation:
* Area of MAC accelerator is very small (0.0231 mm^2) (2593 cells)
* Further reduction to Memory access by reusing input data
* Make use of parallelism operations


## Architecture :
![Untitled Diagram drawio (2)](https://user-images.githubusercontent.com/72893623/145666664-f81cddb1-433d-43c4-b72f-98bdea884c77.png)


## Analysis :


<img width="576" alt="analysis" src="https://user-images.githubusercontent.com/72893623/145667264-be763238-0859-4904-b4bb-cc302d1a0fa6.png">

<img width="768" alt="analysis2" src="https://user-images.githubusercontent.com/72893623/145667266-df018e0b-121e-4a10-b729-c4e0bd25307e.png">










