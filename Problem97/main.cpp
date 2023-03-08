#include <string>
#include <iostream>

std::string PowerOf2(int power)
{
    std::string last_ten_digits = "1";
    std::string tmp_string = "";
    int carry = 0;
    int value = 0;

    int length = 0;

    std::string::size_type sz;

    for(int i = 0; i < power; i++)
    {
        length = last_ten_digits.length();

        if(length < 12)
        {
            for(int j = length-1; j >= 0; j--)
            {
                value = (last_ten_digits[j]-48) * 2 + carry;
                carry = value / 10;
                value = value % 10;
                tmp_string.insert(0,std::to_string(value));
            }
        }
        else // only interested in last 12 digits
        {
            for(int j = length-1; j > length-11; j--)
            {
                value = (last_ten_digits[j]-48) * 2 + carry;
                carry = value / 10;
                value = value % 10;
                tmp_string.insert(0,std::to_string(value));
            }
        }

        if (carry != 0)
            tmp_string.insert(0, std::to_string(carry));

        carry = 0;
        last_ten_digits = tmp_string;
        tmp_string = "";
    }
    return last_ten_digits;
}

int main(void)
{
    int multiplier = 28433;
    int power = 7830457;
    //int power = 200;

    std::string exponent_value = PowerOf2(power);

    std::cout << "2^2 = " << PowerOf2(2) << std::endl;
    std::cout << "2^3 = " << PowerOf2(3) << std::endl;
    std::cout << "2^4 = " << PowerOf2(4) << std::endl;
    std::cout << "2^5 = " << PowerOf2(5) << std::endl;
    std::cout << "2^6 = " << PowerOf2(6) << std::endl;

    std::cout << "2^" << power << " = " << exponent_value << std::endl;

    long long prime = ((long long) multiplier * std::stoll(exponent_value, nullptr, 10) + 1);

    std::cout << "Prime is " << prime << std::endl;
    std::cout << "stoll is " << std::stoll(exponent_value, nullptr, 10) << std::endl;

    return 0;
}