module tb_seven_segment;

    reg [3:0] digit;   // 4-bit input to select a digit
    wire a, b, c, d, e, f, g;  // Seven segment outputs

    // Instantiate the seven_segment module
    seven_segment uut (
        .digit(digit),
        .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g)
    );

    // Stimulus block
    initial begin
	    $dumpfile("seven_segment.vcd");
        $dumpvars(0, tb_seven_segment);
        
        // Display digits 0 to 9
        digit = 4'b0000; #10;  // Display 0
        digit = 4'b0001; #10;  // Display 1
        digit = 4'b0010; #10;  // Display 2
        digit = 4'b0011; #10;  // Display 3
        digit = 4'b0100; #10;  // Display 4
        digit = 4'b0101; #10;  // Display 5
        digit = 4'b0110; #10;  // Display 6
        digit = 4'b0111; #10;  // Display 7
        digit = 4'b1000; #10;  // Display 8
        digit = 4'b1001; #10;  // Display 9

        $finish;  // End simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | digit = %d | a = %b | b = %b | c = %b | d = %b | e = %b | f = %b | g = %b", 
                 $time, digit, a, b, c, d, e, f, g);
    end

endmodule

