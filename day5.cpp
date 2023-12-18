#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <queue>

namespace Day5 {
    std::string input = "day5_input.txt";
    std::vector<uint64_t> seeds;

    struct Instruction {
        uint64_t src;
        uint64_t dest;
        uint64_t range;
    };

    using Instructions = std::vector<Instruction>;
    std::vector<Instructions> data;
    std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>>
        locations;

    void ReadData()
    {
        std::string line;
        std::ifstream file(input);
        uint64_t num;
        uint64_t length;

        if(std::getline(file, line))
        {
            // std::cout << "\nSeeds: ";
            std::stringstream ss(line);
            std::string seeds_string;
            ss >> seeds_string;
            while(ss >> num >> length)
            {
                for(uint64_t i = num; i < num+length; i++)
                {
                    seeds.push_back(num);
                }
            }
            std::getline(file, line); 
        }

        while(std::getline(file, line))
        {
            Instructions instructions;
            while(std::getline(file, line) && !line.empty())
            {
                std::stringstream ss(line);
                Instruction i;
                if(ss >> i.dest >> i.src >> i.range)
                    instructions.push_back(std::move(i));
            }
            data.push_back(std::move(instructions));
        }
    }


    void PartA()
    {
        ReadData();
        uint64_t num;
        for(const auto &seed: seeds)
        {
            num = seed;
            for(const auto &record: data)
            {
                for(const auto &instruction: record)
                {
                    if(num >= instruction.src && num < instruction.src + instruction.range)
                    {
                        num = instruction.dest + num - instruction.src;
                        break;
                    }
                }
            }
            std::cout << "\nLocation: " << num;
            locations.push(num);
        }
        std::cout << "Closest location: " << locations.top() << "\n";
    }

    extern void Run() 
    {
        std::cout << "Result Part A: ";
        PartA(); 
    }
}