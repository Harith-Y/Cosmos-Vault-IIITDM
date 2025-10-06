module pattern_checker_tb;
    reg [7:0] data;
    wire is_alt;
    wire parity;

    pattern_checker uut (
        .in(data),
        .is_alt(is_alt),
        .parity(parity)
    );
    
    initial begin
    
    $monitor("Time = %0t | is_alt = %b | parity = %b", $time, is_alt, parity);

    data = 8'b10101010; #10;
    data = 8'b01010101; #10;
    data = 8'b00110011; #10;
    data = 8'b11110000; #10;
    data = 8'b00000000; #10;
    $finish;
    end
endmodule