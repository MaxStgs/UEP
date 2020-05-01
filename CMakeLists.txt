# Copyright (C), UNIGINE. All rights reserved.


add_library(SystemsPluginsPlugin MODULE ${CMAKE_CURRENT_SOURCE_DIR}/plugin.cpp)

ung_target_configure_artifact_name(SystemsPluginsPlugin plugin)
ung_target_set_artifact_output(SystemsPluginsPlugin LIBRARY ${CMAKE_CURRENT_SOURCE_DIR})
ung_target_set_artifact_output(SystemsPluginsPlugin RUNTIME ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(SystemsPluginsPlugin
	PRIVATE
	Unigine::Engine
	Unigine::CompilerFlags
	)
