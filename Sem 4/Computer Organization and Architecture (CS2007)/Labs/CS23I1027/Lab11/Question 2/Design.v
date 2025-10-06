module room_light_controller (
    input wire clk,
    input wire reset,
    input wire [7:0] motion,
    output reg [7:0] light
);

    reg [3:0] countdown [7:0];
    
    reg [3:0] active_lights_count;
    
    always @(*) begin
        active_lights_count = light[0] + light[1] + light[2] + light[3] + light[4] + light[5] + light[6] + light[7];
    end
    
    integer i;
    always @(posedge clk or posedge reset) begin
        if (reset) begin
        for (i = 0; i < 8; i = i + 1) begin
            light[i] <= 0;
            countdown[i] <= 0;
        end
    end else begin
            for (i = 0; i < 8; i = i + 1) begin
                if (motion[i]) begin
                    if (light[i]) begin
                        countdown[i] <= 10;
                    end
                    else begin
                        if (active_lights_count > 5) begin
                            countdown[i] <= 5;
                        end else begin
                            countdown[i] <= 10;
                        end
                        light[i] <= 1;
                    end
                end
                
                else if (countdown[i] > 0) begin
                    countdown[i] <= countdown[i] - 1;
                    
                    if (countdown[i] == 1) begin
                        light[i] <= 0;
                    end
                end
            end
        end
    end
endmodule
