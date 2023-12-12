#include <iostream>
#include <fstream>
#include <vector>



namespace Day2 {

    std::vector<std::string> split(std::string txt, char ch)
    {
        std::vector<std::string> strs;
        std::cout<<"\nSplit";

        // Decompose statement
        int i = 0, len  = 0, start = 0;
        std::string word;
        while(i < txt.size()) {
            if(txt[i] == ' ') {
                // std::cout<<"\ni = "<<i;
                word = txt.substr(start, len);
                strs.push_back(word);
                // std::cout<<"\n Word = "<<word;
                start = i+1;
                len = 0;
                i++;
            } else {
                i++;
                len++;
            }
        }
        std::cout<<"\n Last Word = "<<word;
        word = txt.substr(start, len);
        strs.push_back(word);

        return strs;
    }

    int getPower(std::string input) 
    {
        std::cout<<"\nGetValidGame";
        int i = 1, game = 0, red_max = 0, green_max = 0, blue_max = 0;
        std::vector<std::string> input_split;
        input_split = split(input, ' ');

        while(i < input_split.size()) {
            std::string word = input_split[i];
            // int count = stoi(input_split[i-1]);
            std::cout<<"\n i = "<<i;
            std::cout<<"\n word = "<<word;
            if(i == 1) 
            {
                game = stoi(word.substr(0, word.size()-1));
                std::cout<<"\nGame = "<<game;
                i += 2;
            }
            if(word == "red" || word == "red;" || word == "red,") 
            {
                if(stoi(input_split[i-1]) > red_max)
                    red_max = stoi(input_split[i-1]);
                i += 2;
            }
            if(word == "blue" || word == "blue;" || word == "blue,") 
            {
                if(stoi(input_split[i-1]) > blue_max)
                    blue_max = stoi(input_split[i-1]);
                i += 2;
            }
            if(word == "green" || word == "green;" || word == "green,") 
            {
                if(stoi(input_split[i-1]) > green_max)
                    green_max = stoi(input_split[i-1]);
                i += 2;
            }
        }

        return red_max*green_max*blue_max;
    }

    int getValidGame(std::string input) 
    {
        std::cout<<"\nGetValidGame";
        int i = 1, game = 0, red_max = 12, green_max = 13, blue_max = 14;
        std::vector<std::string> input_split;
        input_split = split(input, ' ');

        while(i < input_split.size()) 
        {
            std::string word = input_split[i];
            std::cout<<"\n i = "<<i;
            std::cout<<"\n word = "<<word;
            if(i == 1) 
            {
                game = stoi(word.substr(0, word.size()-1));
                std::cout<<"\nGame = "<<game;
                i += 2;
            }
            if(word == "red" || word == "red;" || word == "red,") 
            {
                if(stoi(input_split[i-1]) > red_max)
                    return 0;
                i += 2;
            }
            if(word == "blue" || word == "blue;" || word == "blue,") 
            {
                if(stoi(input_split[i-1]) > blue_max)
                    return 0;
                i += 2;
            }
            if(word == "green" || word == "green;" || word == "green,") 
            {
                if(stoi(input_split[i-1]) > green_max)
                    return 0;
                i += 2;
            }
        }

        return game;
    }

    extern void Run() 
    {
        std::cout<<"\nStart";
        int result = 0;
        std::ifstream input( "day2_input.txt" );
        for( std::string line; getline( input, line ); ) 
        {
            std::cout<<"\nLine:  "<<line;
            result += getPower(line);
        }
        std::cout << "\nResult = "<<result << "\n";
    }

}