#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    const string HEADER("--------------Text analyser--------------");
    string input_string;

    std::cout
        << HEADER << "\n"
        << "Please write some sentences\nsubmit an empty line, if you're done."
        << endl;

    int sentence_count=0, word_count=0, whitespace_count=0;

    while(getline(cin, input_string)){
        // std::cout << "len: " << input_string.length() << "\n\0"; // debug: mirror input length
        // std::cout << "is: " << input_string << endl; // debug: mirror input
        if (input_string.length()==0){
            break;
        }
        ++sentence_count;
        char input_char;
        for (long long unsigned int i=0; i<input_string.length(); i++){
            input_char = input_string[i];
            // std::cout << tempstring << endl;
            switch (input_char){
                case ' ': // space
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\t': // horizontal tab
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\r': // carriage return
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\f': // form feed
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\v': // vertical tab
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\n': // newline
                    ++whitespace_count;
                    // ++word_count;
                    break;
                case '\0': // end of text
                    break;
                default:
                    break;

            } // end of switch
            continue;
        }// end of for
    } // end of while
    word_count = whitespace_count + 1;
    int col1_width = 10, col2_width = 5, padding = 1;
    string first_pad(padding, ' '), pad = first_pad + '|' + first_pad;
    std::cout
        << first_pad << setw(col1_width) << "" << pad << setw(col2_width) << "count" << first_pad << "\n"
        << string(first_pad.length() * 2 + col1_width + col2_width + pad.length(), '-') << first_pad << "\n"
        << first_pad << setw(col1_width) << "sentence" << pad << setw(col2_width) << sentence_count << first_pad << "\n"
        << first_pad << setw(col1_width) << "word" << pad << setw(col2_width) << word_count << first_pad << "\n"
        << first_pad << setw(col1_width) << "whitespace" << pad << setw(col2_width) << whitespace_count << first_pad << "\n\0";

    return 0;
} // end of main

