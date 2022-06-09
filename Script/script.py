import string
from turtle import delay
import numpy as np
import serial
import time
import array


port = "COM3"
baud = 4800

def Send_hex():
 with open('test.hex','r') as f:
  lines=f.read().splitlines()
  lines= [x for x in lines if not x.startswith('@')]
  lines = [i.split(" ") for i in lines]
  for x in lines:
     for i in x[:-1]:
       temp= int(i,16)
       print((hex(temp)))
       #SPI_BYTE_WR(temp)

    

  #print(lines)
  #return lines

def FW_RD(A, D):
         # each print should be replaced 
     temp= int('A5',16)
   
     Byte= temp.to_bytes(1, 'big')
     
    
     #print ('Receiving...' , out)
     #sending the Adress
     mask = (1 << 8) - 1
     Firs_byte = A & mask   
     
    
     #print ('Receiving...' , out)
     mask = ((1 << 8) - 1) << 8
     Second_byte= (A & mask)>>8
     
    
     #print ('Receiving...' , out)
     mask = ((1 << 8) - 1) << 16
     Third_byte= (A & mask)>>16
     
     #out = ser.read()

     #print ('Receiving...' , out)
     mask = ((1 << 8) - 1) << 24
     Fourth_byte= (A & mask)>>24
     


     ser.write(Byte) 
     ser.write(Firs_byte.to_bytes(1, 'big'))  # first byte
     ser.write(Second_byte.to_bytes(1, 'big'))    #second byte
     ser.write(Third_byte.to_bytes(1, 'big'))
     ser.write(Fourth_byte.to_bytes(1, 'big'))

     out1 = ser.read()
     
     out2 = ser.read()
     
     out3 = ser.read()
     
     out4 = ser.read()
     firstByte = int.from_bytes(out4,'big') & 0xff000000
     secondByte = int.from_bytes(out3,'big') & 0x00ff0000
     thirdByte = int.from_bytes(out2,'big') & 0x0000ff00
     fourthByte = int.from_bytes(out1,'big') & 0x000000ff
     D= firstByte | secondByte | thirdByte | fourthByte

     #print ('Receiving...' , out1)
     #print ('Receiving...' , out2)
     #print ('Receiving...' , out3)
     #print ('Receiving...' , out4)
     #print('####################')
     #print(D)
     return D
     
     
     


def FW_WR(A,D):
    temp= int('A3',16)
    #print(temp)
    Byte= temp.to_bytes(1, 'big')
    
    mask = (1 << 8) - 1
    Firs_byte_A = A & mask
    
    mask = ((1 << 8) - 1) << 8
    Second_byte_A= (A & mask)>>8
    
    mask = ((1 << 8) - 1) << 16
    Third_byte_A= (A & mask)>>16
    
    mask = ((1 << 8) - 1) << 24
    Fourth_byte_A= (A & mask)>>24
    
    mask = (1 << 8) - 1
    Firs_byte_D = D & mask
    
    mask = ((1 << 8) - 1) << 8
    Second_byte_D= (D & mask)>>8
    
    mask = ((1 << 8) - 1) << 16
    Third_byte_D= (D & mask)>>16
    
    mask = ((1 << 8) - 1) << 24
    Fourth_byte_D= (D & mask)>>24
    
    ser.write(Byte)
    ser.write(Firs_byte_A.to_bytes(1, 'big'))
    ser.write(Second_byte_A.to_bytes(1, 'big'))
    ser.write(Third_byte_A.to_bytes(1, 'big'))
    ser.write(Fourth_byte_A.to_bytes(1, 'big'))
    #SENDING DATA
    ser.write(Firs_byte_D.to_bytes(1, 'big'))
    ser.write(Second_byte_D.to_bytes(1, 'big'))
    ser.write(Third_byte_D.to_bytes(1, 'big'))
    ser.write(Fourth_byte_D.to_bytes(1, 'big'))
    


def FW_ENABLE():
    FW_WR(0x4c000000,0xA5A85501)

def SPI_OE(data):
 FW_WR(0x4c00000c,data)

def SPI_STATRT():
 FW_WR(0x4c000004,0)

def SPI_STOP():
 FW_WR(0x4c000004,1)

def SPI_BYTE_WR(data):
    for x in range(7, -1,-1):
        mask = ((1 << 1) - 1) <<x
        bit = (data & mask)>>x
        #print("the bit is ",bit)
        #print (hex(byte))
        FW_WR(0x4c000010, bit)
        FW_WR(0x4c000008, 1)
        FW_WR(0x4c000008, 0)    

def SPI_BYTE_RD():
    word=0
    data=0
    temp={}
    for x in range(7, -1,-1):
        FW_WR(0x4c000008, 1)
        word=FW_RD(0x4c000014,word)
        temp[x]= ((word) & 1)#(word[0])0000000000000000000001
        FW_WR(0x4c000008, 0)
        
    num =0
    for x in range(7, -1,-1):
      if (temp[x]== 1):
         num+=2**(x)
    data = num
    #print(hex(data))
    return hex(data)
#test case 
#FW_RD(0x12345678,0xAB125577)

data = 0x12345678
ser = serial.Serial(port, baud, timeout=1)

if ser.isOpen():
  print (ser.name + 'is open...')

D = 0

def FLASH_WDI():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X04)
    SPI_STOP()
def FLASH_WEN():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X06)
    SPI_STOP()
def FLASH_WEN_VOL():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X50)
    SPI_STOP()
def FLASH_PORT_UNLK():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X98)
    SPI_STOP()
def FLASH_CHIP_ERASE():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0XC7)
    SPI_STOP()


def ENABLE_QE(data):
    FLASH_WEN_VOL()
    time.sleep(1)
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X31)
    SPI_BYTE_WR(data)
    #SPI_BYTE_WR(data)
    SPI_STOP()

