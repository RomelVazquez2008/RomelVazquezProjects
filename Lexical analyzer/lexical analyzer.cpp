#include<iostream>
#include<fstream>

using namespace std;

/**
 * Print blank spaces.
 *
 * Print some spaces according to number of symbols in the line.
 *
 * @param int n_size
 * @return
 */
void print_blank_spaces(int n_size){
    int iterator=30;
    iterator=iterator-n_size;
    for(int i=0;i<iterator;i++){
        cout<<" ";
    }
}

/**
 * lower case.
 *
 * Using the ASCII language, identify if the given token is a lower case letter.
 *
 * @param int token
 * @return bool
 */
bool lower_case(int token){
    if ((token>=97) && (token<=122)){
        return true;
    }
    else{
        return false;
    }
}

/**
 * capital letter.
 *
 * Using the ASCII language, identify if the given token is a capital letter.
 *
 * @param int token
 * @return bool
 */
bool capital_letter(int token){
    if ((token>=65) && (token<=90)){
        return true;
    }
    else{
        return false;
    }
}

/**
 * digit number.
 *
 * Using the ASCII language, identify if the given token is a digit number.
 *
 * @param int token
 * @return bool
 */
bool digit_number(int token){
    if ((token>=48) && (token<=57)){
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify variable.
 *
 * print and return true if the given token is variable type.
 *
 * @param int token, string line, int& iterator
 * @return bool
 */
bool identify_variable(int token, string line, int& iterator){
    int i;
    int for_counter=0;
    if ((capital_letter(token)==true) || (lower_case(token)==true)){
        for (i=iterator;i<line.size();i++){
            for_counter++;
            if ((capital_letter(line[i])==true) || (lower_case(line[i])==true)
            || (line[i]==95) || (digit_number(line[i])==true)){
                cout<<line[i];
            }
            else{
                break;
            }
        }
        iterator=i-1;
        print_blank_spaces(for_counter);
        cout<<"----->           Variable"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify positive or negative number.
 *
 * return true if the given token is a positive or a negative number.
 *
 * @param int token, string line, int iterator
 * @return bool
 */
bool identify_positive_or_negative_number(int token, string line, int iterator){
    if ((token==45) || (token==46) || (digit_number(token)==true)){
        if((token==46) && (line[iterator+1]=='.')){ //not valid number [e.g. 0..00]
            return false;
        }
        else if((digit_number(line[iterator+1])==true)
        || (line[iterator+1]=='.')){
        //identify that for the next element can be either a '.' or a number
            return true;

        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

/**
 * identify a number.
 *
 * return true if the given number has a decimal part and also a scientific notation.
 *
 * @param int token, string line, int iterator
 * @return bool
 */
bool identify_a_number(int token, string line, int iterator){
    int i;
    bool decimal=false;
    if(identify_positive_or_negative_number(token,line,iterator)==true){
        for(i=iterator;i<line.size();i++){
            if((line[i]=='-') || (digit_number(line[i])==true)
            || (line[i]=='.')){
                if(line[i]=='.'){
                    decimal=true;
                }
            }
            else if((line[i]=='e') || (line[i]=='E')){
                if((identify_positive_or_negative_number(line[i],line,iterator)==true)
                && (decimal==true)){
                    return true;
                }
            }
            else{
                break;
            }
        }
        if(decimal==true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

/**
 * identify float.
 *
 * print and return true if the given token is a float type.
 *
 * @param int token, string line, int& iterator
 * @return bool
 */

bool identify_float(int token, string line, int& iterator){
    int i, for_counter=0;
    if (identify_a_number(token,line,iterator)==true){
        for(i=iterator;i<line.size();i++){
            for_counter++;
            if ((digit_number(line[i])==true) || (line[i]=='.') ||
            (line[i]=='e') || (line[i]=='E') || (line[i]=='-')){
                cout<<line[i];
            }
            else{
                break;
            }
        }
        iterator=i-1;
        print_blank_spaces(for_counter);
        cout<<"----->           Float"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify comment.
 *
 * print and return true if the given token is a comment type.
 *
 * @param int token, string line, int& iterator
 * @return bool
 */
bool identify_comment(int token, string line, int& iterator){
    int i, for_counter=0;
    if(token == 47 && line[iterator+1] == 47){
        for (i=iterator;i<line.size();i++){
            for_counter++;
            cout<<line[i];

        }
        iterator=i-1;
        print_blank_spaces(for_counter);
        cout<<"----->           Comment"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify integer.
 *
 * print and return true if the given token is an integer type.
 *
 * @param int token, string line, int& iterator
 * @return bool
 */

bool identify_integer(int token, string line, int& iterator){
    int i, for_counter=0;
    if (digit_number(token)==true){
        for (i=iterator;i<line.size();i++){
            for_counter++;
            if (digit_number(line[i])==true){
                cout<<line[i];
            }
            else{
                break;
            }
        }
        iterator=i-1;
        print_blank_spaces(for_counter);
        cout<<"----->           Integer"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify special symbol.
 *
 * print and return true if the given token is a Left parenthesis or a Right parenthesis.
 *
 * @param int token
 * @return bool
 */
bool identify_special_symbol(int token){
    if (token == 40){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Left parenthesis"<<endl;
        return true;
    }
    else if (token == 41){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Right parenthesis"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * identify operator.
 *
 * print and return true if the given token is an operator (=,+,-.*,/,^).
 *
 * @param int token
 * @return bool
 */
bool identify_operator(int token){
    if (token == 61){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Assigment"<<endl;
        return true;
    }
    else if (token == 43){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Add"<<endl;
        return true;
    }
    else if (token == 45){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Substraction"<<endl;
        return true;
    }
    else if (token == 42){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Multiplication"<<endl;
        return true;
    }
    else if (token == 47){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Division"<<endl;
        return true;
    }
    else if (token == 94){
        cout<<char(token);
        print_blank_spaces(1);
        cout<<"----->           Power"<<endl;
        return true;
    }
    else{
        return false;
    }
}

/**
 * ignore blank space.
 *
 * return true if the given token is a blank space.
 *
 * @param int token
 * @return bool
 */
bool ignore_blank_space(int token){
    if (token == 32){
        return true;
    }
    else{
        return false;
    }
}

/**
 * not a valid token.
 *
 * print an error message if the given token is not a valid input.
 *
 * @param int token
 * @return
 */
void not_valid_token(int token){
    cout<<"ERROR: "<<char(token);
    print_blank_spaces(8);
    cout<<"---->           Not a valid input"<<endl;
}

/**
 * identify token.
 *
 * iterates in other functions to determinate if the token is a valid type.
 *
 * @param char token, string line, int& iterator
 * @return
 */
void identify_token(char token, string line, int& iterator){
    if(identify_comment(token, line, iterator)==true){
        return;
    }
    else if(identify_variable(token, line, iterator)==true){
        return;
    }
    else if(identify_float(token, line, iterator)==true){
        return;
    }
    else if (identify_integer(token, line, iterator)==true){
        return;
    }
    else if(identify_operator(token)==true){
        return;
    }
    else if(identify_special_symbol(token)==true){
        return;
    }
    else if(ignore_blank_space(token)==true){
        return;
    }
    else{
        not_valid_token(token);
        return;
    }
}

/**
 * read line.
 *
 * read all lines of the txt file.
 *
 * @param string line
 * @return
 */
void read_line(string line){
    for(int i=0; i<line.size() ;i++){
        identify_token(line[i], line, i);
    }
}

/**
 * valid empty file.
 *
 * return true and an error message if the txt is empty.
 *
 * @param string my_file
 * @return bool
 */
bool validate_empty_file (string my_file){
    ifstream txt;
    string line;
    double bytes=0;
    txt.open(my_file);
    while (!txt.eof()){
        getline(txt,line);
        for (int i=0; i<line.size() ;i++){
            bytes++;
            break;
        }
        if (bytes>0){
            break;
        }
    }
    if (bytes==0){
        cout<<"ERROR: txt file empty"<<endl;
        txt.close();
        return (true);
    }
    else {
        txt.close();
        return (false);
    }
}

/**
 * validate open file.
 *
 * return false and an error message if the txt is empty.
 *
 * @param string my_file
 * @return bool
 */
bool validate_open_file (string my_file){
    ifstream txt;
    txt.open(my_file);
    if (txt.fail()){
        cout<<"ERROR: txt file cannot be opened"<<endl;
        txt.close();
        return (false);
    }
    else {
        txt.close();
        return (true);
    }

}

/**
 * validate file.
 *
 * call other functions to decide if the txt file is valid.
 *
 * @param string my_file
 * @return bool
 */
bool validate_file (string my_file){
    if (validate_open_file(my_file)==false){
        return (false);
    }

    if (validate_empty_file(my_file)==true){
        return (false);
    }
    return (true);
}

/**
 * lexerAritmetico.
 *
 * the function open the txt file in order to read it.
 *
 * @param string my_file
 * @return
 */
void lexerAritmetico(string my_file){
    if (validate_file(my_file)==false){
        return;
    }

    ifstream txt;
    string line;
    txt.open(my_file);
    cout<<"TOKEN";
    print_blank_spaces(-15);
    cout<<"TYPE"<<endl;
    while (!txt.eof()){
        getline(txt,line);
        read_line(line);
    }

    txt.close();
    return;
}

int main(){
    string my_file;
    cout<<"Type the name of a txt file: ";
    cin>>my_file;
    lexerAritmetico(my_file);
    return(0);
}
