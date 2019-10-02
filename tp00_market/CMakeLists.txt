cmake_minimum_required(VERSION 3.14)
project(ex0_market)

set(CMAKE_CXX_STANDARD 14)

add_executable(AEDAex0 src/main.cpp src/market/market.cpp src/market/market.h src/exception/file/fileException.cpp src/exception/file/fileException.h src/market/participant/participant.cpp src/market/participant/participant.h src/market/product/product.cpp src/market/product/product.h src/exception/market/business.cpp src/exception/market/business.h src/market/product/marketable_product.cpp src/market/product/marketable_product.h)