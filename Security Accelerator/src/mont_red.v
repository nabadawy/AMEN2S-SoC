// file: mont_red.v
// author: @mariamhmousa

`timescale 1ns/1ns

module mont_red(
  input clk,
  input rst,
	input [31:0] x,//the number to compute its mont reduction
	input [31:0] m,
	input [31:0] m_inv,//m inverse mod 2
	output [31:0] x_red //the reduction of x
);
//Modules implemented
//Register
//mux_2x1
//DFlipFlop
//shifter
//ADDER
//mux_3x2
//MULT --- a multiplier
//CMP --- comparator


reg [1:0]stage = 2'd0;
wire [31:0] shiftIN;
wire [31:0] shiftmount;
wire [31:0] shiftOUT;
wire shiftType;
wire [31:0] adderOUT_3;
wire [31:0] adderOUT_2;
wire [31:0] ANDOUT;
wire [31:0] mulIN1;
wire [31:0] mulIN2;
wire [31:0] mulOUT;
wire [31:0] ANDIN1;
wire [31:0] ANDIN2;
wire [31:0] addIN1;
wire [31:0] addIN2;
wire [31:0] k;
wire [31:0] temp_out;
wire [4:0] n;
wire cmprslt;
reg flag2, flag3, flag4;

reg [1:0] counter;//= 2'd0;

always @ (posedge clk)
  begin
    if (rst == 1'b1) begin
      stage <=0 ;
      counter <=  2'd1;
      flag3= 0;
      flag2=0;
      flag4=0;
    end 
    else 
     
      if(stage == 2'd1)
          begin
           if(counter == 2'd1)
             begin
              stage <= 2'd2;
              counter <= 0;
              flag3= 1;
              flag2=0;
              flag4=0;
             end
            else
              counter <= counter + 1;

           end
           
      else if(stage == 2'd2)
           begin
             if(counter == 2'd1)
               begin
               stage <= 2'd3;
               counter <= 0;
               flag3= 0;
               flag2=0;
               flag4=1;
               end
              else
              counter <= counter + 1;

           end
           
       else if((stage == 2'd3) |(stage == 2'd0))
           begin 
             if(counter == 2'd1)
                begin
                stage <= 2'd1;
                counter <= 0;
                flag2=1;
                flag3= 0;
                flag4=0;
                end
              else
              counter <= counter + 1;

            end
  end

used_bits ub(m, n);

//Stage 1: shift left, 2's complement, multiplication

mux32_2x1 mx1(stage[1], 1, adderOUT_3, shiftIN);//stage[1]=1 when at stage 3, =0 when at stage 1

mux_2x1 mx7(stage[1], 1'b0, 1'b1, shiftType);//to decide whether it's a shift left or shift right

shifter sh(shiftIN, n, shiftType, shiftOUT);//added shift type (right or left)


mux32_2x1 mx2(stage[1], m_inv, ANDOUT, mulIN1);//stage[1]=1 when at stage 2, =0 at stage 1

mux32_2x1 mx3(stage[1], x, m, mulIN2);

MULT mul(mulIN1, mulIN2, mulOUT);

Register reg1(clk, rst, flag2, {adderOUT_2, mulOUT}, {ANDIN1, ANDIN2}); //add register size as parameter

//Stage 2: AND, multiplication, add


assign ANDOUT = ANDIN1 & ANDIN2;

mux_3x2 mx4(stage, shiftOUT, x, shiftOUT, addIN1);//left as it is since r & t are both shiftOUT (an output of the shifter)

mux_3x2 mx5(stage, 1, mulOUT, m, addIN2);//added another option (that is 1) to implement the (r-1)

mux_3x2 mx8(stage, 1, 0, 1, k);//1= subtract, 0= add

addsub add(addIN1, addIN2, adderOUT_2, k[0]);//based on the stage, we either add or subtract

Register #(32) reg2(clk, rst, flag3, adderOUT_2, adderOUT_3);

//Stage 3: shift right, add, mux
cmp cmp1(m, shiftOUT, cmprslt);

mux32_2x1 mx6(cmprslt, shiftOUT, adderOUT_2, temp_out);

Register #(32) reg3(clk, rst, flag4, temp_out, x_red);



endmodule