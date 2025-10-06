module tb_full_adder;

    reg A;        // First input
    reg B;        // Second input
    reg C;        // Carry-in input
    wire sum;     // Sum output
    wire carry;   // Carry output

    // Instantiate the Full Adder module
    full_adder uut (
        .A(A), 
        .B(B),
        .C(C),
        .sum(sum), 
        .carry(carry)
    );

    // Test stimulus
    initial begin
        $dumpfile("full_adder.vcd");
        $dumpvars(0, tb_full_adder);

        // Test all combinations of inputs
        A = 0; B = 0; C = 0; #10;  // Test case: 0 + 0 + 0
        A = 0; B = 0; C = 1; #10;  // Test case: 0 + 0 + 1
        A = 0; B = 1; C = 0; #10;  // Test case: 0 + 1 + 0
        A = 0; B = 1; C = 1; #10;  // Test case: 0 + 1 + 1
        A = 1; B = 0; C = 0; #10;  // Test case: 1 + 0 + 0
        A = 1; B = 0; C = 1; #10;  // Test case: 1 + 0 + 1
        A = 1; B = 1; C = 0; #10;  // Test case: 1 + 1 + 0
        A = 1; B = 1; C = 1; #10;  // Test case: 1 + 1 + 1

        $finish;  // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | A = %b | B = %b | C = %b | sum = %b | carry = %b", $time, A, B, C, sum, carry);
    end

endmodule

