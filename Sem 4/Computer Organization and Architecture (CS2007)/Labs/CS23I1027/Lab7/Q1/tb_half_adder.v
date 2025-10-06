module tb_half_adder;

    reg A;        // First input
    reg B;        // Second input
    wire sum;     // Sum output
    wire carry;   // Carry output

    // Instantiate the Half Adder module
    half_adder uut (
        .A(A), 
        .B(B), 
        .sum(sum), 
        .carry(carry)
    );

    // Test stimulus
    initial begin
        $dumpfile("half_adder.vcd");
        $dumpvars(0, tb_half_adder);

        // Test all combinations of inputs
        A = 0; B = 0; #10;  // Test case: 0 + 0
        A = 0; B = 1; #10;  // Test case: 0 + 1
        A = 1; B = 0; #10;  // Test case: 1 + 0
        A = 1; B = 1; #10;  // Test case: 1 + 1

        $finish;  // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | A = %b | B = %b | sum = %b | carry = %b", $time, A, B, sum, carry);
    end

endmodule

