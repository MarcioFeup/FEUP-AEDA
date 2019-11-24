#include <gtest/gtest.h>
#include "../src/binary_tree/bst.h"
#include "../src/dictionary/dictionary.h"
#include "../src/dictionary/non_existing_word.h"
#include "../src/game/game.h"
#include <fstream>


using testing::Eq;


TEST(test_1, a_CriaDictionary){
    std::ifstream fich;
    fich.open("dic.txt");
    Dictionary d1;
    d1.read(fich);
    fich.close();
    BST<Word> arvPals = d1.getWords();
    bool isEmp = arvPals.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false) {
        BSTItrIn<Word> it(arvPals);
        it.advance();
        it.advance();
        EXPECT_EQ("gato", it.retrieve().getWord());
    }
}

TEST(test_1, b_ImprimeDictionary){
    cout << "Este teste nao falha. Verifique na consola os valores" << endl;
    EXPECT_TRUE(true);
    ifstream fich;
    fich.open("dic.txt");

    Dictionary d1;
    d1.read(fich);
    fich.close();
    d1.print();
}

TEST(test_1, c_ConsultaDictionary){
    ifstream fich;
    fich.open("dic.txt");

    Dictionary d1;
    d1.read(fich);
    fich.close();
    EXPECT_EQ("mamifero felino", d1.query("gato"));
    EXPECT_THROW(d1.query("rio"), NonExistingWord);
    try {
        string signf=d1.query("janela");
    }
    catch (NonExistingWord &e) {
        cout << "Apanhou excepcao: NonExistingWord" << endl;
        EXPECT_EQ("ilha", e.getPreviousWord());
        EXPECT_EQ("porto de terra emersa rodeada de agua", e.getPreviousMeaning());
        EXPECT_EQ("macaco", e.getNextWord());
        EXPECT_EQ("mamifero da ordem dos primatas", e.getNextMeaning());
    }
}

TEST(test_1, d_CorrigeDictionary){
    ifstream fich;
    fich.open("dic.txt");

    Dictionary d1;
    d1.read(fich);
    fich.close();
    EXPECT_EQ(true,d1.amend("morango","fruto vermelho"));
    EXPECT_EQ("fruto vermelho", d1.query("morango"));
    EXPECT_EQ(false,d1.amend("esquilo","pequeno mamifero roedor de cauda longa"));
    BST<Word> arvPals = d1.getWords();
    bool isEmp = arvPals.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false) {
        BSTItrIn<Word> it(arvPals);
        it.advance();
        it.advance();
        EXPECT_EQ("esquilo", it.retrieve().getWord());
        EXPECT_EQ("pequeno mamifero roedor de cauda longa", d1.query("esquilo"));
    }
}

TEST(test_2, a_InicioGame){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6); pontos.push_back(7);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true); estados.push_back(false);
    Game jogo1(2, pontos, estados);
    EXPECT_EQ(1, jogo1.getBoard().getRoot().getScore());
}

TEST(test_2, b_EscreveGame){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Game jogo1(3, pontos, estados);
    string jogoStr="1-true-0\n2-false-0\n3-false-0\n4-false-0\n5-false-0\n6-true-0\n7-false-0\n8-true-0\n9-true-0\n10-true-0\n11-true-0\n12-true-0\n13-true-0\n14-true-0\n15-true-0\n";
    EXPECT_EQ(jogoStr, jogo1.print());
}

TEST(test_2, c_FazJogada){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Game jogo1(3, pontos, estados);
    EXPECT_EQ(13, jogo1.play());
    EXPECT_EQ(8,jogo1.play());
}

TEST(test_2, d_MaisVisitado){
    vector<int> pontos;
    vector<bool> estados;
    pontos.push_back(1); pontos.push_back(2); pontos.push_back(3);
    pontos.push_back(4); pontos.push_back(5); pontos.push_back(6);
    pontos.push_back(7); pontos.push_back(8); pontos.push_back(9);
    pontos.push_back(10); pontos.push_back(11); pontos.push_back(12);
    pontos.push_back(13); pontos.push_back(14); pontos.push_back(15);
    estados.push_back(true); estados.push_back(false); estados.push_back(false);
    estados.push_back(false); estados.push_back(false); estados.push_back(true);
    estados.push_back(false); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    estados.push_back(true); estados.push_back(true); estados.push_back(true);
    Game jogo1(3, pontos, estados);
    jogo1.play(); jogo1.play(); jogo1.play();
    EXPECT_EQ(2, jogo1.mostVisited());
    jogo1.play(); jogo1.play(); jogo1.play();jogo1.play();
    EXPECT_EQ(4, jogo1.mostVisited());
}
