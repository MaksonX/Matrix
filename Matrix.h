#pragma once
#include<string>
#include <vector>
#include <cstdlib>
using namespace std;
enum class OE { odd = 'O', even = 'E', other };
class Matrix {
private:
    int rows = 0, cols = 0;
    vector<vector<int>> vec;
public:
    Matrix(char) = delete;
    Matrix(string) = delete;
    Matrix() = default;
    explicit Matrix(int rows, int cols) :rows(rows), cols(cols) {
        check();
    }
    void create();
    void get() const noexcept;
    void check() const;
    void erase() noexcept;
    void checkOE() const noexcept;
    void matrLoop();
    void dispRC() const;
    void randFill() noexcept;
    void eraseRC() noexcept;
    Matrix operator+(Matrix m) const noexcept;
    Matrix operator-(Matrix m) const noexcept;
    void operator=(Matrix obj) noexcept;
    ~Matrix() {}
};