def ENTER_QPI():
    FLASH_WEN()
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X38)
    SPI_STOP()

def FLASH_BLOCK_ERASE(A):
    mask = ((1 << 8) - 1) << 16
    Third_byte_A= (A & mask)>>16
    mask = ((1 << 8) - 1) << 8
    Second_byte_A= (A & mask)>>8
    mask = (1 << 8) - 1
    Firs_byte_A = A & mask

    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0XD8)

    SPI_BYTE_WR(Third_byte_A)
    SPI_BYTE_WR(Second_byte_A)
    SPI_BYTE_WR(Firs_byte_A)
    SPI_STOP()

def FLASH_PAGE_PROG(A, arr):
    print("Loading the first page")
   
    mask = ((1 << 8) - 1) << 16
    Third_byte_A= (A & mask)>>16
    
    mask = ((1 << 8) - 1) << 8
    Second_byte_A= (A & mask)>>8
  
    mask = (1 << 8) - 1
    Firs_byte_A = A & mask
    
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X02)
    SPI_BYTE_WR(Third_byte_A)
    SPI_BYTE_WR(Second_byte_A)
    SPI_BYTE_WR(Firs_byte_A)

    
    for byte in arr:
        SPI_BYTE_WR(byte)
  
    SPI_STOP()

def READ_SR2():
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X35)
    D= SPI_BYTE_RD()
    SPI_STOP()
    return D

def READ_SR1():
    #SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X05)
    #time.sleep(0.1)
    D= SPI_BYTE_RD()
    #print(D)
    
    SPI_STOP()
    return D

def FLASH_PAGE_RD(A):
    print("reading page")

    mask = ((1 << 8) - 1) << 16
    Third_byte_A= (A & mask)>>16
    
    mask = ((1 << 8) - 1) << 8
    Second_byte_A= (A & mask)>>8
    
    mask = (1 << 8) - 1
    Firs_byte_A = A & mask
    
    SPI_OE(0X1)
    SPI_STATRT()
    SPI_BYTE_WR(0X03)
    SPI_BYTE_WR(Third_byte_A)
    SPI_BYTE_WR(Second_byte_A)
    SPI_BYTE_WR(Firs_byte_A)
    
    #SPI_BYTE_RD()
    #SPI_BYTE_RD()
    #SPI_BYTE_RD()
    #SPI_BYTE_RD()
    f= open("out.txt", "a")
    x=0
    for i in range (128):
     f.write(SPI_BYTE_RD())
     x=x+1
     f.write(" ")
     if x==16:
         f.write("\n")
         x=0

 
    SPI_STOP()
    f.close()

   # return D

def PROG_WR():
   
   print("In loading the Program..")
   K=0
   n=0
   flag=1
   arr= array.array('B',)
   with open('test.mem','r') as f:
    lines=f.read().splitlines()
    lines= [x for x in lines if not x.startswith('@')]
    lines = [i.split(" ") for i in lines]
    for x in lines:
        for i in x[:-1]:
            temp= int(i,16)
            if (n<128):
                arr.append(temp)
                n=n+1
                #print(n, (hex(temp)))
            if(n==128): 
                print("hello")   
                n=0
                FLASH_WEN()
                FLASH_PAGE_PROG(K, arr)
                time.sleep(0.1)
                #FLASH_WDI()
                #FLASH_PAGE_RD(K)
                K = K + 128
                flag=flag+1
                #arr.clear()
                for i in range(128):
                    arr.pop()
                #return
            #if(flag==3):
                #return
            
    
       
       #SPI_BYTE_WR(temp)

  


##########################
# To exit the QPI mode
###########################
FW_ENABLE()
SPI_OE(0x1)
SPI_STATRT()
SPI_BYTE_WR(0xFF)
SPI_STOP()
############################

############################
# To read the JEDEC ID
############################
print("Reading JEDEC ID")
SPI_STATRT()
SPI_BYTE_WR(0x9F)
print(SPI_BYTE_RD())
print(SPI_BYTE_RD())
print(SPI_BYTE_RD())
SPI_STOP()
#############################

#############################
#Read SR 1 & 2
#############################
SR1= READ_SR1()
print ("SR 1: ",SR1)

SR2= READ_SR2()
print("SR 2 before WR: ",SR2)

SR2= int(SR2,16)
SR1 = int(SR1,16)
mask_SR2 = SR2 | 0x02
print("SR 2 mask: ",mask_SR2)

#################################
#Write SR1 & SR2 with 0x01 commd
#################################
FW_ENABLE()
time.sleep(1)
SPI_OE(0x1)
SPI_STATRT()
SPI_BYTE_WR(0x01)
SPI_BYTE_WR(SR1)  # write SR1
SPI_BYTE_WR(mask_SR2)  #Write SR2
SPI_STOP()
##################################
# READ SR2 
##################################
time.sleep(1)

D3= READ_SR1()
print ("SR 1",D3)
D2 = READ_SR2()
print ("SR 2 after WR", D2)






#FLASH_WEN()
#FLASH_WEN()
#time.sleep(0.07)
#FLASH_BLOCK_ERASE(6656)
#time.sleep(0.7)
#FLASH_PAGE_PROG(6656, arr)
#time.sleep(0.1)
#FLASH_WDI()

#for i in range(6656):
    #FLASH_PAGE_RD(i)
#FLASH_PAGE_RD(6656)

#temp= int('0F',16)
#Byte= temp.to_bytes(1, 'big')
#while True:
#ser.write(Byte)
#FLASH_WEN()
#ENABLE_QE()
#ENTER_QPI()
#FLASH_WDI()
#FLASH_WDI()

#FLASH_WEN()
#READ_ST_REG()

#print(end-start)
#print(hex(Data))
