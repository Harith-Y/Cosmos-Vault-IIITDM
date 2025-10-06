module add_sum_mul_tb;

    reg [7:0] a, b;
    reg op, mul_flag;
    wire [7:0] result;
    wire [15:0] mul_result;

    add_sub_mul uut (
        .a(a),
        .b(b),
        .op(op),
        .mul_flag(mul_flag),
        .result(result),
        .mul_result(mul_result)
    );

    initial begin
        $monitor("A = %d | B = %d | Op = %b | Mul Enable = %b | Result = %d | Mul Result = %d",
                 a, b, op, mul_flag, result, mul_result);

        a = 8'd16; b = 8'd8; op = 0; mul_flag = 0; #10;
        a = 8'd40; b = 8'd5; op = 1; mul_flag = 0; #10;
        a = 8'd6; b = 8'd9; op = 0; mul_flag = 1; #10;
        a = 8'd19; b = 8'd14; op = 0; mul_flag = 1; #10;
        a = 8'd210; b = 8'd90; op = 0; mul_flag = 0; #10;
        $finish;
    end
endmodule