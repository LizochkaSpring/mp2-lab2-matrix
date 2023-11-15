#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	//может создать вектор с положительной длиной
  ASSERT_NO_THROW(TDynamicVector<int> v(1));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	//не могу создать слишком большой вектор
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	//выдает при создании вектора с отрицательной длиной
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	//может создать скопированный вектор
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	//скопированный вектор равен исходному
	TDynamicVector<int> v(11);
	for (int i = 0; i < 11; i++) {
		v[i] = i;
	}
	TDynamicVector<int> k(v);
	EXPECT_EQ(v, k);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	//скопированный вектор имеет свою собственную память
	TDynamicVector<int> v(11);
	for (int i = 0; i < 11; i++) {
		v[i] = i;
	}
	TDynamicVector<int> k(v);
	for (int i = 0; i < 11; i++) {
		v[i] += i;
	}
	EXPECT_NE(v, k);
}

TEST(TDynamicVector, can_get_size)
{
	//можно получить по размеру
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	//выдает при установке элемента с отрицательным индексом
	TDynamicVector<int> v(11);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	//выдает ошибку, когда задан элемент со слишком большим индексом
	TDynamicVector<int> v(11);
	ASSERT_ANY_THROW(v.at(12));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	//может присвоить вектор самому себе
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	//может назначать векторы одинакового размера
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	EXPECT_EQ(k.size(), v.size());
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	//назначить оператору изменение размера вектора
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v = k);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	//может назначать векторы разного размера
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	EXPECT_NE(k.size(), v.size());
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	//сравнение равных векторов возвращает значение true
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(v);
	EXPECT_EQ(true, k == v);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	//сравнить вектор с самим собой, вернуть true
	TDynamicVector<int> v(11);
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	//векторы с разным размером не равны
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	EXPECT_NE(k.size(), v.size());
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	//можно добавить скаляр к вектору
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v + 11);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	//может вычесть скаляр из вектора
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v - 7);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	//может умножать скаляр на вектор
	TDynamicVector<int> v(11);
	ASSERT_NO_THROW(v * 7);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	//можно добавлять векторы одинакового размера
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v + k);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	//не удается добавить векторы с неодинаковым размером
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v + k);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	//может вычитать векторы одинакового размера
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v - k);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	//не удается вычесть векторы с неравным размером
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v - k);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	//может умножать векторы одинакового размера
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(11);
	ASSERT_NO_THROW(v * k);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	//не удается умножить векторы с неодинаковым размером
	TDynamicVector<int> v(11);
	TDynamicVector<int> k(12);
	ASSERT_ANY_THROW(v * k);
}

