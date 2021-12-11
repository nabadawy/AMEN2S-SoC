module MAC#(
  parameter WIDTH_SUM = 32,
	parameter WIDTH_A = 8,
	parameter WIDTH_B = 8
	)
	(
	input			[WIDTH_SUM-1:0] 			sum1,
	input		 	[WIDTH_A-1:0] 			a,
	input		 	[WIDTH_B-1:0] 			b,
	output	wire 		[WIDTH_SUM-1:0]	out
    );

assign out = sum1 + a*b;
endmodule
