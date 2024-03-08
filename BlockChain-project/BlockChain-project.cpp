#include "Block.h"
#include "BlockChain.h"

#include <iostream>
#include <chrono>

std::string get_current_time_stamp() {
    
    std::time_t currentTime;
    std::time(&currentTime);

    // Convert the current time to a struct tm
    std::tm timeInfo;
    localtime_s(&timeInfo, &currentTime);

    // Format the time into a string
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &timeInfo);

    return std::string(buffer);
}

int main() {
    std::string time_stamp = get_current_time_stamp();
    BlockChain block_chain(time_stamp,"testing");

    Block second_block(1, "testing again", get_current_time_stamp());
    Block third_block(2, "testing again", get_current_time_stamp());

    block_chain.add_block(second_block);
    block_chain.add_block(third_block);

    if(block_chain.is_chain_valid())
        block_chain.print_chain();


    return 0;
}

