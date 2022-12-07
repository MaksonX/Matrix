#ifndef MATRIX_H
#define MATRIX_H


#include <iostream>
#include <vector>
#include <cstdlib>
#include "Matrix.h"

void Matrix::eraseRC() noexcept {
    rows = 0;
    cols = 0;
}

void Matrix::dispRC() const {
    cout << "Rows: " << rows << "\tColumns: " << cols << endl;
}

void Matrix::randFill() noexcept {
    cout << "What is the max number for random number?: ";
    int num;
    cin >> num;
    srand(time(0));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            vec[i][j] = rand() % num;
        }
    }
}

void Matrix::matrLoop() {
    cout << "Input your wished operations\t";
    string str;
    while (str != "stop") {
        cin >> str;
        if (str == "get") {
            this->get();
        }
        else if (str == "create") {
            this->create();
        }
        else if (str == "erase") {
            this->erase();
        }
        else if (str == "checkOE") {
            this->checkOE();
        }
        else if (str == "dispRC") {
            this->dispRC();
        }
        else if (str == "randFill") {
            this->randFill();
        }
        else if (str == "eraseRC") {
            this->eraseRC();
        }
    }
}

void Matrix::create() {
    if (this->rows > 0 && this->cols > 0) {
        cout << "Input digits of matrix: ";
        for (int i = 0; i < this->rows; ++i) {
            vector<int> vv;
            for (int j = 0; j < this->cols; ++j) {
                int num;
                cin >> num;
                vv.push_back(num);
            }
            this->vec.push_back(vv);
        }
    }
    else if (this->rows == 0 && this->cols == 0) {
        cout << "How many rows and cols do you need for your Matrix?: ";
        cin >> this->rows >> this->cols;
        cout << "Input digits of matrix: ";
        for (int i = 0; i < this->rows; ++i) {
            vector<int> vv;
            for (int j = 0; j < this->cols; ++j) {
                int num;
                cin >> num;
                vv.push_back(num);
            }
            this->vec.push_back(vv);
        }
    }
}

void Matrix::get() const noexcept {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Matrix::check() const {
    if (this->rows <= 0 && this->cols <= 0) {
        throw 1;
    }
}

void Matrix::erase() noexcept {
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            this->vec[i][j] = 0;
        }
    }
}

void Matrix::checkOE() const noexcept {
    cout << "What do you want to check? O/E(Odd/Even): ";
    int count = 0;
    OE resultOE = OE::other;
    char res;
    cin >> res;
    if (res == static_cast<char>(OE::odd) || res == 'o') {
        resultOE = OE::odd;
    }
    else if (res == static_cast<char>(OE::even) || res == 'e') {
        resultOE = OE::even;
    }
    else if (res != static_cast<char>(OE::even) && res != static_cast<char>(OE::odd)) {
        resultOE = OE::other;
    }
    switch (resultOE) {
    case OE::even:
        count = 0;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                if (this->vec[i][j] % 2 == 0) {
                    ++count;
                }
            }
        }
        if (count == this->rows * this->cols) {
            cout << "Matrix is even.\n";
            break;
        }
        else {
            cout << "These members of Matrix are not even: " << (this->rows * this->cols - count) << '\n';
            break;
        }
        break;
    case OE::odd:
        count = 0;
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                if (this->vec[i][j] % 2 != 0) {
                    ++count;
                }
            }
        }
        if (count == this->rows * this->cols) {
            cout << "Matrix is odd.\n";
            break;
        }
        else {
            cout << "These members of Matrix are not odd: " << (this->rows * this->cols - count) << '\n';
            break;
        }
        break;
    case OE::other:
        cout << "Your input is invalid!" << endl;
        exit(1);
        break;
    }
}

inline Matrix Matrix::operator+(Matrix m) const noexcept {
    Matrix res(this->rows, this->cols);
    for (int i = 0; i < res.rows; ++i) {
        vector<int> temp;
        for (int j = 0; j < res.cols; ++j) {
            temp.push_back(this->vec[i][j] + m.vec[i][j]);
        }
        res.vec.push_back(temp);
    }
    return res;
}

inline Matrix Matrix::operator-(Matrix m) const noexcept {
    Matrix res(this->rows, this->cols);
    for (int i = 0; i < rows; ++i) {
        vector<int> temp;
        for (int j = 0; j < cols; ++j) {
            temp.push_back(this->vec[i][j] - m.vec[i][j]);
        }
        res.vec.push_back(temp);
    }
    return res;
}

inline void Matrix::operator=(Matrix obj) noexcept {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            this->vec[i][j] = obj.vec[i][j];
        }
    }
}

#endif
