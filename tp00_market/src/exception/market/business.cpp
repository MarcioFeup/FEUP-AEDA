//
// Created by marcio on 9/28/19.
//

#include "business.h"

NonExistentParticipantException::NonExistentParticipantException(std::string error) : std::invalid_argument(error) {}