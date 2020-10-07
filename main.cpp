#include <string>
#include <iostream>
#include <algorithm>
#include <tclap/CmdLine.h>
using namespace std;
int main(int argc, char **argv)
{
    try
    {
        TCLAP::CmdLine cmd("Een testprogramma voor tclap", ' ', "0.9");
        TCLAP::ValueArg<string> nameArg("n", "name", "Name to print", false, "homer", "string");
        cmd.add(nameArg);
        TCLAP::SwitchArg reverseSwitch("r", "reverse", "Print name backwards", cmd, false);
        cmd.parse(argc, argv);
        string name = nameArg.getValue();
        bool reverseName = reverseSwitch.getValue();
        // Do what you intend.
        if (reverseName)
        {
            reverse(name.begin(), name.end());
            cout << "My name (spelled backwards) is: " << name << endl;
        }
        else
            cout << "My name is: " << name << endl;
    }
    catch (TCLAP::ArgException &e) // catch any exceptions
    {
        cerr << "error: " << e.error() << " for arg " << e.argId() << endl;
    }
}
//test add