
file(GLOB MAIN "./main.cpp" )

ADD_EXECUTABLE(signal ${MAIN}) 

ADD_EXECUTABLE(cluster "./r_main.cpp")
#链接库
TARGET_LINK_LIBRARIES(signal uSockets z)
#链接库
TARGET_LINK_LIBRARIES(cluster hiredis redis++)


