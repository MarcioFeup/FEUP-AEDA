//
// Created by marcio on 9/28/19.
//

#ifndef AEDAEX0_MARKET_H
#define AEDAEX0_MARKET_H


#include <bits/exception.h>
#include <stdexcept>

/*!
 * Represents an exception caused by requesting an unavailable product.
 *
 * @author Márcio Duarte
 */
class UnavailableProduct : public std::exception {
};


#endif //AEDAEX0_MARKET_H
