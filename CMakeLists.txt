cmake_minimum_required(VERSION 3.12)
project(AnnotatedTree)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
link_directories(library)

add_library(AnnotatedTree ChunkType.h SearchType.h Layer/WordLayer.cpp Layer/WordLayer.h Layer/SingleWordLayer.h Layer/MultiWordLayer.h Layer/MultiWordMultiItemLayer.h Layer/SingleWordMultiItemLayer.h Layer/SourceLanguageWordLayer.h Layer/TargetLanguageWordLayer.h Layer/DependencyLayer.h Layer/EnglishPropbankLayer.h Layer/EnglishSemanticLayer.h Layer/EnglishWordLayer.h Layer/MetaMorphemesMovedLayer.h Layer/MetaMorphemeLayer.h Layer/MorphologicalAnalysisLayer.h Layer/DependencyLayer.cpp Layer/EnglishPropbankLayer.cpp Layer/EnglishSemanticLayer.cpp Layer/EnglishWordLayer.cpp Layer/MetaMorphemeLayer.cpp Layer/MetaMorphemesMovedLayer.cpp Layer/MorphologicalAnalysisLayer.cpp Layer/SourceLanguageWordLayer.cpp Layer/TargetLanguageWordLayer.cpp Layer/MultiWordLayer.cpp Layer/SingleWordLayer.cpp Layer/SingleWordMultiItemLayer.cpp Layer/NERLayer.cpp Layer/NERLayer.h Layer/PersianWordLayer.cpp Layer/PersianWordLayer.h Layer/ShallowParseLayer.cpp Layer/ShallowParseLayer.h Layer/TurkishPropbankLayer.cpp Layer/TurkishPropbankLayer.h Layer/TurkishSemanticLayer.cpp Layer/TurkishSemanticLayer.h Layer/TurkishWordLayer.cpp Layer/TurkishWordLayer.h LayerInfo.cpp LayerInfo.h ParseNodeDrawable.cpp ParseNodeDrawable.h)

target_link_libraries(AnnotatedTree AnnotatedSentence Dictionary Propbank MorphologicalAnalysis NamedEntityRecognition ParseTree)