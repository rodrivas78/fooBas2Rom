#include "parser_statement_strategy_factory.h"

ParserStatementStrategyFactory::ParserStatementStrategyFactory() {
  strategies["REM"] = &noopStrategy;
  strategies["CL"] = &noopStrategy;
  strategies["END"] = &noopStrategy;
  strategies["BEEP"] = &noopStrategy;
  strategies["RANDOMIZE"] = &noopStrategy;
  strategies["'"] = &noopStrategy;

  strategies["WIDTH"] = &genericStrategy;
  strategies["CLEAR"] = &genericStrategy;
  strategies["ERASE"] = &genericStrategy;
  strategies["LC"] = &genericStrategy;
  strategies["DRAW"] = &genericStrategy;
  strategies["GT"] = &genericStrategy;
  strategies["GS"] = &genericStrategy;
  strategies["RT"] = &genericStrategy;
  strategies["SOUND"] = &genericStrategy;
  strategies["RESTORE"] = &genericStrategy;
  strategies["RESUME"] = &genericStrategy;
  strategies["RD"] = &genericStrategy;
  strategies["IREAD"] = &genericStrategy;
  strategies["IRESTORE"] = &genericStrategy;
  strategies["PK"] = &genericStrategy;
  strategies["IPOKE"] = &genericStrategy;
  strategies["VP"] = &genericStrategy;
  strategies["OUT"] = &genericStrategy;
  strategies["SWAP"] = &genericStrategy;
  strategies["WAIT"] = &genericStrategy;
  strategies["SEED"] = &genericStrategy;
  strategies["BLOAD"] = &genericStrategy;
  strategies["PLAY"] = &genericStrategy;

  strategies["LET"] = &letStrategy;
  strategies["DIM"] = &dimStrategy;
  strategies["REDIM"] = &dimStrategy;
  strategies["PRINT"] = &printStrategy;
  strategies["?"] = &printStrategy;
  strategies["INPUT"] = &inputStrategy;
  strategies["DT"] = &dataStrategy;
  strategies["IDATA"] = &idataStrategy;
  strategies["SN"] = &screenStrategy;
  strategies["SP"] = &spriteStrategy;
  strategies["BASE"] = &baseStrategy;
  strategies["VDP"] = &vdpStrategy;
  strategies["PU"] = &putStrategy;
  strategies["TIME"] = &timeStrategy;
  strategies["SET"] = &setStrategy;
  strategies["GET"] = &getStrategy;
  strategies["ON"] = &onStrategy;
  strategies["INTERVAL"] = &onStrategy;
  strategies["STOP"] = &onStrategy;
  strategies["KEY"] = &onStrategy;
  strategies["SG"] = &onStrategy;
  strategies["CR"] = &colorStrategy;
  strategies["CMD"] = &cmdStrategy;
  strategies["OPEN"] = &openStrategy;
  strategies["CLOSE"] = &closeStrategy;
  strategies["MAXFILES"] = &maxfilesStrategy;
  strategies["CALL"] = &callStrategy;
  strategies["_"] = &callStrategy;
  strategies["DEF"] = &defStrategy;
  strategies["DEFINT"] = &defStrategy;
  strategies["DEFSTR"] = &defStrategy;
  strategies["DEFSNG"] = &defStrategy;
  strategies["DEFDBL"] = &defStrategy;
  strategies["IF"] = &ifStrategy;
  strategies["FO"] = &forStrategy;
  strategies["NX"] = &nextStrategy;
  strategies["PS"] = &graphicsStrategy;
  strategies["PRESET"] = &graphicsStrategy;
  strategies["LINE"] = &graphicsStrategy;
  strategies["CIRCLE"] = &graphicsStrategy;
  strategies["PAINT"] = &graphicsStrategy;
  strategies["COPY"] = &graphicsStrategy;
}

ParserStatementStrategyFactory::~ParserStatementStrategyFactory() = default;

IParserStatementStrategy* ParserStatementStrategyFactory::getStrategyByKeyword(
    const string& keyword) {
  map<string, IParserStatementStrategy*>::iterator it =
      strategies.find(keyword);
  if (it == strategies.end()) return nullptr;

  return it->second;
}

size_t ParserStatementStrategyFactory::size() const {
  return strategies.size();
}