#ifndef AEDA1920_FP10_EMPTY_MACHINE_EXCEPTION_H
#define AEDA1920_FP10_EMPTY_MACHINE_EXCEPTION_H


#include <stdexcept>

/**
 * Exception that represents a machine without boxes.
 */
class EmptyMachineException {
  public:
    /**
     * The default constructor.
     */
	EmptyMachineException() = default;
};


#endif //AEDA1920_FP10_EMPTY_MACHINE_EXCEPTION_H
