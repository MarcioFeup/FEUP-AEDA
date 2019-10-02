# Sports Club / AEDA ex0

### Assignment:

* A management application of a sports club that saves information about its **personal**, this is _athletes_, _teachers_ and _club members_.
* All sports club personal are identified by a sequential ID.
  * Athletes are registered in a modality and a class.
  * Teachers teach a single modality to various classes.
  * Club members pay a monthly quota.
  * The class must specify its weekly schedule.

Implement the class hierarchy that best describes the scenario above, specifying the attributes and methods of each class.



___

### Class Diagram:

![Class Diagram](https://i.imgur.com/LNBNMox.png)

___
### Code:

* One class per .cpp/.h so class organization is easier to follow;
* Designwise, DRY (Don't Repeat Yourself) was put aside so that the Dependency Inversion Principle was explicit (e.g., interface "Personal");
* Schedule was ignored because the assignment is not clear.