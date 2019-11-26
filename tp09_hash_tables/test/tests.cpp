#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "../src/bet.h"
#include "../src/player.h"


using testing::Eq;


TEST(test_1, a_GeraBet){
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    EXPECT_EQ(6, ap1.getNumbers().size());
}

TEST(test_1, b_VerificaBet){
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    EXPECT_EQ(true, ap1.has(30));
    EXPECT_EQ(true, ap1.has(45));
    EXPECT_EQ(true, ap1.has(15));
    EXPECT_EQ(false, ap1.has(21));
}

TEST(test_1, c_ContaBet){
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    std::vector<unsigned> valsF;
    valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
    valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
    Bet chave;
    chave.build(valsF,6);
    EXPECT_EQ(3,ap1.getCorrects(chave.getNumbers()));
}

TEST(test_2, a_PlayerAdicionaBet){
    Player jogador1("Rui");
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    jogador1.addBet(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(44); vals.push_back(22);
    vals.push_back(15); vals.push_back(44); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Bet ap2;
    ap2.build(vals,6);
    jogador1.addBet(ap2);
    vals.clear();
    vals.push_back(41); vals.push_back(32); vals.push_back(12);
    vals.push_back(15); vals.push_back(28); vals.push_back(32);
    vals.push_back(12); vals.push_back(41); vals.push_back(4);
    Bet ap3;
    ap3.build(vals,6);
    jogador1.addBet(ap3);
    EXPECT_EQ(3,jogador1.getQtBets());
}

TEST(test_2, b_PlayerBetsEmNumero){
    Player jogador1("Rui");
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(15); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    jogador1.addBet(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(44); vals.push_back(22);
    vals.push_back(15); vals.push_back(44); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Bet ap2;
    ap2.build(vals,6);
    jogador1.addBet(ap2);
    vals.clear();
    vals.push_back(41); vals.push_back(32); vals.push_back(12);
    vals.push_back(15); vals.push_back(28); vals.push_back(32);
    vals.push_back(12); vals.push_back(41); vals.push_back(4);
    Bet ap3;
    ap3.build(vals,6);
    jogador1.addBet(ap3);
    EXPECT_EQ(2,jogador1.qtBetsOn(22));
}

TEST(test_2, c_PlayerBetsPremiadas){
    Player jogador1("Rui");
    std::vector<unsigned> vals;
    vals.push_back(30); vals.push_back(45); vals.push_back(22);
    vals.push_back(17); vals.push_back(45); vals.push_back(8);
    vals.push_back(30); vals.push_back(18); vals.push_back(24);
    vals.push_back(22);
    Bet ap1;
    ap1.build(vals,6);
    jogador1.addBet(ap1);
    vals.clear();
    vals.push_back(3); vals.push_back(4); vals.push_back(22);
    vals.push_back(15); vals.push_back(4); vals.push_back(3);
    vals.push_back(34); vals.push_back(20); vals.push_back(17);
    Bet ap2;
    ap2.build(vals,6);
    jogador1.addBet(ap2);
    vals.clear();
    vals.push_back(45); vals.push_back(32); vals.push_back(18);
    vals.push_back(15); vals.push_back(8); vals.push_back(32);
    vals.push_back(18); vals.push_back(45); vals.push_back(33);
    Bet ap3;
    ap3.build(vals,6);
    jogador1.addBet(ap3);

    std::vector<unsigned> valsF;
    valsF.push_back(44); valsF.push_back(18); valsF.push_back(22);
    valsF.push_back(33); valsF.push_back(45); valsF.push_back(8);
    Bet chave;
    chave.build(valsF,6);

    EXPECT_EQ(4,ap1.getCorrects(chave.getNumbers()));
    EXPECT_EQ(1,ap2.getCorrects(chave.getNumbers()));
    EXPECT_EQ(4,ap3.getCorrects(chave.getNumbers()));

    EXPECT_EQ(2,jogador1.getPrizedBets(chave.getNumbers()).size());
}