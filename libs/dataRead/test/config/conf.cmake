#set(SRC_DIR2 ../dataPack/test/config)
#set(DST_DIR2 ${TEST_OUTPUT_PATH})

#add_custom_target(${PROJECT_NAME}_tconf2
#COMMAND ${CMAKE_COMMAND} -E create_symlink ${SRC_DIR} ${DST_DIR}/packer
#)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/test/config)
set(DST_DIR ${TEST_OUTPUT_PATH})

add_custom_target(${PROJECT_NAME}_tconf
COMMAND ${CMAKE_COMMAND} -E create_symlink ${SRC_DIR} ${DST_DIR}/reader
)

add_dependencies(${PROJECT_NAME}_t ${PROJECT_NAME}_tconf)
