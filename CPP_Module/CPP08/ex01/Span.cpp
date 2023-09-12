#include "Span.hpp"

Span::Span(const size_t &size) : _size(size) {}

Span::Span(const Span &obj) {
    *this = obj;
    return;
}

Span &Span::operator=(const Span &obj) {
    if (this != &obj) {
        this->_v = obj._v;
        this->_size = obj._size;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int &n) {
    if (std::find(_v.begin(), _v.end(), n) != _v.end())
        throw ArgumentException::exception();
    if (_v.size() < _size) {
        _v.push_back(n);
    } else {
        throw FullException::exception();
    }
}

int Span::shortestSpan() {
    int ret = _v[0];
    std::vector<int> tmp = _v;
    if (tmp.size() < 2)
        throw std::exception();
    std::sort(tmp.begin(), tmp.end());
    for (size_t i = 0; i < tmp.size() - 1; i++) {
        if (i == 0)
            ret = tmp[i + 1] - tmp[i];
        else if (ret > tmp[i + 1] - tmp[i])
            ret = tmp[i + 1] - tmp[i];
    }

    return (ret);
}

int Span::longestSpan() {
    int ret = _v[0];
    std::vector<int> tmp = _v;

    if (tmp.size() < 2)
        throw std::exception();
    ret = *std::max_element(tmp.begin(), tmp.end()) -
          *std::min_element(tmp.begin(), tmp.end());
    return (ret);
}
