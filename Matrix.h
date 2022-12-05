#pragma once
#include<iostream>
#include <vector>
using namespace std;
enum OE{ odd = 'O', even = 'E' };
class Matrix {
private:
    int rows = 0, cols = 0;
    vector<vector<int>> vec;
public:
    explicit Matrix() { this->rows = this->cols = 0; }
    explicit Matrix(int rows, int cols) :rows(rows), cols(cols) {
        check();
    }
    void create() {
        if ((this->rows & this->cols) == 0) {
            cout << "Haw many rows and cols of your Matrix do you want?: ";
            cin >> this->rows >> this->cols;
        }
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
    inline void get() const noexcept {
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                cout << vec[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    void check() const noexcept {
        if ((this->rows & this->cols) < 0) {
            terminate;
        }
    }
    void erase() {
        for (int i = 0; i < this->rows; ++i) {
            for (int j = 0; j < this->cols; ++j) {
                this->vec[i][j] = 0;
            }
        }
    }
    void checkOE() const {
        cout << "What do you want to check? O/E(Odd/Even): ";
        int count = 0;
        OE r;
        char res;
        cin >> res;
        (static_cast<char>(OE::odd) == res ? r = OE::odd : r = OE::even);
        switch (r) {
        case OE::odd:
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
        case OE::even:
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
        default:
            cout << "You didn't input valid char!" << endl;
        }

    }
    inline Matrix operator+(Matrix m) const {
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
    inline Matrix operator-(Matrix m) const {
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
    inline void operator=(Matrix obj) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                this->vec[i][j] = obj.vec[i][j];
            }
        }
    }
    ~Matrix() {}
};
