#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "../src/child.h"
#include "../src/game.h"


using testing::Eq;
using namespace std;

TEST(test, a_add_child) {
	Child c1("Rui", 6);
	Child c2("Ana", 4);
	Child c3("Rita", 6);
	Child c4("Joao", 5);
	Child c5("Marta", 4);
	Child c6("Vasco", 5);

	Game game1;
	list<Child> cc = game1.getChildren();
	EXPECT_EQ(0, cc.size());

	game1.addChild(c1);
	game1.addChild(c2);
	game1.addChild(c3);
	game1.addChild(c4);
	game1.addChild(c5);
	game1.addChild(c6);

	cc = game1.getChildren();
	EXPECT_EQ(6, cc.size());

	if (cc.size() == 6) {
		Child c = cc.front();
		EXPECT_EQ("Rui", c.getName());
		c = cc.back();
		EXPECT_EQ("Vasco", c.getName());
	}

	Game game2;
	cc.clear();
	cc.push_back(c1);
	cc.push_back(c2);
	cc.push_back(c3);
	cc.push_back(c4);
	game2.setChildren(cc);

	cc = game2.getChildren();
	EXPECT_EQ(4, cc.size());

	if (cc.size() == 4) {
		Child c = cc.front();
		EXPECT_EQ("Rui", c.getName());
		c = cc.back();
		EXPECT_EQ("Joao", c.getName());
	}
}

TEST(test, b_describe_game) {
	Game game1;
	EXPECT_EQ("", game1.describe());

	Child c1("Rui", 6);
	Child c2("Ana", 4);
	Child c3("Vasco", 5);
	game1.addChild(c1);
	game1.addChild(c2);
	game1.addChild(c3);
	cout << game1.describe();
	EXPECT_EQ("Rui: 6\nAna: 4\nVasco: 5\n", game1.describe());
}

TEST(test, c_who_looses) {
	Child c1("Rui", 6);
	Child c2("Ana", 4);
	Child c3("Rita", 6);
	Child c4("Joao", 5);
	Child c5("Marta", 4);
	Child c6("Vasco", 5);

	Game game1;
	game1.addChild(c1);
	game1.addChild(c2);
	game1.addChild(c3);
	game1.addChild(c4);
	game1.addChild(c5);
	game1.addChild(c6);

	string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
	Child cx = game1.whoLooses(s);
	EXPECT_EQ("Rui", cx.getName());

	Game game2;
	s = "Pim Pam Pum";
	game2.addChild(c1);
	game2.addChild(c2);
	game2.addChild(c3);
	cx = game2.whoLooses(s);
	EXPECT_EQ("Ana", cx.getName());
}

TEST(test, d_reverse_game) {
	Child c1("Rui", 6);
	Child c2("Vasco", 5);
	Child c3("Ana", 4);
	Child c4("Joao", 5);
	Child c5("Marta", 4);
	Child c6("Rita", 6);

	Game game1;
	game1.addChild(c1);
	game1.addChild(c2);
	game1.addChild(c3);
	game1.addChild(c4);
	game1.addChild(c5);
	game1.addChild(c6);

	EXPECT_EQ("Rui", game1.getChildren().front().getName());
	EXPECT_EQ("Rita", game1.getChildren().back().getName());

	list<Child> invertida = game1.reverse();
	EXPECT_EQ("Rita", invertida.front().getName());
	EXPECT_EQ("Rui", invertida.back().getName());
}

TEST(test, e_divide_game) {
	Child c1("Rui", 6);
	Child c2("Ana", 4);
	Child c3("Rita", 3);
	Child c4("Joao", 5);
	Child c5("Marta", 7);
	Child c6("Vasco", 5);
	Game game1;
	game1.addChild(c1);
	game1.addChild(c2);
	game1.addChild(c3);
	game1.addChild(c4);
	game1.addChild(c5);
	game1.addChild(c6);

	list<Child> dividida = game1.divide(5);
	Game game2(dividida);
	EXPECT_EQ("Rui: 6\nMarta: 7\n", game2.describe());
}

TEST(test, f_game_equality) {
	list<Child> children1;
	children1.push_back(Child("Rui", 6));
	children1.push_back(Child("Ana", 4));
	children1.push_back(Child("Rita", 3));
	children1.push_back(Child("Joao", 5));
	children1.push_back(Child("Marta", 7));
	children1.push_back(Child("Vasco", 5));
	children1.push_back(Child("Ines", 5));

	Game game1(children1);
	Game game2(children1);
	EXPECT_EQ(true, game1 == game2);

	list<Child> children2;
	children2.push_back(Child("Rui", 6));
	children2.push_back(Child("Ana", 4));
	children2.push_back(Child("Rita", 3));
	children2.push_back(Child("Maria", 5));
	children2.push_back(Child("Marta", 7));
	children2.push_back(Child("Vasco", 5));
	children2.push_back(Child("Ines", 5));

	game2.setChildren(children2);
	EXPECT_EQ(false, game1 == game2);
}

TEST(test, g_shuffle_children) {
	list<Child> children;
	children.push_back(Child("Rui", 6));
	children.push_back(Child("Ana", 4));
	children.push_back(Child("Rita", 3));
	children.push_back(Child("Joao", 5));
	children.push_back(Child("Marta", 7));
	children.push_back(Child("Vasco", 5));
	children.push_back(Child("Ines", 5));

	Game game1;
	game1.setChildren(children);

	list<Child> children2 = game1.shuffle();
	EXPECT_EQ(7, children2.size());

	list<Child>::iterator it;
	it = find(children2.begin(), children2.end(), Child("Rui", 6));
	EXPECT_EQ("Rui", it->getName());

	it = find(children2.begin(), children2.end(), Child("Ines", 5));
	EXPECT_EQ("Ines", it->getName());

	Game game2(children2);
	EXPECT_EQ(false, game1 == game2);
}