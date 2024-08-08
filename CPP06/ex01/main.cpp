#include "Serializer.hpp"

void printData(Data *data)
{
    std::cout << "c: " << data->c << std::endl;
    std::cout << "number: " << data->number << std::endl;
    std::cout << "emoji: " << data->emoji << std::endl;
    std::cout << "boolean: " << data->boolean << std::endl;
    std::cout << "f: " << data->f << std::endl;
    std::cout << "str: " << data->str << std::endl;
    std::cout << "l: " << data->l << std::endl;
}
int main()
{
    Data data;
    data.c = 'a';
    data.number = 42;
    data.emoji = "🤯";
    data.boolean = true;
    data.f = 3.14f;
    data.str = "Hello, World!";
    data.l = 1234567890L;

    std::cout << "\033[1;33mOriginal:\033[0m" << std::endl;
    printData(&data);
    uintptr_t serialized = Serializer::serialize(&data);

    std::cout << "\033[1;33mDeserialized:\033[0m" << std::endl;
    Data *deserialized = Serializer::deserialize(serialized);
    printData(deserialized);

    uintptr_t serialized2 = Serializer::serialize(deserialized);
    std::cout << "\033[1;33mDeserialized again:\033[0m" << std::endl;
    Data *deserialized2 = Serializer::deserialize(serialized2);
    printData(deserialized2);
   
    return 0;
}