cmake_minimum_required(VERSION 3.12)
project(AnnotatedTree)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(AnnotatedTree ChunkType.h SearchType.h Layer/WordLayer.cpp Layer/WordLayer.h Layer/SingleWordLayer.h Layer/MultiWordLayer.h Layer/MultiWordMultiItemLayer.h Layer/SingleWordMultiItemLayer.h Layer/SourceLanguageWordLayer.h Layer/TargetLanguageWordLayer.h)

target_link_libraries(AnnotatedTree AnnotatedSentence Dictionary)