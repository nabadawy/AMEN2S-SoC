// file: mont_red_tb.v
// author: @sarahali
// Testbench for mont_red

`timescale 1ns/1ns

module mont_red_tb;
	// Declarations
	reg  clk;
	reg  rst;
	reg [31:0]  x;
	reg [31:0]  m;
	reg [31:0]  m_inv;
	wire [31:0]  x_red;

	// Instantiation of Unit Under Test
	mont_red uut (
		.clk(clk),
		.rst(rst),
		.x(x),
		.m(m),
		.m_inv(m_inv),
		.x_red(x_red)
	);

	//clk
    always 
     #5  clk =  ! clk;
		//

	initial begin
		// Input Initialization
		clk = 0;
		rst = 1;
		x = 0;
		m = 0;
		m_inv = 0;
		// Reset
		#15;
		
		rst = 0;
		x = 9486;
		m = 109;
		m_inv = 27;
		#60;
		
	  x = 546;
		m = 169;
		m_inv = 103;

		#60;
		
		x = 859;
		m = 169;
		m_inv = 103;

		#60;
		
		x =17535;
		m = 169;
		m_inv = 103;

		#60;
		
		
	end

endmodule