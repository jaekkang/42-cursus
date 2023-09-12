#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "longest span value : " << sp.longestSpan() << std::endl;
        std::cout << "shortest span value : " << sp.shortestSpan() << std::endl;
    } catch (Span::FullException &e) {
        std::cout << e.what() << std::endl;
    } catch (Span::ArgumentException &e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        std::cout << "Unknown exception" << std::endl;
    }
    return 0;
}