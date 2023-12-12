#include <iostream>
using namespace std;

#define DAY Day5

namespace Day1 { extern void Run(); }
namespace Day2 { extern void Run(); }
namespace Day3 { extern void Run(); }
namespace Day4 { extern void Run(); }
namespace Day5 { extern void Run(); }

int main()
{
    // cout << "Hello World" << endl;
    DAY::Run();

    // uncomment below line to stop cmd from exiting immediately in case of "externalConsole": true
    system("pause");
    return 0;
}
