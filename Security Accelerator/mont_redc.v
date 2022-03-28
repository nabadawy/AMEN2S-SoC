//xR^-1 mod m
module mont_reduce (
	input [31:0] x,//the number to compute its mont reduction
	input [31:0] m,
	input [31:0] m_inv,//m inverse mod 2
	input [4:0] n,//RIND: number of bits in m
	output [31:0] x_red //the reduction of x
);

wire [31:0] r;//r = 2^n
wire [31:0] mu_1;//x * m_inv mod r 
wire [31:0] mu_2;//x + mu_1 * m
wire [31:0] t;

assign r = (31'b1 << n);

assign mu_1 = x * m_inv & (r-1);

assign mu_2 = x + mu_1 * m;

assign t = mu_2 >> n;

assign x_red = (m <= t)? t - m: t;

endmodule
