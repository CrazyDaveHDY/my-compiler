#include"LexicalAnalyser.h"
#include "ParserAndSemanticAnalyser.h"
#include "ObjectCodeGenerator.h"

int main() {
	LexicalAnalyser lexicalAnalyser("test.cmm");
	lexicalAnalyser.analyse();
	lexicalAnalyser.outputToFile("lexical.txt");
	
	ParserAndSemanticAnalyser parserAndSemanticAnalyser("grammar.txt");
	parserAndSemanticAnalyser.analyse(lexicalAnalyser.getResult(), "analyse.txt");
	//parserAndSemanticAnalyser.outputIntermediateCode();
	
	IntermediateCode* code = parserAndSemanticAnalyser.getIntermediateCode();
	code->divideBlocks(parserAndSemanticAnalyser.getFuncEnter());
	code->outputBlocks("mid.txt");

	ObjectCodeGenerator objectCodeGenerator;
	objectCodeGenerator.analyseBlock(code->getFuncBlock());
	//objectCodeGenerator.outputIBlocks();
	objectCodeGenerator.generateCode();
	//objectCodeGenerator.outputObjectCode();
	objectCodeGenerator.outputObjectCode("test.asm");
	return 0;
}