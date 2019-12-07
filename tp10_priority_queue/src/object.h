#ifndef AEDA1920_FP10_OBJECT_H
#define AEDA1920_FP10_OBJECT_H


#include <ostream>

/**
 * Represents an object to store in boxes.
 */
class Object {
  public:
    /**
     * The full constructor of the object.
     *
     * @param id the ID of the object
     * @param weight the weight of the object
     */
    Object(unsigned int id, unsigned int weight);

    /**
     * Gets the ID of the object.
     *
     * @return the ID
     */
     unsigned int getId() const;

     /**
      * Gets the weight of the object.
      *
      * @return the weight
      */
    unsigned int getWeight() const;

    /**
     * Compares with another object.
     *
     * @param object the other object
     * @return true if this object is "lower", false otherwise
     */
    bool operator<(const Object &object) const;

    /**
     * Prints an object in an ostream.
     *
     * @param os the reference to the ostream
     * @param object the object
     * @return the reference to the ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Object &object);

  private:
    /**
     * The ID of the object.
     */
    unsigned id;

    /**
     * The weight of the object
     */
    unsigned weight;
};


#endif //AEDA1920_FP10_OBJECT_H
