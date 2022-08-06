#include <iostream>

char letter_shift(char chr, int shift){
    shift=(shift>0?shift%26:26+shift%26);
    if (chr >= 'a' && chr <= 'z') {
        int chrn=(int)chr;
        chrn -= 'a';
        chrn+=shift;
        chrn%=26;
        chrn += 'a';
        return (char)chrn;
    } else if (chr >= 'A' && chr <= 'Z') {
        int chrn=(int)chr;
        chrn -= 'A';
        chrn+=shift;
        chrn%=26;
        chrn += 'A';
        return (char)chrn;
    } else
        return chr;
}

std::string caesar_encrypt(std::string str, int shift){
    int chr;
    bool cap,letter;
    for (int i=0;i<str.length();i++){
        str[i]= letter_shift(str[i],shift);
    }
    return str;
}
std::string caesar_decrypt(std::string str, int shift){
    return caesar_encrypt(str,-shift);
}
void test(std::string str, int key){
    std::cout <<"======\n" <<"Key: " << key << " String: " << str << std::endl<<std::endl;
    std::cout << "Encrypted: " << caesar_encrypt(str,key)<<std::endl << std::endl;
}

int main() {
    std::cout << "" << std::endl;
    std::string str;
    std::getline(std::cin,str);
    test(str,2);
    test("The quick brown fox jumps over the lazy dog",5);
    test("Lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut labore et dolore magna aliqua Ut enim ad minim veniam quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur Excepteur sint occaecat cupidatat non proident sunt in culpa qui officia deserunt mollit anim id est laborum", -1);
    return 0;
}


