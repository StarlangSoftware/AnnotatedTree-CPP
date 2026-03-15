# Constituency TreeBank

A treebank is a corpus where the sentences in each language are syntactically (if necessary morphologically) annotated. In the treebanks, the syntactic annotation usually follows constituent and/or dependency structure.

Treebanks annotated for the syntactic or semantic structures of the sentences are essential for developing state-of-the-art statistical natural language processing (NLP) systems including part-of-speech-taggers, syntactic parsers, and machine translation systems. There are two main groups of syntactic treebanks, namely treebanks annotated for constituency (phrase structure) and the ones that are annotated for dependency structure.

## Data Format

We extend the original format with the relevant information, given between curly braces. For example, the word 'problem' in a sentence in the standard Penn Treebank notation, may be represented in the data format provided below:

	(NN problem)

After all levels of processing are finished, the data structure stored for the same word has the following form in the system.

	(NN {turkish=sorunu} {english=problem} 
	{morphologicalAnalysis=sorun+NOUN+A3SG+PNON+ACC}
	{metaMorphemes=sorun+yH}
	{semantics=TUR10-0703650})

As is self-explanatory, 'turkish' tag shows the original Turkish word; 'morphologicalanalysis' tag shows the correct morphological parse of that word; 'semantics' tag shows the ID of the correct sense of that word; 'namedEntity' tag shows the named entity tag of that word; 'propbank' tag shows the semantic role of that word for the verb synset id (frame id in the frame file) which is also given in that tag.

Video Lectures
============

