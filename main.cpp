#include "record.h"
#include "handler.h"
#include "print.h"
using namespace std;

void app() {
    for(;;)
    system("cls"),
    print_help(),
    print_data(),
    get_and_handle_input();
}

signed main() {
    app();
}

