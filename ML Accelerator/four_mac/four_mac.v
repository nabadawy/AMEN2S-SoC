// file: four_mac.v
// author: @ashrakatkh and @eman

`timescale 1ns/1ns

module four_mac #(
  	parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 32,
	parameter WIDTH_B = 32
	)
	(
	input     [2:0] 			valid,
	input	signed		[WIDTH_SUM-1:0] 			sumin,
	input	signed		[WIDTH_A-1:0] 			a,
	input		signed      	[WIDTH_B-1:0] 			b,
	output  wire 	[WIDTH_SUM-1:0]		out

    );

wire [3:0] validbit;
wire [1:0] val;
wire [WIDTH_SUM-1:0]		sum0;
wire [WIDTH_SUM-1:0]		sum1;
wire [WIDTH_SUM-1:0]		sum2;
wire [WIDTH_SUM-1:0]		sum3;


assign val= valid -1'd1;
assign validbit= val[1]? (val[0]? 4'b1111 : 4'b0111) :(val[0]? 4'b0011 : 4'b0001);

		MAC  mac0 (validbit[0],a[7:0],b[7:0],sum0);
		MAC  mac1 (validbit[1],a[15:8],b[15:8],sum1);
		MAC  mac2 (validbit[2],a[23:16],b[23:16],sum2);
		MAC  mac3 (validbit[3],a[31:24],b[31:24],sum3);


assign out = sum0+sum1+sum2+sum3+sumin;

endmodule
