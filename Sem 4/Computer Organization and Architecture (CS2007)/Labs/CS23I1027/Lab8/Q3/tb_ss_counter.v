module tb_ss_counter;

    reg clk;           // Clock signal
    reg reset;         // Reset signal
    wire [3:0] count;  // 4-bit counter output
    wire [6:0] segments; // 7-segment display output

    // Instantiate the counter module
    ss_counter uut (
        .clk(clk),
        .reset(reset),
        .count(count),
        .segments(segments)
    );

    // Generate clock signal
    always begin
        #5 clk = ~clk; // Toggle clock every 5 time units
    end

    // Test stimulus
    initial begin
        $dumpfile("ss_counter.vcd");
        $dumpvars(0, tb_ss_counter);

        // Initialize signals
        clk = 0;
        reset = 1;    // Apply reset initially
        #10 reset = 0; // Release reset after 10 time units

        // Simulate for 100 time units to observe the counter's behavior
        #100;

        $finish; // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | reset = %b | count = %d | segments = %b",
                 $time, reset, count, segments);
    end

endmodule

