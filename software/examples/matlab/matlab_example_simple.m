function matlab_example_simple()
    import com.tinkerforge.IPConnection;
    import com.tinkerforge.BrickletRGBLEDV2;

    HOST = 'localhost';
    PORT = 4223;
    UID = 'XYZ'; % Change XYZ to the UID of your RGB LED Bricklet 2.0

    ipcon = IPConnection(); % Create IP connection
    rl = handle(BrickletRGBLEDV2(UID, ipcon), 'CallbackProperties'); % Create device object

    ipcon.connect(HOST, PORT); % Connect to brickd
    % Don't use device before ipcon is connected

    % Set light blue color
    rl.setRGBValue(0, 170, 234);

    input('Press key to exit\n', 's');
    ipcon.disconnect();
end
