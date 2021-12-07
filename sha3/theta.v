//calculate bc outside and take it as input
module theta (
    input [0:31] in_st,
    input [0:63] bc,
    output [0:31] out_st
    
);

    assign out_st = in_st ^ bc[0:31] ^ ROTL64(bc[32:63], 1);

    function [0:31] ROTL64(integer x, integer y);
        ROTL64 = (((x) << (y)) | ((x) >> (32 - (y))));
endfunction

endmodule
