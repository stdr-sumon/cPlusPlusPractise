#include "Integers.h"

Integers::Integers() {
    m_ptr = new int(0);
}

Integers::Integers(int value) {
    m_ptr = new int(value);
}

Integers::Integers(const Integers& obj) {
    m_ptr = new int(*obj.m_ptr);
}

void Integers::SetValue(int value) {
    *m_ptr = value;
}

int Integers::GetValue() const {
    return *m_ptr;
}

Integers::~Integers() {
    delete m_ptr;
}
