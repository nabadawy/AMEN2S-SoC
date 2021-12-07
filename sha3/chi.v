module chi (
    input [0:95] in_st, //takes three 32-bit blocks
    output [0:31] out_st //outputs one 32-bit block
    
);
    wire [0:31] bc[0:1];

    assign bc[0] = in_st[32:63];
    assign bc[1] = in_st[64:95];

    assign out_st = in_st[0:31] ^ (~bc[0] & bc[1]);

endmodule
