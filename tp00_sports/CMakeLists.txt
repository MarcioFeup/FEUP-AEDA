cmake_minimum_required(VERSION 3.14)
project(ex0_sports)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex0_sports src/sports_club/SportsClub.cpp src/sports_club/SportsClub.h src/activity/Modality.cpp src/activity/Modality.h src/personal/Personal.cpp src/personal/Personal.h src/personal/Athlete.cpp src/personal/Athlete.h src/personal/Teacher.cpp src/personal/Teacher.h src/personal/ClubMember.cpp src/personal/ClubMember.h src/activity/Class.cpp src/activity/Class.h)