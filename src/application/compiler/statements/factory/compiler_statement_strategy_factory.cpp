/***
 * @file compiler_statement_strategy_factory.cpp
 * @brief Compiler statement strategy factory
 */

#include "compiler_statement_strategy_factory.h"

CompilerStatementStrategyFactory::CompilerStatementStrategyFactory() {
  strategies["REM"] = &noopStrategy;
  strategies["'"] = &noopStrategy;

  strategies["FILE"] = &fileStrategy;
  strategies["TEXT"] = &textStrategy;

  strategies["CLEAR"] = &clearStrategy;
  strategies["DEF"] = &defStrategy;
  strategies["DI"] = &defintStrategy;
  strategies["DEFSNG"] = &defsngStrategy;
  strategies["DEFDBL"] = &defdblStrategy;
  strategies["DEFSTR"] = &defstrStrategy;
  strategies["DEFUSR"] = &defusrStrategy;
  strategies["CL"] = &clsStrategy;
  strategies["BP"] = &beepStrategy;
  strategies["LET"] = &letStrategy;
  strategies["TM"] = &timeStrategy;
  strategies["DM"] = &dimStrategy;
  strategies["REDIM"] = &redimStrategy;
  strategies["RN"] = &randomizeStrategy;

  strategies["EN"] = &endStrategy;
  strategies["GT"] = &gotoStrategy;
  strategies["GS"] = &gosubStrategy;
  strategies["RT"] = &returnStrategy;
  strategies["IF"] = &ifStrategy;
  strategies["FO"] = &forStrategy;
  strategies["NX"] = &nextStrategy;
  strategies["ON"] = &onStrategy;
  strategies["IN"] = &intervalStrategy;
  strategies["STOP"] = &stopStrategy;

  strategies["PRINT"] = &printStrategy;
  strategies["IP"] = &inputStrategy;
  strategies["SD"] = &soundStrategy;
  strategies["OUT"] = &outStrategy;
  strategies["PK"] = &pokeStrategy;
  strategies["VP"] = &vpokeStrategy;
  strategies["IPOKE"] = &ipokeStrategy;
  strategies["DT"] = &dataStrategy;
  strategies["IDATA"] = &idataStrategy;
  strategies["RD"] = &readStrategy;
  strategies["IREAD"] = &ireadStrategy;
  strategies["RS"] = &restoreStrategy;
  strategies["IRESTORE"] = &irestoreStrategy;
  strategies["RM"] = &resumeStrategy;
  strategies["WAIT"] = &waitStrategy;
  strategies["SWAP"] = &swapStrategy;
  strategies["CALL"] = &callStrategy;
  strategies["CMD"] = &cmdStrategy;
  strategies["MAXFILES"] = &maxfilesStrategy;
  strategies["OPEN"] = &openStrategy;
  strategies["OPEN_GRP"] = &openGrpStrategy;
  strategies["CLOSE"] = &closeStrategy;
  strategies["BLOAD"] = &bloadStrategy;

  strategies["PL"] = &playStrategy;
  strategies["DW"] = &drawStrategy;
  strategies["LC"] = &locateStrategy;
  strategies["SN"] = &screenStrategy;
  strategies["WIDTH"] = &widthStrategy;
  strategies["CR"] = &colorStrategy;
  strategies["PS"] = &psetStrategy;
  strategies["PRESET"] = &presetStrategy;
  strategies["LN"] = &lineStrategy;
  strategies["PAINT"] = &paintStrategy;
  strategies["CI"] = &circleStrategy;
  strategies["COPY"] = &copyStrategy;
  strategies["PU"] = &putStrategy;
  strategies["GET"] = &getStrategy;
  strategies["SET"] = &setStrategy;
  strategies["KEY"] = &keyStrategy;
  strategies["SG"] = &strigStrategy;
  strategies["SP"] = &spriteStrategy;
}

ICompilerStatementStrategy* CompilerStatementStrategyFactory::getByKeyword(
    const string& keyword) {
  auto it = strategies.find(keyword);

  if (it == strategies.end()) return nullptr;

  return it->second;
}

size_t CompilerStatementStrategyFactory::size() const {
  return strategies.size();
}