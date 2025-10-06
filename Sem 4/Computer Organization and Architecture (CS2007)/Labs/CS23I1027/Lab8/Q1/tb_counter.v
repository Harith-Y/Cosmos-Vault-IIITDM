module tb_counter;

    reg clk;           // Clock signal
    reg reset;         // Reset signal
    wire [3:0] count;  // 4-bit counter output

    // Instantiate the counter module
    counter uut (
        .clk(clk),
        .reset(reset),
        .count(count)
    );

    // Generate clock signal
    always begin
        #5 clk = ~clk; // Toggle clock every 5 time units
    end

    // Test stimulus
    initial begin
        $dumpfile("counter.vcd");
        $dumpvars(0, tb_counter);

        // Initialize signals
        clk = 0;
        reset = 1;    // Initially
        #10 reset = 0; // Reset after 10 time units

        // Simulate for 100 time units to observe the counter's behavior
        #100;

        $finish; // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | reset = %b | count = %d", $time, reset, count);
    end

endmodule

