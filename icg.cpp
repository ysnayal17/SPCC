#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

char input[20];
char op, op1, op2;

char temp[5] = {'v', 'w', 'x', 'y', 'z'};
int temp_pointer = 0;

void scan()
{
    ofstream fout;
    fout.open("icg.txt");
    for (int i = 0; i < strlen(input); i++)
    {
        if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
        {
            op = input[i];
            op1 = input[i - 1];
            op2 = input[i + 1];

            cout << "\n"
                 << temp[temp_pointer] << "=" << op1 << op << op2 << "\n";
            fout << temp[temp_pointer] << "=" << op1 << op << op2 << "\n";
            input[i + 1] = temp[temp_pointer++];
        }
    }
    fout.close();
}

int main()
{
    cout << "\nEnter expression:";
    cin >> input;
    input[strlen(input) - 1] = '\0';
    scan();
    ifstream fin;
    fin.open("icg.txt");
    string line;
    cout << "op\targ1\targ2\tresult";
    while (fin)
    {
        getline(fin, line);
        cout << line << endl;
        cout << line.at(3) << "\t" << line.at(2) << "\t" + line.at(4) << "\t" << line.at(0);
    }
    fin.close();
    return 0;
}