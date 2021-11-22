#include "matrix.h"
#include "exceptions.h"
#include <cmath>

namespace prep {
	Matrix::Matrix(size_t rows, size_t cols) {
		Rows = rows;
		Cols = cols;
		matrix.resize(Rows);
		for (size_t i = 0; i < Rows; i++) {
			matrix[i].resize(Cols);
		}
	}
	Matrix::Matrix(std::istream& is) {
		is >> Rows;
		is >> Cols;
		matrix.resize(Rows);
		for (size_t k = 0; k < Rows; k++) {
			matrix[k].resize(Cols);
		}
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				is >> matrix[i][j];
			}
		}		
	}
	size_t Matrix::getRows() const { return Rows; }
	size_t Matrix::getCols() const { return Cols; }

	double Matrix::operator()(size_t i, size_t j) const {
   		return matrix[i][j];
  	}
	double& Matrix::operator()(size_t i, size_t j) {
		double& s = matrix[i][j];
   		return s;
  	}

	bool Matrix::operator==(const Matrix& rhs) const {
		if (Rows != rhs.Rows || Cols != rhs.Cols) {
			// DimensionMismatch(rhs.matrix);
			return (false);
		}
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				if(fabs(matrix[i][j] - rhs.matrix[i][j]) > 1e-07) {
					return (false);
				}
			}
		}
		return (true);
	}
	bool Matrix::operator!=(const Matrix& rhs) const {
		if (Rows != rhs.Rows || Cols != rhs.Cols) {
			//  DimensionMismatch(matrix, rhs);
				return (false);
		}
		bool i = operator==(rhs); 
		return !i;
	}

	Matrix Matrix::operator+(const Matrix& rhs) const {
		if (Rows != rhs.Rows || Cols != rhs.Cols) {
			//  DimensionMismatch(matrix, rhs);
		}
		Matrix new_matrix(Rows, Cols);
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				new_matrix.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
			}
		}
		return Matrix(new_matrix);
	}

	Matrix Matrix::operator-(const Matrix& rhs) const {
		if (Rows != rhs.Rows || Cols != rhs.Cols) {
			//  DimensionMismatch(matrix, rhs);
		}
		Matrix new_matrix(Rows, Cols);
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				new_matrix.matrix[i][j] = matrix[i][j] - rhs.matrix[i][j];
			}
		}
		return Matrix(new_matrix);
	}

	Matrix Matrix::operator*(const Matrix& rhs) const {
		if (Rows != rhs.Rows || Cols != rhs.Cols) {
			// DimensionMismatch(matrix, rhs);
		}
		Matrix new_matrix(Rows, Cols);
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				double sum = 0;
				size_t num = 0;
				while (num != Cols) {
					sum += matrix[i][num]*rhs.matrix[num][j];
					num += 1;
				}
				new_matrix.matrix[i][j] = sum;
			}
		}
		return Matrix(new_matrix);
	}

	Matrix Matrix::operator*(double val) const {
		Matrix new_matrix(Rows, Cols);
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				new_matrix.matrix[i][j] = matrix[i][j]*val;
			}
		}
		return Matrix(new_matrix);
	}

	Matrix operator*(double val, const Matrix& matrix) {
		Matrix new_matrix(matrix.Rows, matrix.Cols);
		for (size_t i = 0; i < matrix.Rows; i++) {
			for (size_t j = 0; j < matrix.Cols; j++) {
				new_matrix.matrix[i][j] = val*matrix.matrix[i][j];
			}
		}
		return Matrix(new_matrix);
	}

	std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
		for (size_t i = 0; i < matrix.Rows; i++) {
			for (size_t j = 0; j < matrix.Cols; j++) {
				os << matrix.matrix[i][j];
				if (j != matrix.Cols-1) {
					os << ' ';
				}
			}
			os << '\n';
		}
		return os;
	}

	Matrix Matrix::transp() const {
		Matrix new_matrix(Rows, Cols);
		for (size_t i = 0; i < Rows; i++) {
			for (size_t j = 0; j < Cols; j++) {
				new_matrix.matrix[i][j] = matrix[j][i];
			}
		}
		return Matrix(new_matrix);
	}

	Matrix Matrix::adj() const {
		Matrix new_matrix(Rows, Cols);
		return Matrix(new_matrix);
	}
	double Matrix::det() const {
		Matrix new_matrix(Rows, Cols);
		return 1.2;
	}
	Matrix Matrix::inv() const {
		Matrix new_matrix(Rows, Cols);
		return Matrix(new_matrix);
	}
}
