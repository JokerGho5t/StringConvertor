#include <iostream>
#include <locale>
#include <string>

using namespace std;

string convert(string const& text)
{
    string result = text;
    
    for (size_t i = 0; i < text.size(); i++)
    {
        result[i] = '(';
        for (size_t j = i - 1; j != SIZE_MAX; j--)
        {
            if (tolower(text[j]) == tolower(text[i]))
            {
                result[j] = ')';
                result[i] = ')';
                break;
            }
        }
    }

    return result;
}

void example(const string& text, const string& result)
{
    string converted = convert(text);

    cout << "Input: " << text << endl;
    cout << "Expected result: " << result << endl;
    cout << "Result: " << result << endl;
    cout << "---------------------------" << endl;
}

int main()
{  
    cout << "-==========Examples==========-" << endl;
    example("din", "(((");
    example("recede", "()()()");
    example("Success", ")())())");
    example("(( @", "))((");
    cout << "-============================-" << endl << endl;
    
    cout << "Enter \"exit\" to exit" << endl;
    
    while (true)
    {
        string str;

        cout << "Enter your line: ";
        getline(cin, str, '\n');
        cout << endl;
        
        if(str == "exit")
            break;
        
        cout << "Result: " << convert(str) << "\n-============================-" << endl;
    }

    return 0;
}