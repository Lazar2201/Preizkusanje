#include "gtest/gtest.h"
#include "BellmanFord.h"
#include "cmake-build-debug/_deps/googletest-src/googletest/include/gtest/gtest.h"

// Testiranje funkcije readGraph() za uspješno čitanje grafa iz datoteke
TEST(BellmanFordTest, ReadGraphSuccessful) {
    BF program;
    program.readGraph("test_graph.txt"); // Pretpostavljamo da postoji datoteka "test_graph.txt" s validnim grafom
    ASSERT_GT(program.node_matrix.size(), 0); // Provjeravamo da li je matrica inicijalizovana
    ASSERT_EQ(program.node_matrix[0][0], 0); // Provjeravamo da li je prvi čvor ispravno postavljen na 0
    // Dodajte više provjera po potrebi
}

// Testiranje funkcije readGraph() za neuspješno čitanje grafa iz nepostojeće datoteke
TEST(BellmanFordTest, ReadGraphFileNotFound) {
    BF program;
    // Pokušavamo pročitati graf iz nepostojeće datoteke
    program.readGraph("nonexistent_graph.txt"); // Pretpostavljamo da datoteka ne postoji
    ASSERT_TRUE(program.node_matrix.empty()); // Provjeravamo da li je matrica ostala prazna
}

// Testiranje funkcije startAlgorithm() za početak algoritma s neispravnim grafom
TEST(BellmanFordTest, StartAlgorithmInvalidGraph) {
    BF program;
    // Pokušavamo pokrenuti algoritam na neispravnom grafu (praznoj matrici)
    int error = program.startAlgorithm(0);
    ASSERT_EQ(error, -1); // Očekujemo povratnu vrijednost -1 koja označava grešku
}

// Dodajte više testova za ostale funkcije po potrebi

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
