module flipFlop#(
  	parameter WIDTH = 8
	)
	(input clk, 
	input [WIDTH-1:0] d, 
	output reg [WIDTH-1:0] q);
	always @ (posedge clk)
		q <= d;                // pronounced “q gets d”
endmodule
