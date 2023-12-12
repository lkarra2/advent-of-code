#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>
#include <queue>

namespace Day5 {
    std::string input = "day5_input.txt";

    std::vector<int> seeds;

    struct Instruction {
        int src;
        int dest;
        int range;
    };

    using Instructions = std::vector<Instruction>;
    std::vector<Instructions> data;
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        locations;

    void skip(std::istream &stream, char delim)
    {
        stream.ignore(std::numeric_limits<std::streamsize>::max(), delim);
    }

    void ReadData()
    {
        std::string line;
        std::ifstream file(input);
        int num;

        std::cout << "\nInside ReadData";

        if(std::getline(file, line))
        {
            std::cout << "\nSeeds: ";
            std::stringstream ss(line);
            std::string seeds;
            ss >> seeds;
            while(ss >> num)
            {
                seeds.push_back(num);
                std::cout << num << " ";
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
        int num;
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
            locations.push(num);
        }
        std::cout << "Closest location: " << locations.top() << "\n";
    }

    void PartB()
    {

    }

    extern void Run() 
    {
        std::cout << "Result Part A: ";
        PartA();
        std::cout << "\nResult Part B: ";
        PartB(); 
    }
}