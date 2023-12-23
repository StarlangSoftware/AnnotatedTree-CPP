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
	
