module rhopi (
    input [0:31] in_st,
    input rotc,
    output [0:31] out_st
);

assign out_st = ROTL64(in_st, rotc);

    function [0:31] ROTL64(integer x, integer y);
        ROTL64 = (((x) << (y)) | ((x) >> (32 - (y))));
endfunction

endmodule
