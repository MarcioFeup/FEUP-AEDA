#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <string>
#include "../src/object.h"
#include "../src/packing_machine.h"
#include "../src/empty_machine_exception.h"


using testing::Eq;
using namespace std;



TEST(test, a_CarregaObjects){
    std::vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 11);
    objects.emplace_back(3, 17); objects.emplace_back(4, 3);
    objects.emplace_back(5, 9); objects.emplace_back(6, 4);
    objects.emplace_back(7, 2); objects.emplace_back(8, 12);
    objects.emplace_back(9, 7); objects.emplace_back(10, 1);

    for(auto object : objects) cout << object << endl;

    PackingMachine machine;
    int loaded_objects = machine.loadObjects(objects);
    int ignored_objects  = objects.size();
    EXPECT_EQ(7, loaded_objects);
    EXPECT_EQ(3, ignored_objects);
    std::priority_queue<Object> objects_heap= machine.getObjects();
    bool isEmp = objects_heap.empty();
    EXPECT_EQ(false, isEmp);
    if (!isEmp)
        EXPECT_EQ(5, objects_heap.top().getId());
}


TEST(test, b_ProcuraBox){
    vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 5);
    objects.emplace_back(3, 8); objects.emplace_back(4, 1);
    objects.emplace_back(5, 4); objects.emplace_back(6, 6);
    objects.emplace_back(7, 1); objects.emplace_back(8, 4);

    Box::resetId();

    Box c1(10); //7
    c1.addObject( objects[0] );
    c1.addObject( objects[1] );
    Box c2(10); //8
    c2.addObject( objects[2] );

    PackingMachine maquina;
    maquina.addBox( c1 );
    maquina.addBox( c2 );

    cout << "Carga livre em C" << c1.getId() << ": " << c1.getFreeWeight() << endl; //3
    cout << "Carga livre em C" << c2.getId() << ": " << c2.getFreeWeight() << endl; //2

    EXPECT_EQ(2, maquina.qtUsedBoxes()); // 8 7
    priority_queue<Box> caixasH= maquina.getBoxes();
    bool isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (!isEmp)
        EXPECT_EQ(2,caixasH.top().getFreeWeight());

    Box cx = maquina.searchBox( objects[3] );
    cx.addObject( objects[3] );
    maquina.addBox( cx );
    //cout << "Carga livre em C" << cx.getId() << ": " << cx.getFreeWeight() << endl;
    EXPECT_EQ(2, maquina.qtUsedBoxes()); // 9 7
    caixasH= maquina.getBoxes();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (!isEmp)
        EXPECT_EQ(1,caixasH.top().getFreeWeight());

    cx = maquina.searchBox( objects[4] );
    cx.addObject( objects[4] );
    maquina.addBox( cx );
    cout << "Carga livre em C" << cx.getId() << ": " << cx.getFreeWeight() << endl;
    EXPECT_EQ(3, maquina.qtUsedBoxes()); // 9 7 4
    caixasH= maquina.getBoxes();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(1,caixasH.top().getFreeWeight());

    cx = maquina.searchBox( objects[5] );
    cx.addObject( objects[5] );
    maquina.addBox( cx );
    cout << "Carga livre em C" << cx.getId() << ": " << cx.getFreeWeight() << endl;
    EXPECT_EQ(3, maquina.qtUsedBoxes()); // 10 9 7
    caixasH= maquina.getBoxes();
    isEmp = caixasH.empty();
    EXPECT_EQ(false, isEmp);
    if (isEmp==false)
        EXPECT_EQ(0,caixasH.top().getFreeWeight());

    cx = maquina.searchBox( objects[6] );
    cx.addObject( objects[6] );
    maquina.addBox( cx );
    cout << "Carga livre em C" << cx.getId() << ": " << cx.getFreeWeight() << endl;
    EXPECT_EQ(3, maquina.qtUsedBoxes()); // 10 10 7
    caixasH = maquina.getBoxes();
    EXPECT_EQ(3,caixasH.size());
    if (caixasH.size()==3) {
        caixasH.pop();
        EXPECT_EQ(0, caixasH.top().getFreeWeight());
    }

    cx = maquina.searchBox( objects[7] );
    cx.addObject( objects[7] );
    maquina.addBox( cx );
    cout << "Carga livre em C" << cx.getId() << ": " << cx.getFreeWeight() << endl;
    EXPECT_EQ(4, maquina.qtUsedBoxes()); // 10 10 7 6
    caixasH = maquina.getBoxes();
    EXPECT_EQ(4,caixasH.size());
    if (caixasH.size()==4) {
        caixasH.pop();
        caixasH.pop();
        EXPECT_EQ(3, caixasH.top().getFreeWeight());
    }
}


