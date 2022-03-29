// file: mac.v
// author: @ashrakatkh and @eman
module MAC#(
  parameter WIDTH_SUM = 8,
	parameter WIDTH_A = 8,
	parameter WIDTH_B = 8
	)
	(

	input valid,
	input	signed	 	[WIDTH_A-1:0] 			a,
	input	signed	 	[WIDTH_B-1:0] 			b,
	output 	wire 		[WIDTH_SUM-1:0]	out
    );


assign out = valid? a*b: 0;
endmodule
