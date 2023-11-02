#include <iostream>
#include <string>
#include <cstdlib>

// You would use libraries like libssh or expect to interact with the device.
// Below is a simplified example that uses system() to send commands via the shell.

int main() {
    std::string deviceIp = "192.168.1.1"; // Replace with the IP address of your device
    std::string username = "your_username";
    std::string password = "your_password";

    // Connect to the device (this is a simplified example)
    std::string connectCommand = "ssh " + username + "@" + deviceIp;
    int connectStatus = std::system(connectCommand.c_str());

    if (connectStatus != 0) {
        std::cerr << "Failed to connect to the device." << std::endl;
        return 1;
    }

    // Send configuration commands (replace with your actual commands)
    std::string configCommand1 = "configure terminal";
    std::string configCommand2 = "interface FastEthernet0/0";
    std::string configCommand3 = "ip address 192.168.1.2 255.255.255.0";
    
    std::string exitCommand = "exit"; // Exit configuration mode
    std::string saveCommand = "write memory"; // Save configuration

    std::system(configCommand1.c_str());
    std::system(configCommand2.c_str());
    std::system(configCommand3.c_str());
    std::system(exitCommand.c_str());
    std::system(saveCommand.c_str());

    // Close the connection (for SSH, you'd need to handle this properly)
    std::string disconnectCommand = "exit";
    std::system(disconnectCommand.c_str());

    return 0;
}
