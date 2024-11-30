#include <iostream>


//2
struct Matrix {
    // ��������� ������ � �������.
    int** data_ = nullptr;
    // ���������� ��������
    size_t n_ = 0u;
    // ���������� �����
    size_t m_ = 0u;
};


void Construct(Matrix& out, size_t n, size_t m) { // ������� ����������� ������ ������� n x m
    out.m_ = m; // ��������� ���-�� �����
    out.n_ = n; // ��������� ���-�� �������� 
    out.data_ = new int* [n];  // �������� ������ ��� ������� ���������� �� ������
    for (int i = 0; i < n; ++i) {
        out.data_[i] = new int[m]; // �������� ������ ��� ������� ��������
        for (int j = 0; j < m; ++j) {
            out.data_[i][j] = 0; // ������� ����� 0
        }
    }
}


void Destruct(Matrix& in) { // ������������ ���������� ������ 
    for (int i = 0; i < in.n_; i++) // ����������� ������ ������ ������
        delete[] in.data_[i]; // ������� ������ �������� � ������
    delete[] in.data_;  // ������� ������ ���������� �� ������
}


Matrix Copy(const Matrix& matrix) { // �������� ����� ������� 
    Matrix res{};  // ������� ������ ������� ��� ���������� 
    res.n_ = matrix.n_;  // �������� ���-�� ��������
    res.m_ = matrix.m_;  // �������� ���-�� �����
    res.data_ = new int* [res.n_];   // �������� ������ ��� �����
    for (int i = 0; i < res.n_; ++i) { // ��� ������ ������
        res.data_[i] = new int[res.m_];  // �������� ������ ��� �������� 
        for (int j = 0; j < res.m_; ++j) {
            res.data_[i][j] = matrix.data_[i][j];  // �������� ������� �� �������� �������
        }
    }
    return res;
}

Matrix Add(const Matrix& a, const Matrix& b) { // ����� ���� ������
    Matrix res{}; // ������ ������� ��� ����������
    if ((a.n_ != b.n_) || (a.m_ != b.m_)) // ��������� �������, ���� �� ���������, �� ���������� ������ ������
        return res;
    res.n_ = a.n_; // ���-�� �������� ��������� � ������ �������� 
    res.m_ = a.m_; // ���-�� ����� ��������� � ������ ��������
    res.data_ = new int* [res.n_]; // �������� ������ ��� �����
    for (int i = 0; i < res.n_; ++i) { 
        res.data_[i] = new int[res.m_];
        for (int j = 0; j < res.m_; ++j) {
            res.data_[i][j] = a.data_[i][j] + b.data_[i][j];
        }
    }
    return res;

}

Matrix Sub(const Matrix& a, const Matrix& b) { // �������� ���� ������
    Matrix res{};
    if ((a.n_ != b.n_) || (a.m_ != b.m_))
        return res;
    res.n_ = a.n_;
    res.m_ = a.m_;
    res.data_ = new int* [res.n_];
    for (int i = 0; i < res.n_; ++i) {
        res.data_[i] = new int[res.m_];
        for (int j = 0; j < res.m_; ++j) {
            res.data_[i][j] = a.data_[i][j] - b.data_[i][j];
        }
    }
    return res;
}


Matrix Mult(const Matrix& a, const Matrix& b) { // ������������ ���� ������
    Matrix res{};
    if (a.m_ != b.n_)
        return res;
    res.n_ = a.n_;
    res.m_ = b.m_;
    res.data_ = new int* [res.n_];
    for (int i = 0; i < res.n_; ++i) {
        res.data_[i] = new int[res.m_];
        for (int j = 0; j < res.m_; ++j) {
            res.data_[i][j] = 0;
            for (int k = 0; k < a.m_; k++) {
                res.data_[i][j] += a.data_[i][k] * b.data_[k][j];
            }
        }
    }
    return res;
}


void Transposition(Matrix& matrix) { // ���������������� �������
    Matrix res{};
    res.n_ = matrix.m_;
    res.m_ = matrix.n_;
    res.data_ = new int* [res.n_];
    for (int i = 0; i < res.n_; i++) {
        res.data_[i] = new int[res.m_];
        for (int j = 0; j < res.m_; j++) {
            res.data_[i][j] = matrix.data_[j][i];
        }
    }
    matrix.n_ = res.n_;
    matrix.m_ = res.m_;
    matrix.data_ = res.data_;
}


bool operator==(const Matrix& a, const Matrix& b) { // ��������� ���� ������.
    if ((a.n_ != b.n_) || (a.m_ != b.m_))
        return false;
    for (int i = 0; i < a.n_; ++i) {
        for (int j = 0; j < a.m_; ++j) {
            if (a.data_[i][j] != b.data_[i][j]) {
                return false;
            }
        }
    }
    return true;
}






int main() {
    Matrix mat1;
    Construct(mat1, 5, 5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j)
            mat1.data_[i][j] = 5;
    }

    Matrix mat2;
    Construct(mat2, 4, 6);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 6; ++j) {
            mat2.data_[i][j] = i + j;
        }
    }

    Matrix mat3 = Add(mat1, Copy(mat1));
    Matrix mat5 = Sub(mat3, mat1);
    std::cout << (mat1 == mat5) << std::endl;
    std::cout << (mat1 == mat2) << std::endl;

    Matrix mat4 = Copy(mat1);
    Transposition(mat2);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << mat2.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    Matrix mat6 = Mult(mat1, mat5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << mat6.data_[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Destruct(mat1);
    Destruct(mat2);
    Destruct(mat3);
    Destruct(mat4);
    Destruct(mat5);
    Destruct(mat6);
    return 0;
}
