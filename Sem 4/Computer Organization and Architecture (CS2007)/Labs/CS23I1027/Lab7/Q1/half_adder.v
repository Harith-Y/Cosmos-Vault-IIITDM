module half_adder (
    input A,        // First input bit
    input B,        // Second input bit
    output sum,     // Sum output
    output carry    // Carry output
);

    assign sum = A ^ B;      // Sum is the XOR of the two inputs
    assign carry = A & B;    // Carry is the AND of the two inputs

endmodule

