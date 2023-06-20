#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
    Data *a = new Data(123);
    Serializer defaultData(a);
    uintptr_t tmp;

    std::cout << std::endl;

    tmp = defaultData.serialize(&defaultData);
    std::cout << std::endl;

    defaultData.deserialize(tmp);
    std::cout << std::endl;

    std::cout << defaultData.getValue()->_value << std::endl;
}
