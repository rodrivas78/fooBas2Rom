#include "parser_statement_strategy_factory.h"

ParserStatementStrategyFactory::ParserStatementStrategyFactory() {
  strategies["REM"] = &noopStrategy;
  strategies["CL"] = &noopStrategy;
  strategies["EN"] = &noopStrategy;
  strategies["BP"] = &noopStrategy;
  strategies["RN"] = &noopStrategy;
  strategies["'"] = &noopStrategy;

  strategies["WIDTH"] = &genericStrategy;
  strategies["CLEAR"] = &genericStrategy;
  strategies["ERASE"] = &genericStrategy;
  strategies["LC"] = &genericStrategy;
  strategies["DW"] = &genericStrategy;
  strategies["GT"] = &genericStrategy;
  strategies["GS"] = &genericStrategy;
  strategies["RT"] = &genericStrategy;
  strategies["SD"] = &genericStrategy;
  strategies["RS"] = &genericStrategy;
  strategies["RM"] = &genericStrategy;
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
  strategies["PL"] = &genericStrategy;

  strategies["LET"] = &letStrategy;
  strategies["DM"] = &dimStrategy;
  strategies["REDIM"] = &dimStrategy;
  strategies["PRINT"] = &printStrategy;
  strategies["?"] = &printStrategy;
  strategies["IP"] = &inputStrategy;
  strategies["DT"] = &dataStrategy;
  strategies["IDATA"] = &idataStrategy;
  strategies["SN"] = &screenStrategy;
  strategies["SP"] = &spriteStrategy;
  strategies["BASE"] = &baseStrategy;
  strategies["VDP"] = &vdpStrategy;
  strategies["PU"] = &putStrategy;
  strategies["TM"] = &timeStrategy;
  strategies["SET"] = &setStrategy;
  strategies["GET"] = &getStrategy;
  strategies["ON"] = &onStrategy;
  strategies["IN"] = &onStrategy;
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
  strategies["DI"] = &defStrategy;
  strategies["DEFSTR"] = &defStrategy;
  strategies["DEFSNG"] = &defStrategy;
  strategies["DEFDBL"] = &defStrategy;
  strategies["IF"] = &ifStrategy;
  strategies["FO"] = &forStrategy;
  strategies["NX"] = &nextStrategy;
  strategies["PS"] = &graphicsStrategy;
  strategies["PRESET"] = &graphicsStrategy;
  strategies["LN"] = &graphicsStrategy;
  strategies["CI"] = &graphicsStrategy;
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