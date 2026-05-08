#include <stdio.h>

struct access_rights {
    unsigned char execute :1; // 1비트 할당
    unsigned char write   :1; // 1비트 할당
    unsigned char read    :1; // 1비트 할당
};

union file_access_rights {
    unsigned int int_value;
    struct access_rights rights;
};

int main() {
    union file_access_rights some_file = {0};
    
    some_file.rights.read = 1;      // 001 (2진수)
    some_file.rights.write = 0;     // 000 (2진수)
    some_file.rights.execute = 1;   // 100 (2진수)
    
    // 비트들이 합쳐져서 하나의 숫자로 출력됩니다.
    printf("current mode: %u\n", some_file.int_value);
}
