#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#include "botcraft/Game/ConnectionClient.hpp"
#include "botcraft/Utilities/Logger.hpp"

int main(int argc, char* argv[]) {
	try {
		// Init logging, log everything >= Info, only to console, no file
        Botcraft::Logger::GetInstance().SetLogLevel(Botcraft::LogLevel::Info);
        Botcraft::Logger::GetInstance().SetFilename("");
        // Add a name to this thread for logging
        Botcraft::Logger::GetInstance().RegisterThread("main");
		
        
        Botcraft::ConnectionClient client;

        LOG_INFO("Starting connection process");
        client.Connect("simpcraft.com", "");

        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
        client.SendChatMessage(u8"another message sent with objectBot");
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        client.Disconnect();
		
	} catch (std::exception& e) {
        LOG_FATAL("Exception: " << e.what());
        return 1;
    } catch (...) {
        LOG_FATAL("Unknown exception");
        return 2;
    }
}