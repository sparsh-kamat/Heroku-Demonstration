#include <iostream>
#include <string>

using namespace std;

void nrz_encode(const string &data)
{
    string encoded_data1 = "";
    string encoded_data2 = "";
    int length = data.length();
    cout << endl
         << "NRZ encoded data: " << endl
         << endl;
    ;
    for (int i = 0; i < length; i++)
    {
        // cout<<data[i]<<endl;
        char bit = data[i];
        if (bit == '0')
        {
            encoded_data1 += "   "; // Representing '0' as 'LOW HIGH'
            encoded_data2 += "___"; // Representing '0' as '_'
        }
        else if (bit == '1')
        {
            encoded_data1 += "___"; // Representing '1' as 'HIGH LOW'
            encoded_data2 += "   "; // Representing '1' as '|'
        }
        // else
        //     encoded_data2 += bit; // Handling any other characters as they are
        if (i != length - 1)
        {
            encoded_data2 += "|"; // Adding delimiter (|) between bits (except for the last bit
            encoded_data1 += "|"; // Adding delimiter (|) between bits (except for the last bit
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (i == 0)
        {
            cout.width(2);
        }
        else
            cout.width(4);
        cout << data[i];
    }
    cout << endl
         << encoded_data1 << endl;
    cout << encoded_data2 << endl;
    for (int i = 0; i < length; i++)
    {
        if (i != length - 1)
            cout << "   |";
    }
    cout << endl;
}

int main()
{
    string input_data;
    cout << "Enter binary data to encode (consisting of 0s and 1s): ";
    getline(cin, input_data);
    nrz_encode(input_data);
    return 0;
}
