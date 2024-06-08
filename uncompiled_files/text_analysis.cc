//------------------------------------------------------------------------------
#include <iostream> // cin, cout
#include <iomanip>  // setw
#include <vector>   // vector
#include <sstream>  // stringstream
#include <string>   // getline
#include <cctype>   // isspace, isdigit, isalpha, ispunct

void print_table(
    std::vector<std::string> categories, 
    std::vector<float> values,
    std::vector<std::string> columns,
    int padding = 2)
{
    long long unsigned int _col2_width = columns[1].length();
    long long unsigned int _col1_width = columns[0].length();
    
    // chars for lines
    char box_h = 45, box_v = 124, box_x = 43;

    std::string _first_pad(padding, ' ');
    std::string _pad = _first_pad + box_v + _first_pad;

    // calc max len columns
    // start with column names
    _col1_width = columns[0].length();
    _col2_width = columns[1].length();

    // walk both vectors concurrently to check length of all values in both cols
    for (unsigned long long int i=0; i < categories.size(); i++){

        // get the longest string of either the column name or category string
        if (_col1_width < categories[i].length()){
            _col1_width = categories[i].length();
        } // end if

        // get the longest string representation of either 2nd column name or
        // value as the values are floats of unknown decimals, a stringstream is
        // used to measure the length of each float
        std::stringstream _sstream;
        _sstream << values[i] << std::endl;
        unsigned long long int _value_length = _sstream.str().length();

        if (_col2_width < _value_length) {
            _col2_width = _value_length;
            // std::cout << "debug col2 width: " << _col2_width << std::endl;
        } // end if
    } // end for col1

    // needed width for col1 and 2 is now known, table can be built now
    // columns
    std::cout << _first_pad << std::setw(_col1_width) << std::left << columns[0]
        << _pad << std::setw(_col2_width) << std::right << columns[1]
        << _first_pad << "\n";
    
    // linerow
    int len1 = _first_pad.length() * 2 + _col1_width;
    int len2 = _first_pad.length() * 2 + _col2_width;
    std::cout << std::string(len1, box_h) << box_x << std::string(len2, box_h)
        << "\n";
    
    // data
    for (unsigned long long int i=0; i < categories.size(); i++){
        std::cout << _first_pad << std::setw(_col1_width) << std::left
            << categories[i] << _pad << std::setw(_col2_width) << std::right
            << values[i] << _first_pad
        << "\n";
    } // end for categories.size()
} // end print_table

int main()
{
    const std::string HEADER("------------------------- Text analyser -------------------------");
    std::string input_string;

    std::cout
        << HEADER << "\n"
        << "Please write some sentences and submit an empty line to proceed."
        << std::endl;

    int sentence_count=0, word_count=0, whitespace_count=0, digit_count=0,
        punct_count=0, alpha_count=0;

    while(std::getline(std::cin, input_string))
    {
        // // debug: mirror input length
        // std::cout << "len: " << input_string.length() << "\n\0";
        
        // // debug: mirror input
        // std::cout << "is: " << input_string << endl;
        if (input_string.length()==0)
        {
            break;
        }
        char input_char;
        for (long long unsigned int i=0; i<input_string.length(); i++)
        {
            input_char = input_string[i];
            if(isspace(input_char)){++whitespace_count;}
            if(isdigit(input_char)){++digit_count;}
            if(isalpha(input_char)){++alpha_count;}
            if(ispunct(input_char))
            {
                switch (input_char)
                {
                    case '.':
                        ++sentence_count;
                        ++punct_count;
                        break;
                    case '!':
                        ++sentence_count;
                        ++punct_count;
                        break;
                    case '?':
                        ++sentence_count;
                        ++punct_count;
                        break;
                    default:
                        ++punct_count;
                        break;
                } // end of switch
            } // end if ispunct
            continue;
        }// end of for
    } // end of while
    word_count = whitespace_count + sentence_count;

    std::vector<std::string> categories {
        "sentence count",
        "word count",
        "letter count",
        "numerical count",
        "whitespace count",
        "punctuation count",
        "mean letters per word"
        };

    std::vector<float> values {
        (float)sentence_count,
        (float)word_count,
        (float)alpha_count,
        (float)digit_count,
        (float)whitespace_count,
        (float)punct_count,
        (float)alpha_count/(float)word_count
        };

    std::vector<std::string> colnames {
        "category",
        "value"
        };

    int padding = 2;

    print_table(categories, values, colnames, padding);

    return 0;
} // end of main


