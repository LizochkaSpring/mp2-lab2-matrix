#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	//может создать матрицу с положительной длиной
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	//не удается создать слишком большую матрицу
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	//выдает при создании матрицы с отрицательной длиной
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	//может создать скопированную матрицу
  TDynamicMatrix<int> m(5);
  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	//скопированная матрица равна исходной
	TDynamicMatrix<int> v(11);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			v[i][j] = 111;
		}
	}
	TDynamicMatrix<int> k(v);
	EXPECT_EQ(v, k);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	//скопированная матрица имеет свою собственную память
	TDynamicMatrix<int> v(11);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			v[i][j] = 111;
		}
	}
	TDynamicMatrix<int> k(v);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			k[i][j] = 0;
		}
	}
	EXPECT_NE(v, k);
}

TEST(TDynamicMatrix, can_get_size)
{
	//может получить размер
	TDynamicMatrix<int> v(11);
	EXPECT_EQ(11, v.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	//может устанавливать и получать элемент
	TDynamicMatrix<int> v(11);
	v[7][7] = 7;
	EXPECT_EQ(7, v[7][7]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	//выдает при установке элемента с отрицательным индексом
	TDynamicMatrix<int> v(11);
	ASSERT_ANY_THROW(v.at(-1, -1) = 7);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	//выдает ошибку, когда задан элемент со слишком большим индексом
	TDynamicMatrix<int> v(11);
	ASSERT_ANY_THROW(v.at(12, 12) = 7);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	//может присвоить матрицу самому себе
	TDynamicMatrix<int> v(11);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	//может назначать матрицы одинакового размера
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> w(11);
	EXPECT_EQ(v.size(), w.size());
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	//назначить оператору изменение размера матрицы
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(11);
	ASSERT_NO_THROW(v = k);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	//может назначать матрицы разного размера
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(12);
	ASSERT_NO_THROW(v = k);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	//сравнение равных матриц возвращает значение true
	TDynamicMatrix<int> v(11);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			v[i][j] = 111;
		}
	}
	TDynamicMatrix<int> k(v);
	EXPECT_EQ(true, v == k);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	//сравнить матрицу с самой собой, вернуть true
	TDynamicMatrix<int> v(11);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			v[i][j] = 111;
		}
	}
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	//матрицы с разным размером не равны
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(12);
	EXPECT_NE(v, k);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	//можно добавлять матрицы одинакового размера
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(11);
	ASSERT_NO_THROW(v + k);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	//не удается добавить матрицы с неодинаковым размером
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(12);
	ASSERT_ANY_THROW(v + k);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	//может вычитать матрицы одинакового размера
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(11);
	ASSERT_NO_THROW(v - k);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	//не удается вычесть матрицы с неодинаковым размером
	TDynamicMatrix<int> v(11);
	TDynamicMatrix<int> k(12);
	ASSERT_ANY_THROW(v - k);
}

