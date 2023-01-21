#include <iostream>
#include <optional>

std::optional<float> divide(float a, float b) {
    if (b!=0.f) return a/b;
    return {};
}

int main() {
    std::optional<float> result = divide(25.0, 0);
    std::cout << divide(15.0, 2.0).value_or(100.0) << std::endl;
    std::cout << result.value_or(100.0) << std::endl;
}