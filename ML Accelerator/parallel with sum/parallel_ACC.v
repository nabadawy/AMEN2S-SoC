// file: parallel_ACC.v
// author: @ashrakatkh and @eman

`timescale 1ns/1ns

module parallel_ACC#(
  	parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 32,
	parameter WIDTH_B = 32
	)
	(
	input     [2:0] 			valid,
	input			[WIDTH_SUM-1:0] 			sumin,
  input			[WIDTH_A-1:0] 			sum0,
	input			[WIDTH_A-1:0] 			sum1,
	input			[WIDTH_A-1:0] 			sum2,
	input			[WIDTH_A-1:0] 			sum3,
	input			[WIDTH_A-1:0] 			a,
	input		  [WIDTH_B-1:0] 			w0,
	input		  [WIDTH_B-1:0] 			w1,
	input		  [WIDTH_B-1:0] 			w2,
	input		  [WIDTH_B-1:0] 			w3,
	
	//output	wire 	[WIDTH_SUM-1:0]		out
	output	wire 	[WIDTH_SUM-1:0]		out0,
	output	wire 	[WIDTH_SUM-1:0]		out1,
	output	wire 	[WIDTH_SUM-1:0]		out2,
	output	wire 	[WIDTH_SUM-1:0]		out3

    );
  wire [3:0] validbit;
  wire [1:0] val;

  assign val= valid -1'd1;
  assign validbit= val[1]? (val[0]? 4'b1111 : 4'b0111) :(val[0]? 4'b0011 : 4'b0001);

    four_mac  macp0 (sumin,validbit,a,w0,out0);
		four_mac  macp1 (sumin,validbit,a,w1,out1);
		four_mac  macp2 (sumin,validbit,a,w2,out2);
		four_mac  macp3 (sumin,validbit,a,w3,out3);
		


endmodule