[<img src=https://github.com/StarlangSoftware/AnnotatedTree/blob/master/video1.jpg width="50%">](https://youtu.be/LfMf1bo3tEw)[<img src=https://github.com/StarlangSoftware/AnnotatedTree/blob/master/video2.jpg width="50%">](https://youtu.be/QoFPb9XY8Vc)

For Developers
============

You can also see [Java](https://github.com/starlangsoftware/AnnotatedTree), [C](https://github.com/starlangsoftware/AnnotatedTree-C), [Python](https://github.com/starlangsoftware/AnnotatedTree-Py), [Cython](https://github.com/starlangsoftware/AnnotatedTree-Cy), [Js](https://github.com/starlangsoftware/AnnotatedTree-Js), [Swift](https://github.com/starlangsoftware/AnnotatedTree-Swift), or [C#](https://github.com/starlangsoftware/AnnotatedTree-CS) repository.

## Requirements

* [C++ Compiler](#cpp)
* [Git](#git)


### CPP
To check if you have compatible C++ Compiler installed,
* Open CLion IDE 
* Preferences >Build,Execution,Deployment > Toolchain  

### Git

Install the [latest version of Git](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).

## Download Code

In order to work on code, create a fork from GitHub page. 
Use Git for cloning the code to your local or below line for Ubuntu:

	git clone <your-fork-git-link>

A directory called AnnotatedTree-CPP will be created. Or you can use below link for exploring the code:

	git clone https://github.com/starlangsoftware/AnnotatedTree-CPP.git

## Open project with CLion IDE

To import projects from Git with version control:

* Open CLion IDE , select Get From Version Control.

* In the Import window, click URL tab and paste github URL.

* Click open as Project.

Result: The imported project is listed in the Project Explorer view and files are loaded.


## Compile

**From IDE**

After being done with the downloading and opening project, select **Build Project** option from **Build** menu. After compilation process, user can run TestAnnotatedTree.cpp .

Detailed Description
============

+ [TreeBankDrawable](#treebankdrawable)
+ [ParseTreeDrawable](#parsetreedrawable)
+ [LayerInfo](#layerinfo)

## TreeBankDrawable

To load an annotated TreeBank:

	TreeBankDrawable(File folder, String pattern)
	a = new TreeBankDrawable(new File("/Turkish-Phrase"), ".train")

	TreeBankDrawable(File folder)
	a = new TreeBankDrawable(new File("/Turkish-Phrase"))

	TreeBankDrawable(File folder, String pattern, int from, int to)
	a = new TreeBankDrawable(new File("/Turkish-Phrase"), ".train", 1, 500)

To access all the trees in a TreeBankDrawable:

	for (int i = 0; i < a.sentenceCount(); i++){
		ParseTreeDrawable parseTree = (ParseTreeDrawable) a.get(i);
		....
	}

## ParseTreeDrawable

To load a saved ParseTreeDrawable:

	ParseTreeDrawable(FileInputStream file)
	
is used. Usually it is more useful to load TreeBankDrawable as explained above than to load ParseTree one by one.

To find the node number of a ParseTreeDrawable:

	int nodeCount()
	
the leaf number of a ParseTreeDrawable:

	int leafCount()
	
the word count in a ParseTreeDrawable:

	int wordCount(boolean excludeStopWords)
	
above methods can be used.

## LayerInfo

Information of an annotated word is kept in LayerInfo class. To access the morphological analysis
of the annotated word:

	MorphologicalParse getMorphologicalParseAt(int index)

meaning of an annotated word:

	String getSemanticAt(int index)

the shallow parse tag (e.g., subject, indirect object etc.) of annotated word: 

	String getShallowParseAt(int index)

the argument tag of the annotated word:

	Argument getArgumentAt(int index)
	
the word count in a node:

	int getNumberOfWords()

# Cite

	@inproceedings{yildiz-etal-2014-constructing,
    	title = "Constructing a {T}urkish-{E}nglish Parallel {T}ree{B}ank",
    	author = {Y{\i}ld{\i}z, Olcay Taner  and
      	Solak, Ercan  and
      	G{\"o}rg{\"u}n, Onur  and
      	Ehsani, Razieh},
    	booktitle = "Proceedings of the 52nd Annual Meeting of the Association for Computational Linguistics (Volume 2: Short Papers)",
    	month = jun,
    	year = "2014",
    	address = "Baltimore, Maryland",
    	publisher = "Association for Computational Linguistics",
    	url = "https://www.aclweb.org/anthology/P14-2019",
    	doi = "10.3115/v1/P14-2019",
    	pages = "112--117",
	}
	
For Contibutors
============

### Conan Setup

1. First install conan.

pip install conan

Instructions are given in the following page:

https://docs.conan.io/2/installation.html

2. Add conan remote 'ozyegin' with IP: 104.247.163.162 with the following command:

conan remote add ozyegin http://104.247.163.162:8081/artifactory/api/conan/conan-local --insert

3. Use the comman conan list to check for installed packages. Probably there are no installed packages.

conan list

### conanfile.py file

1. Put the correct dependencies in the requires part
```
    requires = ["math/1.0.0", "classification/1.0.0"]
```

2. Default settings are:
```
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": True, "fPIC": True}
    exports_sources = "src/*", "Test/*"

    def layout(self):
        cmake_layout(self, src_folder="src")

    def generate(self):
        tc = CMakeToolchain(self)
        tc.generate()
        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        copy(conanfile=self, keep_path=False, src=join(self.source_folder), dst=join(self.package_folder, "include"), pattern="*.h")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.a")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.so")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "lib"), pattern="*.dylib")
        copy(conanfile=self, keep_path=False, src=self.build_folder, dst=join(self.package_folder, "bin"), pattern="*.dll")

    def package_info(self):
        self.cpp_info.libs = ["ComputationalGraph"]
```

### CMakeLists.txt file
1. Set the C++ standard with compiler flags.
```
	set(CMAKE_CXX_STANDARD 20)
	set(CMAKE_CXX_FLAGS "-O3")
```
2. Dependent packages should be given with find_package.
```
	find_package(util_c REQUIRED)
	find_package(data_structure_c REQUIRED)
```
3. For library part, use add_library and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_library(Math src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h)
	target_link_libraries(Math util_c::util_c data_structure_c::data_structure_c m)
```
4. For executable tests, use add_executable and target_link_libraries commands. Use m library for math linker in Linux.
```
	add_executable(DiscreteDistributionTest src/Distribution.cpp src/Distribution.h src/DiscreteDistribution.cpp src/DiscreteDistribution.h src/Vector.cpp src/Vector.h src/Eigenvector.cpp src/Eigenvector.h src/Matrix.cpp src/Matrix.h src/Tensor.cpp src/Tensor.h Test/DiscreteDistributionTest.cpp)
	target_link_libraries(DiscreteDistributionTest util_c::util_c data_structure_c::data_structure_c m)
```

### Data files
1. Add data files to the cmake-build-debug folder.

### C++ files

1. If needed, comparator operators == and < should be implemented for map and set data structures.
```
    bool operator==(const Word &anotherWord) const{
        return (name == anotherWord.name);
    }
    bool operator<(const Word &anotherWord) const{
        return (name < anotherWord.name);
    }
```
2. Do not forget to comment each function.
```
	/**
 	* A constructor of Word class which gets a String name as an input and assigns to the name variable.
	*
	* @param _name String input.
 	*/
	Word::Word(const string &_name) {
```
3. Function names should follow caml case.
```
	int Word::charCount() const
```
4. Write getter and setter methods.
```
	string Word::getName() const
	void Word::setName(const string &_name)
```
5. Use catch.hpp for testing purposes. Add
```
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
```
line in only one of the test files. Add
```
#include "catch.hpp"
```
line in all test files. Example test file is given below:
```
TEST_CASE("DictionaryTest") {
    TxtDictionary lowerCaseDictionary = TxtDictionary("lowercase.txt", "turkish_misspellings.txt");
    TxtDictionary mixedCaseDictionary = TxtDictionary("mixedcase.txt", "turkish_misspellings.txt");
    TxtDictionary dictionary = TxtDictionary();
    SECTION("testSize"){
        REQUIRE(29 == lowerCaseDictionary.size());
        REQUIRE(58 == mixedCaseDictionary.size());
        REQUIRE(62113 == dictionary.size());
    }
    SECTION("testGetWord"){
        for (int i = 0; i < dictionary.size(); i++){
            REQUIRE_FALSE(nullptr == dictionary.getWord(i));
        }
    }
    SECTION("testLongestWordSize"){
        REQUIRE(1 == lowerCaseDictionary.longestWordSize());
        REQUIRE(1 == mixedCaseDictionary.longestWordSize());
        REQUIRE(21 == dictionary.longestWordSize());
    }
```
6. Enumerated types should be declared with enum class.
```
	enum class Pos {
		ADJECTIVE,
		NOUN,
		VERB,
		ADVERB,
```
7. Every header file should start with
```
	#ifndef MATH_DISTRIBUTION_H
	#define MATH_DISTRIBUTION_H
```
and end with
```
	#endif //MATH_DISTRIBUTION_H
```
8. Do not forget to use const expression for parameters, if they will not be changed in the function.
```
	void Word::setName(const string &_name);
```
9. Do not forget to use const expression for methods, which do not modify any class attribute. Also use [[dodiscard]]
```
	[[nodiscard]] bool isPunctuation() const;
```
10. Use xmlparser package for parsing xml files.
```
    auto* doc = new XmlDocument("test.xml");
    doc->parse();
    XmlElement* root = doc->getFirstChild();
    XmlElement* firstChild = root->getFirstChild();
```
11. Data structures: Use map for hash map, unordered_map for linked hash map, vector for array list, unordered_set for hash set
