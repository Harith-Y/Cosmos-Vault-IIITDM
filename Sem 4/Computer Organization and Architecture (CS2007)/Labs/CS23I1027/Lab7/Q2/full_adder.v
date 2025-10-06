module full_adder (
    input A,        // First input bit
    input B,        // Second input bit
    input C,        // Third input bit
    output sum,     // Sum output
    output carry    // Carry output
);

    assign sum0 = A ^ B;     // Sum0 is the XOR of the two inputs
    assign sum = sum0 ^ C; // Sum1 is the XOR of the three inputs
    
    assign carry0 = A & B;
    assign carry1 = (A ^ B) & C;
    assign carry = (carry1 | carry0);    // Carry is the overall carry.

endmodule

