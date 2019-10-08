#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/zoo.h"
#include <string>
#include <fstream>

using testing::Eq;


TEST(test, a_createAnimals){
    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, breed
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, max velocity, max height
    Animal *a3=new Dog("bobby",3,"rafeiro");
    Animal *a4=new Dog("fly",7,"dalmata");
    Animal *a5=new Bat("timao",7,80,4);
    ASSERT_EQ("kurika", a1->getName());
    ASSERT_EQ("bobo", a2->getName());
    ASSERT_EQ("bobby", a3->getName());
    ASSERT_EQ("fly", a4->getName());
    ASSERT_EQ("timao", a5->getName());
    ASSERT_EQ(true, a3->isYoung());
    ASSERT_EQ(false, a4->isYoung());
    ASSERT_EQ(true, a2->isYoung());
    ASSERT_EQ(false, a5->isYoung());
    ASSERT_EQ(2, Animal::getYoungest());
}

TEST(test, b_addAnimals){
	Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, ra�a
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, velocidade_maxima, altura_maxima
    Animal *a3=new Dog("bobby",3,"rafeiro");
    Animal *a4=new Dog("fly",7,"dalmata");
    Animal *a5=new Bat("timao",7,80,4);

    z1.addAnimal(a1);
    z1.addAnimal(a2);
    z1.addAnimal(a3);
    z1.addAnimal(a4);
    z1.addAnimal(a5);

    ASSERT_EQ(5, z1.qtdAnimals());
}

TEST(test, c_PrintAnimals){
    Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, breed
    ASSERT_EQ("kurika, 10, estrela", a1->info());

    Animal *a2=new Bat("bobo",2,70,2);  //name, age, max velocity, max height
    ASSERT_EQ("bobo, 2, 70, 2", a2->info());

    z1.addAnimal(a1);
    z1.addAnimal(a2);

    cout << z1.info();
}

TEST(test, d_verifyIsYoungAnimal){
   	Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, breed
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, max velocity, max height

    z1.addAnimal(a1);
    z1.addAnimal(a2);

    ASSERT_EQ(false, z1.isYoungAnimal("kurika"));
    ASSERT_EQ(true, z1.isYoungAnimal("bobo"));
}

TEST(test, e_alocarVeterinarios){
  	Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, ra�a
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, max velocity, max height
    Animal *a3=new Dog("bobby",3,"rafeiro");
    Animal *a4=new Dog("fly",7,"dalmata");
    Animal *a5=new Bat("timao",7,80,4);

    z1.addAnimal(a1);
    z1.addAnimal(a2);
    z1.addAnimal(a3);
    z1.addAnimal(a4);
    z1.addAnimal(a5);

    ifstream fVet("/");
    if (!fVet) cerr << "Ficheiro de vets inexistente!\n";
    else z1.readVets(fVet);
    fVet.close();

    ASSERT_EQ(5, z1.qtdAnimals());
    ASSERT_EQ(3, z1.qtdVets());
    ASSERT_EQ("kurika, 10, Rui Silva, 1234, estrela", a1->info());
}

TEST(test, f_removerVeterinario){
    Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, breed
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, max velocity, max height
    Animal *a3=new Dog("bobby",3,"rafeiro");
    Animal *a4=new Dog("fly",7,"dalmata");
    Animal *a5=new Bat("timao",7,80,4);

    z1.addAnimal(a1);
    z1.addAnimal(a2);
    z1.addAnimal(a3);
    z1.addAnimal(a4);
    z1.addAnimal(a5);

    ifstream fVet("vets.txt");
    if (!fVet) cerr << "Ficheiro de vets inexistente!\n";
    else z1.readVets(fVet);
    fVet.close();

    ASSERT_EQ(5, z1.qtdAnimals());
    ASSERT_EQ(3, z1.qtdVets());
    ASSERT_EQ("kurika, 10, Rui Silva, 1234, estrela", a1->info());

    z1.removeVet("Rui Silva");

    ASSERT_EQ("kurika, 10, Artur Costa, 3542, estrela", a1->info());
}

TEST(test, h_compararZoos){
   /* Zoo z1;

    Animal *a1=new Dog("kurika",10,"estrela");  //name, age, ra�a
    Animal *a2=new Bat("bobo",2,70,2);  //name, age, velocidade_maxima, altura_maxima
    Animal *a3=new Dog("bobby",3,"rafeiro");
    Animal *a4=new Dog("fly",7,"dalmata");
    Animal *a5=new Bat("timao",7,80,4);

    z1.addAnimal(a1);
    z1.addAnimal(a2);
    z1.addAnimal(a3);
    z1.addAnimal(a4);
    z1.addAnimal(a5);

    Zoo z2;

    Animal *b1=new Dog("kurika",10,"estrela");  //name, age, ra�a
    Animal *b2=new Bat("bobo",2,70,2);  //name, age, velocidade_maxima, altura_maxima
    Animal *b3=new Dog("bobby",3,"rafeiro");
    Animal *b4=new Dog("fly",7,"dalmata");

    z2.addAnimal(b1);
    z2.addAnimal(b2);
    z2.addAnimal(b3);
    z2.addAnimal(b4);

    ASSERT_EQ(true, z2 < z1);*/
}