// file: testbench_tb.v
// author: @ashrakatkh
// Testbench testbench_tb

`timescale 1ns/1ns

module testbench_tb;
	reg  [31:0] a;
	reg  [31:0]b;
	reg  [31:0] sum0;
	wire [31:0] out;
	
		test_mlp uut (
		.sum0(sum0),
		.a(a),
		.b(b),
		.out(out)

	);
		initial begin
		a = 0;
		b =0;
		sum0 = 0;
		#100
		sum0 = 000000000000000000000011;
		a= 00001010000010100000101000001010;
		b= 00001010000010100000101000001010;
		end

endmodule