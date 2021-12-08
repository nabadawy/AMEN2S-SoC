`timescale 1ns/1ns


module test_ml#(
  	parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 32,
	parameter WIDTH_B = 32
	)
	(
	input   clk,
	input	signed		[WIDTH_A-1:0] 			sum1,
	input	signed		[WIDTH_A-1:0] 			a,
	input	signed		[WIDTH_B-1:0] 			b,
	output	wire	signed	[WIDTH_SUM-1:0]		out
    );

integer counter;
wire [WIDTH_SUM-1:0] 		SUMout;
wire [WIDTH_SUM-1:0]		flip1out;
wire [WIDTH_A-1:0]		flip2out;
wire [WIDTH_B-1:0]		flip3out;
wire [WIDTH_A-1:0]		MACout;
wire [WIDTH_A-1:0]		MUX1out;
wire [WIDTH_B-1:0]		MUX2out;	

assign SUMout= sum1;
initial begin
	//flipFlop #(WIDTH_A) flop(clk, sum1, flip1out);
	//flipFlop #(WIDTH_A)  flop2(clk,a,flip2out);
	//flipFlop #(WIDTH_B) flop3(clk,b,flip3out);
	for (counter=0; counter<4;counter=counter+1)begin
		Mux4 mux1(a,counter,MUX1out);
		Mux4 mux2(b,counter,MUX2out);
		MAC #(WIDTH_SUM,WIDTH_A ,WIDTH_B) mac (SUMout,MUX1out,MUX2out,MACout);
		SUMout<=MACout;
	end
	//flipFlop #(WIDTH_SUM) flop4(clk, MACout,out); 
	out<=MACout;	  
end 

endmodule
