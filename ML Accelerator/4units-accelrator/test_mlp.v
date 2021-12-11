// file: test_ml.v
// author: @eman

`timescale 1ns/1ns

module test_mlp#(
  	parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 32,
	parameter WIDTH_B = 32
	)
	(
	input   clk,
	input   clk2,
	input   rstn,
	input			[WIDTH_A-1:0] 			sum0,
	input			[WIDTH_A-1:0] 			a,
	input		      	[WIDTH_B-1:0] 			b,
	output	wire 	[WIDTH_SUM-1:0]		out

    );

wire [31:0]		sum1;
wire [31:0]		sum2;
wire [31:0]		sum3;
wire [31:0]		sum4;

		MAC  mac1 (sum0,a[7:0],b[7:0],sum1);
		MAC  mac2 (sum1,a[15:8],b[15:8],sum2);
		MAC  mac3 (sum2,a[23:16],b[23:16],sum3);
		MAC  mac4 (sum3,a[31:24],b[31:24],out);

//assign out= sum0+sum1+sum2+sum3+sum4;
/*		
always @ (posedge clk2)
begin
if (! rstn)
begin
 SUMout = sum1;
 end
else
begin
 SUMout <= out;
end
end
*/		
	
		

 
 
endmodule