TEST(test, c_EmpacotaObjects){
    vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 11);
    objects.emplace_back(3, 17); objects.emplace_back(4, 3);
    objects.emplace_back(5, 9); objects.emplace_back(6, 4);
    objects.emplace_back(7, 2); objects.emplace_back(8, 12);
    objects.emplace_back(9, 7); objects.emplace_back(10, 10);
    objects.emplace_back(11, 10); objects.emplace_back(12, 1);

    Box::resetId();

    PackingMachine machine;

    EXPECT_EQ(9, machine.loadObjects(objects));
    EXPECT_EQ(3, objects.size());
    EXPECT_EQ(5, machine.packObjects());

    priority_queue<Box> boxes = machine.getBoxes();
    EXPECT_EQ(5, boxes.size());
    if (boxes.size() == 5) {
        EXPECT_EQ(0, boxes.top().getFreeWeight());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFreeWeight());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFreeWeight());
        boxes.pop();
        EXPECT_EQ(0, boxes.top().getFreeWeight());
        boxes.pop();
        EXPECT_EQ(2, boxes.top().getFreeWeight());
    }
}


TEST(test, d_ObjectsPorEmpacotar){
	PackingMachine maquina;

    EXPECT_EQ("There's no objects!\n", maquina.printUnpackedObjects());

    vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 12);
    objects.emplace_back(3, 8); objects.emplace_back(4, 1);

    EXPECT_EQ(3, maquina.loadObjects(objects));
    string toPack = maquina.printUnpackedObjects();
    cout << toPack;
    EXPECT_EQ("O3: 8\nO1: 2\nO4: 1\n", maquina.printUnpackedObjects());

    EXPECT_EQ(2, maquina.packObjects());

    EXPECT_EQ("There's no objects!\n", maquina.printUnpackedObjects());
}


TEST(test, e_ConteudoBox){
    vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 5);

    Box::resetId();

    Box c1(10);
    EXPECT_EQ("Box 1 empty!\n", c1.print());

    c1.addObject( objects[0] );
    c1.addObject( objects[1] );

    EXPECT_EQ("C1[ O2: 5 O1: 2 ]", c1.print());
}

TEST(test, f_BoxMaisObjects){
    vector<Object> objects;
    objects.emplace_back(1, 2); objects.emplace_back(2, 11);
    objects.emplace_back(3, 17); objects.emplace_back(4, 3);
    objects.emplace_back(5, 9); objects.emplace_back(6, 4);
    objects.emplace_back(7, 2); objects.emplace_back(8, 12);
    objects.emplace_back(9, 7); objects.emplace_back(10, 10);
    objects.emplace_back(11, 10); objects.emplace_back(12, 1);

    Box cx;
    Box::resetId();

    PackingMachine machine;

    EXPECT_THROW(machine.boxWithMostObjects(), EmptyMachineException);
    try {
        cx = machine.boxWithMostObjects();
    }
    catch(EmptyMachineException &msc) {
        cout << "Este teste nunca falha! VERIFICAR informacao escrita no monitor" << endl;
        EXPECT_TRUE(true);

    }

    EXPECT_EQ(9, machine.loadObjects(objects));
    EXPECT_EQ(3, objects.size());
    EXPECT_EQ(5, machine.packObjects());

    cx = machine.boxWithMostObjects();
    EXPECT_EQ(5, cx.getId());
    EXPECT_EQ("C5[ O1: 2 O7: 2 O6: 4 ]", cx.print());
}
