module left_shift_tb;
    reg [15:0] in;
    reg [3:0] shift_amount;
    wire [15:0] out;
    
    left_shift uut (
        .data_in(in),
        .shift_amt(shift_amount),
        .data_out(out)
    );
    
    initial begin
    
    $monitor("Time = %0t | Input = %b | Shift Amount = %d | Output = %b", $time, in, shift_amount, out);
    
    in = 16'b1010010001000010; shift_amount = 4'b0000; #10;
    in = 16'b1010010001000010; shift_amount = 4'b0001; #10;
    in = 16'b1010010001000010; shift_amount = 4'b0100; #10;
    in = 16'b1010010001000010; shift_amount = 4'b1000; #10;
    in = 16'b1010010001000010; shift_amount = 4'b1100; #10;
    
    $finish;
    end
endmodule
    
    
    
    
    
    
    
    