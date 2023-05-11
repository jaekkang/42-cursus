#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain Class constructor called" << std::endl;

    for (int i = 0; i < 100; ++i) {
        std::stringstream ss;
        ss << i;
        this->_ideas[i] = ss.str();
    }
}

Brain::Brain(const Brain &obj) {
    for (int i = 0; i < 100; ++i) {
        _ideas[i] = obj.getIdeas()[i];
    }
}

Brain &Brain::operator=(const Brain &obj) {
    if (this != &obj) {
        for (int i = 0; i < 100; ++i) {
            _ideas[i] = obj.getIdeas()[i];
        }
    }
    return (*this);
}

Brain::~Brain() { std::cout << "Brain Class destructor called" << std::endl; }

const std::string *Brain::getIdeas() const { return (this->_ideas); }

const std::string Brain::getIdea(int idx) const { return (this->_ideas[idx]); }

void Brain::setIdea(int idx, std::string value) { this->_ideas[idx] = value; }