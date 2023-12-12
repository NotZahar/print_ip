#include <print_ip.h>

#define ENDL std::cout << '\n';

int main(int, char**) {
    using namespace print;

    print_ip( int8_t{-1} ); ENDL // 255
    print_ip( int16_t{0} ); ENDL // 0.0
    print_ip( int32_t{2130706433} ); ENDL // 127.0.0.1
    print_ip( int64_t{8875824491850138409} ); ENDL // 123.45.67.89.101.112.131.41
    print_ip( std::string{"Hello, World!"} ); ENDL // Hello, World!
    print_ip( std::vector<int>{100, 200, 300, 400} ); ENDL // 100.200.300.400
    print_ip( std::list<short>{400, 300, 200, 100} ); ENDL // 400.300.200.100
    
    return 0;
}
