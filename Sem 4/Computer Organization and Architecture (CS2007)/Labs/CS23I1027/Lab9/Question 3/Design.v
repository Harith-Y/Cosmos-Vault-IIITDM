module add_sub_mul (
    input [7:0] a, b,
    input op, // 0 for addition and 1 for subtraction
    input mul_flag, // 1 to perform multiplication
    output reg [7:0] result,
    output reg [15:0] mul_result
);


function [7:0] add_sub;
    input [7:0] x, y;
    input op;
    begin
        add_sub = op ? (x - y) : (x + y); // i.e. op = 1 -> Subtract, else Add
    end
endfunction

function [15:0] multiply;
    input [7:0] x, y;
    begin
        multiply = x * y; 
    end
endfunction

always @(*) begin
    if (!mul_flag) begin
        result = add_sub(a, b, op);
        mul_result = 16'b0;
    end

    else begin
        mul_result = multiply(a, b);
        result = 8'b0;
    end
end

endmodule