#include <gtest/gtest.h>
#include "case.hpp"

TEST(SolucaoTest, SomaNumerosPositivos) {
    EXPECT_EQ(sum(2, 3), 5) << "A soma deu um valor positivo";
}

TEST(SolucaoTest, SomaComZero) {
    EXPECT_EQ(sum(0, 10), 10) << "Soma com elemento neutro";
}

TEST(SolucaoTest, SomaNumerosNegativos) {
    EXPECT_EQ(sum(-2, -3), -5) << "Soma entre 2 numeros negativos";
}