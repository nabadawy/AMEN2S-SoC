`timescale 1ns/1ns

module MAC#(
  parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 8,
	parameter WIDTH_B = 8
	)
	(
	input	signed		[WIDTH_SUM-1:0] 			sum1,
	input	signed		[WIDTH_A-1:0] 			a,
	input	signed		[WIDTH_B-1:0] 			b,
	output	wire	signed	[WIDTH_SUM-1:0]	out
    );

wire [WIDTH_A+WIDTH_B-1:0]	mulOut;
assign mulOut = a*b;
assign out = sum1 + mulOut;

		   

endmodule
